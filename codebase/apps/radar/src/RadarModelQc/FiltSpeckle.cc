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
/**
 * @file FiltSpeckle.cc
 */
#include "FiltSpeckle.hh"
#include <toolsa/LogMsg.hh>

//------------------------------------------------------------------
FiltSpeckle::FiltSpeckle(const Params::data_filter_t f,
		       const Params &P) : Filter(f, P)
{
  if (!ok())
  {
    return;
  }

  _outlierExceedsSurroundings =
    P._parm_speckle[f.filter_index].outlier_exceeds_surroundings;
  _outlierThresh = P._parm_speckle[f.filter_index].outlier_thresh;
  _speckleConfidence = P._parm_speckle[f.filter_index].speckle_confidence;
  _nonspeckleConfidence = P._parm_speckle[f.filter_index].nonspeckle_confidence;
}

//------------------------------------------------------------------
FiltSpeckle::~FiltSpeckle()
{
}

//------------------------------------------------------------------
void FiltSpeckle::filter_print(void) const
{
  LOG(LogMsg::DEBUG_VERBOSE, "filtering");
}

//------------------------------------------------------------------
bool FiltSpeckle::filter(const time_t &t, const RadxRay &ray,
			std::vector<RayData> &data)
{
  RayData r;
  if (!RadxFiltAlg::retrieveRay(_f.input_field, ray, data, r))
  {
    return false;
  }
  r.speckleMask(_outlierThresh, _speckleConfidence, _nonspeckleConfidence, 
		_outlierExceedsSurroundings);
  RadxFiltAlg::modifyRayForOutput(r, _f.output_field, _f.output_units,
				  _f.output_missing);
  data.push_back(r);
  return true;
}

