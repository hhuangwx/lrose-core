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
// RealtimeDirInputStrategy.hh
//
// Realtime mode:
//   The constructor passes in an input directory to watch, as well as
//   as max valid age and a heartbeat function to be called while
//   waiting for new data to arrive. When next() is called, the
//   routine will watch the input directory for a new file. When
//   a new file arrives the path is returned by next(). If the
//   heartbeat_func is not NULL, it gets called every second while
//   next() is waiting for a file to arrive.
//
// Nancy Rehak, RAP, NCAR, P.O. Box 3000, Boulder, CO 80307-3000, USA
//
// Sept 2002
//
// November 2004 - Carl Drews added code to avoid rsync temporary files.
//
/////////////////////////////////////////////////////////////

#ifndef _RealtimeDirInputStrategy_
#define _RealtimeDirInputStrategy_

#include <string>

#include <toolsa/InputDir.hh>

#include "InputStrategy.hh"

using namespace std;


class RealtimeDirInputStrategy : public InputStrategy
{
  
public:

  // Typedef for heartbeat function. If heartbeat_func is non-null,
  // the client must provide a pointer to a function which fits this
  // prototype. The label will be generated by this class prior
  // to calling the heartbeat function.

  typedef void (*heartbeat_t)(const char *label);

  RealtimeDirInputStrategy(const string &data_dir,
			   const string &input_substring,
			   const int max_valid_age = -1,
			   heartbeat_t heartbeat_func = 0,
			   const bool debug = false);

  ~RealtimeDirInputStrategy();

  const string &next();

protected:
 
  /**
   * Determine if this file is a temporary file created by rsync,
   * and therefore should not be processed.  Rsync creates temp
   * files beginning with a dot (.), and some random chars
   * on the end.
   * @param filepath is the full directory and filename
   * @return true if this file appears to be an rsync temp
   */
  bool isRsyncTempFile(char *filepath);

private:

  int _maxValidAge;
  heartbeat_t _heartbeatFunc;
  
  InputDir *_inputDir;

  // Define a member for the current input path so we can return a
  // constant reference to it from the next() method.

  string _currentInputPath;

};

#endif
