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
 *
 * @file MedianStatCalc.cc
 *
 * @class MedianStatCalc
 *
 * Class for calculating the median value statistic.
 *  
 * @date 8/31/2011
 *
 */

#include <iostream>

#include "MedianStatCalc.hh"

using namespace std;

/**********************************************************************
 * Constructor
 */

MedianStatCalc::MedianStatCalc()
{
}


/**********************************************************************
 * Destructor
 */

MedianStatCalc::~MedianStatCalc()
{
}
  

/**********************************************************************
 * calculate()
 */

double MedianStatCalc::calculate(const vector< double > &values) const
{
  // If there are no values, return the bad data value

  if (values.size() == 0)
    return BAD_DATA_VALUE;
  
  // Return the median value
  
  int mid_index = values.size() / 2;

  if (values.size() % 2 == 0)
    return (values[mid_index] + values[mid_index-1]) / 2.0;
  else
    return values[mid_index];
  
}


/**********************************************************************
 *              Private Member Functions                              *
 **********************************************************************/
