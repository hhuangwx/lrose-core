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
// DiffRefl.hh
//
// Definitons for class
//
// Niles Oien, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
//
/////////////////////////////////////////////////////////////

#ifndef DIFFREFL_H
#define DIFFREFL_H
#include <dataport/port_types.h>
#include "Product.hh"
#include <cmath>

using namespace std;

class DiffRefl: public Product {
  
public:

  // Constructor. 
  DiffRefl (FILE *filePtr, bool byteSwapFlag, bool debugFlag);

  // Destructor.
  ~DiffRefl ();

  fl32 convertData(ui08 x);
 
  void calcDependentVals();

protected:
  
private:

  
  //
  // stored in hw30
  //
  fl32 _elevAngle;

  //
  // stored in hw31 and hw32
  // 
  fl32 _scale;

  //
  // stored in hw33 hw34
  //
  fl32 _bias;
  
  //
  // stored in hw36
  //
  fl32 _maxVal;

  //
  // stored in hw37
  //
  ui16 _leadingFlags;

  //
  // stored in hw38
  //  
  ui16 _trailingFlags;

  //
  // stored in hw47
  //
  fl32 _minDataVal;
  
  //
  // stored in hw48
  //
  fl32 _maxDataVal;

  //
  // stored in hw51
  // 
  ui16 _compression;

  //
  // stored in h52
  // 
  ui16 _sizeMSW;

  //
  // stored in h53
  // 
  ui16 _sizeLSW;
 
};

#endif





