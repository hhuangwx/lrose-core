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
/////////////////////////////////////////////////////////////
// BufrFile.cc
//
// BUFR file wrapper
//
// Mike Dixon, EOL, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Jan 2017
//
///////////////////////////////////////////////////////////////

#include <Radx/BufrFile.hh>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <sys/stat.h>
#include <dirent.h>
#include <algorithm>
#include <Radx/TableMapKey.hh>
//#include <Radx/TableMap.hh>

using namespace std;

//////////////
// Constructor

BufrFile::BufrFile()
  
{

  //_ncFormat = Nc3File::Classic;

  _file = NULL;
  _errString.clear();

  clear();


}

/////////////
// destructor

BufrFile::~BufrFile()

{
  clear();
}

/////////////////////////////////////////////////////////
// clear the data in the object

void BufrFile::clear()
  
{
  //clearErrStr();
  close();
  _pathInUse.clear();
}

/*
//////////////////////////////////////
// open netcdf file for reading
4// Returns 0 on success, -1 on failure

int BufrFile::openRead(const string &path)
  
{

  close();
  _pathInUse = path;
  _file = new Nc3File(path.c_str(), Nc3File::ReadOnly);
  
  // Check that constructor succeeded
  
  if (!_ncFile || !_ncFile->is_valid()) {
    _addErrStr("ERROR - BufrFile::openRead");
    _addErrStr("  File is not NetCDF, path: ", path);
    close();
    return -1;
  }
  
  // Change the error behavior of the netCDF C++ API by creating an
  // Nc3Error object. Until it is destroyed, this Nc3Error object will
  // ensure that the netCDF C++ API silently returns error codes
  // on any failure, and leaves any other error handling to the
  // calling program.

  if (_err == NULL) {
    _err = new Nc3Error(Nc3Error::silent_nonfatal);
  }

  return 0;

}
*/
/*
//////////////////////////////////////////////
/// open netcdf file for writing
/// create error object so we can handle errors
/// set the netcdf format, before a write
/// format options are:
///   Classic - classic format (i.e. version 1 format)
///   Offset64Bits - 64-bit offset format
///   Netcdf4 - netCDF-4 using HDF5 format
///   Netcdf4Classic - netCDF-4 using HDF5 but only netCDF-3 calls
/// Returns 0 on success, -1 on failure

int BufrFile::openWrite(const string &path,
                        Nc3File::FileFormat format) 

{
  
  close();
  _pathInUse = path;
  _ncFormat = format;
  _ncFile = new Nc3File(path.c_str(), Nc3File::Replace, NULL, 0, _ncFormat);
  
  if (!_ncFile || !_ncFile->is_valid()) {
    _addErrStr("ERROR - BufrFile::openWrite");
    _addErrStr("  Cannot open netCDF file for writing: ", path);
    close();
    return -1;
  }
  
  // Change the error behavior of the netCDF C++ API by creating an
  // Nc3Error object. Until it is destroyed, this Nc3Error object will
  // ensure that the netCDF C++ API silently returns error codes
  // on any failure, and leaves any other error handling to the
  // calling program.
  
  if (_err == NULL) {
    _err = new Nc3Error(Nc3Error::silent_nonfatal);
  }

  return 0;

}
*/

//////////////////////////////////////
// close netcdf file if open
// remove error object if it exists

void BufrFile::close()
  
{
  
  // close file if open, delete ncFile
  
  if (_file) {
    fclose(_file);
    //delete _ncFile;
    _file = NULL;
  }
  /*
  if (_err) {
    delete _err;
    _err = NULL;
  }
  */
}

/*
///////////////////////////////////////////
// add string global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, const string &val)
{
  if (!_ncFile->add_att(name.c_str(), val.c_str())) {
    _addErrStr("ERROR - BufrFile::addGlobalAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrStr("  val: ", val);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add int global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, int val)
{
  if (!_ncFile->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add float global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, float val)
{
  if (!_ncFile->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add double global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, double val)
{
  if (!_ncFile->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add int[] global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, int len, int *vals)
{
  if (!_ncFile->add_att(name.c_str(), len, vals)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  n ints: ", len);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add float[] global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, int len, float *vals)
{
  if (!_ncFile->add_att(name.c_str(), len, vals)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  n floats: ", len);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add double[] global attribute
// Returns 0 on success, -1 on failure

int BufrFile::addGlobAttr(const string &name, int len, double *vals)
{
  if (!_ncFile->add_att(name.c_str(), len, vals)) {
    _addErrStr("ERROR - BufrFile::addGlobAttr");
    _addErrStr("  Cannot add global attr name: ", name);
    _addErrInt("  n doubles: ", len);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// read a global attribute
// Returns 0 on success, -1 on failure

int BufrFile::readGlobAttr(const string &name, string &val)
{
  Nc3Att *att = _ncFile->get_att(name.c_str());
  if (att == NULL) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot read global attr name: ", name);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  val = asString(att);
  return 0;
}

int BufrFile::readGlobAttr(const string &name, int &val)
{
  Nc3Att *att = _ncFile->get_att(name.c_str());
  if (att == NULL) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot read global attr name: ", name);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  string sval = asString(att);
  int ival;
  if (sscanf(sval.c_str(), "%d", &ival) != 1) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot interpret global attr as int");
    _addErrStr("  name: ", name);
    _addErrStr("  val: ", sval);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  val = ival;
  return 0;
}

int BufrFile::readGlobAttr(const string &name, float &val)
{
  Nc3Att *att = _ncFile->get_att(name.c_str());
  if (att == NULL) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot read global attr name: ", name);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  string sval = asString(att);
  float fval;
  if (sscanf(sval.c_str(), "%g", &fval) != 1) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot interpret global attr as float");
    _addErrStr("  name: ", name);
    _addErrStr("  val: ", sval);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  val = fval;
  return 0;
}

int BufrFile::readGlobAttr(const string &name, double &val)
{
  Nc3Att *att = _ncFile->get_att(name.c_str());
  if (att == NULL) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot read global attr name: ", name);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  string sval = asString(att);
  double dval;
  if (sscanf(sval.c_str(), "%lg", &dval) != 1) {
    _addErrStr("ERROR - BufrFile::readGlobAttr");
    _addErrStr("  Cannot interpret global attr as double");
    _addErrStr("  name: ", name);
    _addErrStr("  val: ", sval);
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  val = dval;
  return 0;
}

///////////////////////////////////////////
// add string attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, const string &val)
{
  if (!var->add_att(name.c_str(), val.c_str())) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add string var attr, name: ", name);
    _addErrStr("  val: ", val);
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add double attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, double val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add double var attr, name: ", name);
    _addErrDbl("  val: ", val, "%g");
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add float attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, float val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add float var attr, name: ", name);
    _addErrDbl("  val: ", val, "%g");
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add int attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, int val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add int var attr, name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add long attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, long val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add long var attr, name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add short attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, short val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add short var attr, name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add ncbyte attribute
// Returns 0 on success, -1 on failure

int BufrFile::addAttr(Nc3Var *var, const string &name, ncbyte val)
{
  if (!var->add_att(name.c_str(), val)) {
    _addErrStr("ERROR - BufrFile::addAttr");
    _addErrStr("  Cannot add ncbyte var attr, name: ", name);
    _addErrInt("  val: ", val);
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// add a dimension
// Returns 0 on success, -1 on failure
// Side effect: dim arg is updated

int BufrFile::addDim(Nc3Dim* &dim, const char *name, int size)
{
  if (size < 1) {
    dim = _ncFile->add_dim(name);
  } else {
    dim = _ncFile->add_dim(name, size);
  }
  if (dim == NULL) {
    _addErrStr("ERROR - BufrFile::addDim");
    _addErrStr("  Cannot add dimension: ", name);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}

///////////////////////////////////////////
// read a dimension
// Returns 0 on success, -1 on failure
// Side effect: dim arg is set

int BufrFile::readDim(const string &name, Nc3Dim* &dim)

{
  dim = _ncFile->get_dim(name.c_str());
  if (dim == NULL) {
    _addErrStr("ERROR - BufrFile::readDim");
    _addErrStr("  Cannot read dimension, name: ", name);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  return 0;
}
*/
//////////////////////////////////////
// open netcdf file for reading
// Returns 0 on success, -1 on failure

