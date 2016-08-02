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
// SpectraScope.hh
//
// SpectraScope object
//
// Mike Dixon, RAP, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Oct 2008
//
///////////////////////////////////////////////////////////////
//
// Displays radar spectra stored in SPDB
//
///////////////////////////////////////////////////////////////

#ifndef SpectraScope_H
#define SpectraScope_H

#include <string>
#include <rapformats/coord_export.h>
#include <Fmq/DsFmq.hh>
#include "Args.hh"
#include "Params.hh"

////////////////////////
// This class

class SpectraScope {
  
public:

  // constructor

  SpectraScope (int argc, char **argv);

  // destructor
  
  ~SpectraScope();

  // run 

  int Run();

  // data members

  bool isOK;

protected:
  
private:

  int _argc;
  char **_argv;
  string _progName;
  char *_paramsPath;
  Args _args;
  Params _params;
  coord_export_t *_coordShmem;
  DsFmq _inputFmq;

};

///////////////////////////////////////
// extern prototypes to non-object code

#include <xview/notify.h>
using namespace std;
#ifdef MIN
#undef MIN
#endif
#ifdef MAX
#undef MAX
#endif

extern int strip_chart_main(int argc, char **argv, Params *params,
			    coord_export_t *coord_shmem,
			    DsFmq &input_fmq);

extern  void strip_chart_free();

extern int stag_chart_main(int argc, char **argv, Params *params,
                           coord_export_t *coord_shmem,
                           DsFmq &input_fmq);

extern  void stag_chart_free();

#endif

