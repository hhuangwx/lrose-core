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
// QuadratureTest.hh
//
// Mike Dixon, RAP, NCAR
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// March 2010
//
///////////////////////////////////////////////////////////////
//
// QuadratureTest tests computing IQ from data samples
//
////////////////////////////////////////////////////////////////

#ifndef QuadratureTest_H
#define QuadratureTest_H

#include <string>
#include <vector>
#include <cstdio>

#include "Args.hh"

using namespace std;

////////////////////////
// This class

class QuadratureTest {
  
public:

  // constructor

  QuadratureTest (int argc, char **argv);

  // destructor
  
  ~QuadratureTest();

  // run 

  int Run();

  // data members

  bool isOK;

protected:
  
private:

  string _progName;
  Args _args;
};

#endif
