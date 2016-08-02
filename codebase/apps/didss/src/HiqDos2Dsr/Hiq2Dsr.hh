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
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* RCS info
 *   $Author: dixon $
 *   $Locker:  $
 *   $Date: 2016/03/06 23:53:40 $
 *   $Id: Hiq2Dsr.hh,v 1.2 2016/03/06 23:53:40 dixon Exp $
 *   $Revision: 1.2 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * Hiq2Dsr: Hiq2Dsr program object.
 *
 * RAP, NCAR, Boulder CO
 *
 * November 2006
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef Hiq2Dsr_HH
#define Hiq2Dsr_HH


#include <cstdio>
#include <string>

#include <Fmq/DsFmq.hh>

#include "Args.hh"
#include "Params.hh"

#include "BeamWriter.hh"
#include "HiqBeamMsg.hh"
#include "HiqRadarMsg.hh"
#include "HiqReader.hh"
#include "MedianFilter.hh"

using namespace std;


class Hiq2Dsr
{
 public:

  ////////////////////
  // Public members //
  ////////////////////

  // Flag indicating whether the program status is currently okay.

  bool okay;


  ////////////////////
  // Public methods //
  ////////////////////

  //////////////////////////////
  // Constructors/Destructors //
  //////////////////////////////

  /*********************************************************************
   * Destructor
   */

  ~Hiq2Dsr(void);
  

  /*********************************************************************
   * Inst() - Retrieve the singleton instance of this class.
   */

  static Hiq2Dsr *Inst(int argc, char **argv);
  static Hiq2Dsr *Inst();
  

  /*********************************************************************
   * init() - Initialize the local data.
   *
   * Returns true if the initialization was successful, false otherwise.
   */

  bool init();
  

  /////////////////////
  // Running methods //
  /////////////////////

  /*********************************************************************
   * run() - run the program.
   */

  void run();
  

 private:

  /////////////////////
  // Private members //
  /////////////////////

  // Singleton instance pointer

  static Hiq2Dsr *_instance;
  
  // Program parameters.

  char *_progName;
  Args *_args;
  Params *_params;
  
  // Data reader objects

  HiqReader *_reader;
  
  // Objects for writing the beam data

  BeamWriter *_beamWriter;
  
  // Current messages since we generally need information from both
  // message types at the same time.

  HiqBeamMsg *_currentBeamMsg;
  HiqRadarMsg *_currentRadarMsg;

  // Median filter.  This filter cleans up the elevation and azimuth angles
  // in the received beams.

  MedianFilter _medianFilter;
  

  /////////////////////
  // Private methods //
  /////////////////////

  /*********************************************************************
   * Constructor -- private because this is a singleton object
   */

  Hiq2Dsr(int argc, char **argv);
  

  /*********************************************************************
   * _initBeamWriter() - Initialize the BeamWriter object.
   *
   * Returns true on success, false on failure.
   */

  bool _initBeamWriter(void);
  

  /*********************************************************************
   * _initReader() - Initialize the reader object.
   *
   * Returns true on success, false on failure.
   */

  bool _initReader(void);
  

  /*********************************************************************
   * _processData() - Process data for the given time.
   *
   * Returns true on success, false on failure.
   */

  bool _processData(void);
  

};


#endif
