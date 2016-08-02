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
//
// main driver for ChillSdb2Dsr
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// May 2009
//
///////////////////////////////////////////////////////////////
//
// ChillSdb2Dsr reads CHILL moments from the SDB server,
// reformats it into DsRadar format and writes to a DsRadar FMQ
//
// Also optionally computes calibration from SDB packets, and
// writes calibration XML files to a specified directory.
//
////////////////////////////////////////////////////////////////

#include "ChillSdb2Dsr.hh"
#include <csignal>
#include <new>
#include <cstdio>
using namespace std;

// file scope

static void tidy_and_exit(int sig);
static void out_of_store();
static ChillSdb2Dsr *_prog;

// main

int main(int argc, char **argv)
  
{

  // create program object

  _prog = new ChillSdb2Dsr(argc, argv);
  if (!_prog->isOK) {
    return(-1);
  }

  // set signal handling
  
  signal(SIGINT, tidy_and_exit);
  signal(SIGHUP, tidy_and_exit);
  signal(SIGTERM, tidy_and_exit);
  signal(SIGPIPE, SIG_IGN);

  // set new() memory failure handler function

  set_new_handler(out_of_store);

  // run it

  int iret = _prog->Run();

  // clean up

  tidy_and_exit(iret);
  return (iret);
  
}

///////////////////
// tidy up on exit

static void tidy_and_exit (int sig)

{

  delete(_prog);
  exit(sig);

}
////////////////////////////////////
// out_of_store()
//
// Handle out-of-memory conditions
//

static void out_of_store()

{

  fprintf(stderr, "FATAL ERROR - program ChillSdb2Dsr\n");
  fprintf(stderr, "  Operator new failed - out of store\n");
  exit(-1);

}