int BufrFile::openRead(const string &path)
  
{

  close();
  _file = fopen(path.c_str(), "r");
  
  // Check that constructor succeeded
  
  if (_file == NULL) {
    // int errNum = errno;
    // _addErrStr("ERROR - BufrFile::_openRead");
    // _addErrStr("  Cannot open file for reading, path: ", path);
    // _addErrStr("  ", strerror(errNum));
    return -1;
  }
  
  return 0;

}

///////////////////////////////////////////
// read Section 0
// which positively identifies this as a BUFR file
// Returns 0 on success, -1 on failure
// Side effect: 

int BufrFile::readSection0()

{

  //if (!bufr_read_file(&msg, argv[1])) {
  //      fprintf (stderr, "FATAL: Unable to read the BUFR-message in %s!\n", argv[1]);
  //      exit (EXIT_FAILURE);
  //}

  /******* decode section 0 */
  fprintf (stderr, "Input file header:\n");


  /*-----------------------------
  // open file

  if (_openRead(path)) {
    _addErrStr("ERROR - BufrFile::_readSection0");
    return -1;
  }
  */
  // read through file, finding data blocks
  
  //while (!feof(_file)) {

    // read ID
    
    char id[8];
    memset(id, 0, 8);
    
    if (fread(id, 1, 4, _file) != 4) {
      //if (feof(_file)) {
        // done
      //  break;
      //}
      /*
      int errNum = errno;
      _addErrStr("ERROR - BufrFile::_readSection0");
      _addErrStr("  Cannot read id string");
      _addErrStr("  File path: ", path);
      _addErrStr(strerror(errNum));
      */
      close();
      return -1;
    }

    _numBytesRead += 4;

    string idStr(id);
    if ((id[0] != 'B') || (id[1] != 'U') || (id[2] != 'F') || (id[3] != 'R')) {
      return -1;
    }
    
    // read length of message in octets
    // the length is 24 bits (3 bytes)
    Radx::ui32 nBytes;
    unsigned char id2[4];
    //id[0] = 0;
    if (fread(id2, 1, 3, _file) != 3) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }

    _numBytesRead += 3;

    nBytes = 0;
    nBytes = nBytes | id2[2];
    nBytes = nBytes | (id2[1] << 8);
    nBytes = nBytes | (id2[0] << 16);

    cerr << "nBytes " << nBytes << endl;
    _s0.nBytes = nBytes;

    Radx::ui08 bufr_edition;

    if (fread(&bufr_edition, 1, 1, _file) != 1) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }
    _s0.edition = bufr_edition;   
    printf("BUFR edition number %d\n", bufr_edition); 

    _numBytesRead += 1;
    // swap as needed

    //-------------------

    //}
  /*
  //dim = _ncFile->get_dim(name.c_str());
  if (!_file->bufr_decode_sections01(&s1, &msg)) {
    //fprintf (stderr, "FATAL: Unable to decode section 1\n");
    //exit (EXIT_FAILURE);
    _addErrStr("ERROR - BufrFile::readDim");
    _addErrStr("  Cannot read dimension, name: ", name);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  header_dump(&s1);
  */
  return 0;
}
///////////////////////////////////////////
// read Section 1
// which gives time and table info
// Returns 0 on success, -1 on failure
// Side effect: 

int BufrFile::readSection1()
{

  /******* decode section 1 */
  fprintf (stderr, "Input file header:\n");


    // read ID
    // TODO: allocate this space based on the length of section read (octets 1 - 3)
    Radx::ui08 id[4];
    memset(id, 0, 4);
    
    // read length of message in octets
    // the length is 24 bits (3 bytes)
    Radx::ui32 nBytes;
    if (fread(id, 1, 3, _file) != 3) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }
    nBytes = 0;
    nBytes = nBytes | id[2];
    nBytes = nBytes | (id[1] << 8);
    nBytes = nBytes | (id[0] << 16);
    Radx::ui32 sectionLen;
    sectionLen = nBytes;

    cerr << "sectionLen " << sectionLen << endl;

    Radx::ui08 *buffer;
    buffer = (Radx::ui08 *) calloc(sectionLen, sizeof(Radx::ui08));
    memset(buffer, 0, sectionLen);

    if (fread(buffer, 1, sectionLen-3, _file) != sectionLen-3) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }


    Radx::ui08 bufrMasterTable;
    bufrMasterTable = buffer[0];
    // check 1st bit of the octect for optional section 2
    bool section2 = buffer[6]; //  & 0x80; 
    _s1.hasSection2 = section2;
    cerr << "section 2? " ;
    if (section2) {
      cerr << "yes" << endl;
    } else {
      cerr << "no" << endl;
    }
    Radx::ui16 yearOfCentury;
    Radx::ui08 month;
    Radx::ui08 day;
    Radx::ui08 hour;
    Radx::ui08 minute;
    Radx::ui08 seconds;


    if (_s0.edition >= 4) {
      _s1.masterTable = buffer[0];
      _s1.generatingCenter = buffer[1] << 8 | (buffer[2]);
      _s1.originatingSubcenter = buffer[3] << 8 | (buffer[4]);
      _s1.updateSequenceNumber = buffer[5]; // original BUFR message
      _s1.dataCategoryType = buffer[7];
      _s1.localTableVersionNumber = buffer[11];
      _s1.masterTableVersionNumber = buffer[10];

      printf("master table: %d\n", _s1.masterTable);
      printf("generatingc center: %d\n", _s1.generatingCenter);
      printf("originating subcenter: %d\n", _s1.originatingSubcenter);
      printf("update sequence number: %d\n", _s1.updateSequenceNumber);
      printf("data category type: %d\n", _s1.dataCategoryType);
      printf("local table version: %d\n", _s1.localTableVersionNumber);
      printf("master table version: %d\n", _s1.masterTableVersionNumber);

      yearOfCentury = 0;
      yearOfCentury = yearOfCentury |  buffer[13];
      yearOfCentury = yearOfCentury | (buffer[12] << 8);
      month = buffer[14] | 0;
      day = buffer[15] | 0;
      hour = buffer[16] | 0;
      minute = buffer[17] | 0;
      seconds = buffer[18] | 0;

    }   
    // TODO: figure out _debug ... try RadxFile::copyReadDirectives .. if (_debug) {
      cerr << "year-month-day hour:minute:sec " <<
        yearOfCentury << "-" << 
        month  << "-" << 
        day  << " " << 
        hour  << ":" << 
        minute <<  ":" <<
        seconds << endl;
      //}

      printf("year-month-day hour:minute:sec\n%d-%d-%d %d:%d:%d\n",
	     yearOfCentury, month, day, hour, minute, seconds); 
    
      _numBytesRead += sectionLen;
  return 0;
}

// taken from bufr2hdf5.c -- read_tables(...)
int BufrFile::readDescriptorTables() {

  return 0;
}



