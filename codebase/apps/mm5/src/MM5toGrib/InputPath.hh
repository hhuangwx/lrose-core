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
// InputPath.hh
//
// Handling of input paths for MDV files into archive and
// realtime programs.
//
// There are two modes of operation, reflected by the two
// constructors.
//
// Archive mode:
//   The constructor passes in a list of MDV file paths.
//   This list is stored, and then the paths are served out
//   when next() is called. If next() returns NULL, the list
//   is exhausted.
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
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 1998
//
/////////////////////////////////////////////////////////////

#ifndef InputPath_H
#define InputPath_H

#include "Params.hh"
#include <toolsa/umisc.h>
#include <didss/DsInputPath.hh>
#include <string>
#include <set>
using namespace std;

// typedef for heartbeat function. If heartbeat_func is non-null,
// the client must provide a pointer to a function which fits this
// prototype. The label will be generated by this class prior
// to calling the heartbeat function.

typedef void (*MdvInput_heartbeat_t)(const char *label);

class InputPath {
  
public:

  /////////////////////////////
  // Constructor - Archive mode
  //
  // Pass in a list of file paths.
  //

  InputPath (const string &prog_name,
	     const Params &params,
	     int n_files,
	     char **file_paths);
    
  //////////////////////////////
  // Constructor - realtime mode
  //
  // Pass in (a) the input directory to be watched.
  //         (b) the max valid age for a realtime file (secs)
  //             the routine will wait for a file with the age
  //             less than this.
  //         (c) pointer to heartbeat_func. If NULL this is ignored.
  //             If non-NULL, this is called once per second while
  //             the routine is waiting for new data.
  
  InputPath (const string &prog_name,
	     const Params &params,
	     MdvInput_heartbeat_t heartbeat_func);
  
  /////////////
  // destructor

  ~InputPath();

  ////////////////
  // get next file
  //
  // returns empty string on failure

  const string &next();

  /////////////////////////
  // reset to start of list
  // 
  // Archive mode only.

  void reset();


protected:
  
private:

  const string &_progName;
  const Params &_params;

  set<string, less<string> > _filePaths;
  set<string, less<string> >::iterator _currentPath;
  
  string _inputPath;
  bool _archiveMode;
  DsInputPath *_dsInputPath;
  MdvInput_heartbeat_t _heartbeatFunc;

  void _loadDay(char *subdir_path,
		date_time_t *midday,
		time_t start_time,
		time_t end_time);

};

#endif
