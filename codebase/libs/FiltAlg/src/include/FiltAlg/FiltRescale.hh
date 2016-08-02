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
 * @file FiltRescale.hh 
 * @brief Rescale Data using a scale and offset
 * @class FiltRescale
 * @brief Rescale Data using a scale and offset
 *
 * The one input is data to remap. The one output is data of the same type
 * with all values rescaled using the scale and offset. Any type of data
 * is allowed.
 */

#ifndef FILT_RESCALE_H
#define FILT_RESCALE_H
#include <FiltAlg/FiltAlgParams.hh>
#include <FiltAlg/Filter.hh>

//------------------------------------------------------------------
class FiltRescale : public Filter
{
public:

  /**
   * Constructor
   * @param[in] f  Parameters for particular filter
   * @param[in] p  General params
   */
  FiltRescale(const FiltAlgParams::data_filter_t f, const FiltAlgParms &p);

  /**
   * Destructor
   */
  virtual ~FiltRescale(void);

  #include <FiltAlg/FilterVirtualFunctions.hh>

protected:
 private:

  double _scale;  /**< Value to use for rescaling */
  double _offset; /**< Value to use for offset */

  /**
   * Remap the input data
   * @param[in,out] o
   * @return true for success
   */
  bool _remap(FiltInfoOutput &o) const;

};

#endif
