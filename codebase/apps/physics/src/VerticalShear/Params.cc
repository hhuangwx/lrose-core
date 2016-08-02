// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Research Applications Laboratory(RAL)
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program VerticalShear
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
    tt->comment_hdr = tdrpStrDup("VerticalShear");
    tt->comment_text = tdrpStrDup("This program calculates the magnitude of vertical shear using the following equation:\n\tsqrt((v(i,j,highest_level_k) - v(i,j,lowest_level_k))**2 +\n\t\t(u(i,j,highest_level_k) - u(i,j,lowest_level_k))**2) /\n\t(lowest_level_height - highest_level_height)");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters controlling debug outputs.");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("debug flag");
    tt->help = tdrpStrDup("Debug flag.");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS PARAMETERS");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("PROCESS I/O PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the input and output locations.");
    tt++;
    
    // Parameter 'trigger_mode'
    // ctype is '_trigger_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("trigger_mode");
    tt->descr = tdrpStrDup("Input triggering mode");
    tt->help = tdrpStrDup("In LATEST_DATA mode, the program waits for new data from the MDV location specified by the latest_data_trigger parameter.\nIn TIME_LIST mode, the program operates on archive data as specified in the time_list_trigger parameter.LOCAL_FILEPATH_REALTIME is a realtime mode used when data resides on the host where the application is running. This was added due to the problems that the latest data server layer had distinguishing data times of data written very close together. ");
    tt->val_offset = (char *) &trigger_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("trigger_mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("LATEST_DATA");
      tt->enum_def.fields[0].val = LATEST_DATA;
      tt->enum_def.fields[1].name = tdrpStrDup("TIME_LIST");
      tt->enum_def.fields[1].val = TIME_LIST;
      tt->enum_def.fields[2].name = tdrpStrDup("LOCAL_FILEPATH_REALTIME");
      tt->enum_def.fields[2].val = LOCAL_FILEPATH_REALTIME;
    tt->single_val.e = LATEST_DATA;
    tt++;
    
    // Parameter 'time_list_trigger'
    // ctype is '_time_list_trigger_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("time_list_trigger");
    tt->descr = tdrpStrDup("Trigger information used when using the TIME_LIST trigger");
    tt->help = tdrpStrDup("start_time specifies the archive start time in any format recognized by the DateTime class.\nend_time specifies the archive end time in any format recognized by the DateTime class.");
    tt->val_offset = (char *) &time_list_trigger - &_start_;
    tt->struct_def.name = tdrpStrDup("time_list_trigger_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("start_time");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &time_list_trigger.start_time - (char *) &time_list_trigger;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("end_time");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &time_list_trigger.end_time - (char *) &time_list_trigger;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("2001/1/1 00:00:00");
      tt->struct_vals[1].s = tdrpStrDup("2002/1/2 00:00:00");
    tt++;
    
    // Parameter 'input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url");
    tt->descr = tdrpStrDup("URL for input files. Note that for mode LOCAL_FILEPATH_REALTIME this is a fully qualified path. ");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::./mdv/derived_ruc");
    tt++;
    
    // Parameter 'use_field_name'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_field_name");
    tt->descr = tdrpStrDup("Flag indicating whether to use the field_name or the field_num field in the input_fields array to identify the input fields.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &use_field_name - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'u_field'
    // ctype is '_input_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("u_field");
    tt->descr = tdrpStrDup("Information identifying the U field in the input file.");
    tt->help = tdrpStrDup("If use_field_name is true, uses the field_name field to identify the input fields.  Otherwise, uses field_num to identify the input fields.");
    tt->val_offset = (char *) &u_field - &_start_;
    tt->struct_def.name = tdrpStrDup("input_info_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &u_field.field_name - (char *) &u_field;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("field_num");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &u_field.field_num - (char *) &u_field;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("U");
      tt->struct_vals[1].l = 0;
    tt++;
    
    // Parameter 'v_field'
    // ctype is '_input_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("v_field");
    tt->descr = tdrpStrDup("Information identifying the V field in the input file.");
    tt->help = tdrpStrDup("If use_field_name is true, uses the field_name field to identify the input fields.  Otherwise, uses field_num to identify the input fields.");
    tt->val_offset = (char *) &v_field - &_start_;
    tt->struct_def.name = tdrpStrDup("input_info_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &v_field.field_name - (char *) &v_field;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("field_num");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &v_field.field_num - (char *) &v_field;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("V");
      tt->struct_vals[1].l = 0;
    tt++;
    
    // Parameter 'pressure_limits'
    // ctype is '_pressure_limits_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("pressure_limits");
    tt->descr = tdrpStrDup("The minimum and maximum pressure levels to process");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &pressure_limits - &_start_;
    tt->struct_def.name = tdrpStrDup("pressure_limits_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("lower_level");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &pressure_limits.lower_level - (char *) &pressure_limits;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("upper_level");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &pressure_limits.upper_level - (char *) &pressure_limits;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 1000;
      tt->struct_vals[1].d = 700;
    tt++;
    
    // Parameter 'max_input_valid_secs'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_input_valid_secs");
    tt->descr = tdrpStrDup("Maximum input valid age in seconds");
    tt->help = tdrpStrDup("Once the algorithm is triggered, it will not use any input data older than this value.");
    tt->val_offset = (char *) &max_input_valid_secs - &_start_;
    tt->single_val.l = 1800;
    tt++;
    
    // Parameter 'remap_grid'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("remap_grid");
    tt->descr = tdrpStrDup("Set to true to remap the data.");
    tt->help = tdrpStrDup("Defaults to false");
    tt->val_offset = (char *) &remap_grid - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'grid_projection'
    // ctype is '_projection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("grid_projection");
    tt->descr = tdrpStrDup("Projection type for remapped grid");
    tt->help = tdrpStrDup("Projections currently supported are PROJ_FLAT, PROJ_LATLON and PROJ_LAMBERT");
    tt->val_offset = (char *) &grid_projection - &_start_;
    tt->enum_def.name = tdrpStrDup("projection_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("PROJ_FLAT");
      tt->enum_def.fields[0].val = PROJ_FLAT;
      tt->enum_def.fields[1].name = tdrpStrDup("PROJ_LATLON");
      tt->enum_def.fields[1].val = PROJ_LATLON;
      tt->enum_def.fields[2].name = tdrpStrDup("PROJ_LAMBERT");
      tt->enum_def.fields[2].val = PROJ_LAMBERT;
    tt->single_val.e = PROJ_FLAT;
    tt++;
    
    // Parameter 'grid_params'
    // ctype is '_grid_params_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("grid_params");
    tt->descr = tdrpStrDup("Grid parameters for remapping in x,y.");
    tt->help = tdrpStrDup("These params apply to all projection types.");
    tt->val_offset = (char *) &grid_params - &_start_;
    tt->struct_def.name = tdrpStrDup("grid_params_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("nx");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &grid_params.nx - (char *) &grid_params;
      tt->struct_def.fields[1].ftype = tdrpStrDup("int");
      tt->struct_def.fields[1].fname = tdrpStrDup("ny");
      tt->struct_def.fields[1].ptype = INT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &grid_params.ny - (char *) &grid_params;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("minx");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &grid_params.minx - (char *) &grid_params;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("miny");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &grid_params.miny - (char *) &grid_params;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("dx");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &grid_params.dx - (char *) &grid_params;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("dy");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &grid_params.dy - (char *) &grid_params;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 812;
      tt->struct_vals[1].i = 485;
      tt->struct_vals[2].d = -99.086;
      tt->struct_vals[3].d = 31.515;
      tt->struct_vals[4].d = 0.038239;
      tt->struct_vals[5].d = 0.035933;
    tt++;
    
    // Parameter 'origin_lat'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("origin_lat");
    tt->descr = tdrpStrDup("Remapped grid origin latitude.");
    tt->help = tdrpStrDup("This applies only to PROJ_FLAT and PROJ_LAMBERT projections.");
    tt->val_offset = (char *) &origin_lat - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'origin_lon'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("origin_lon");
    tt->descr = tdrpStrDup("Remapped grid origin longitude.");
    tt->help = tdrpStrDup("This applies only to PROJ_FLAT and PROJ_LAMBERT projections.");
    tt->val_offset = (char *) &origin_lon - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'flat_rotation'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("flat_rotation");
    tt->descr = tdrpStrDup("Rotation (in degrees) of grid from true north");
    tt->help = tdrpStrDup("Usually 0 - applied to flat earth only");
    tt->val_offset = (char *) &flat_rotation - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = -360;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'lambert_lat1'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("lambert_lat1");
    tt->descr = tdrpStrDup("First true latitude for PROJ_LAMBERT projection.");
    tt->help = tdrpStrDup("Applies only to PROJ_LAMBERT.");
    tt->val_offset = (char *) &lambert_lat1 - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -90;
    tt->max_val.d = 90;
    tt->single_val.d = 25.1;
    tt++;
    
    // Parameter 'lambert_lat2'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("lambert_lat2");
    tt->descr = tdrpStrDup("Second true latitude for PROJ_LAMBERT projection.");
    tt->help = tdrpStrDup("Applies only to PROJ_LAMBERT.");
    tt->val_offset = (char *) &lambert_lat2 - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -90;
    tt->max_val.d = 90;
    tt->single_val.d = 25;
    tt++;
    
    // Parameter 'output_as_forecast'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_as_forecast");
    tt->descr = tdrpStrDup("Set to output the data as forecast in mdv format.");
    tt->help = tdrpStrDup("This forces a forecast-style output, whether the data is of forecast type or not.");
    tt->val_offset = (char *) &output_as_forecast - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::./mdv/output");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
