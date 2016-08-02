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
// WafsTiled2Mdv.hh
//
// WafsTiled2Mdv object
//
// Mike Dixon, RAP, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// June 2004
//
///////////////////////////////////////////////////////////////
//
// WafsTiled2Mdv reads in raw WAFS model data files, which are
// tiled to cover the entire globe. Each file covers part of the globe.
// The files are merged and written out into a single MDV file.
//
////////////////////////////////////////////////////////////////

#ifndef WafsTiled2Mdv_hh
#define WafsTiled2Mdv_hh

#include <string>
#include <vector>
#include <cstdio>
#include <didss/DsInputPath.hh>
#include <Mdv/DsMdvx.hh>
#include "Args.hh"
#include "Params.hh"
#include "OutputField.hh"
using namespace std;

////////////////////////
// This class

class WafsTiled2Mdv {
  
public:

  // constructor

  WafsTiled2Mdv (int argc, char **argv);

  // destructor
  
  ~WafsTiled2Mdv();

  // run 

  int Run();

  // data members

  bool isOK;

  // get output field object
  // Returns NULL on failure.
  
  OutputField *getOutputField(const int field_id);

protected:
  
private:

  string _progName;
  char *_paramsPath;
  Args _args;
  Params _params;

  DsInputPath *_input;
  vector<OutputField *> _outputFields;

  // private functions

  int _processFile(const char *input_path);

  int _processFileSet(const vector<string> &path_set);

  void _loadMasterHeader(DsMdvx &mdv,
			 time_t gen_time,
			 int forecast_lead_time);
  
};

#endif

