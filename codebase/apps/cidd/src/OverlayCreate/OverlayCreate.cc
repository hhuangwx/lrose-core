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
// OverlayCreate.cc
//
// OverlayCreate object
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// April 1998
//
///////////////////////////////////////////////////////////////
//
// OverlayCreate creates overlays for displays, writes them in
// ASCII to stdout.
//
///////////////////////////////////////////////////////////////

#include "OverlayCreate.h"
#include "Circle.h"
#include <toolsa/str.h>
using namespace std;

// Constructor

OverlayCreate::OverlayCreate(int argc, char **argv)

{

  OK = TRUE;
  Done = FALSE;

  // set programe name

  _progName = STRdup("OverlayCreate");
  ucopyright(_progName);

  // get command line args

  _args = new Args(argc, argv, _progName);
  if (!_args->OK) {
    fprintf(stderr, "ERROR: %s\n", _progName);
    fprintf(stderr, "Problem with command line args\n");
    OK = FALSE;
    return;
  }
  if (_args->Done) {
    Done = TRUE;
    return;
  }

  // get TDRP params

  _Params = new Params(_args->paramsFilePath,
		       &_args->override,
		       _progName,
		       _args->checkParams,
		       _args->printParams,
		       _args->printShort);
  
  if (!_Params->OK) {
    fprintf(stderr, "ERROR: %s\n", _progName);
    fprintf(stderr, "Problem with TDRP parameters\n");
    OK = FALSE;
    return;
  }
  if (_Params->Done) {
    Done = TRUE;
    return;
  }
  _params = &_Params->p;

  if (!OK) {
    return;
  }

  return;

}

// destructor

OverlayCreate::~OverlayCreate()

{

  // free up

  delete(_params);
  delete(_args);
  STRfree(_progName);

}

//////////////////////////////////////////////////
// Run

int OverlayCreate::Run ()
{

  Circle *circ = new Circle(_progName,
			    _params,
			    _params->circle_lat,
			    _params->circle_lon,
			    _params->circle_radius,
			    _params->circle_npoints);

  circ->compute();
  circ->write();
  delete (circ);

  return (0);

}

