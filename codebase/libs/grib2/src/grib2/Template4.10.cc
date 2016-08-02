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
/////////////////////////////////////////////////
// Template4_pt_10 Template for percentile 
//                 forecasts at a horizontal level 
//                 or in a horizontal layer in a 
//                 continuous or non-continuous 
//                 time interval.
//
// Jason Craig,  Oct 2008
//
//////////////////////////////////////////////////

#include <iostream>
#include <cmath>

#include <grib2/Template4.10.hh>
#include <grib2/ProdDefTemp.hh>

using namespace std;

namespace Grib2 {

const si32 Template4_pt_10::TEMPLATE4_PT_10_BASE_SIZE = 47;

Template4_pt_10::Template4_pt_10()
: ProdDefTemp()
{

}

Template4_pt_10::Template4_pt_10(Grib2Record::Grib2Sections_t sectionsPtr)
: ProdDefTemp(sectionsPtr)
{

}


Template4_pt_10::~Template4_pt_10 () {


}


int Template4_pt_10::pack (ui08 *templatePtr) 
{
  templatePtr[0] = (ui08) _parameterCategory;

  templatePtr[1] = (ui08) _paramNumber;

  templatePtr[2] = (ui08) _processType;

  templatePtr[3] = (ui08) _backgrdProcessId;

  templatePtr[4] = (ui08) _processID;

  GribSection::_pkUnsigned2(_hoursObsDataCutoff, &(templatePtr[5]));

  templatePtr[7] = (ui08) _minutesObsDataCutoff;

  templatePtr[8] = (ui08) _timeRangeUnit;

  GribSection::_pkUnsigned4(_forecastTime, &(templatePtr[9]));

  templatePtr[13] = (ui08) _firstSurfaceType;

  templatePtr[14] = (ui08) _scaleFactorFirstSurface;

  GribSection::_pkUnsigned4(_scaleValFirstSurface, &(templatePtr[15]));

  templatePtr[19] = (ui08) _secondSurfaceType;

  templatePtr[20] = (ui08) _scaleFactorSecondSurface;

  GribSection::_pkUnsigned4(_scaleValSecondSurface, &(templatePtr[21]));

  templatePtr[25] = (ui08) _percentileValue;

  GribSection::_pkUnsigned2(_year, &(templatePtr[26]));

  templatePtr[28] = (ui08) _month;

  templatePtr[29] = (ui08) _day;

  templatePtr[30] = (ui08) _hour;

  templatePtr[31] = (ui08) _minute;

  templatePtr[32] = (ui08) _second;

  templatePtr[33] = (ui08) _numTimeIntervals;

  GribSection::_pkUnsigned4(_numMissingVals, &(templatePtr[34]));

  for (int i = 0; i < _numTimeIntervals; i++) {
    templatePtr[38 + i * 12] = (ui08) _interval[i]._processId;
    templatePtr[39 + i * 12] = (ui08) _interval[i]._timeIncrementType;
    templatePtr[40 + i * 12] = (ui08) _interval[i]._timeRangeUnit;
    GribSection::_pkUnsigned4(_interval[i]._timeRangeLen, &(templatePtr[41 + i * 12]));
    templatePtr[45 + i * 12] = (ui08) _interval[i]._timeIncrUnit;
    GribSection::_pkUnsigned4(_interval[i]._timeIncrement, &(templatePtr[46 + i * 12]));     
  }

  return GRIB_SUCCESS;

}

int Template4_pt_10::unpack (ui08 *templatePtr) 
{

  _parameterCategory = (si32) templatePtr[0]; 
  
  _paramNumber = (si32) templatePtr[1]; 

  // set strings for parameter, longParameter and units
  setParamStrings();

  // Type of generating process
  _processType = (si32) templatePtr[2]; 

  // Background generating process identifier 
  _backgrdProcessId = (si32) templatePtr[3]; 

  // Analysis or forecast generating processes identifier 
  _processID = (si32) templatePtr[4]; 

  // Hours of observational data cutoff after reference time
  _hoursObsDataCutoff 
            = GribSection::_upkUnsigned2 (templatePtr[5], templatePtr[6]);

  // Minutes of observational data cutoff after reference time
  _minutesObsDataCutoff = (si32) templatePtr[7]; 

  // Indicator of unit of time range
  _timeRangeUnit = (si32) templatePtr[8]; 

  // Forecast Time, In units defined by _timeRangeUnit
  _forecastTime =
       GribSection::_upkUnsigned4 (templatePtr[9], templatePtr[10], templatePtr[11], templatePtr[12]);

  // Type of first fixed surface
  _firstSurfaceType = (si32) templatePtr[13]; 

  // Scale factor of first fixed surface
  _scaleFactorFirstSurface = (si32) templatePtr[14];

  // Scale value of first fixed surface
  _scaleValFirstSurface =
       GribSection::_upkUnsigned4 (templatePtr[15], templatePtr[16], templatePtr[17], templatePtr[18]);

  if(_scaleValFirstSurface < -100000000) 
    _scaleValFirstSurface = 
      GribSection::_upkSigned4 (templatePtr[15], templatePtr[16], templatePtr[17], templatePtr[18]);

  // Type of second fixed surface
  _secondSurfaceType = (si32) templatePtr[19]; 

  // Scale factor of second fixed surface
  _scaleFactorSecondSurface = (si32) templatePtr[20];

  // Scale value of second fixed surface
  _scaleValSecondSurface =
       GribSection::_upkUnsigned4 (templatePtr[21], templatePtr[22], templatePtr[23], templatePtr[24]);

  // Percentile value (from 100% to 0%)
  _percentileValue = (si32) templatePtr[25];

  _year   = GribSection::_upkUnsigned2 (templatePtr[26], templatePtr[27]);
  _month  = (si32) templatePtr[28];
  _day    = (si32) templatePtr[29];
  _hour   = (si32) templatePtr[30];
  _minute = (si32) templatePtr[31];
  _second = (si32) templatePtr[32];

  _numTimeIntervals = (si32) templatePtr[33];
  _numMissingVals = GribSection::_upkUnsigned4 (templatePtr[34], templatePtr[35], templatePtr[36], templatePtr[37]);

  for (int i = 0; i < _numTimeIntervals; i++) {
     ProdDefTemp::interval_t intrv;
     intrv._processId = (si32) templatePtr[38 + i * 12]; 
     intrv._timeIncrementType = (si32) templatePtr[39 + i * 12];
     intrv._timeRangeUnit = (si32) templatePtr[40 + i * 12];
     intrv._timeRangeLen = GribSection::_upkUnsigned4 (templatePtr[41 + i * 12], 
                                                       templatePtr[42 + i * 12], 
                                                       templatePtr[43 + i * 12], 
                                                       templatePtr[44 + i * 12]);
     intrv._timeIncrUnit = (si32) templatePtr[45 + i * 12];
     intrv._timeIncrement = GribSection::_upkUnsigned4 (templatePtr[46 + i * 12],
                                                        templatePtr[47 + i * 12], 
                                                        templatePtr[48 + i * 12], 
                                                        templatePtr[49 + i * 12]);
     _interval.push_back(intrv);
     
  }

  return (GRIB_SUCCESS);
}

void Template4_pt_10::getRecSummary (Grib2Record::rec_summary_t *summary) 
{

  int ndex, ndex2;
  summary->discipline = _disciplineNum;
  summary->category = _parameterCategory;
  summary->paramNumber = _paramNumber;
  summary->name.assign (_parameterName->c_str());
  summary->name.append ("_PERC");
  summary->longName.assign (_parameterLongName->c_str());
  summary->longName.append (" Percentile");
  summary->units.assign ("%");

  summary->forecastTime = _getTimeUnitName(_forecastTime, _timeRangeUnit);

  summary->additional.assign ("");

  ndex = _getSurfaceIndex(_firstSurfaceType);
  if ((ndex < 0)) {
    summary->levelType.assign("UNKNOWN");
    summary->levelTypeLong.assign ("unknown primary surface type");
    summary->levelUnits.assign ("");
  } else {
    summary->levelType.assign (_surface[ndex].name);
    summary->levelTypeLong.assign (_surface[ndex].comment);
    summary->levelUnits.assign (_surface[ndex].unit);
  }

  summary->levelVal = _scaleValFirstSurface;
  if(_scaleFactorFirstSurface > 0 && _scaleFactorFirstSurface < 127)
    summary->levelVal /= pow(10.0, _scaleFactorFirstSurface);
  if(_scaleFactorFirstSurface > 127 && _scaleFactorFirstSurface != 255)
    summary->levelVal *= pow(10.0, _scaleFactorFirstSurface & 127);

  ndex2 = _getSurfaceIndex(_secondSurfaceType);
  if (_secondSurfaceType == 255 || (ndex2 < 0))
    summary->levelVal2 = -999;
  else
    if(ndex2 != ndex) {
      summary->levelType.append ("-");
      summary->levelType.append (_surface[ndex2].name);
    } else {
      summary->levelVal2 = _scaleValSecondSurface;
      if(_scaleFactorSecondSurface > 0 && _scaleFactorSecondSurface < 127)
	summary->levelVal2 /= pow(10.0, _scaleFactorSecondSurface);
      if(_scaleFactorSecondSurface > 127 && _scaleFactorSecondSurface != 255)
	summary->levelVal2 *= pow(10.0, _scaleFactorSecondSurface & 127);
    }

  vector <interval_t >::const_iterator I = _interval.begin();
  int timeRangeUnit = I->_timeRangeUnit;
  int processId = I->_processId;
  int totalTime = 0;
  for (; I != _interval.end(); ++I) {
    totalTime += I->_timeRangeLen; 
    if(timeRangeUnit != I->_timeRangeUnit) {
      cerr << "WARNING: Template4.10::getRecSummary()" << endl;
      cerr << "Interval timeRangeUnits are not equal." << endl;
    }
    if(processId != I->_processId) {
      cerr << "WARNING: Template4.8::getRecSummary()" << endl;
      cerr << "Interval statistical process types are not equal." << endl;
    }
  }
  summary->name.append ( _getTimeUnitName(totalTime, timeRangeUnit) );
  summary->name.append ( _getStatisticalProcess(processId) );

  return;
}

long int Template4_pt_10::getForecastTime() const
{
  long int forecastTime = _getTimeUnits(_timeRangeUnit) * _forecastTime;
   
   vector <interval_t >::const_iterator I;
   for (I = _interval.begin(); I != _interval.end(); ++I) {
     forecastTime += _getTimeUnits(I->_timeRangeUnit) * I->_timeRangeLen;
   }
   return( forecastTime );
}


void Template4_pt_10::print(FILE *stream) const
{
  int ndex;

  fprintf(stream, "Parameter Discipline: %d\n", _disciplineNum);
  fprintf(stream, "Parameter Category is %d\n", _parameterCategory);
  fprintf(stream, "Parameter Number is %d\n", _paramNumber);
  fprintf(stream, "Parameter name '%s_PERC' \n", _parameterName->c_str());
  fprintf(stream, "     long name '%s Percentile'\n", _parameterLongName->c_str());
  fprintf(stream, "         units '%%'\n");
  _printGeneratingProcessType(stream, _processType);
  fprintf(stream, "Background generating process identifier %d\n", _backgrdProcessId);
  fprintf(stream, "Generating process identifier: %s\n", getGeneratingProcess().c_str());
  fprintf(stream, "Hours of observational data cutoff after reference time %d\n", _hoursObsDataCutoff);
  fprintf(stream, "Minutes of observational data cutoff after reference time %d\n", _minutesObsDataCutoff);
  fprintf(stream, "Forecast time is %d ", _forecastTime);
  _printTimeUnits(stream, _timeRangeUnit);

  fprintf(stream, "Type of first fixed surface is %d\n", _firstSurfaceType);
  ndex = _getSurfaceIndex(_firstSurfaceType);
  if ((ndex < 0) || (_firstSurfaceType == 255))
    fprintf (stream, "    unknown/missing primary surface type\n");
  else {
    fprintf(stream, "    Surface name '%s'\n", _surface[ndex].name.c_str());
    fprintf(stream, "       long name '%s'\n", _surface[ndex].comment.c_str());
    fprintf(stream, "           units '%s'\n", _surface[ndex].unit.c_str());
    fprintf(stream, "    Scale factor of first fixed surface %d\n", _scaleFactorFirstSurface);
    fprintf(stream, "    Scale value of first fixed surface %d\n", _scaleValFirstSurface);
  }
  fprintf(stream, "Type of second fixed surface %d\n", _secondSurfaceType);
  ndex = _getSurfaceIndex(_secondSurfaceType);
  if ((ndex < 0) || (_secondSurfaceType == 255))
    fprintf (stream, "    unknown/missing second surface type\n");
  else {
    fprintf(stream, "    Surface name '%s'\n", _surface[ndex].name.c_str());
    fprintf(stream, "       long name '%s'\n", _surface[ndex].comment.c_str());
    fprintf(stream, "           units '%s'\n", _surface[ndex].unit.c_str());
    fprintf(stream, "    Scale factor of second fixed surface %d\n", _scaleFactorFirstSurface);
    fprintf(stream, "    Scale value of second fixed surface %d\n", _scaleValFirstSurface);
  }
  fprintf(stream, "Percentile Value %d %%\n", _percentileValue);
  fprintf(stream, "Time of end of overall time interval %4d%02d%02d%02d%02d%02d\n",
	  _year, _month, _day, _hour, _minute, _second);

  fprintf(stream, "Number of trime range specifications %d\n", _numTimeIntervals);
  fprintf(stream, "Total number of missing values %d\n", (int)_numMissingVals);

  vector <interval_t >::const_iterator I;
  for (I = _interval.begin(); I != _interval.end(); ++I) {
    _printStatisticalProcess(stream, I->_processId);
    _printTimeIncrementType(stream, I->_timeIncrementType);

    fprintf(stream, "    Length of the time range %d ", I->_timeRangeLen); 
    _printTimeUnits(stream, I->_timeRangeUnit);

    fprintf(stream, "    Time increment between successive fields %d ", I->_timeIncrement);
    _printTimeUnits(stream, I->_timeIncrUnit);
  }
  fprintf(stream,"\n\n");
}

} // namespace Grib2