int BufrFile::readDataDescriptors() {  // read section 3
  /******* decode section 3 */
  fprintf (stderr, "Reading section 3 ...\n");

    // read 
    // TODO: allocate this space based on the length of section read (octets 1 - 3)
    Radx::ui08 id[4];
    memset(id, 0, 4);
    
    // read length of message in octets
    // the length is 24 bits (3 bytes)
    Radx::ui32 nBytes;
    if (fread(id, 1, 3, _file) != 3) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }
    nBytes = 0;
    nBytes = nBytes | id[2];
    nBytes = nBytes | (id[1] << 8);
    nBytes = nBytes | (id[0] << 16);
    Radx::ui32 sectionLen;
    sectionLen = nBytes;

    cerr << "sectionLen " << sectionLen << endl;

    Radx::ui08 *buffer;
    buffer = (Radx::ui08 *) calloc(sectionLen, sizeof(Radx::ui08));
    memset(buffer, 0, sectionLen);
    int nBytesToSectionEnd;
    nBytesToSectionEnd = sectionLen-3;
    if (fread(buffer, 1, nBytesToSectionEnd, _file) != sectionLen-3) {
      int errNum = errno;
      //      _addErrStr("ERROR - DoradeRadxFile::_readSection0()");
      //_addErrStr("  Cannot read data length");
      //_addErrStr("  ID: ", id);
      //_addErrStr("  File path: ", path);
      //_addErrStr(strerror(errNum));
      close();
      return -1;
    }

    // octet 4 is reserved and set to zero
    // get the number of data subsets/descriptors
    Radx::ui16 nDataSubsets;
    nDataSubsets = 0;
    nDataSubsets = nDataSubsets | buffer[2];
    nDataSubsets = nDataSubsets | (buffer[1] << 8);
    printf("nDataSubsets = %d\n", nDataSubsets);

    // determine observed and compressed info
    bool observedData = buffer[3] & 0x80;
    bool compressedData = buffer[3] & 0x40;

    // read the descriptors and keep them in a list for
    // traversal later 

    //_descriptorsToProcess.clear();
    //int nDescriptors;
    //nDescriptors = sectionLen 
    int i;
    int startOffset = 4;
    // remember, we need to have two bytes remaining
    // in the buffer in order to grab another descriptor
    for (i=startOffset; i<nBytesToSectionEnd-1; i+=2) {
      // get and decode the descriptors
      DescriptorKey d;
      // f is the first 2 bits
      Radx::ui08 f;
      f =  buffer[i] >> 6;  // 1100 0000
      d.f = f;
      d.x = buffer[i] & 0x3f; // 0011 1111
      d.y = buffer[i + 1];
      printf("f x y: %d %d %d\n", d.f, d.x, d.y);
      unsigned short key;
      key = TableMapKey().EncodeKey(d.f, d.x, d.y);
      _descriptorsToProcess.insert(_descriptorsToProcess.begin(), key);
    }

    _numBytesRead += sectionLen;
  return 0;
}

// necessary for entry into this function:
// the file pointer must be positioned at the start of 
// section 4.
int BufrFile::readData() {  // read section 4

  // prime the pump
  currentBufferLengthBytes = ReplenishBuffer();
  currentBufferLengthBits = currentBufferLengthBytes * 8;
  currentBufferIndexBits = 0;
  if (currentBufferLengthBits <= 0) {
    return -1;
  }

  /*  // >>>>>>>>>> just for testing 
  _dataBuffer[0] = 0x4d;

  Radx::ui32 x;
  x = ExtractIt(3);
  x = ExtractIt(2); 
  x = ExtractIt(17);
  */

  //  TableMap tableMap;
  tableMap.ImportTables();

  TraverseNew(_descriptorsToProcess);

  //TODO:  read the last section 
  int nbytesRead;
  nbytesRead = ReplenishBuffer();

  return 0;
}

// return the next nbits in the read buffer encased in a string
// there can be leading and trailing bits that are not needed
// returns 0 on success; -1 on failure
// int  BufrFile::NextNBitsEncased(int nbits, string ecasedBits, int *startIndex) {
//   string s; 
//   s = newString();

//   return 0;
// }

// need to buffer the binary data, so that we can read in a block
// of data and move a pointer within the block to retrieve bits
//char *BufrFile::NextNBitsAsChar(int nbits) {
  // remember, the character strings are encoded ins CCITT International Alphabet No. 5
//  return NULL;
//}

int BufrFile::ReplenishBuffer() {

  static bool first = true;
  static int nOctetsRead = 0;
  //bool _debug = false;

  if (first) {
    fread(_dataBuffer, 1, 4, _file);
    first = false;
  }
  int nBytesRead;
  nBytesRead = fread(_dataBuffer, 1, MAX_BUFFER_SIZE_BYTES, _file);

  nOctetsRead += nBytesRead;
  printf("nOctetsRead = %d\n", nOctetsRead);

  _numBytesRead += nBytesRead;
  printf("Read %d/%d bytes ", _numBytesRead, _s0.nBytes);

  if (_debug) {
    printf("buffer: ");
    for (int i=0; i<MAX_BUFFER_SIZE_BYTES; i++) 
      printf("%0x ", _dataBuffer[i]);
    printf(" current position %d \n", currentBufferIndexBits);
  }

  return nBytesRead;
 
}

bool BufrFile::NextBit() {
  int idx;
  unsigned char mask;
  int bitPosition;
  bool bitValue;
  static bool endOfFile = false;

    bitPosition = 7 - currentBufferIndexBits % 8;
    mask = 1 << bitPosition;
    idx = currentBufferIndexBits / 8;
    if (mask & _dataBuffer[idx]) {
      // insert a 1
      bitValue = true;
    } else {
      bitValue = false;
    }
   
    // advance the index
    currentBufferIndexBits += 1;
    if (currentBufferIndexBits >= currentBufferLengthBits) {
      // replenish the buffer
      currentBufferLengthBytes = ReplenishBuffer();
      currentBufferLengthBits = currentBufferLengthBytes * 8;
      currentBufferIndexBits = 0;
      if (currentBufferLengthBits <= 0) {
        endOfFile = true;  // TODO: throw an exception
      }
    }
    return bitValue;
}


// on error, return -1; otherwise, a positive integer will be returned
string BufrFile::ExtractText(int nBits) {

  string val;
  int idx;
  unsigned char mask;
  unsigned char character;

  val.clear();

  // if the number of bits is not a multiple of 8, then
  // we cannot extract as text
  if ((nBits % 8) != 0)  {
    cout << "ERROR: text width is not multiple of 8; cannot read in data" << endl;
    return val;
  }

  int i=0;
  bool endOfFile = false;
  int bitPosition;
  // move one bit at a time
  while ((i<nBits) && (!endOfFile)) {
    // bitPosition = 7 - currentBufferIndexBits % 8;
    // mask = 1 << bitPosition;
    // idx = currentBufferIndexBits / 8;
    // if (mask & _dataBuffer[idx]) {
    if (NextBit()) {
      // insert a 1
      character = character * 2 + 1;
    } else {
      character = character * 2;
    }
   
    // // advance the index
    // currentBufferIndexBits += 1;
    // if (currentBufferIndexBits >= currentBufferLengthBits) {
    //   // replenish the buffer
    //   currentBufferLengthBytes = ReplenishBuffer();
    //   currentBufferLengthBits = currentBufferLengthBytes * 8;
    //   currentBufferIndexBits = 0;
    //   if (currentBufferLengthBits <= 0) {
    //     endOfFile = true;
    //   }
    // }
    i += 1;
    // if we've completed a character, move it into string
    // and clear the value
    if ((i % 8) == 0) {
      val.push_back(character);
      character = 0;
    }
  }

  if ((endOfFile) && (i < nBits)) {
    val.clear();
    return val;  // ran out of data before completed the value
  }  else {
    cout << "extracted " << val << endl;
    return val;
  }
}


// on error, return -1; otherwise, a positive integer will be returned
Radx::ui32 BufrFile::ExtractIt(int nBits) {

  Radx::ui32 val;
  int idx;
  unsigned char mask;
  //bool _debug = true;

  if (_debug) {
    printf(" nBits=%d\n", nBits);
  }

  if (nBits > 32) {
    // TODO: for now ... just skip it
    //return -1;
    //SkipIt(nBits);
    //return 0;
    exit(1); // TODO throw exception
  }
  val = 0;
  int i=0;
  bool endOfFile = false;
  int bitPosition;
  while ((i<nBits) && (!endOfFile)) {
    if (NextBit()) {
      // insert a 1
      val = val * 2 + 1;
    } else {
      val = val * 2;
    }
    i += 1;
  }

  if ((endOfFile) && (i < nBits)) {
    return -1;  // ran out of data before completed the value
  }  else {
    cout << "extracted " << val << endl;
    return val;
  }
}

