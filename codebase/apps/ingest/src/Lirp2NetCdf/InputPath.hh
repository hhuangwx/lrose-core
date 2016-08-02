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
// Handling of input paths for data system files into archive and
// realtime programs.  Data system files are expected to be stored
// in files whose paths match the following pattern:
//         <file_path>/YYYYMMDD/hhmmss.<ext>
//
// There are three modes of operation, reflected by the different
// constructors.
//
// Archive mode:
//   The constructor passes in a list of data file paths.
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
// May 2003
//
/////////////////////////////////////////////////////////////

#ifndef InputPath_HH
#define InputPath_HH

#include <string>
#include <vector>
#include <map>
using namespace std;

// typedef for heartbeat function. If heartbeat_func is non-null,
// the client must provide a pointer to a function which fits this
// prototype. The label will be generated by this class prior
// to calling the heartbeat function.

typedef void (*Input_heartbeat_t)(const char *label);

class InputPath {
  
public:

  typedef multimap<string, time_t, less<string> > PathTimeMap;
  typedef pair<string, time_t > PathTimePair;
  typedef PathTimeMap::iterator PathTimeIter;

  // mode typedef

  typedef enum {
    REALTIME_MODE,
    ARCHIVE_MODE,
  } mode_t;

  // Dataset time information typedef
  
  typedef struct {
    time_t gen_time;      // Dataset generation time.
    time_t forecast_time; // Dataset forecast time.  Set to -1 for datasets
                          // that don't contain forecasts.
  } dataset_time_t;

  /////////////////////////////
  // Constructor - Archive mode
  //
  // Pass in a vector of file paths.
  //

  InputPath (const vector< string >& file_paths);
  
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
  //         (d) latest_file_only flag. Only applies if use_ldata_info is
  //             false. If set, the routine returns the latest file.
  //             If false, it returns the earliest file which is younger than
  //             the max valid age and which has not been used yet.

  // next() will recurse looking for files in subdirectories. However,
  // you need to understand the way in which directory modify times
  // are set. A directory modify time is set only when a file is added
  // or removed from the directory, not if an existing file is
  // modified. next() will traverse into a subdirectory if is has been
  // modified within the last max_valid_age secs.

  InputPath (const string &input_dir,
	     int max_valid_age = 3600,
	     Input_heartbeat_t heartbeat_func = NULL,
	     bool latest_file_only = true);
  
  /////////////
  // destructor

  ~InputPath();

  // set debug

  void setDebug(bool debug) { _debug = debug; }

  /////////////////////////
  // reset to start of list
  // 
  // Archive mode only.

  void reset();

  /////////////////////////
  // step back by one entry
  // 
  // Archive mode only.
  //
  // Returns 0 on success, -1 if already at start of list
  
  int stepBack();

  ///////////////////////////////////////
  // set the heartbeat function
  //

  void setHeartbeatFunc(Input_heartbeat_t func);

  ///////////////////////////////////////
  // set the required data file extension
  //
  // If set, only files with this extension will be returned

  void setSearchExt(const string &search_ext);

  ///////////////////////////////////////
  // set a substring that must be in the filename
  // for it to be considered valid.
  //
  // If set, only files with this string in
  // their full path will be returned. Applies
  // only to realtime mode with no ldata_info active.
  // Added by Niles to read MM5 data from a directory in
  // which files for several domains appeared at once.
  //
  void setSubString(const string &subString);

  ///////////////////////////////////////////////////////////
  // set the directory scan sleep interval - secs
  //
  // This only applies to REALTIME mode. This is the time the search
  // routine sleeps between each scan of the directory looking for new
  // data. The default is 5, and the maximum is 50, so that the
  // routine will register with the procmap at least once per minute.
  
  void setDirScanSleep(int dir_scan_sleep_secs = 5);
  
  ///////////////////////////////////////////////////////////
  // set the file quiescence time - secs
  //
  // This only applies to REALTIME mode. The next() routine, when
  // searching for new files, waits for files to be quiescent before
  // assuming they are complete on disk. This is the number of secs of
  // quiescence we wait.
  
  void setFileQuiescence(int file_quiescence_secs = 5);

  ///////////////////////////////////////////////////////////
  // set the recursion flag (default is true)
  //
  // This only applies to REALTIME mode. The next() routine, when
  // searching for new files, will recurse down new directories unless
  // the recursion flag is set to false.

  void setRecursion(bool recursionFlag = true);

  //////////////////////////////////////////////////
  // get next file path
  //
  // Realtime and Archive modes only
  //
  // If block is true, blocks until data is available.
  // If block is false, returns immediately if no data is available.
  // Blocking is only applicable in Realtime mode.
  //
  // Returns the path of the next available file.
  // If no file is available, returns NULL.

  char *next(bool block = true);

  ////////////////////////////////////////////////////////////////////
  // access to selected data members
  
  const string &getInputDir() { return _input_dir; } 
  const string &getSearchExt() { return _search_ext; } 
  mode_t getMode() { return _mode; };

protected:

private:

  bool _debug;

  string _input_dir;
  string _search_ext;
  
  mode_t _mode;
  int _max_age;
  int _dir_scan_sleep_secs;
  int _file_quiescence_secs;
  bool _recurse;
  bool _latest_file_only;
  time_t _latest_time_used;

  Input_heartbeat_t _heartbeat_func;
  
  PathTimeMap _pathTimes;
  PathTimeIter _posn;
  
  mutable string _returned_path;

  bool _checkSubString; // TRUE if filenames must contain a substring
  string _subString;    // The substring to check for.

  int _setFileModTime(const string &path, time_t &modTime);

  int _nextArchive();

  int _nextRealtime(bool block);

  int _find_next_path(const string &input_dir,
		      time_t &closest_valid_time);
  
  bool _hasExt(const string &path, const string &ext);
  
  void _insertPathPair(const string &path, time_t file_time);

};

#endif

