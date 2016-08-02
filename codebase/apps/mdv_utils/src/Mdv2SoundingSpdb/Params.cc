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
// Code for program Mdv2SoundingSpdb
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
    tt->comment_hdr = tdrpStrDup("Mdv2SoundingSpdb reads MDV Cartesian grid files, samples the data at an array of specified points, loads the data as a sounding and writes the soundings to SPDB.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUG AND PROCESS CONTROL");
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
    
    // Parameter 'procmap_register_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("procmap_register_interval");
    tt->descr = tdrpStrDup("Interval for registering with procmap (secs)");
    tt->help = tdrpStrDup("Sometime this app will spend a long time writing the netCDF file, since compression can be quite time-consuming. Setting this to longer than 60 secs (say 180) gives the app more time to complete its work. The auto-restarter will restart any app which has not registered for twice the length of the register interval.");
    tt->val_offset = (char *) &procmap_register_interval - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Input directory");
    tt->help = tdrpStrDup("Path of input directory");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./input");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operational mode");
    tt->help = tdrpStrDup("REALTIME: - waits for new data. ARCHIVE: uses start and end times. FILELIST: processes specified file list");
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
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max age of input data");
    tt->help = tdrpStrDup("REALTIME mode only. Max age of input data for it to be valid");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 0;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'latest_data_info_avail'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("latest_data_info_avail");
    tt->descr = tdrpStrDup("Use _latest_data_info files to decide when new data has arrived.");
    tt->help = tdrpStrDup("REALTIME mode only. If false, the directory input_dir is scanned for new files.");
    tt->val_offset = (char *) &latest_data_info_avail - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("INPUT DATA FIELD NAMES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'temp_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("temp_field_name");
    tt->descr = tdrpStrDup("Name of temperature field");
    tt->help = tdrpStrDup("Set to empty string if no temperature field");
    tt->val_offset = (char *) &temp_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Temp");
    tt++;
    
    // Parameter 'temp_units_are_kelvin'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("temp_units_are_kelvin");
    tt->descr = tdrpStrDup("Set to TRUE if temperature is in Kelvin.");
    tt->help = tdrpStrDup("If false, temps are in Celsius. Also applies to dew-pt.");
    tt->val_offset = (char *) &temp_units_are_kelvin - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'rh_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("rh_field_name");
    tt->descr = tdrpStrDup("Name of relative humidity field.");
    tt->help = tdrpStrDup("Set to empty string if no RH field is available");
    tt->val_offset = (char *) &rh_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("RH");
    tt++;
    
    // Parameter 'compute_rh_from_dewpt'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("compute_rh_from_dewpt");
    tt->descr = tdrpStrDup("Set to TRUE to compute relative humidity from dew-pt field.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &compute_rh_from_dewpt - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'dewpt_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("dewpt_field_name");
    tt->descr = tdrpStrDup("Name of dew-pt field.");
    tt->help = tdrpStrDup("Set to empty string if no dew-pt field");
    tt->val_offset = (char *) &dewpt_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Dewpt");
    tt++;
    
    // Parameter 'u_wind_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("u_wind_field_name");
    tt->descr = tdrpStrDup("Name of field for X component of wind.");
    tt->help = tdrpStrDup("Set to empty string if no X component of wind. Assumed to be in m/s.");
    tt->val_offset = (char *) &u_wind_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Uwind");
    tt++;
    
    // Parameter 'v_wind_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("v_wind_field_name");
    tt->descr = tdrpStrDup("Name of field for Y component of wind.");
    tt->help = tdrpStrDup("Set to empty string if no Y component of wind. Assumed to be in m/s.");
    tt->val_offset = (char *) &v_wind_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Vwind");
    tt++;
    
    // Parameter 'w_wind_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("w_wind_field_name");
    tt->descr = tdrpStrDup("Name of field for Z component of wind.");
    tt->help = tdrpStrDup("Set to empty string if no Z component of wind. Assumed to be in m/s.");
    tt->val_offset = (char *) &w_wind_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Wwind");
    tt++;
    
    // Parameter 'pressure_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("pressure_field_name");
    tt->descr = tdrpStrDup("Name of pressure field.");
    tt->help = tdrpStrDup("Set to empty string if no prssure field. Assumed to be in hPa. If this is missing, and the vertical levels are in pressure, the vertical level value will be used.");
    tt->val_offset = (char *) &pressure_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Pressure");
    tt++;
    
    // Parameter 'height_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("height_field_name");
    tt->descr = tdrpStrDup("Name of height field.");
    tt->help = tdrpStrDup("Set to empty string if no height field. Assumed to be in km. If this is missing, and the vertical levels are in km, the vertical level value will be used.");
    tt->val_offset = (char *) &height_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Height");
    tt++;
    
    // Parameter 'heights_are_in_km'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("heights_are_in_km");
    tt->descr = tdrpStrDup("Set to TRUE if height values are in km instead of m.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &heights_are_in_km - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("SAMPLING LOCATIONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'station_locations'
    // ctype is '_station_location_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("station_locations");
    tt->descr = tdrpStrDup("Sampling locations.");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_station_locations - &_start_;
    tt->array_n_offset = (char *) &station_locations_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(station_location_t);
    tt->array_n = 8;
    tt->struct_def.name = tdrpStrDup("station_location_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_station_locations->name - (char *) _station_locations;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("latitude");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_station_locations->latitude - (char *) _station_locations;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("longitude");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_station_locations->longitude - (char *) _station_locations;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("altitudeKm");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_station_locations->altitudeKm - (char *) _station_locations;
    tt->n_struct_vals = 32;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("SPOL");
      tt->struct_vals[1].d = 40.1233;
      tt->struct_vals[2].d = -104.891;
      tt->struct_vals[3].d = 1.55296;
      tt->struct_vals[4].s = tdrpStrDup("CHILL");
      tt->struct_vals[5].d = 40.4464;
      tt->struct_vals[6].d = -104.637;
      tt->struct_vals[7].d = 1.432;
      tt->struct_vals[8].s = tdrpStrDup("KFTG");
      tt->struct_vals[9].d = 39.7866;
      tt->struct_vals[10].d = -104.546;
      tt->struct_vals[11].d = 1.709;
      tt->struct_vals[12].s = tdrpStrDup("KCYS");
      tt->struct_vals[13].d = 41.1519;
      tt->struct_vals[14].d = -104.806;
      tt->struct_vals[15].d = 1.886;
      tt->struct_vals[16].s = tdrpStrDup("KPUX");
      tt->struct_vals[17].d = 38.4595;
      tt->struct_vals[18].d = -104.181;
      tt->struct_vals[19].d = 1.634;
      tt->struct_vals[20].s = tdrpStrDup("KGLD");
      tt->struct_vals[21].d = 39.3667;
      tt->struct_vals[22].d = -101.7;
      tt->struct_vals[23].d = 1.131;
      tt->struct_vals[24].s = tdrpStrDup("KGJX");
      tt->struct_vals[25].d = 39.0622;
      tt->struct_vals[26].d = -108.213;
      tt->struct_vals[27].d = 3.064;
      tt->struct_vals[28].s = tdrpStrDup("PWNE");
      tt->struct_vals[29].d = 40.8712;
      tt->struct_vals[30].d = -104.714;
      tt->struct_vals[31].d = 1.688;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Directory for output data");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::/tmp/spdb/Mdv2SoundingSpdb");
    tt++;
    
    // Parameter 'valid_period_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("valid_period_secs");
    tt->descr = tdrpStrDup("Valid age for sounding data.");
    tt->help = tdrpStrDup("How long until the next sounding is expected?");
    tt->val_offset = (char *) &valid_period_secs - &_start_;
    tt->single_val.i = 43200;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
