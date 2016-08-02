// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////////////////////////////////
// KSMesonet2Spdb.cc
//
// KSMesonet2Spdb object
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// June 2015
//
///////////////////////////////////////////////////////////////
//
// KSMesonet2Spdb reads surface weather observations from the
// Kansas State Mesonet, converts them to station_report_t
// format and writes them to an SPDB data base
//
////////////////////////////////////////////////////////////////

#include <cerrno>
#include <toolsa/pmu.h>
#include <toolsa/Path.hh>
#include <toolsa/TaStr.hh>
#include <didss/DsInputPath.hh>
#include <physics/thermo.h>
#include <physics/physics.h>
#include <Spdb/DsSpdb.hh>
#include <rapformats/WxObs.hh>
#include "KSMesonet2Spdb.hh"
using namespace std;

// Constructor

KSMesonet2Spdb::KSMesonet2Spdb(int argc, char **argv)

{

  isOK = true;

  // set programe name

  _progName = "KSMesonet2Spdb";
  ucopyright((char *) _progName.c_str());

  // get command line args

  if (_args.parse(argc, argv, _progName)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with command line args" << endl;
    isOK = FALSE;
    return;
  }

  // get TDRP params
  
  _paramsPath = (char *) "unknown";
  if (_params.loadFromArgs(argc, argv, _args.override.list,
			   &_paramsPath)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with TDRP parameters" << endl;
    isOK = FALSE;
    return;
  }

  // init process mapper registration

  if (_params.mode == Params::REALTIME) {
    PMU_auto_init((char *) _progName.c_str(),
                  _params.instance,
                  PROCMAP_REGISTER_INTERVAL);
  }

  return;

}

// destructor

KSMesonet2Spdb::~KSMesonet2Spdb()

{

  // unregister process

  PMU_auto_unregister();

}

//////////////////////////////////////////////////
// Run

int KSMesonet2Spdb::Run ()
{

  // register with procmap
  
  PMU_auto_register("Run");

  // file input object
  
  DsInputPath *input = NULL; // Set to NULL to get around compiler warnings.
  
  if (_params.mode == Params::FILELIST) {
    
    // FILELIST mode
    
    input = new DsInputPath(_progName,
			    _params.debug >= Params::DEBUG_VERBOSE,
			    _args.inputFileList);
    
  } else if (_params.mode == Params::ARCHIVE) {
    
    // archive mode - start time to end time
    
    input = new DsInputPath(_progName,
			    _params.debug >= Params::DEBUG_VERBOSE,
			    _params.input_dir,
			    _args.startTime, _args.endTime);
    
  } else if (_params.mode == Params::REALTIME) {
    
    // realtime mode - no latest_data_info file
    
    input = new DsInputPath(_progName,
			    _params.debug >= Params::DEBUG_VERBOSE,
			    _params.input_dir,
			    _params.max_realtime_valid_age,
			    PMU_auto_register,
			    _params.latest_data_info_avail,
			    true);
    
    if (_params.strict_subdir_check) {
      input->setStrictDirScan(true);
    }
    
    if (_params.file_name_check) {
      input->setSubString(_params.file_match_string);
    }
    
  }

  // read in station location details

  if (_readStationLocationFile(_params.station_location_path)) {
    cerr << "ERROR - KSMesonet2Spdb::Run" << endl;
    cerr << "  Cannot read in station location file: " 
         << _params.station_location_path << endl;
    return -1;
  }
  
  // loop through available files
  
  char *inputPath;
  int iret = 0;
  while ((inputPath = input->next()) != NULL) {

    if (_processFile(inputPath)) {
      cerr << "WARNING - KSMesonet2Spdb::Run" << endl;
      cerr << "  Errors in processing file: " << inputPath << endl;
      iret = -1;
    }
    
  } // while
    
  return iret;

}

////////////////////
// process file

int KSMesonet2Spdb::_processFile(const char *file_path)
  
