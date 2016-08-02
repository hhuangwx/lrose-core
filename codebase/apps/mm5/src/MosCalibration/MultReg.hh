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
///////////////////////////////////////////////////////////////////
//
// Multiple Linear Regression 
//
// $Id: MultReg.hh,v 1.23 2016/03/07 01:33:50 dixon Exp $
//
///////////////////////////////////////////////////////////////////
#ifndef _MULT_REG_INC_
#define _MULT_REG_INC_

#include <string>
#include <vector>
#include <values.h>

#include "Regression.hh"
#include "MultRegVar.hh"
using namespace std;

class MultReg : public Regression {

 public:

   MultReg( const string& baseName, double missVal,
            vector< string >& varNames, Params* params, bool useNorm = false );
   ~MultReg(){ clear(); }

   virtual void      clear();
   int               addPoint(double yVal, vector<double>& xVals, time_t metarTime, time_t modelTime, int forecastLead);
   int               doRegression();
   int               writeVars( const string& outputFile );



   //
   // Constants
   //
   static const int NRHS;
   static const int MIN_N_PTS;
   
 private:

   bool                  normalize;
   
   vector< MultRegVar* > x;
   MultRegVar            y;
   vector< time_t > modelUnixTime; 
   vector< time_t > metarUnixTime; 

   void                  findDetermination();
   void                  missingCoeffs();

};

#endif
