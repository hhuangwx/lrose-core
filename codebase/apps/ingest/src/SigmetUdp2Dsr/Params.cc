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
// Code for program SigmetUdp2Dsr
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
    tt->comment_hdr = tdrpStrDup("SigmetUdp2Dsr reads Sigmet moments data from UDP and writes the contents into a DsRadar FMQ.");
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
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'udp_port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("udp_port");
    tt->descr = tdrpStrDup("Port number for UDP input.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &udp_port - &_start_;
    tt->single_val.i = 30730;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("RADAR PARAMS");
    tt->comment_text = tdrpStrDup("If any of the params are set in the input data files, the values in those params will be taken from the input data stream rather than from the parameter file.");
    tt++;
    
    // Parameter 'radar'
    // ctype is '_radar_params_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("radar");
    tt->descr = tdrpStrDup("Default radar params. If any of the params are set in the input data files, the values in those params will be taken from the input data stream rather than from the parameter file.");
    tt->help = tdrpStrDup("========== Radar params ==========\n\t\npolarization: polarization type\naltitude: km\nlatitude: degrees\nlongitude: degrees\nhoriz_beam_width: half-power beam width - degrees\nvert_beam_width: half-power beam width - degrees\npulse_width: micro-secs\nradar_constant: dB\nxmit_peak_pwr: watts\nreceiver_mds: dBm\nreceiver_gain: dB\nantenna_gain: dB\nsystem_gain: dB\nnoise_value: dBM - system noise\nmin_dbz_at_1km: dBZ - min detectable dBZ at 1km range\n\t\n");
    tt->val_offset = (char *) &radar - &_start_;
    tt->struct_def.name = tdrpStrDup("radar_params_t");
    tt->struct_def.nfields = 16;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("radar_id");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &radar.radar_id - (char *) &radar;
      tt->struct_def.fields[1].ftype = tdrpStrDup("polar_t");
      tt->struct_def.fields[1].fname = tdrpStrDup("polarization");
      tt->struct_def.fields[1].ptype = ENUM_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &radar.polarization - (char *) &radar;
        tt->struct_def.fields[1].enum_def.name = tdrpStrDup("polar_t");
        tt->struct_def.fields[1].enum_def.nfields = 4;
        tt->struct_def.fields[1].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[1].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[1].enum_def.fields[0].name = tdrpStrDup("HORIZONTAL");
        tt->struct_def.fields[1].enum_def.fields[0].val = HORIZONTAL;
        tt->struct_def.fields[1].enum_def.fields[1].name = tdrpStrDup("VERTICAL");
        tt->struct_def.fields[1].enum_def.fields[1].val = VERTICAL;
        tt->struct_def.fields[1].enum_def.fields[2].name = tdrpStrDup("CIRCULAR");
        tt->struct_def.fields[1].enum_def.fields[2].val = CIRCULAR;
        tt->struct_def.fields[1].enum_def.fields[3].name = tdrpStrDup("ELLIPTICAL");
        tt->struct_def.fields[1].enum_def.fields[3].val = ELLIPTICAL;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("altitude");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &radar.altitude - (char *) &radar;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("latitude");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &radar.latitude - (char *) &radar;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("longitude");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &radar.longitude - (char *) &radar;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("horiz_beam_width");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &radar.horiz_beam_width - (char *) &radar;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("vert_beam_width");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &radar.vert_beam_width - (char *) &radar;
      tt->struct_def.fields[7].ftype = tdrpStrDup("double");
      tt->struct_def.fields[7].fname = tdrpStrDup("pulse_width");
      tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &radar.pulse_width - (char *) &radar;
      tt->struct_def.fields[8].ftype = tdrpStrDup("double");
      tt->struct_def.fields[8].fname = tdrpStrDup("radar_constant");
      tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &radar.radar_constant - (char *) &radar;
      tt->struct_def.fields[9].ftype = tdrpStrDup("double");
      tt->struct_def.fields[9].fname = tdrpStrDup("xmit_peak_pwr");
      tt->struct_def.fields[9].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[9].rel_offset = 
        (char *) &radar.xmit_peak_pwr - (char *) &radar;
      tt->struct_def.fields[10].ftype = tdrpStrDup("double");
      tt->struct_def.fields[10].fname = tdrpStrDup("receiver_mds");
      tt->struct_def.fields[10].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[10].rel_offset = 
        (char *) &radar.receiver_mds - (char *) &radar;
      tt->struct_def.fields[11].ftype = tdrpStrDup("double");
      tt->struct_def.fields[11].fname = tdrpStrDup("receiver_gain");
      tt->struct_def.fields[11].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[11].rel_offset = 
        (char *) &radar.receiver_gain - (char *) &radar;
      tt->struct_def.fields[12].ftype = tdrpStrDup("double");
      tt->struct_def.fields[12].fname = tdrpStrDup("antenna_gain");
      tt->struct_def.fields[12].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[12].rel_offset = 
        (char *) &radar.antenna_gain - (char *) &radar;
      tt->struct_def.fields[13].ftype = tdrpStrDup("double");
      tt->struct_def.fields[13].fname = tdrpStrDup("system_gain");
      tt->struct_def.fields[13].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[13].rel_offset = 
        (char *) &radar.system_gain - (char *) &radar;
      tt->struct_def.fields[14].ftype = tdrpStrDup("double");
      tt->struct_def.fields[14].fname = tdrpStrDup("noise_value");
      tt->struct_def.fields[14].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[14].rel_offset = 
        (char *) &radar.noise_value - (char *) &radar;
      tt->struct_def.fields[15].ftype = tdrpStrDup("double");
      tt->struct_def.fields[15].fname = tdrpStrDup("min_dbz_at_1km");
      tt->struct_def.fields[15].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[15].rel_offset = 
        (char *) &radar.min_dbz_at_1km - (char *) &radar;
    tt->n_struct_vals = 16;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 0;
      tt->struct_vals[1].e = HORIZONTAL;
      tt->struct_vals[2].d = 1.742;
      tt->struct_vals[3].d = 39.9321;
      tt->struct_vals[4].d = -105.182;
      tt->struct_vals[5].d = 0.91;
      tt->struct_vals[6].d = 0.91;
      tt->struct_vals[7].d = 1;
      tt->struct_vals[8].d = 70.1652;
      tt->struct_vals[9].d = 8e+06;
      tt->struct_vals[10].d = -113;
      tt->struct_vals[11].d = 46.05;
      tt->struct_vals[12].d = 45.2;
      tt->struct_vals[13].d = 46.05;
      tt->struct_vals[14].d = -110;
      tt->struct_vals[15].d = -42;
    tt++;
    
    // Parameter 'scan_type_id'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("scan_type_id");
    tt->descr = tdrpStrDup("Scan type id");
    tt->help = tdrpStrDup("Unique identifier for scan strategy");
    tt->val_offset = (char *) &scan_type_id - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'scan_type_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("scan_type_name");
    tt->descr = tdrpStrDup("Scan type name");
    tt->help = tdrpStrDup("Descriptive name for scan strategy");
    tt->val_offset = (char *) &scan_type_name - &_start_;
    tt->single_val.s = tdrpStrDup("Surveillance");
    tt++;
    
    // Parameter 'samples_per_beam'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("samples_per_beam");
    tt->descr = tdrpStrDup("Number of IQ samples per beam.");
    tt->help = tdrpStrDup("Number of samples from which moments are computed.");
    tt->val_offset = (char *) &samples_per_beam - &_start_;
    tt->single_val.i = 64;
    tt++;
    
    // Parameter 'check_task_name'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("check_task_name");
    tt->descr = tdrpStrDup("Option to check the task name.");
    tt->help = tdrpStrDup("If TRUE, only data packets with the specified task name will be processed. If FALSE, all task names will be accepted.");
    tt->val_offset = (char *) &check_task_name - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'task_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("task_name");
    tt->descr = tdrpStrDup("Specified task name");
    tt->help = tdrpStrDup("See 'check_task_name'");
    tt->val_offset = (char *) &task_name - &_start_;
    tt->single_val.s = tdrpStrDup("VOL_SCAN");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("TIME CORRECTION OPTION");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'time_correction_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("time_correction_secs");
    tt->descr = tdrpStrDup("Correction to input data times.");
    tt->help = tdrpStrDup("This correction is added to the incoming data times, to give the output beam times. This can be used to (a) correct times when it is known that there is a time error or (b) convert local time to UTC.");
    tt->val_offset = (char *) &time_correction_secs - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("OUTPUT DsRadar FMQ");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_fmq_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_url");
    tt->descr = tdrpStrDup("Output URL for DsRadar data via FMQ");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_fmq_url - &_start_;
    tt->single_val.s = tdrpStrDup("fmqp:://$(HOST)::fmq/dsRadar");
    tt++;
    
    // Parameter 'output_fmq_size'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_size");
    tt->descr = tdrpStrDup("Size of output FMQ, in bytes.");
    tt->help = tdrpStrDup("This is the total size of the output FMQ buffer. Some of this buffer will be used for control bytes (12 bytes per message).");
    tt->val_offset = (char *) &output_fmq_size - &_start_;
    tt->single_val.i = 2000000;
    tt++;
    
    // Parameter 'output_fmq_nslots'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_nslots");
    tt->descr = tdrpStrDup("Number of slots in output FMQ.");
    tt->help = tdrpStrDup("The number of slots corresponds to the maximum number of messages which may be written to the buffer before overwrites occur. However, overwrites may occur sooner if the size is not set large enough.");
    tt->val_offset = (char *) &output_fmq_nslots - &_start_;
    tt->single_val.i = 3600;
    tt++;
    
    // Parameter 'output_fmq_compress'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_fmq_compress");
    tt->descr = tdrpStrDup("FMQ compression option.");
    tt->help = tdrpStrDup("If TRUE FMQ messages are compressed.");
    tt->val_offset = (char *) &output_fmq_compress - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'write_blocking'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_blocking");
    tt->descr = tdrpStrDup("Option to set up the FMQ as blocking.");
    tt->help = tdrpStrDup("If TRUE, FMQ will be set up FMQ for blocking operation. If the FMQ becomes full, Test2Dsr will then block until there is space for more data.");
    tt->val_offset = (char *) &write_blocking - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'beam_wait_msecs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("beam_wait_msecs");
    tt->descr = tdrpStrDup("Wait per beam (milli-secs)");
    tt->help = tdrpStrDup("ARCHIVE and SIMULATE modes only.");
    tt->val_offset = (char *) &beam_wait_msecs - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'set_end_of_vol_flag'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_end_of_vol_flag");
    tt->descr = tdrpStrDup("Option to set the end of volume flag in the FMQ.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &set_end_of_vol_flag - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'volume_starts_at_bottom'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("volume_starts_at_bottom");
    tt->descr = tdrpStrDup("Flag to indicate that elevation angles increase in the volume.");
    tt->help = tdrpStrDup("If the volume starts at the top, i.e. elevations decrease during the volume, set this to FALSE.");
    tt->val_offset = (char *) &volume_starts_at_bottom - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'el_change_for_end_of_vol'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("el_change_for_end_of_vol");
    tt->descr = tdrpStrDup("Change in elevation which triggers and end of volume.");
    tt->help = tdrpStrDup("If the elevation angle changes by this amount, and end of volume flag will be set.");
    tt->val_offset = (char *) &el_change_for_end_of_vol - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0.1;
    tt->single_val.d = 1.5;
    tt++;
    
    // Parameter 'min_beams_per_vol'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_beams_per_vol");
    tt->descr = tdrpStrDup("Min number of beams per volume.");
    tt->help = tdrpStrDup("Used to prevent end-of-volume conditions being determined during antenna transition to the start of the next volume.");
    tt->val_offset = (char *) &min_beams_per_vol - &_start_;
    tt->single_val.i = 360;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
