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
 *   $Date: 2016/03/04 02:22:11 $
 *   $Id: Args.hh,v 1.2 2016/03/04 02:22:11 dixon Exp $
 *   $Revision: 1.2 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * Args.hh : header file for the Args class.
 *
 * RAP, NCAR, Boulder CO
 *
 * August 2009
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef Args_HH
#define Args_HH

#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>

#include <tdrp/tdrp.h>
#include <toolsa/DateTime.hh>

using namespace std;

class Args
{
 public:

  ////////////////////
  // Public members //
  ////////////////////

  // TDRP overrides specified in the command line arguments.

  tdrp_override_t override;
  

  ////////////////////
  // Public methods //
  ////////////////////

  /**********************************************************************
   * Constructor
   */

  Args(int argc, char **argv, char *prog_name);
  

  /**********************************************************************
   * Destructor
   */

  ~Args(void);
  

  ////////////////////
  // Access methods //
  ////////////////////

  /**********************************************************************
   * Get the start time for archive mode.
   */

  const DateTime &getStartTime(void)
  {
    return _startTime;
  }
  

  /**********************************************************************
   * Get the end time for archive mode.
   */

  const DateTime &getEndTime(void)
  {
    return _endTime;
  }
  

 private:

  /////////////////////
  // Private members //
  /////////////////////

  // The program name for error messages

  string _progName;

  // The start and end times for archive mode

  DateTime _startTime;
  DateTime _endTime;
  

  /////////////////////
  // Private methods //
  /////////////////////

  /**********************************************************************
   * _usage() - Print the usage for this program.
   */

  void _usage(FILE *stream);
  
};


#endif
