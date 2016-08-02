////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program TsTcp2Fmq
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
    tt->comment_hdr = tdrpStrDup("TsTcp2Fmq reads raw time-series data via TCP/IP. It saves the time series data out to a file message queue (FMQ), which can be read by multiple clients.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL.");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'register_with_procmap'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("register_with_procmap");
    tt->descr = tdrpStrDup("Option to register with the process mapper.");
    tt->help = tdrpStrDup("If true, this application will try to register with procmap once per minute. (If unable to do so, no error occurs.)");
    tt->val_offset = (char *) &register_with_procmap - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'do_not_register_on_read'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("do_not_register_on_read");
    tt->descr = tdrpStrDup("Option to only register with the process mapper during the write.");
    tt->help = tdrpStrDup("Sometimes the reader keeps registering, but no data is being written to the FMQ. If this parameter is true, we only register with procmap during the write. So if no writes are occurring, no registrations will occur and the auto_restarter will kill and restart this application. This makes it robust when the reading hangs for some reason.");
    tt->val_offset = (char *) &do_not_register_on_read - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("TCP DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'ts_tcp_server_host'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("ts_tcp_server_host");
    tt->descr = tdrpStrDup("Host name on which time series server is running.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &ts_tcp_server_host - &_start_;
    tt->single_val.s = tdrpStrDup("localhost");
    tt++;
    
    // Parameter 'ts_tcp_server_port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("ts_tcp_server_port");
    tt->descr = tdrpStrDup("TCP/IP port on which time series server is running.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &ts_tcp_server_port - &_start_;
    tt->single_val.i = 12000;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("FMQ DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_fmq_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_path");
    tt->descr = tdrpStrDup("Path to output FMQ.");
    tt->help = tdrpStrDup("The FMQ consists of 2 files, ??.buf and ??.stat.");
    tt->val_offset = (char *) &output_fmq_path - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/fmq/ts");
    tt++;
    
    // Parameter 'output_fmq_size'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_size");
    tt->descr = tdrpStrDup("Size of output FMQ, in bytes.");
    tt->help = tdrpStrDup("This is the total size of the output FMQ buffer.");
    tt->val_offset = (char *) &output_fmq_size - &_start_;
    tt->single_val.i = 100000000;
    tt++;
    
    // Parameter 'output_fmq_nslots'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_nslots");
    tt->descr = tdrpStrDup("Number of slots in the output FMQ.");
    tt->help = tdrpStrDup("The number of slots corresponds to the maximum number of messages which may be written to the buffer before overwrites occur. However, overwrites may occur sooner if the size is not set large enough.");
    tt->val_offset = (char *) &output_fmq_nslots - &_start_;
    tt->single_val.i = 500;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("CORRECT THE SWEEP NUMBER");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'zero_sweep_number_at_start_of_vol'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("zero_sweep_number_at_start_of_vol");
    tt->descr = tdrpStrDup("Option to correct the sweep number relative to the start of a volume.");
    tt->help = tdrpStrDup("Some radars set the sweep number to always increase, without resetting to 0 when a new volume starts. If this parameter is TRUE, the sweep number will be corrected so that it is zero at the start of each volume.");
    tt->val_offset = (char *) &zero_sweep_number_at_start_of_vol - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("RADAR POSITION - Mobile Radar Support");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'update_position'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("update_position");
    tt->descr = tdrpStrDup("Option to update the radar's position from info in a position file");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &update_position - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'position_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("position_file_path");
    tt->descr = tdrpStrDup("Path Mobile Radar position and heading file");
    tt->help = tdrpStrDup("This file contains records: Heading Lat Lon Altitude(m) Time(YYYYMMDD.HHMMSS)");
    tt->val_offset = (char *) &position_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("/var/log/positions");
    tt++;
    
    // Parameter 'position_check_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("position_check_interval");
    tt->descr = tdrpStrDup("Interval at which to check on position file changes (secs).");
    tt->help = tdrpStrDup("The position file will be checked at this interval, and if it has changed the new position information will be read in.");
    tt->val_offset = (char *) &position_check_interval - &_start_;
    tt->single_val.i = 5;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("SWEEP NUMBER");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'delay_sweep_num_change_in_sector_scan'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("delay_sweep_num_change_in_sector_scan");
    tt->descr = tdrpStrDup("Option to delay the change of the sweep number in sector scan mode.");
    tt->help = tdrpStrDup("On some systems (e.g. those which use a PMAC) the scan flags are updated at the start of the antenna transition. This means that the entire transition is included in the new sweep. If this parameter is set to TRUE, and the scan mode is SECTOR, the sweep num change is delayed until the antenna  changes direction. This means that the first half of the transition will be flagged as the previous sweep, and the second half as the next sweep. In non-sector mode, this parameter is ignored.");
    tt->val_offset = (char *) &delay_sweep_num_change_in_sector_scan - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("OVERRIDE CALIBRATION");
    tt->comment_text = tdrpStrDup("Limited calibration information is passed down from the drx. This option allows you to override this calibration information with that from a file on disk.");
    tt++;
    
    // Parameter 'override_calibration'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("override_calibration");
    tt->descr = tdrpStrDup("Option to override calibration, with values from local xml file.");
    tt->help = tdrpStrDup("If true, the calibration will be read in from an xml file. Calibration packets arriving from the drx will be replaced with the local information.");
    tt->val_offset = (char *) &override_calibration - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'cal_xml_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("cal_xml_file_path");
    tt->descr = tdrpStrDup("File path for calibration to be used for override.");
    tt->help = tdrpStrDup("See 'override_calibration'.");
    tt->val_offset = (char *) &cal_xml_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("./cal.xml");
    tt++;
    
    // Parameter 'Comment 8'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 8");
    tt->comment_hdr = tdrpStrDup("IQ DATA SCALING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'apply_scale'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("apply_scale");
    tt->descr = tdrpStrDup("Option to apply a scale and bias to each I and Q value before writing.");
    tt->help = tdrpStrDup("NOTE - this only applies to IQ data stored as FLOAT-32s.");
    tt->val_offset = (char *) &apply_scale - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'scale'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("scale");
    tt->descr = tdrpStrDup("Scale constant for I and Q data.");
    tt->help = tdrpStrDup("Applies if apply_scale == TRUE. Value written = Value_in * scale + bias.");
    tt->val_offset = (char *) &scale - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'bias'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("bias");
    tt->descr = tdrpStrDup("Bias for I and Q data.");
    tt->help = tdrpStrDup("Applies if apply_scale == TRUE. Value written = Value_in * scale + bias.");
    tt->val_offset = (char *) &bias - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'Comment 9'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 9");
    tt->comment_hdr = tdrpStrDup("OUTPUT FMQ MESSAGE DETAILS");
    tt->comment_text = tdrpStrDup("The output messages are written to the FMQ. To improve performance, each message contains a number of time series pulses.");
    tt++;
    
    // Parameter 'n_pulses_per_message'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("n_pulses_per_message");
    tt->descr = tdrpStrDup("Number of pulses per output message.");
    tt->help = tdrpStrDup("The actual number will sometimes be 1 less than this, because an info data part may will be written once in a while.");
    tt->val_offset = (char *) &n_pulses_per_message - &_start_;
    tt->single_val.i = 200;
    tt++;
    
    // Parameter 'n_pulses_per_power_info'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("n_pulses_per_power_info");
    tt->descr = tdrpStrDup("The xmit_power packet will be written each time this number of pulses is written.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &n_pulses_per_power_info - &_start_;
    tt->single_val.i = 1000;
    tt++;
    
    // Parameter 'data_mapper_report_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("data_mapper_report_interval");
    tt->descr = tdrpStrDup("Number of seconds between reports to DataMapper.");
    tt->help = tdrpStrDup("If > 0, the program will register with the DataMapper when the output FMQ is written to. If <= 0, registration will not be performed.");
    tt->val_offset = (char *) &data_mapper_report_interval - &_start_;
    tt->single_val.i = 5;
    tt++;
    
    // Parameter 'write_end_of_vol_when_data_stops'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_end_of_vol_when_data_stops");
    tt->descr = tdrpStrDup("Write end of vol event when data stops.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_end_of_vol_when_data_stops - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'nsecs_no_data_for_end_of_vol'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nsecs_no_data_for_end_of_vol");
    tt->descr = tdrpStrDup("Number of secs before writing end of vol.");
    tt->help = tdrpStrDup("See 'write_end_of_vol_when_data_stops'");
    tt->val_offset = (char *) &nsecs_no_data_for_end_of_vol - &_start_;
    tt->single_val.i = 5;
    tt++;
    
    // Parameter 'Comment 10'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 10");
    tt->comment_hdr = tdrpStrDup("IGNORE PULSES IF TIME GOES BACKWARDS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'ignore_pulse_if_time_goes_backwards'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("ignore_pulse_if_time_goes_backwards");
    tt->descr = tdrpStrDup("This applies to older version of the HIQ.");
    tt->help = tdrpStrDup("If true, check that the time goes forwards. If not, ignore the pulse.");
    tt->val_offset = (char *) &ignore_pulse_if_time_goes_backwards - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 11'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 11");
    tt->comment_hdr = tdrpStrDup("ANGLE DEBUGGING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'compute_azimuth_from_time'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("compute_azimuth_from_time");
    tt->descr = tdrpStrDup("Option to override the azimuth based on time.");
    tt->help = tdrpStrDup("This is intended for trouble-shooting. If this is set to true, the azimuth is set to a value computed from the time.");
    tt->val_offset = (char *) &compute_azimuth_from_time - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'simulated_secs_per_rev'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("simulated_secs_per_rev");
    tt->descr = tdrpStrDup("Simulated seconds per revolution.");
    tt->help = tdrpStrDup("The simulated azimuth will be 0 at the start of each revolution.");
    tt->val_offset = (char *) &simulated_secs_per_rev - &_start_;
    tt->single_val.i = 6;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