{

  int iret = 0;

  if (_params.debug) {
    cerr << "Processing file: " << file_path << endl;
  }

  // registration
  
  char procmapString[BUFSIZ];
  Path path(file_path);
  sprintf(procmapString, "Processing file <%s>", path.getFile().c_str());
  PMU_force_register(procmapString);
  
  // create spdb output object
  
  DsSpdb out;

  // read in file, loading up chunks in output object spdb
  
  FILE *in;
  if ((in = fopen(file_path, "r")) == NULL) {
    int errNum = errno;
    cerr << "ERROR - KSMesonet2Spdb::_processAwsFile" << endl;
    cerr << "  Cannot open file: " << file_path << endl;
    cerr << "  " << strerror(errNum) << endl;
    return -1;
  }

  int nObs = 0;
  while (!feof(in)) {

    char line[1024];

    if (fgets(line, 1024, in) == NULL) {
      break;
    }

    if (line[0] == ':') {
      continue;
    }

    // remove CR

    line[strlen(line)-1] = '\0';

    // tokenize the line
    
    vector<string> toks;
    TaStr::tokenize(line, _params.input_delimiter, toks);
    WxObs obs;
    si32 stationId = 0;
    if (_fillObs(toks, obs, stationId)) {
      cerr << "ERROR - bad line, cannot decode: " << line << endl;
      continue;
    }
    
    if (_params.debug >= Params::DEBUG_VERBOSE) {
      cerr << "Read line: " << line;
      cerr << "Decoded to the following: " << endl;
      obs.print(cerr);
    }
    
    if (_params.output_report_type == Params::STATION_REPORT) {
      obs.assembleAsReport(STATION_REPORT);
    } else if (_params.output_report_type == Params::XML) {
      obs.assembleAsXml();
    } else {
      fclose(in);
      return -1;
    }
    
    // int stationId = Spdb::hash4CharsToInt32(stid + 1);
    time_t validTime = obs.getObservationTime();
    out.addPutChunk(stationId,
                    validTime,
                    validTime + _params.expire_seconds,
                    obs.getBufLen(), obs.getBufPtr());
    
    nObs++;
    
  } // while

  // close file

  fclose(in);
  
  if (nObs < 0) {
    cerr << "ERROR - KSMesonet2Spdb::_processAwsFile" << endl;
    cerr << "  No valid obs in file: " << file_path << endl;
    return -1;
  }

  // put the data
  
  if (out.put(_params.output_url,
	      SPDB_STATION_REPORT_ID,
	      SPDB_STATION_REPORT_LABEL)) {
    cerr << "ERROR - KSMesonet2Spdb::_processAwsFile" << endl;
    cerr << "  Cannot put station data to: "
	 << _params.output_url << endl;
    cerr << "  " << out.getErrStr() << endl;
    iret = -1;
  }

  if (_params.debug >= Params::DEBUG_VERBOSE) {
    cerr << "Wrote " << nObs << " reports to url: "
	 << _params.output_url << endl;
  }

  if (_params.debug) {
    cerr << "  Done with file: " << file_path << endl;
  }

  return iret;
   
}

///////////////////////////////
// fill out obs object

int KSMesonet2Spdb::_fillObs(const vector<string> &toks, WxObs &obs, si32 &stationId)
  
{

  int iret = 0;

  if (toks.size() < 16) {
    cerr << "ERROR - line too short, only n tokens: " << toks.size() << endl;
    return -1;
  }

  string id = toks[0];
  string timeStr = toks[1];
  double tempF = _decodeDouble(toks[2]);
  double relh = _decodeDouble(toks[3]);
  double precip = _decodeDouble(toks[4]);
  double wspd2m = _decodeDouble(toks[5]);
  double wdir2m = _decodeDouble(toks[6]);
  double wspd10m = _decodeDouble(toks[7]);
  double wdir10m = _decodeDouble(toks[8]);
  double gust2m = _decodeDouble(toks[9]);
  string gustTime2m = toks[10];
  double gust10m = _decodeDouble(toks[11]);
  string gustTime10m = toks[12];
  double solar = _decodeDouble(toks[13]);
  double slp = _decodeDouble(toks[14]);
  string stationName = toks[15];

  if (_params.debug >= Params::DEBUG_VERBOSE) {
    cerr << "--------------------------------" << endl;
    cerr << "  id: " << id << endl;
    cerr << "  timeStr: " << timeStr << endl;
    cerr << "  tempF: " << tempF << endl;
    cerr << "  relh: " << relh << endl;
    cerr << "  precip: " << precip << endl;
    cerr << "  wspd2m: " << wspd2m << endl;
    cerr << "  wdir2m: " << wdir2m << endl;
    cerr << "  wspd10m: " << wspd10m << endl;
    cerr << "  wdir10m: " << wdir10m << endl;
    cerr << "  gust2m: " << gust2m << endl;
    cerr << "  gustTime2m: " << gustTime2m << endl;
    cerr << "  gust10m: " << gust10m << endl;
    cerr << "  gustTime10m: " << gustTime10m << endl;
    cerr << "  solar: " << solar << endl;
    cerr << "  slp: " << slp << endl;
    cerr << "  stationName: " << stationName << endl;
    cerr << "--------------------------------" << endl;
  }

  // get the station location

  StationLoc loc;
  bool found = false;
  for (size_t ii = 0; ii < _stationLocs.size(); ii++) {
    loc = _stationLocs[ii];
    if (id == "xxxxx") {
      if (stationName.find(loc.name) != string::npos) {
        found = true;
        break;
      }
    } else {
      if (id.find(loc.id) != string::npos) {
        found = true;
        break;
      }
    }
  }

  if (!found) {
    cerr << "ERROR - KSMesonet2Spdb::_fillObs()" << endl;
    cerr << "  No station location entry for id: " << id << endl;
    return -1;
  }

  // time

  DateTime obsTime(timeStr);
  DateTime utcTime(obsTime.utime() + _params.utc_correction_secs);
  obs.setObservationTime(utcTime.utime());

  // id

  obs.setStationId(loc.id);
  obs.setLongName(stationName);
  stationId = Spdb::hash4CharsToInt32(loc.id.c_str());

  // location

  obs.setLatitude(loc.latitude);
  obs.setLongitude(loc.longitude);
  obs.setElevationM(loc.htMslM);

  // temp

  double tempC = PHYtemp_f_to_c(tempF);
  if (tempF > -9990) {
    obs.addTempC(tempC);
  }

  // rh

  if (relh > -9990) {
    obs.addRhPercent(relh);
  }

  // dp

  if (tempF > -9990 && relh > -9990) {
    double dewp = PHYrhdp(tempC, relh);
    obs.addDewpointC(dewp);
  }

  // pressure

  if (slp > -9990) {
    obs.addPressureMb(slp);
  }

  // wind

  if (wspd10m > -9990) {
    obs.addWindSpeedMps(wspd10m);
  } else if (wspd2m > -9990) {
    obs.addWindSpeedMps(wspd2m);
  }

  if (wdir10m > -9990) {
    obs.addWindDirnDegT(wdir10m);
  } else if (wdir2m > -9990) {
    obs.addWindDirnDegT(wdir2m);
  }
  
  if (gust10m > -9990) {
    obs.addWindGustMps(gust10m);
  } else if (gust2m > -9990) {
    obs.addWindGustMps(gust2m);
  }

  // precip

  if (precip > -9990) {
    obs.addPrecipLiquidMm(precip * 25.4, 86400);
  }

  return iret;
   
}