// TODO: not working ... need to fix it
void BufrFile::SkipIt(int nBits) {
  int val;
  int idx;
  unsigned char mask;

  printf("entered non working code; exiting. \n");
  exit(1);
  /*
  int bitsNeeded;
  bitsNeeded = nBits;
  bool done = false;
  bool endOfFile = false; /// TODO: maybe this should be a class variable?? 
  while (!done && !endOfFile) {
    if (bitsNeeded+currentBufferIndex < currentBufferLength) {
      // too easy, we are done
      currentBufferIndex += bitsNeeded;
      done = true;
    } else {
      // a little more work ...
      bitsNeeded = bitsNeeded - (currentBufferLength - currentBufferIndex);
      // replenish the buffer
      currentBufferLength = ReplenishBuffer();
      currentBufferIndex = 0;
      if (currentBufferLength <= 0) {
        endOfFile = true;  // TODO: do something with this condition
      }
    }
  }
  */
}

  // val = 0;
  // int i=0;
  // bool endOfFile = false;
  // int bitPosition;
  // while ((i<nBits) && (!endOfFile)) {
  //   bitPosition = 7 - currentBufferIndex % 8;
  //   mask = 1 << bitPosition;
  //   idx = currentBufferIndex / 8;
  //   if (mask & _dataBuffer[idx]) {
  //     // insert a 1
  //     val = val * 2 + 1;
  //   } else {
  //     val = val * 2;
  //   }

  //   // advance the index
  //   currentBufferIndex += 1;
  //   if (currentBufferIndex > currentBufferIndex) {
  //     // replenish the buffer
  //     currentBufferLength = ReplenishBuffer();
  //     currentBufferIndex = 0;
  //     if (currentBufferLength <= 0) {
  //       endOfFile = true;
  //     }
  //   }
  //   i += 1;
  // }

  // if ((endOfFile) && (i < nBits)) {
  //    return -1;  // ran out of data before completed the value
  // }  else {
  // }
//}

Radx::ui32 BufrFile::NextNBitsAsInt32(int nbits) {


  string encasedBits;
  int startIndex;
  // TODO: what if the variable spans a block boundary??  Handled in NextNBitsEncased
  // if (!NextNBitsEncased(nbits, encasedBits, &startIndex)) {
  //    return -1;
  // }
  // make a variable big enough to span the buffer sections
  // if (encasedBits.size() > 4) {
  //}
  
  // move a bit mask into place

  // AND to extract the bits
  // shift right as needed
  // convert to specified data type

  // TODO:  can I make use of netCDF code? 
  return 0; 
}

Radx::ui32 BufrFile::Apply(TableMapElement f) {

  if (f._whichType != TableMapElement::TableMapElementType::DESCRIPTOR) {
    return -1;
  } 
  cout << "Applying " << endl;
  cout << "  " << f._descriptor.fieldName << " ";

  for (int i=0; i<50-f._descriptor.fieldName.size(); i++)
    cout << "-";
  cout << " " << f._descriptor.dataWidthBits << endl;
  cout << " scale  " << f._descriptor.scale << endl;
  cout << " units  " << f._descriptor.units << endl;;
  cout << " reference value " << f._descriptor.referenceValue << endl;
 
  if (f._descriptor.units.find("CCITT") != string::npos) {
    string  value;
    value = ExtractText(f._descriptor.dataWidthBits);
    cout << "extracted string = " << value << endl;
    return 0;
  } else {
    Radx::ui32 value;
    value = ExtractIt(f._descriptor.dataWidthBits);
    return value;
  }

    //return -1;
}
//
// 10^(-10) to 10^10  ==> need 21 elements
//  -3 -2 -1 0 1 2 3
double BufrFile::fastPow10(int n)
{
  static double pow10[21] = {
    .0000000001, .000000001, .00000001, .0000001, .000001,
         .00001, .0001, .001, .01, .1,
        1, 10, 100, 1000, 10000, 
    100000, 1000000, 10000000, 100000000, 1000000000,
                                         10000000000
    };

  if ((n > 10) || (n < -10))
    throw "Scale outside of bounds; must be between -10 and 10";
  else
    return pow10[n+10]; 
}

Radx::si32 BufrFile::ApplyNumeric(TableMapElement f) {

  if (f._whichType != TableMapElement::TableMapElementType::DESCRIPTOR) {
    return -1;
  } 
  cout << "Applying " << endl;
  cout << "  " << f._descriptor.fieldName << " ";

  for (int i=0; i<50-f._descriptor.fieldName.size(); i++)
    cout << "-";
  cout << " " << f._descriptor.dataWidthBits << endl;
  cout << " scale  " << f._descriptor.scale << endl;
  cout << " units  " << f._descriptor.units << endl;;
  cout << " reference value " << f._descriptor.referenceValue << endl;
 
  if (f._descriptor.units.find("CCITT") != string::npos) {
    string  value;
    value = ExtractText(f._descriptor.dataWidthBits);
    cout << "extracted string = " << value << endl;
    return 0;
  } else {
    Radx::ui32 value;
    value = ExtractIt(f._descriptor.dataWidthBits);
    Radx::si32 svalue;
    svalue = (value+f._descriptor.referenceValue)/fastPow10(f._descriptor.scale);
    cout << "converted to " << svalue << endl;
    return svalue;
  }
}

bool BufrFile::StuffIt(string fieldName, double value) {
  bool ok = true;

  std::transform(fieldName.begin(), fieldName.end(), fieldName.begin(), ::tolower);
  if (fieldName.find("latitude") != string::npos) {
    latitude = value;
  } else if (fieldName.find("longitude") != string::npos) {
    longitude = value;
  } else if (fieldName.find("height") != string::npos) {
    height = value;
  } else {
    ok = false;
  }
  return ok;
}

/*
// traverse the trees from section 3.  These are the decoders
// of the data in section 4
// need knowledge of BUFR tables, pointer to data file ( _file )
int BufrFile::TraverseOriginal(vector<unsigned short> descriptors) {



  bool _debug = true;  // TODO: make this more global

  if (_debug) 
    printf("\nTraversing ... \n");

  unsigned short des;
  try {
  // for each descriptor in the list
  while (!descriptors.empty()) {  // NOTE: the descriptor list is changing

    unsigned char f, x, y;

    des = descriptors.back();
    TableMapKey key(des);
    descriptors.pop_back();
    
    // visit the node
    if (_debug) {
      TableMapKey().Decode(des, &f, &x, &y);
      printf("visiting f(x,y): %x(%x,%x) ", f, x, y);        
    }

    if (key.isTableBEntry()) {  // a leaf
      if (_debug) 
        printf(" leaf\n");
      // if the node is from table b, retrieve the data; apply any transformations;
      //   insert into temporary structure for saving
      TableMapElement val1;
      val1 = tableMap.Retrieve(des);
      if (val1._whichType == TableMapElement::TableMapElementType::DESCRIPTOR) {
        cout << "value for key " << des << ":" <<
          val1._descriptor.fieldName << "," << 
          val1._descriptor.scale << endl;
      }
      Radx::ui32 valueFromData; 
      valueFromData = Apply(val1);
      // cout << "value from Data = " << valueFromData << endl;

    } else if (key.isReplicator()) {
	if (_debug) 
	  printf(" replicator\n");

	// if the node is a replicator, e.g. 1;2;0 or 1;3;5
	// decode the key into f(x,y) and check y for different action
        unsigned char f,x,y;
        TableMapKey().Decode(des, &f, &x, &y);
	bool variable_repeater = false;
        if (y == 0) variable_repeater = true;
      
        if (variable_repeater) {
	  // there will be a special "delayed replication", y=0
          unsigned short delayed_replication_descriptor;
          delayed_replication_descriptor = descriptors.back();
          descriptors.pop_back();
          // get the number of repeats from section 4 data
          unsigned char nrepeats; // actually read this from the data section
          Radx::ui32 valueFromData; 
          valueFromData = Apply(tableMap.Retrieve(delayed_replication_descriptor));
          cout << "nrepeats from Data = " << valueFromData << endl;
          nrepeats = (unsigned char) valueFromData; // TODO: check if value exceeds max for y values     
          if (nrepeats > 0) {
            // construct a new descriptor with the number of repeats
            unsigned short new_descriptor;
            new_descriptor = TableMapKey().EncodeKey(f, x, nrepeats);
            // push the new fixed repeater back on the stack
	    descriptors.push_back(new_descriptor);
	  } else {
	    // remove the items that would have been traversed, since there are no repeats
            for (int i=0; i<x; i++)
              descriptors.pop_back();
          }
	} else { 
          // must be a fixed repeater
          // pop the next x descriptors and apply them
	  vector<unsigned short> theNextList;
          for (int i=0; i<x; i++) {
            unsigned short embedded_des;
            embedded_des = descriptors.back();
            //TableMapKey key(des);
            descriptors.pop_back();
	    theNextList.insert(theNextList.begin(), embedded_des);
	  }
	  // if there are more repeats, decrement the count and push 
          // everything back on the stack with a decremented repeater
          // 1st attempt, use recursion
          for (int i=0; i<y; i++) {
            printf("%d out of %d repeats\n", i+1, y);
            printf("  working with list: "); 
	    for (vector<unsigned short>::iterator i = descriptors.begin(); i!= descriptors.end(); ++i)
	      cout << *i << ' ';
            TraverseOriginal(theNextList);
	  }
	}
        

    } else if (key.isAnotherNode()) {
	if (_debug) 
	  printf(" another node\n");

	// if the node is another node; recur
	// look up the expansions and insert them...
	//TableMapElement val1 = tableMap.Retrieve(des);
        TableMapElement val1;
        val1 = tableMap.Retrieve(des);
	 
      
	//descriptors.push_back();
	vector<unsigned short> theList;
	theList = val1._listOfKeys; 
	//cout << "value for key " << key << ": " << theList.size() << endl; 
	for (vector<unsigned short>::reverse_iterator i = theList.rbegin(); i!= theList.rend(); ++i)
	  descriptors.push_back(*i);
	//cout << *i << ' ';

    } else {
	if (_debug) 
	  printf(" unknown\n");
        return -1; // error occurred
    }
  }
  } catch (const std::out_of_range& e) {
    cout << "Error: unknown descriptor: " << des << endl;
    exit(1);
  }
  return 0;
}
*/

