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
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Taf2Spdb
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("Program name: Taf2Spdb");
    tt->comment_text = tdrpStrDup("Taf2Spdb reads TAF data (Terminal Aerodrome Forecasts) from text files and stores it in an SPDB data base in XML or ASCII format.");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'print_decode_problems_to_stderr'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_decode_problems_to_stderr");
    tt->descr = tdrpStrDup("Option to print decoding problems to stderr.");
    tt->help = tdrpStrDup("Turn this on if you want to log these problems in detail or if you want to run Taf2Spdb.pl to generate statistics.");
    tt->val_offset = (char *) &print_decode_problems_to_stderr - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("OPERATIONAL MODE.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operational mode");
    tt->help = tdrpStrDup("REALTIME mode - waits for new data. ARCHIVE mode - finds files between start and end times. FILELIST mode - uses file list from -f on command line.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[0].val = REALTIME;
      tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[1].val = ARCHIVE;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir_path");
    tt->descr = tdrpStrDup("Name of input data directory.");
    tt->help = tdrpStrDup("ASCII input files are stored in this directory.");
    tt->val_offset = (char *) &input_dir_path - &_start_;
    tt->single_val.s = tdrpStrDup("raw/aftn");
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max age of input data");
    tt->help = tdrpStrDup("For REALTIME only - max age of input data for it to be valid");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'taf_format'
    // ctype is '_taf_format_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("taf_format");
    tt->descr = tdrpStrDup("taf format : AFTN, GTS, CAF or CWB_CAF");
    tt->help = tdrpStrDup("Set to the format appropriate for the input stream. GTS: Global Telecommunications System. AFTN: Aeronautical Fixed Telecommunication Network. CAF - Received directly from the Taiwan air force. CWB_CAF: CAF data received via the Central Weather Bureau in Taiwan.");
    tt->val_offset = (char *) &taf_format - &_start_;
    tt->enum_def.name = tdrpStrDup("taf_format_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("GTS");
      tt->enum_def.fields[0].val = GTS;
      tt->enum_def.fields[1].name = tdrpStrDup("AFTN");
      tt->enum_def.fields[1].val = AFTN;
      tt->enum_def.fields[2].name = tdrpStrDup("CAF");
      tt->enum_def.fields[2].val = CAF;
      tt->enum_def.fields[3].name = tdrpStrDup("CWB_CAF");
      tt->enum_def.fields[3].val = CWB_CAF;
    tt->single_val.e = GTS;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("STATION LOCATIONS.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'station_location_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("station_location_path");
    tt->descr = tdrpStrDup("Path to station location file.");
    tt->help = tdrpStrDup("Used to determine the location of station identifiers. The station location file should contain a station identification followed by the latitude and longitude for each station.");
    tt->val_offset = (char *) &station_location_path - &_start_;
    tt->single_val.s = tdrpStrDup("./station_location.txt");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("FILTERING STATIONS BASED ON NAME.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'useAcceptedStationsList'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("useAcceptedStationsList");
    tt->descr = tdrpStrDup("Set to TRUE to use the acceptedStations list (below)");
    tt->help = tdrpStrDup("Only accept stations in this list.");
    tt->val_offset = (char *) &useAcceptedStationsList - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'acceptedStations'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("acceptedStations");
    tt->descr = tdrpStrDup("List of accepted station IDs");
    tt->help = tdrpStrDup("If a station is not on this list, it is not stored.");
    tt->array_offset = (char *) &_acceptedStations - &_start_;
    tt->array_n_offset = (char *) &acceptedStations_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 7;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("RCTP");
      tt->array_vals[1].s = tdrpStrDup("RCFG");
      tt->array_vals[2].s = tdrpStrDup("RCSS");
      tt->array_vals[3].s = tdrpStrDup("RCGM");
      tt->array_vals[4].s = tdrpStrDup("RCNO");
      tt->array_vals[5].s = tdrpStrDup("RCQC");
      tt->array_vals[6].s = tdrpStrDup("RCBS");
    tt++;
    
    // Parameter 'useRejectedStationsList'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("useRejectedStationsList");
    tt->descr = tdrpStrDup("Set to TRUE to use the rejectedStations list (below)");
    tt->help = tdrpStrDup("Reject stations in this list.");
    tt->val_offset = (char *) &useRejectedStationsList - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'rejectedStations'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("rejectedStations");
    tt->descr = tdrpStrDup("List of rejected station IDs");
    tt->help = tdrpStrDup("If a station is not on this list, it is not stored.");
    tt->array_offset = (char *) &_rejectedStations - &_start_;
    tt->array_n_offset = (char *) &rejectedStations_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 5;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("RCFN");
      tt->array_vals[1].s = tdrpStrDup("RCAY");
      tt->array_vals[2].s = tdrpStrDup("RCQS");
      tt->array_vals[3].s = tdrpStrDup("RCFS");
      tt->array_vals[4].s = tdrpStrDup("RCMT");
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("ASCII OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'store_ascii_format'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("store_ascii_format");
    tt->descr = tdrpStrDup("Option to store in ascii format.");
    tt->help = tdrpStrDup("If TRUE, ascii data is stored using the ascii_output_url.");
    tt->val_offset = (char *) &store_ascii_format - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'store_header'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("store_header");
    tt->descr = tdrpStrDup("Option to include header with the TAF.");
    tt->help = tdrpStrDup("Sometimes there is a header, starting with FT, at the start of a TAF block. If store_header is true, the header is added to the start of the TAF message before storing it.");
    tt->val_offset = (char *) &store_header - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'ascii_output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("ascii_output_url");
    tt->descr = tdrpStrDup("Output SPDB URL for ascii data.");
    tt->help = tdrpStrDup("Used if 'store_ascii_format' is TRUE.");
    tt->val_offset = (char *) &ascii_output_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdb/ascii_taf");
    tt++;
    
    // Parameter 'ascii_expire_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("ascii_expire_secs");
    tt->descr = tdrpStrDup("Data expire seconds - ASCII data");
    tt->help = tdrpStrDup("Number of seconds the data is valid before it should be expired.");
    tt->val_offset = (char *) &ascii_expire_secs - &_start_;
    tt->single_val.i = 10800;
    tt++;
    
    // Parameter 'ascii_cancel_msg_handling'
    // ctype is '_cancel_msg_handling_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("ascii_cancel_msg_handling");
    tt->descr = tdrpStrDup("How to process cancel (CNL) messages in the ASCII database.");
    tt->help = tdrpStrDup("\tCANCEL_MSG_OVERWRITES_ORIGINAL_MSG - When a cancel message is received, it overwrites the original TAF that it is cancelling, so the original message no longer exists in the ASCII database. In this case, the valid time of the cancel message is the same as the valid time of the original message.\n\tCANCEL_MSG_ADDED_WITH_ORIGINAL_VALID_TIME - The cancel message is added to the ASCII database using the valid time of the original message as the valid time of the cancel message. The original message stays in the database so requests to the database will receive both messages.\n\tCANCEL_MSG_ADDED_WITH_ISSUE_TIME_AS_VALID_TIME - The cancel message is added to the ASCII database using the cancel message's issue time as the valid time. The original message is left unchanged in the database and the cancel message will have a later valid time so it will be the message returned from a \"latest\" request.\n");
    tt->val_offset = (char *) &ascii_cancel_msg_handling - &_start_;
    tt->enum_def.name = tdrpStrDup("cancel_msg_handling_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("CANCEL_MSG_OVERWRITES_ORIGINAL_MSG");
      tt->enum_def.fields[0].val = CANCEL_MSG_OVERWRITES_ORIGINAL_MSG;
      tt->enum_def.fields[1].name = tdrpStrDup("CANCEL_MSG_ADDED_WITH_ORIGINAL_VALID_TIME");
      tt->enum_def.fields[1].val = CANCEL_MSG_ADDED_WITH_ORIGINAL_VALID_TIME;
      tt->enum_def.fields[2].name = tdrpStrDup("CANCEL_MSG_ADDED_WITH_ISSUE_TIME_AS_VALID_TIME");
      tt->enum_def.fields[2].val = CANCEL_MSG_ADDED_WITH_ISSUE_TIME_AS_VALID_TIME;
    tt->single_val.e = CANCEL_MSG_OVERWRITES_ORIGINAL_MSG;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("XML OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'store_xml_format'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("store_xml_format");
    tt->descr = tdrpStrDup("Option to store in decoded format in XML.");
    tt->help = tdrpStrDup("If TRUE, decoded data is stored using the xml_output_url.");
    tt->val_offset = (char *) &store_xml_format - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'xml_output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("xml_output_url");
    tt->descr = tdrpStrDup("Output SPDB URL for XML format.");
    tt->help = tdrpStrDup("Used if 'store_xml_format' is TRUE.");
    tt->val_offset = (char *) &xml_output_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdb/xml_taf");
    tt++;
    
    // Parameter 'cancel_input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("cancel_input_url");
    tt->descr = tdrpStrDup("Input URL for cancelling.");
    tt->help = tdrpStrDup("To cancel a sigmet we read in from this URL, set the cancel flag, and then overwrite to decoded_output_url. This is done because the output_url may sometimes be a distribution URL, and we do not want to read from those.");
    tt->val_offset = (char *) &cancel_input_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdb/xml_taf");
    tt++;
    
    // Parameter 'process_tafs_with_missing_issue_times'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("process_tafs_with_missing_issue_times");
    tt->descr = tdrpStrDup("Flag indicating whether to process TAFs with a missing issue time value.");
    tt->help = tdrpStrDup("If set to true, TAFs that are missing the issue time field will be processed and the issue time will be set to the time in the WMO header for the TAF.");
    tt->val_offset = (char *) &process_tafs_with_missing_issue_times - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
