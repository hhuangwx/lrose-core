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
 *  $Id: Args.hh,v 1.3 2016/03/07 01:23:02 dixon Exp $
 *
 */
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

//////////////////////////////////////////////////////////////////////////
// 
// Header:	Args
// 
// Author:	G M Cunning
// 
// Date:	June 17 2014
// 
// Description:	This class manages the argument list for MetReport2Spdb.
// 


#ifndef    ARGS_H
#define    ARGS_H

#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

#include <tdrp/tdrp.h>

class Args {
  
public:


  // Flag indicating whether the current object status is okay.
  bool isOK;

  // TDRP overrides specified in the command line arguments.
  tdrp_override_t override;

  // constructor
  Args(int argc, char **argv, const std::string& prog_name);

  // destructor
  ~Args();

  std::vector<std::string> inputFileList;

protected:
  
private:


  std::string _errStr;
  static const std::string _className;

  // Disallow the copy constructor and assignment operator
  Args(const Args &);
  Args &operator=(const Args &);

  void _setOverride(const std::string&);
  void _setOverride(const std::string&, const char*);
  // Print the usage for this program.

  void _usage(const std::string &prog_name, std::ostream& out);
  
};


# endif     /* ARGS_H */