/*
// traverse the trees from section 3.  These are the decoders
// of the data in section 4
// need knowledge of BUFR tables, pointer to data file ( _file )
// returns a list of any modifications to the repeat factors
// we are going to access the global list of descriptors (_descriptorsToProcess)
int BufrFile::Traverse(int start, int length) {

  bool _debug = true;  // TODO: make this more global

  if (_debug) 
    printf("\nTraversing ... \n");

  unsigned short des;
  int pos, len;
  pos = start;
  len = length;
  try {
  // for each descriptor in the list
    while (!_descriptorsToProcess.empty() ) {  // NOTE: the descriptor list is changing

    unsigned char f, x, y;

    des = _descriptorsToProcess.at(pos); // descriptors.back();
    TableMapKey key(des);

    
    // visit the node
    if (_debug) {
      TableMapKey().Decode(des, &f, &x, &y);
      printf("visiting f(x,y): %x(%x,%x) ", f, x, y);        
    }

    if (key.isTableBEntry()) {  // a leaf
      if (_debug) 
        printf(" leaf\n");
      // if the node is from table b, retrieve the data; apply any transformations;
      //   insert into temporary structure for saving
      TableMapElement val1;
      val1 = tableMap.Retrieve(des);
      if (val1._whichType == TableMapElement::TableMapElementType::DESCRIPTOR) {
        cout << "value for key " << des << ":" <<
          val1._descriptor.fieldName << "," << 
          val1._descriptor.scale << endl;
      }
      Radx::ui32 valueFromData; 
      valueFromData = Apply(val1);
      // cout << "value from Data = " << valueFromData << endl;
      pos += 1;

    } else if (key.isReplicator()) {
	if (_debug) 
	  printf(" replicator\n");

	// if the node is a replicator, e.g. 1;2;0 or 1;3;5
	// decode the key into f(x,y) and check y for different action
        unsigned char f,x,y;
        TableMapKey().Decode(des, &f, &x, &y);
	bool variable_repeater = false;
        if (y == 0) variable_repeater = true;
      
        if (variable_repeater) {
	  // there will be a special "delayed replication", y=0
          unsigned short delayed_replication_descriptor;
          delayed_replication_descriptor = _descriptorsToProcess.back();
          _descriptorsToProcess.pop_back();
          // get the number of repeats from section 4 data
          unsigned char nrepeats; // actually read this from the data section
          Radx::ui32 valueFromData; 
          valueFromData = Apply(tableMap.Retrieve(delayed_replication_descriptor));
          cout << "nrepeats from Data = " << valueFromData << endl;
          nrepeats = (unsigned char) valueFromData; // TODO: check if value exceeds max for y values     
          if (nrepeats > 0) {
            // construct a new descriptor with the number of repeats
            unsigned short new_descriptor;
            new_descriptor = TableMapKey().EncodeKey(f, x, nrepeats);
            // push the new fixed repeater back on the stack
	    _descriptorsToProcess.push_back(new_descriptor);
	  } else {
	    // remove the items that would have been traversed, since there are no repeats
            for (int i=0; i<x; i++)
              _descriptorsToProcess.pop_back();
          }
	} else { 
          // must be a fixed repeater
          // pop the next x descriptors and apply them -- NOPE!
          // just record the length and setup a loop the start and end point
	  //vector<unsigned short> theNextList;
          //for (int i=0; i<x; i++) {
          //  unsigned short embedded_des;
          //  embedded_des = _descriptorsToProcess.back();
          //  //TableMapKey key(des);
          //  //descriptors.pop_back();
	  //  //theNextList.insert(theNextList.begin(), embedded_des);
	  //}
	  // if there are more repeats, decrement the count and push 
          // everything back on the stack with a decremented repeater
          // 1st attempt, use recursion

          //vector<unsigned short> anyMods;
          //printf("1 out of %d repeats\n", y);
          //anyMods = Traverse(start, length); // theNextList);
          for (int i=0; i<y; i++) {
            printf("%d out of %d repeats\n", i+1, y);
            //printf("  anyMods: "); 
	    //for (vector<unsigned short>::iterator i = anyMods.begin(); i!= anyMods.end(); ++i)
	    //  cout << *i << ' ';
            Traverse(pos, x); // (anyMods);
	  }
	}
        

    } else if (key.isAnotherNode()) {
	if (_debug) 
	  printf(" another node\n");
	// pop/remove the element from the list; it is being replaced
        //_descriptorsToProcess.pop_back();
	// if the node is another node,
	// look up the expansions and insert them...
	//TableMapElement val1 = tableMap.Retrieve(des);
        TableMapElement val1;
        val1 = tableMap.Retrieve(des);
	 
      
	//descriptors.push_back();
	vector<unsigned short> theList;
	theList = val1._listOfKeys;
        int nProcessed;
        nProcessed = pos - start; 
        // insert after the pos
        _descriptorsToProcess.insert(pos+1, theList);
        // now, remove the node that was expanded
        _descriptorsToProcess.erase(pos);
	len += theList.size() - 1;
        pos = start + nProcessed;
	//cout << "value for key " << key << ": " << theList.size() << endl; 
	//for (vector<unsigned short>::reverse_iterator i = theList.rbegin(); i!= theList.rend(); ++i)
	// _descriptorsToProcess.push_back(*i);
	//cout << *i << ' ';

    } else {
	if (_debug) 
	  printf(" ERROR!!! unknown\n");  // TODO: this should be an exception thrown
        return -1; // error occurred
    }
  }
  } catch (const std::out_of_range& e) {
    cout << "Error: unknown descriptor: " << des << endl;
    exit(1);
  }
  return 0;
}
*/



void BufrFile::_deleteAfter(DNode *p) {
  DNode *q;
  if (p!=NULL) {
    q = p->next;
    p->next = q->next;
    free(q);
  }
}

//  Node *      _buildTree(vector<unsigned short> descriptors);
BufrFile::DNode* BufrFile::buildTree(vector<unsigned short> descriptors, bool reverse) {
  DNode *t;
  t = NULL;
  if (reverse) {
  for (vector<unsigned short>::reverse_iterator i = descriptors.rbegin(); i!= descriptors.rend(); ++i) {
    DNode *p = (DNode *) malloc(sizeof(DNode));
    p->des = *i;
    //p->nRepeats = 0;
    unsigned short new_descriptor;
    new_descriptor = TableMapKey().EncodeKey(0, 0, 0);
    p->delayed_repeater = new_descriptor;
    p->children = NULL;
    p->next = t;
    t = p;
  }
  } else {
  for (vector<unsigned short>::iterator i = descriptors.begin(); i!= descriptors.end(); ++i) {
    DNode *p = (DNode *) malloc(sizeof(DNode));
    p->des = *i;
    unsigned short new_descriptor;
    new_descriptor = TableMapKey().EncodeKey(0, 0, 0);
    p->delayed_repeater = new_descriptor;
    p->children = NULL;
    p->next = t;
    t = p;
  }
  }
  return t;
}

