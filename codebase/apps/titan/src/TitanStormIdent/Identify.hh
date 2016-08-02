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
// Identify.hh
//
// Identify class
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// November 1998
//
///////////////////////////////////////////////////////////////

#ifndef Identify_HH
#define Identify_HH

#include "Worker.hh"
#include "InputMdv.hh"
#include "Clumping.hh"
#include "ThresholdManager.hh"
#include <titan/TitanStormFile.hh>

class Props;
class GridClump;


////////////////////////////////
// Identify

class Identify : public Worker {
  
public:

  // constructor
  
  Identify(const string &prog_name, const Params &params,
           const InputMdv &input_mdv, TitanStormFile &storm_file,
	   const ThresholdManager &thresholds);

  // destructor
  
  virtual ~Identify();

  // perform identification

  int run(int scan_num, time_t scan_time);
  int run(int scan_num, time_t scan_gen_time, int scan_lead_time);

protected:
  
private:

  const InputMdv &_inputMdv;
  const ThresholdManager &_thresholds;
  TitanStormFile &_sfile;
  Clumping _clumping;

  int _nClumps;
  int _nStorms;

  Props *_props;

  // state variables used to determine SPDB output
  // content for forecasts

  time_t _time;
  int _lead;
  bool _hasLead;

  int _run(int scan_num);
  int _processClumps(int scan_num);
  int _processThisClump(const GridClump &grid_clump);
  int _output(int scan_num);

};

#endif