////////////////////////
// decode token values

int KSMesonet2Spdb::_decodeInt(const string &tok)

{
  int val;
  if (sscanf(tok.c_str(), "%d", &val) != 1) {
    return -9999;
  }
  return val;
}

double KSMesonet2Spdb::_decodeDouble(const string &tok)
{
  
  double val;
  if (sscanf(tok.c_str(), "%lg", &val) != 1) {
    return -9999.0;
  }
  return val;

}

//////////////////////////////////////////////////////////////
// read in station location details
//
// returns 0 on success, -1 on failure.

int KSMesonet2Spdb::_readStationLocationFile(const string &path)

{
  
  if (_params.debug) {
    cerr << "===========================================================" << endl;
    cerr << "Reading station locations from file: " << path << endl;
  }

  // open file

  FILE *in;
  if ((in = fopen(path.c_str(), "r")) == NULL) {
    int errNum = errno;
    cerr << "ERROR - KSMesonet2Spdb::_readStationLocationFile" << endl;
    cerr << "  Cannot open file: " << path << endl;
    cerr << "  " << strerror(errNum) << endl;
    return -1;
  }
  
  _stationLocs.clear();

  while (!feof(in)) {
    
    char line[4096];
    
    if (fgets(line, 1024, in) == NULL) {
      break;
    }

    if (line[0] == '#') {
      continue;
    }

    // remove CR

    line[strlen(line)-1] = '\0';

    if (_params.debug >= Params::DEBUG_EXTRA) {
      cerr << "  decoding line: " << line << endl;
    }

    // tokenize the line
    
    vector<string> toks;
    TaStr::tokenize(line, ",", toks);

    if (toks.size() > 9) {
      StationLoc loc;
      loc.adminUnit = toks[0];
      loc.id = toks[1];
      loc.name = toks[2];
      loc.county = toks[3];
      loc.latitude = atof(toks[4].c_str());
      loc.longitude = atof(toks[5].c_str());
      loc.htMslFt = atof(toks[6].c_str());
      loc.htMslM = atof(toks[7].c_str());
      loc.opName = toks[8];
      loc.description = toks[9];
      if (_params.debug >= Params::DEBUG_VERBOSE) {
        cerr << "  Station id, name, lat, lon, htM: "
             << loc.id << ", "
             << loc.name << ", "
             << loc.latitude << ", "
             << loc.longitude << ", "
             << loc.htMslM << endl;
      }
      _stationLocs.push_back(loc);
    }

  } // while

  fclose(in);
  
  if (_params.debug) {
    cerr << "===========================================================" << endl;
  }

  return 0;

}