void BufrFile::printTree(DNode *tree, int level) {
  DNode *p,*q;
  p = tree;
  if (level == 0) printf("tree: \n");
  while (p!=NULL) {
    for (int i=0; i<level; i++) printf(" ");
    printf("+(%d) delayed_rep %d\n", p->des, p->delayed_repeater);
    q=p->children;
    if (q != NULL) {
      printTree(q, level+1);
    }
    p=p->next;
  }
}

// traverse the trees from section 3.  These are the decoders
// of the data in section 4
// need knowledge of BUFR tables, pointer to data file ( _file )
// returns a list of any modifications to the repeat factors
// we are going to access the global list of descriptors (_descriptorsToProcess)
int BufrFile::TraverseNew(vector<unsigned short> descriptors) {

  GTree = buildTree(descriptors, false);

  int result =   _descend(GTree);
  return result;
}

int BufrFile::_descend(DNode *tree) {

  //bool _debug = true;  // TODO: make this more global

  if (_debug) { 
    printf("\nTraversing ... \n");
    printTree(tree,0);
  }

  unsigned short des;
  DNode *p;
  p = tree;

  try {
  // for each descriptor in the list
    while (p != NULL ) {

    unsigned char f, x, y;

    des = p->des;
    TableMapKey key(des);

    // visit the node
    if (_debug) {
      TableMapKey().Decode(des, &f, &x, &y);
      printf("visiting f(x,y): %x(%x,%x) ", f, x, y);        
    }

    if (key.isTableBEntry()) {  // a leaf
      if (_debug) 
        printf(" leaf\n");
      // if the node is from table b, retrieve the data; apply any transformations;
      //   insert into temporary structure for saving
      TableMapElement val1;
      val1 = tableMap.Retrieve(des);
      if (val1._whichType == TableMapElement::TableMapElementType::DESCRIPTOR) {
        cout << "value for key " << des << ":" <<
          val1._descriptor.fieldName << "," << 
          val1._descriptor.scale << endl;
      }
      Radx::si32 valueFromData;
      if (val1.IsText()) {
	Radx::ui32 junk;
        junk = Apply(val1); // TODO: integrate a string type here  
      } else {
        valueFromData = ApplyNumeric(val1);
        if (!StuffIt(val1._descriptor.fieldName, valueFromData)) {
          // throw "Cannot associate value with BufrField";
          cout << "Cannot associate value with BufrField\n";
	}
      }
      // cout << "value from Data = " << valueFromData << endl;
      p = p->next;

    } else if (key.isReplicator()) {
	if (_debug) 
	  printf(" replicator\n");

	// if the node is a replicator, e.g. 1;2;0 or 1;3;5
	// decode the key into f(x,y) and check y for different action
        unsigned char f,x,y;
        TableMapKey().Decode(des, &f, &x, &y);
	bool variable_repeater = false;
        if (y == 0) variable_repeater = true;
      
        if (variable_repeater) {
	  // there will be a special "delayed replication", y=0
          unsigned short delayed_replication_descriptor;
          if (p->children == NULL) { // if we haven't been here before ...
            DNode *delayed_rep_node;
            delayed_rep_node = p->next;
            delayed_replication_descriptor = delayed_rep_node->des;
            // remove the delayed replication descriptor node from the list
            _deleteAfter(p);   
            // and save it in the node itself
            p->delayed_repeater = delayed_replication_descriptor;
          } else {
            delayed_replication_descriptor = p->delayed_repeater;
	  }
          // get the number of repeats from section 4 data
	  Radx::ui32 nRepeats; // actually read this from the data section
          nRepeats = Apply(tableMap.Retrieve(delayed_replication_descriptor));
          printf("nrepeats from Data = %u\n", nRepeats);

	  //------------------ begin paste ---
          // move the children if they aren't already there
          if (p->children == NULL) {
            // remove the next x descriptors and make them children
            DNode *h, *t;
            h = p->next;
            t = h->next;
            int i = 1;
            while ((t!= NULL) && (i<x)) {
              h = t;
              t = t->next;
              i += 1;
            }
            p->children = p->next;
            // reconnect the list
            p->next = t;
	    h->next = NULL;
	  }  // end moving children
          for (int i=0; i<nRepeats; i++) {
            printf("%d out of %d repeats\n", i+1, nRepeats);
            _descend(p->children);
	  }
          printf("-- end repeat\n");
          p=p->next;
	  //--------------------- end paste -----
	} else {           // must be a fixed repeater
          // move the children if they aren't already there
          if (p->children == NULL) {
            // remove the next x descriptors and make them children
            DNode *h, *t;
            h = p->next;
            t = h->next;
            int i = 1;
            while ((t!= NULL) && (i<x)) {
              h = t;
              t = t->next;
              i += 1;
            }
            p->children = p->next;
            // reconnect the list
            p->next = t;
	    h->next = NULL;
	  }  // end moving children
	  //Radx::ui32 y32;
          //y32 = y;
          //if (p->nRepeats > 0) {
          //  y32 = p->nRepeats;  // because some repeats are larger than 8 bits
	  //}
          for (int i=0; i<y; i++) {
            printf("%d out of %d repeats\n", i+1, y);
            _descend(p->children);
	  }
          printf("-- end repeat\n");
          p=p->next;
	} // end else fixed repeater
        printTree(tree, 0);
    } else if (key.isAnotherNode()) {
	if (_debug) 
	  printf(" another node\n");
	// pop/remove the element from the list; it is being replaced
	// if the node is another node,
	// look up the expansions and insert them...
	//TableMapElement val1 = tableMap.Retrieve(des);
        TableMapElement val1;
        val1 = tableMap.Retrieve(des);
	 
	vector<unsigned short> theList;
	theList = val1._listOfKeys;

        // replace the contents of this node with the first element of the list
        p->des = theList.front();  // TODO: this could be the wrong order
        // insert the remaining elements after this node

        theList.erase(theList.begin());
	if (theList.size() > 0) {
	  DNode *newList = buildTree(theList, true);
          DNode *save;
          save = p->next;
          p->next = newList;
  	  // find the end of the new list;
          DNode *h, *t;
          h = newList;
          t = newList->next;
          while (t != NULL) {
            h = t;
            t = t->next;
          }
          h->next = save;
	}
        printTree(tree, 0);
    } else {
	if (_debug) 
	  printf(" ERROR!!! unknown\n");  // TODO: this should be an exception thrown
        return -1; // error occurred
    }
  }
  } catch (const std::out_of_range& e) {
    cout << "Error: unknown descriptor: " << des << endl;
    exit(1);
  }
  return 0;
}


