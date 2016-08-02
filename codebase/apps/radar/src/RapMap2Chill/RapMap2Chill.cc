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
///////////////////////////////////////////////////////////////
// RapMap2Chill.cc
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 2007
//
///////////////////////////////////////////////////////////////
//
// RapMap2Chill converts NCAR/RAP maps to CHILL format
//
////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <toolsa/toolsa_macros.h>
#include <toolsa/file_io.h>
#include <toolsa/TaFile.hh>

#include "RapMap2Chill.hh"
#include "Map.hh"

using namespace std;

// Constructor

RapMap2Chill::RapMap2Chill(int argc, char **argv)
  
{

  isOK = true;

  // set programe name
  
  _progName = "RapMap2Chill";

  // get command line args

  if (_args.parse(argc, argv, _progName)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with command line args" << endl;
    isOK = false;
    return;
  }

  // get TDRP params
  
  _paramsPath = (char *) "unknown";
  if (_params.loadFromArgs(argc, argv, _args.override.list,
			   &_paramsPath)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with TDRP parameters" << endl;
    isOK = false;
    return;
  }

  // check params

  if (_args.inputFileList.size() < 1) {
    cerr << "ERROR - you must specify rap map files using -f" << endl;
    isOK = false;
  }
  
  return;
  
}

// destructor

RapMap2Chill::~RapMap2Chill()
  
{

  if (_params.debug) {
    cerr << "RapMap2Chill done ..." << endl;
  }

}

//////////////////////////////////////////////////
// Run

int RapMap2Chill::Run ()
{
  
  int iret = 0;
  
  for (int ii = 0; ii < (int) _args.inputFileList.size(); ii++) {
    
    const char *filePath = _args.inputFileList[ii].c_str();
    
    if (_processFile(filePath)) {
      iret = -1;
    }
    
  } // ii

  return iret;
  
}

//////////////////////////////////////////////////
// process a file
//
// Returns 0 on success, -1 on failure

int RapMap2Chill::_processFile(const char* filePath)

{
  
  if (_params.debug) {
    cerr << "Processing file: " << filePath << endl;
  }

  Map map(_params);
  if (map.readFile(filePath)) {
    cerr << "ERROR - RapMap2Chill::_processFile" << endl;
    cerr << "  Cannot read file: " << filePath << endl;
    return -1;
  }

  if (_params.debug >= Params::DEBUG_VERBOSE) {
    map.print(cerr);
  }

  if (_params.mode == Params::GTK_DISPLAY_MODE) {
    map.translate2GtkDisplay();
  }
  
  return 0;

}

