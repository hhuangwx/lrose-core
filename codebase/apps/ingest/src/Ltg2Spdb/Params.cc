// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Ltg2Spdb
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
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
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
    tt->comment_hdr = tdrpStrDup("Ltg2Spdb reads LTG records from ASCII files, converts them to LTG_strike_t format (rapformats library) and stores them in SPDB. The input format is variable and controlled by the param file.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed with the appropriate level of detail.");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
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
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROGRAM MODES OF OPERATION.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In REALTIME mode, the program waits for a new input file. In this mode it is optional to watch for a latest_data_info file. In ARCHIVE mode, it processes all of the data files in the input directory between the start and end times set on the command line. In FILELIST mode, it processes all of the files in the list specified on the command line. In FILELIST mode paths must be fully qualified with respect to the date and time - so if each date has a separate subdirectory the date part of the path must be included.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Input directory");
    tt->help = tdrpStrDup("Directory where input data files can be found.");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./raw/ltg");
    tt++;
    
    // Parameter 'latest_data_info_avail'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("latest_data_info_avail");
    tt->descr = tdrpStrDup("Set to true if there is a latest_data_info file available in the input directory.");
    tt->help = tdrpStrDup("REALTIME mode only.");
    tt->val_offset = (char *) &latest_data_info_avail - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max valid age of rdata input files in realtime mode (secs)");
    tt->help = tdrpStrDup("This the max valid age for an incoming file. The program will wait for a data file more recent than this age.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 3600;
    tt++;
    
    // Parameter 'strict_subdir_check'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("strict_subdir_check");
    tt->descr = tdrpStrDup("When set, only checks input_dir for subdirs of the form YYYYMMDD");
    tt->help = tdrpStrDup("Only in REALTIME mode with latest_data_info_avail FALSE.");
    tt->val_offset = (char *) &strict_subdir_check - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'file_name_check'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("file_name_check");
    tt->descr = tdrpStrDup("When set, check file name contains specified sub-string.");
    tt->help = tdrpStrDup("See file_match_string.");
    tt->val_offset = (char *) &file_name_check - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'file_match_string'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("file_match_string");
    tt->descr = tdrpStrDup("Input filename match string");
    tt->help = tdrpStrDup("Files must contain this string to be processed");
    tt->val_offset = (char *) &file_match_string - &_start_;
    tt->single_val.s = tdrpStrDup("ltg");
    tt++;
    
    // Parameter 'checkBoundingBox'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("checkBoundingBox");
    tt->descr = tdrpStrDup("Set to TRUE to check that LTG strike is within a bounding box.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &checkBoundingBox - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'boundingBox'
    // ctype is '_bbox_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("boundingBox");
    tt->descr = tdrpStrDup("Bounding box to check if checkBoundingBox is TRUE.");
    tt->help = tdrpStrDup("Only data which falls inside this box will be stored.");
    tt->val_offset = (char *) &boundingBox - &_start_;
    tt->struct_def.name = tdrpStrDup("bbox_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("min_lat");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &boundingBox.min_lat - (char *) &boundingBox;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("max_lat");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &boundingBox.max_lat - (char *) &boundingBox;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("min_lon");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &boundingBox.min_lon - (char *) &boundingBox;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("max_lon");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &boundingBox.max_lon - (char *) &boundingBox;
    tt->n_struct_vals = 4;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = -90;
      tt->struct_vals[1].d = 90;
      tt->struct_vals[2].d = -180;
      tt->struct_vals[3].d = 180;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("INPUT FORMAT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_format'
    // ctype is '_input_format_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("input_format");
    tt->descr = tdrpStrDup("Input format type");
    tt->help = tdrpStrDup("A number of formats are supported. The input is one line per strike, space-delimited ASCII.\n\nFORMAT_1:\n  10 fields:\n    year month day hour min sec lat lon amplitude type\n\nFORMAT_2:\n  11 fields:\n    year month day hour min sec lat lon alt_km amplitude type\n\nFORMAT_3:\n  10 fields:\n    month/day/year hour:min:sec lat lon Ka C/G, where\n    sec is a float (not an int) and C/G is either 0 or 1.\n\nFORMAT_4:\n  6 fields : unixTime,lat,lon,amp,dummy,cg (cg=0 => cloud-ground 1 => could-cloud)\n\n  UALF_LF_1: Universal ASCII Ltg Format, Low Freq (LF), version 1:\n  25 fields:\n  version# year month day hour min sec nanosec lat lon amplitude multiplicity n_sensors degress_of_freedom ellipse_angle semi_major_axis semi_minor_axis chi_sq rise_time peak_to_zero_time max_rate_of_rise cloud_flag angle_flag signal_flag timing_flag\n\nUALF_LF_1B: Universal ASCII Ltg Format, Low Freq (LF), version 1B:\n  25 fields:\n  version# year-month-day hour:min:decimal_secs*10-3 nanosec lat lon amplitude multiplicity n_sensors degress_of_freedom ellipse_angle semi_major_axis semi_minor_axis chi_sq rise_time peak_to_zero_time max_rate_of_rise cloud_flag angle_flag signal_flag timing_flag\n\n  Notes:\n    (a) lat and lon in decimal degrees\n    (b) amplitude is peak current in kA, optinally with sign to indicate polarity\n    (c) type: G - cloud-to-ground, C - cloud-to-cloud, U - unknown\n    (d) alt_km is altitude in km MSL\n    (e) multiplicity: stroke_data = 0\n    (f) n_sensors - participating in solution\n    (g) degrees_of_freedom - when optimizing location\n    (h) ellipse_angle - as a clockwise bearing from true N\n    (i) semi_major_axis - length of ellipse in km\n    (j) semi_minor_axis - width of ellipse in km\n    (k) chi_sq - value from location optimization\n    (l) rise_time - of the waveform in microsecs\n    (m) peak_to_zero_time - of the waveform in microsecs\n    (n) max_rate_of_rize - of the waveform in kA/microsec\n    (o) cloud_flag: 0 for cloud-to-ground and 1 for cloud-to-cloud\n    (p) angle_flag: angle data used for posn, 0(no) or 1(yes)\n    (q) signal_flag: signal data used for posn, 0(no) or 1(yes)\n    (r) timing_flag: timing data used for posn, 0(no) or 1(yes)\n\nBOM_AXF: Australian Bureau of Meteorology AXF format:\n  \"yyyymmddhhmmss\",lat,lon,amplitude\n  e.g. \"20071029004920\",-39.769972,157.216649,-34.4\n\nWWLDN: World Wide Lightning Data Network:\n  7 fields:\n    date time milliseconds latN lonE residual N\n    (a) date in format YYYY/MM/DD\n    (b) time in format HH:MM:SS\n    (c) time millisec\n    (d) residual is roughly the location error in seconds\n    (e) N is the number of stations for the flash location (minimum = 5)\n  Note: milliseconds, residual and N values not stored in database\n\nWWLLN: World Wide Lightning Location Network, comma-delimited:\n  7 fields:\n    date,time.microsecs, latN, lonE, residual, N\n    (a) date in format YYYY/MM/DD\n    (b) time in format HH:MM:SS\n    (c) time microsecs\n    (d) residual is roughly the location error in seconds\n    (e) N is the number of stations for the flash location (minimum = 5)\n\nNAPLN: North American Precision Lightning Network, comma-delimited:\n  7 fields:\n    2011-08-26T00:58:37.916,46.4984573,-111.7280142,-15.9,0.5,0.25,-20\n    YYYY-MM-DDTHH:MM:SS.microsecs, lat, lon, amplitude,\n    semi_major_axis, semi_minor_axis, ellipse_angle\n\nNLDN_BINARY: US National Lightning Network (Vaisala) Binary format:\n  7 fields:\n    2011-08-26T00:58:37.916,46.4984573,-111.7280142,-15.9,0.5,0.25,-20\n    YYYY-MM-DDTHH:MM:SS.microsecs, lat, lon, amplitude,\n    semi_major_axis, semi_minor_axis, ellipse_angle\n\nAOAWS_NETCDF: NetCDF format used by CWB.\n  Expected field names are defined in params below\n\nKSC:  Kennedy Space Center\n 7 fields:\n   julianDay utcTime xcoordinate ycoordinatae zcoordinate event type\n   (a) format of UTC time: HH:MM:SS:ssssss( or hour:minute:seconds:microseconds)\n   (b) x-coordinate in meters from KSC ldar longitude -80.642633\n   (c) y-coordinate in meters from KSC ldar latitude 28.538486\n   (d) z-coordinate in meters from KSC ldar\n   (e) Event type is two strings composed of 'LDAR EVENT', '4DLSS EVENT', 'GGLSS EVENT', or 'CAL EVENT' \n\n");
    tt->val_offset = (char *) &input_format - &_start_;
    tt->enum_def.name = tdrpStrDup("input_format_t");
    tt->enum_def.nfields = 13;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("FORMAT_1");
      tt->enum_def.fields[0].val = FORMAT_1;
      tt->enum_def.fields[1].name = tdrpStrDup("FORMAT_2");
      tt->enum_def.fields[1].val = FORMAT_2;
      tt->enum_def.fields[2].name = tdrpStrDup("FORMAT_3");
      tt->enum_def.fields[2].val = FORMAT_3;
      tt->enum_def.fields[3].name = tdrpStrDup("FORMAT_4");
      tt->enum_def.fields[3].val = FORMAT_4;
      tt->enum_def.fields[4].name = tdrpStrDup("UALF_LF_1");
      tt->enum_def.fields[4].val = UALF_LF_1;
      tt->enum_def.fields[5].name = tdrpStrDup("UALF_LF_1B");
      tt->enum_def.fields[5].val = UALF_LF_1B;
      tt->enum_def.fields[6].name = tdrpStrDup("BOM_AXF");
      tt->enum_def.fields[6].val = BOM_AXF;
      tt->enum_def.fields[7].name = tdrpStrDup("WWLDN");
      tt->enum_def.fields[7].val = WWLDN;
      tt->enum_def.fields[8].name = tdrpStrDup("WWLLN");
      tt->enum_def.fields[8].val = WWLLN;
      tt->enum_def.fields[9].name = tdrpStrDup("NAPLN");
      tt->enum_def.fields[9].val = NAPLN;
      tt->enum_def.fields[10].name = tdrpStrDup("NLDN_BINARY");
      tt->enum_def.fields[10].val = NLDN_BINARY;
      tt->enum_def.fields[11].name = tdrpStrDup("AOAWS_NETCDF");
      tt->enum_def.fields[11].val = AOAWS_NETCDF;
      tt->enum_def.fields[12].name = tdrpStrDup("KSC");
      tt->enum_def.fields[12].val = KSC;
    tt->single_val.e = FORMAT_1;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL for decoded metars.");
    tt->help = tdrpStrDup("Example of full URL: spdbp:://localhost::spdb/ltg. If the dir does not start with . or / it is stored relative to $DATA_DIR.");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdb/ltg");
    tt++;
    
    // Parameter 'expire_seconds'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("expire_seconds");
    tt->descr = tdrpStrDup("Expire time in seconds for each strike");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &expire_seconds - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'bufferingPeriod'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("bufferingPeriod");
    tt->descr = tdrpStrDup("Buffering period, seconds.");
    tt->help = tdrpStrDup("Setting to one second effectively disables buffering.");
    tt->val_offset = (char *) &bufferingPeriod - &_start_;
    tt->single_val.i = 30;
    tt++;
    
    // Parameter 'flush_buffer_per_file'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("flush_buffer_per_file");
    tt->descr = tdrpStrDup("If TRUE, data write will be forced at end of each file.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &flush_buffer_per_file - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'put_mode'
    // ctype is '_put_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("put_mode");
    tt->descr = tdrpStrDup("Put mode for SPDB data base.");
    tt->help = tdrpStrDup("PUT_OVER - new data will overwrite a previously-stored data for the same time. PUT_ADD: a chunk will be added to the list of chunks stored at a given valid_time. PUT_ADD_UNIQUE: a chunk will be added to the list of data stored at a given valid_time, provided identical data has not already been added. PUT_ONCE: you can only put data for a given time once. Trying to put at the same valid_time again will generate an error. ");
    tt->val_offset = (char *) &put_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("put_mode_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("PUT_OVER");
      tt->enum_def.fields[0].val = PUT_OVER;
      tt->enum_def.fields[1].name = tdrpStrDup("PUT_ADD");
      tt->enum_def.fields[1].val = PUT_ADD;
      tt->enum_def.fields[2].name = tdrpStrDup("PUT_ADD_UNIQUE");
      tt->enum_def.fields[2].val = PUT_ADD_UNIQUE;
      tt->enum_def.fields[3].name = tdrpStrDup("PUT_ONCE");
      tt->enum_def.fields[3].val = PUT_ONCE;
    tt->single_val.e = PUT_OVER;
    tt++;
    
    // Parameter 'delay_after_write'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("delay_after_write");
    tt->descr = tdrpStrDup("Sleep time after writing, millisecs.");
    tt->help = tdrpStrDup("Use to prevent data distribution problems.");
    tt->val_offset = (char *) &delay_after_write - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'delay_before_processing'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("delay_before_processing");
    tt->descr = tdrpStrDup("Sleep time before processing file, secs.");
    tt->help = tdrpStrDup("Use to prevent data being processed prematurely.");
    tt->val_offset = (char *) &delay_before_processing - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'duplicates'
    // ctype is '_dup_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("duplicates");
    tt->descr = tdrpStrDup("Option to filter out near duplicate types and\nparameters to do so.");
    tt->help = tdrpStrDup("Set check to TRUE to perform this check. It is assumed that the strokes come in in temporal order. If time_millisec is set to TRUE, then maxTime and maxFlashDuration are assumed to be in milliseconds. If time_millisec is FALSE then maxTime and maxFlashDuration are assumed to be in seconds. If a stroke is spatially within maxDist (Km), and temporally within maxTime (seconds or milliseconds) of the previous stroke, and the number of strokes is less than or equal to maxCount, and the flash duration is less than or equal to the maxFlashDuration, then the stroke will be seen as a near duplicate and will be rejected.\n");
    tt->val_offset = (char *) &duplicates - &_start_;
    tt->struct_def.name = tdrpStrDup("dup_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[0].fname = tdrpStrDup("check");
      tt->struct_def.fields[0].ptype = BOOL_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &duplicates.check - (char *) &duplicates;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("maxDist");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &duplicates.maxDist - (char *) &duplicates;
      tt->struct_def.fields[2].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[2].fname = tdrpStrDup("time_millisec");
      tt->struct_def.fields[2].ptype = BOOL_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &duplicates.time_millisec - (char *) &duplicates;
      tt->struct_def.fields[3].ftype = tdrpStrDup("int");
      tt->struct_def.fields[3].fname = tdrpStrDup("maxTime");
      tt->struct_def.fields[3].ptype = INT_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &duplicates.maxTime - (char *) &duplicates;
      tt->struct_def.fields[4].ftype = tdrpStrDup("int");
      tt->struct_def.fields[4].fname = tdrpStrDup("maxFlashDuration");
      tt->struct_def.fields[4].ptype = INT_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &duplicates.maxFlashDuration - (char *) &duplicates;
      tt->struct_def.fields[5].ftype = tdrpStrDup("int");
      tt->struct_def.fields[5].fname = tdrpStrDup("maxCount");
      tt->struct_def.fields[5].ptype = INT_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &duplicates.maxCount - (char *) &duplicates;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].b = pFALSE;
      tt->struct_vals[1].d = 1;
      tt->struct_vals[2].b = pFALSE;
      tt->struct_vals[3].i = 1;
      tt->struct_vals[4].i = 200;
      tt->struct_vals[5].i = 100;
    tt++;
    
    // Parameter 'dup_check_cg_only'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("dup_check_cg_only");
    tt->descr = tdrpStrDup("Option to apply duplicates check to cg strikes only, not cc.");
    tt->help = tdrpStrDup("May be useful.");
    tt->val_offset = (char *) &dup_check_cg_only - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'netcdf_lat_var'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("netcdf_lat_var");
    tt->descr = tdrpStrDup("Variable name for latitude in netcdf input files.");
    tt->help = tdrpStrDup("Ignored unless input_format is AOAWS_NETCDF.");
    tt->val_offset = (char *) &netcdf_lat_var - &_start_;
    tt->single_val.s = tdrpStrDup("lat");
    tt++;
    
    // Parameter 'netcdf_lon_var'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("netcdf_lon_var");
    tt->descr = tdrpStrDup("Variable name for longitude in netcdf input files.");
    tt->help = tdrpStrDup("Ignored unless input_format is AOAWS_NETCDF.");
    tt->val_offset = (char *) &netcdf_lon_var - &_start_;
    tt->single_val.s = tdrpStrDup("lon");
    tt++;
    
    // Parameter 'netcdf_time_var'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("netcdf_time_var");
    tt->descr = tdrpStrDup("Variable name for strike times in netcdf input files.");
    tt->help = tdrpStrDup("Ignored unless input_format is AOAWS_NETCDF.");
    tt->val_offset = (char *) &netcdf_time_var - &_start_;
    tt->single_val.s = tdrpStrDup("time");
    tt++;
    
    // Parameter 'netcdf_strike_num_dim'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("netcdf_strike_num_dim");
    tt->descr = tdrpStrDup("Dimension name for number of entries in netcdf input files.");
    tt->help = tdrpStrDup("Ignored unless input_format is AOAWS_NETCDF.");
    tt->val_offset = (char *) &netcdf_strike_num_dim - &_start_;
    tt->single_val.s = tdrpStrDup("strikeNum");
    tt++;
    
    // Parameter 'ksc_event'
    // ctype is '_ksc_event_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("ksc_event");
    tt->descr = tdrpStrDup("Report type to be decoded for KSC lightning file");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &ksc_event - &_start_;
    tt->enum_def.name = tdrpStrDup("ksc_event_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("KSC_LDAR_EVENT");
      tt->enum_def.fields[0].val = KSC_LDAR_EVENT;
      tt->enum_def.fields[1].name = tdrpStrDup("KSC_4DLSS_EVENT");
      tt->enum_def.fields[1].val = KSC_4DLSS_EVENT;
      tt->enum_def.fields[2].name = tdrpStrDup("KSC_GGLSS_EVENT");
      tt->enum_def.fields[2].val = KSC_GGLSS_EVENT;
      tt->enum_def.fields[3].name = tdrpStrDup("KSC_CAL_EVENT");
      tt->enum_def.fields[3].val = KSC_CAL_EVENT;
    tt->single_val.e = KSC_4DLSS_EVENT;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