/*

int BufrFile::_descend(DNode *tree) {

  bool _debug = true;  // TODO: make this more global

  if (_debug) { 
    printf("\nTraversing ... \n");
    printTree(tree,0);
  }

  unsigned short des;
  DNode *p;
  p = tree;

  try {
  // for each descriptor in the list
    while (p != NULL ) {

    unsigned char f, x, y;

    des = p->des;
    TableMapKey key(des);

    // visit the node
    if (_debug) {
      TableMapKey().Decode(des, &f, &x, &y);
      printf("visiting f(x,y): %x(%x,%x) ", f, x, y);        
    }

    if (key.isTableBEntry()) {  // a leaf
      if (_debug) 
        printf(" leaf\n");
      // if the node is from table b, retrieve the data; apply any transformations;
      //   insert into temporary structure for saving
      TableMapElement val1;
      val1 = tableMap.Retrieve(des);
      if (val1._whichType == TableMapElement::TableMapElementType::DESCRIPTOR) {
        cout << "value for key " << des << ":" <<
          val1._descriptor.fieldName << "," << 
          val1._descriptor.scale << endl;
      }
      Radx::ui32 valueFromData; 
      valueFromData = Apply(val1);
      // cout << "value from Data = " << valueFromData << endl;
      p = p->next;

    } else if (key.isReplicator()) {
	if (_debug) 
	  printf(" replicator\n");

	// if the node is a replicator, e.g. 1;2;0 or 1;3;5
	// decode the key into f(x,y) and check y for different action
        unsigned char f,x,y;
        TableMapKey().Decode(des, &f, &x, &y);
	bool variable_repeater = false;
        if (y == 0) variable_repeater = true;
      
        if (variable_repeater) {
	  // there will be a special "delayed replication", y=0
          unsigned short delayed_replication_descriptor;
          DNode *delayed_rep_node;
          delayed_rep_node = p->next;
          delayed_replication_descriptor = delayed_rep_node->des;
          // get the number of repeats from section 4 data
          unsigned char nrepeats; // actually read this from the data section
          Radx::ui32 valueFromData; 
          valueFromData = Apply(tableMap.Retrieve(delayed_replication_descriptor));
          printf("nrepeats from Data = %u\n", valueFromData);
	  //>>>>> bad conversion!!!      
          nrepeats = (unsigned char) valueFromData; // TODO: check if value exceeds max for y values
          p->nRepeats = valueFromData; 
          // replace the contents of the replicator node with the number of repeats
          // construct a new descriptor with the number of repeats
          unsigned short new_descriptor;
          new_descriptor = TableMapKey().EncodeKey(f, x, nrepeats);
	  p->des = new_descriptor;
          // remove the delayed replication descriptor node from the list
          _deleteAfter(p);    
	} else {           // must be a fixed repeater
          // move the children if they aren't already there
          if (p->children == NULL) {
            // remove the next x descriptors and make them children
            DNode *h, *t;
            h = p->next;
            t = h->next;
            int i = 1;
            while ((t!= NULL) && (i<x)) {
              h = t;
              t = t->next;
              i += 1;
            }
            p->children = p->next;
            // reconnect the list
            p->next = t;
	    h->next = NULL;
	  }  // end moving children
	  Radx::ui32 y32;
          y32 = y;
          if (p->nRepeats > 0) {
            y32 = p->nRepeats;  // because some repeats are larger than 8 bits
	  }
          for (int i=0; i<y32; i++) {
            printf("%d out of %d repeats\n", i+1, y32);
            _descend(p->children);
	  }
          printf("-- end repeat\n");
          p=p->next;
	} // end else fixed repeater
        printTree(tree, 0);
    } else if (key.isAnotherNode()) {
	if (_debug) 
	  printf(" another node\n");
	// pop/remove the element from the list; it is being replaced
	// if the node is another node,
	// look up the expansions and insert them...
	//TableMapElement val1 = tableMap.Retrieve(des);
        TableMapElement val1;
        val1 = tableMap.Retrieve(des);
	 
	vector<unsigned short> theList;
	theList = val1._listOfKeys;

        // replace the contents of this node with the first element of the list
        p->des = theList.front();  // TODO: this could be the wrong order
        // insert the remaining elements after this node

        theList.erase(theList.begin());
	if (theList.size() > 0) {
	  DNode *newList = buildTree(theList, true);
          DNode *save;
          save = p->next;
          p->next = newList;
  	  // find the end of the new list;
          DNode *h, *t;
          h = newList;
          t = newList->next;
          while (t != NULL) {
            h = t;
            t = t->next;
          }
          h->next = save;
	}
        printTree(tree, 0);
    } else {
	if (_debug) 
	  printf(" ERROR!!! unknown\n");  // TODO: this should be an exception thrown
        return -1; // error occurred
    }
  }
  } catch (const std::out_of_range& e) {
    cout << "Error: unknown descriptor: " << des << endl;
    exit(1);
  }
  return 0;
}

*/

