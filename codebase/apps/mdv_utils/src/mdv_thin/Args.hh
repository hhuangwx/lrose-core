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
/*
 *  $Id: Args.hh,v 1.4 2016/03/04 02:22:15 dixon Exp $
 *
 */
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

//////////////////////////////////////////////////////////////////////////
// 
// Header:	Args
// 
// Author:	G M Cunning
// 
// Date:	Sat Feb  5 15:26:38 2000
// 
// Description:	This class manages the argument list.
// 
// 
// 
// 


#ifndef    ARGS_H
#define    ARGS_H


#include <cstdio>
#include <string>
#include <iostream>

#include <tdrp/tdrp.h>
using namespace std;

class Args {
  
public:


  // Flag indicating whether the current object status is okay.
  bool isOK;

  // TDRP overrides specified in the command line arguments.
  tdrp_override_t override;

  // constructor
  Args(int argc, char **argv, const string& prog_name);

  // destructor
  ~Args();

  ////////////////////
  // Access methods //
  ////////////////////

  const time_t& getArchiveStartTime(void) const
  {
    return _archiveStartTime;
  }
  
  const time_t& getArchiveEndTime(void) const
  {
    return _archiveEndTime;
  }


protected:
  
private:


  // Archive start and end times
  time_t _archiveStartTime;
  time_t _archiveEndTime;

  string _errStr;

  static const string _className;

  // Disallow the copy constructor and assignment operator
  Args(const Args &);
  Args &operator=(const Args &);

  // Convert a time string entered on the command line to a UNIX
  // time value.
  //
  // Returns the converted time value if successful, 0 if unsuccessful.
  static time_t _convertTimeString(const char *time_string);

  void _setOverride(const string&);
  void _setOverride(const string&, const char*);
  // Print the usage for this program.

  void _usage(const string &prog_name, ostream& out);
  
};


# endif     /* ARGS_H */