/////////////////////////////////////
// Print contents of Bufr file read
// Returns 0 on success, -1 on failure
int BufrFile::Print() {

  return 0;
}
/*


/////////////////////////////////////
// read int variable, set var and val
// Returns 0 on success, -1 on failure

int BufrFile::readIntVar(Nc3Var* &var, const string &name,
                         int &val, int missingVal, bool required)
  
{
  
  var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (!required) {
      val = missingVal;
      return 0;
    } else {
      _addErrStr("ERROR - BufrFile::readIntVar");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr("  file: ", _pathInUse);
      _addErrStr(_err->get_errmsg());
      return -1;
    }
  }

  // check size
  
  if (var->num_vals() < 1) {
    _addErrStr("ERROR - BufrFile::readIntVar");
    _addErrStr("  variable name: ", name);
    _addErrStr("  variable has no data");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  val = var->as_int(0);
  
  return 0;
  
}

///////////////////////////////////
// read int variable, set val

int BufrFile::readIntVal(const string &name, 
                         int &val, int missingVal,
                         bool required)
  
{
  
  val = missingVal;

  Nc3Var*var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (required) {
      _addErrStr("ERROR - BufrFile::_readIntVal");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr("  file: ", _pathInUse);
      _addErrStr(_err->get_errmsg());
    }
    return -1;
  }
  
  // check size
  
  if (var->num_vals() < 1) {
    if (required) {
      _addErrStr("ERROR - BufrFile::_readIntVal");
      _addErrStr("  variable name: ", name);
      _addErrStr("  variable has no data");
      _addErrStr("  file: ", _pathInUse);
    }
    return -1;
  }

  val = var->as_int(0);
  
  return 0;
  
}

///////////////////////////////////
// read float variable
// Returns 0 on success, -1 on failure

int BufrFile::readFloatVar(Nc3Var* &var, const string &name,
                           float &val, 
                           float missingVal, bool required)

{
  
  var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (!required) {
      val = missingVal;
      return 0;
    } else {
      _addErrStr("ERROR - BufrFile::readFloatVar");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr("  file: ", _pathInUse);
      _addErrStr(_err->get_errmsg());
      return -1;
    }
  }

  // check size
  
  if (var->num_vals() < 1) {
    _addErrStr("ERROR - BufrFile::readFloatVar");
    _addErrStr("  variable name: ", name);
    _addErrStr("  variable has no data");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  val = var->as_float(0);
  
  return 0;
  
}

///////////////////////////////////
// read float value

int BufrFile::readFloatVal(const string &name,
                           float &val,
                           float missingVal,
                           bool required)
  
{
  
  val = missingVal;
  
  Nc3Var* var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (required) {
      _addErrStr("ERROR - BufrFile::readFloatVal");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr(_err->get_errmsg());
    }
    return -1;
  }
  
  // check size
  
  if (var->num_vals() < 1) {
    if (required) {
      _addErrStr("ERROR - BufrFile::readFloatVal");
      _addErrStr("  variable name: ", name);
      _addErrStr("  variable has no data");
    }
    return -1;
  }

  val = var->as_float(0);
  
  return 0;
  
}

///////////////////////////////////
// read double variable
// Returns 0 on success, -1 on failure

int BufrFile::readDoubleVar(Nc3Var* &var, const string &name,
                            double &val, 
                            double missingVal, bool required)
  
{
  
  var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (!required) {
      val = missingVal;
      return 0;
    } else {
      _addErrStr("ERROR - BufrFile::readDoubleVar");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr("  file: ", _pathInUse);
      _addErrStr(_err->get_errmsg());
      return -1;
    }
  }

  // check size
  
  if (var->num_vals() < 1) {
    _addErrStr("ERROR - BufrFile::readDoubleVar");
    _addErrStr("  variable name: ", name);
    _addErrStr("  variable has no data");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  val = var->as_double(0);
  
  return 0;
  
}
*/
/*
///////////////////////////////////
// read double value

int BufrFile::readDoubleVal(const string &name,
                            double &val,
                            double missingVal,
                            bool required)

{
  
  val = missingVal;

  Nc3Var* var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    if (required) {
      _addErrStr("ERROR - BufrFile::readDoubleVal");
      _addErrStr("  Cannot read variable, name: ", name);
      _addErrStr(_err->get_errmsg());
    }
    return -1;
  }

  // check size
  
  if (var->num_vals() < 1) {
    if (required) {
      _addErrStr("ERROR - BufrFile::readDoubleVal");
      _addErrStr("  variable name: ", name);
      _addErrStr("  variable has no data");
    }
    return -1;
  }

  val = var->as_double(0);
  
  return 0;
  
}

///////////////////////////////////
// read a scalar string variable
// Returns 0 on success, -1 on failure

int BufrFile::readStringVar(Nc3Var* &var, const string &name, string &val)

{

  // get var
  
  var = _ncFile->get_var(name.c_str());
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::readStringVar");
    _addErrStr("  Cannot read variable, name: ", name);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }

  // check dimension
  
  if (var->num_dims() != 1) {
    _addErrStr("ERROR - BufrFile::readStringVar");
    _addErrStr("  variable name: ", name);
    _addErrStr("  variable does not have 1 dimension");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  Nc3Dim *stringLenDim = var->get_dim(0);
  if (stringLenDim == NULL) {
    _addErrStr("ERROR - BufrFile::readStringVar");
    _addErrStr("  variable name: ", name);
    _addErrStr("  variable has NULL 0th dimension");
    _addErrStr("  should be a string length dimension");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  Nc3Type ntype = var->type();
  if (ntype != nc3Char) {
    _addErrStr("ERROR - BufrFile::readStringVar");
    _addErrStr("  Incorrect variable type");
    _addErrStr("  expecting char");
    _addErrStr("  found: ", ncTypeToStr(ntype));
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  // load up data

  int stringLen = stringLenDim->size();
  char *cvalues = new char[stringLen+1];
  if (var->get(cvalues, stringLen)) {
    // ensure null termination
    cvalues[stringLen] = '\0';
    val = cvalues;
  } else {
    _addErrStr("ERROR - BufrFile::readStringVar");
    _addErrStr("  Cannot read variable: ", name);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }
  delete[] cvalues;

  return 0;

}


///////////////////////////////////////////////////////////////////////////
// write a scalar double variable
// Returns 0 on success, -1 on failure

int BufrFile::writeVar(Nc3Var *var, double val)
  
{
  
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var is NULL");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (var->type() != nc3Double) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var type should be double, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (!var->put(&val, 1)) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  Cannot write scalar double var, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  } else {
    return 0;
  }

}

///////////////////////////////////////////////////////////////////////////
// write a scalar float variable
// Returns 0 on success, -1 on failure

int BufrFile::writeVar(Nc3Var *var, float val)
  
{
  
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var is NULL");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (var->type() != nc3Float) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var type should be float, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (!var->put(&val, 1)) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  Cannot write scalar float var, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  } else {
    return 0;
  }

}

///////////////////////////////////////////////////////////////////////////
// write a scalar int variable
// Returns 0 on success, -1 on failure

int BufrFile::writeVar(Nc3Var *var, int val)
  
{
  
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var is NULL");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (var->type() != nc3Int) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  var type should be int, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  if (!var->put(&val, 1)) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  Cannot write scalar int var, name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  } else {
    return 0;
  }

}

///////////////////////////////////////////////////////////////////////////
// write a 1-D vector variable
// number of elements specified in dimension
// Returns 0 on success, -1 on failure

int BufrFile::writeVar(Nc3Var *var, const Nc3Dim *dim, const void *data)
  
{
  return writeVar(var, dim, dim->size(), data);
}

///////////////////////////////////////////////////////////////////////////
// write a 1-D vector variable
// number of elements specified in arguments
// Returns 0 on success, -1 on failure

int BufrFile::writeVar(Nc3Var *var, 
                       const Nc3Dim *dim, size_t count, 
                       const void *data)
  
{
  
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::_writeVar");
    _addErrStr("  var is NULL");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  int iret = 0;
  
  switch (var->type()) {
    case nc3Double: {
      iret = !var->put((double *) data, count);
      break;
    }
    case nc3Float:
    default: {
      iret = !var->put((float *) data, count);
      break;
    }
    case nc3Int: {
      iret = !var->put((int *) data, count);
      break;
    }
    case nc3Short: {
      iret = !var->put((short *) data, count);
      break;
    }
    case nc3Byte: {
      iret = !var->put((ncbyte *) data, count);
      break;
    }
  } // switch

  if (iret) {
    _addErrStr("ERROR - BufrFile::writeVar");
    _addErrStr("  Cannot write var, name: ", var->name());
    _addErrStr("  Dim name: ", dim->name());
    _addErrInt("  Count: ", count);
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  } else {
    return 0;
  }

}


///////////////////////////////////////////////////////////////////////////
// write a string variable
// Returns 0 on success, -1 on failure

int BufrFile::writeStringVar(Nc3Var *var, const void *str)
  
{
  
  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::writeStringVar");
    _addErrStr("  var is NULL");
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }
  
  int nDims = var->num_dims();
  if (nDims < 1) {
    _addErrStr("ERROR - BufrFile::writeStringVar");
    _addErrStr("  var has no dimensions");
    _addErrStr("  var name: ", var->name());
    _addErrStr("  file: ", _pathInUse);
    return -1;
  }

  if (nDims == 1) {

    // single dimension

    Nc3Dim *dim0 = var->get_dim(0);
    if (dim0 == NULL) {
      _addErrStr("ERROR - BufrFile::writeStringVar");
      _addErrStr("  Cannot write var, name: ", var->name());
      _addErrStr("  dim 0 is NULL");
      _addErrStr("  file: ", _pathInUse);
      return -1;
    }

    int iret = !var->put((char *) str, dim0->size());
  
    if (iret) {
      _addErrStr("ERROR - BufrFile::writeStringVar");
      _addErrStr("  Cannot write var, name: ", var->name());
      _addErrStr(_err->get_errmsg());
      _addErrStr("  file: ", _pathInUse);
      return -1;
    } else {
      return 0;
    }

  }

  if (nDims == 2) {

    // two dimensions

    Nc3Dim *dim0 = var->get_dim(0);
    if (dim0 == NULL) {
      _addErrStr("ERROR - BufrFile::writeStringVar");
      _addErrStr("  Cannot write var, name: ", var->name());
      _addErrStr("  dim 0 is NULL");
      _addErrStr("  file: ", _pathInUse);
      return -1;
    }

    Nc3Dim *dim1 = var->get_dim(1);
    if (dim1 == NULL) {
      _addErrStr("ERROR - BufrFile::writeStringVar");
      _addErrStr("  Cannot write var, name: ", var->name());
      _addErrStr("  dim 1 is NULL");
      _addErrStr("  file: ", _pathInUse);
      return -1;
    }

    int iret = !var->put((char *) str, dim0->size(), dim1->size());
    
    if (iret) {
      _addErrStr("ERROR - BufrFile::writeStringVar");
      _addErrStr("  Cannot write var, name: ", var->name());
      _addErrInt("                    type: ", var->type());
      _addErrInt("                    is_valid: ", var->is_valid());
      _addErrStr("  file: ", _pathInUse);
      _addErrStr(_err->get_errmsg());
      return -1;
    } else {
      return 0;
    }

  }

  // more than 2 is an error
  
  _addErrStr("ERROR - BufrFile::writeStringVar");
  _addErrStr("  Cannot write var, name: ", var->name());
  _addErrInt("  more than 2 dimensions: ", nDims);
  _addErrStr("  file: ", _pathInUse);
  return -1;

}

///////////////////////////////////////////////////////////////////////////
// compress a variable

int BufrFile::compressVar(Nc3Var *var, int compressionLevel)
{
  
  if (_ncFormat == Nc3File::Netcdf4Classic ||
      _ncFormat == Nc3File::Offset64Bits) {
    // cannot compress
    return 0;
  }

  if (var == NULL) {
    _addErrStr("ERROR - BufrFile::setVarCompression");
    _addErrStr("  var is NULL");
    return -1;
  }
  
  int fileId = _ncFile->id();
  int varId = var->id();
  int shuffle = 0;
  
  if (nc_def_var_deflate(fileId, varId, shuffle,
                         true, compressionLevel)!= NC_NOERR) {
    _addErrStr("ERROR: FieldData::setCompression");
    _addErrStr("  Problem setting compression for var: ",
               var->name());
    _addErrStr("  file: ", _pathInUse);
    _addErrStr(_err->get_errmsg());
    return -1;
  }

  return 0;

}

////////////////////////////////////////
// convert type enum to strings

string BufrFile::ncTypeToStr(Nc3Type nctype)
  
{
  
  switch (nctype) {
    case nc3Double:
      return "nc3Double";
    case nc3Float:
      return "nc3Float";
    case nc3Int:
      return "nc3Int";
    case nc3Short:
      return "nc3Short";
    case nc3Byte:
    default:
      return "nc3Byte";
  }
  
}
*/

