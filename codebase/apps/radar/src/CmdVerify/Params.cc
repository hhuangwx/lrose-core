// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2015
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Research Applications Laboratory(RAL)
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
// ** See LICENCE.TXT if applicable for licence details
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program CmdVerify
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
    tt->comment_hdr = tdrpStrDup("Reads CMD data from CfRadial files, containing (a) weather only, (b) clutter only, (c) merged. Verifies the performance of CMD against the known truthiness. Also writes data out to ASCII file in column format, for analysis by other apps.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING");
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
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In ARCHIVE mode, it moves through the data between the start and end times set on the command line. In FILELIST mode, it moves through the list of file names specified on the command line. Paths (in FILELIST mode, at least) MUST contain a day-directory below the data file -- ./data_file.ext will not work as a file path");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[1].val = FILELIST;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Input directory path.");
    tt->help = tdrpStrDup("Applies to ARCHIVE mode only.");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./input");
    tt++;
    
    // Parameter 'start_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("start_time");
    tt->descr = tdrpStrDup("Start time for reading data.");
    tt->help = tdrpStrDup("Applies to ARCHIVE mode only.");
    tt->val_offset = (char *) &start_time - &_start_;
    tt->single_val.s = tdrpStrDup("2014 05 20 20 00 00");
    tt++;
    
    // Parameter 'end_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("end_time");
    tt->descr = tdrpStrDup("Start time for reading data.");
    tt->help = tdrpStrDup("Applies to ARCHIVE mode only.");
    tt->val_offset = (char *) &end_time - &_start_;
    tt->single_val.s = tdrpStrDup("2014 05 20 22 00 00");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("READ OPTIONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'set_max_range'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_max_range");
    tt->descr = tdrpStrDup("Option to set the max range for any ray.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &set_max_range - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'max_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_range_km");
    tt->descr = tdrpStrDup("Specified maximim range - km.");
    tt->help = tdrpStrDup("Gates beyond this range are removed.");
    tt->val_offset = (char *) &max_range_km - &_start_;
    tt->single_val.d = 9999;
    tt++;
    
    // Parameter 'set_ngates_constant'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_ngates_constant");
    tt->descr = tdrpStrDup("Option to force the number of gates to be constant.");
    tt->help = tdrpStrDup("If TRUE, the number of gates on all rays will be set to the maximum, and gates added to shorter rays will be filled with missing values.");
    tt->val_offset = (char *) &set_ngates_constant - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("OPTION TO SPECIFY OUTPUT FIELD NAMES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'set_output_fields'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_output_fields");
    tt->descr = tdrpStrDup("Set the field names for output");
    tt->help = tdrpStrDup("If false, all fields will be used.");
    tt->val_offset = (char *) &set_output_fields - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'output_field_names'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_field_names");
    tt->descr = tdrpStrDup("Names of output fields to be written");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_output_field_names - &_start_;
    tt->array_n_offset = (char *) &output_field_names_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 69;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("DBZ_WX");
      tt->array_vals[1].s = tdrpStrDup("VEL_WX");
      tt->array_vals[2].s = tdrpStrDup("WIDTH_WX");
      tt->array_vals[3].s = tdrpStrDup("CLUT_WX");
      tt->array_vals[4].s = tdrpStrDup("ZDR_WX");
      tt->array_vals[5].s = tdrpStrDup("RHOHV_WX");
      tt->array_vals[6].s = tdrpStrDup("PHIDP_WX");
      tt->array_vals[7].s = tdrpStrDup("SNRHC_WX");
      tt->array_vals[8].s = tdrpStrDup("SNRVC_WX");
      tt->array_vals[9].s = tdrpStrDup("DBMHC_WX");
      tt->array_vals[10].s = tdrpStrDup("DBMVC_WX");
      tt->array_vals[11].s = tdrpStrDup("NCP_WX");
      tt->array_vals[12].s = tdrpStrDup("CPA_WX");
      tt->array_vals[13].s = tdrpStrDup("TDBZ_WX");
      tt->array_vals[14].s = tdrpStrDup("SPIN_WX");
      tt->array_vals[15].s = tdrpStrDup("ZDR_SDEV_WX");
      tt->array_vals[16].s = tdrpStrDup("PHIDP_SDEV_WX");
      tt->array_vals[17].s = tdrpStrDup("CMD_WX");
      tt->array_vals[18].s = tdrpStrDup("CMD_FLAG_WX");
      tt->array_vals[19].s = tdrpStrDup("DBZ_CLUT");
      tt->array_vals[20].s = tdrpStrDup("VEL_CLUT");
      tt->array_vals[21].s = tdrpStrDup("WIDTH_CLUT");
      tt->array_vals[22].s = tdrpStrDup("CLUT_CLUT");
      tt->array_vals[23].s = tdrpStrDup("ZDR_CLUT");
      tt->array_vals[24].s = tdrpStrDup("RHOHV_CLUT");
      tt->array_vals[25].s = tdrpStrDup("PHIDP_CLUT");
      tt->array_vals[26].s = tdrpStrDup("SNRHC_CLUT");
      tt->array_vals[27].s = tdrpStrDup("SNRVC_CLUT");
      tt->array_vals[28].s = tdrpStrDup("DBMHC_CLUT");
      tt->array_vals[29].s = tdrpStrDup("DBMVC_CLUT");
      tt->array_vals[30].s = tdrpStrDup("NCP_CLUT");
      tt->array_vals[31].s = tdrpStrDup("CPA_CLUT");
      tt->array_vals[32].s = tdrpStrDup("TDBZ_CLUT");
      tt->array_vals[33].s = tdrpStrDup("SPIN_CLUT");
      tt->array_vals[34].s = tdrpStrDup("ZDR_SDEV_CLUT");
      tt->array_vals[35].s = tdrpStrDup("PHIDP_SDEV_CLUT");
      tt->array_vals[36].s = tdrpStrDup("CMD_CLUT");
      tt->array_vals[37].s = tdrpStrDup("CMD_FLAG_CLUT");
      tt->array_vals[38].s = tdrpStrDup("DBZ_COMB");
      tt->array_vals[39].s = tdrpStrDup("DBZ_F_COMB");
      tt->array_vals[40].s = tdrpStrDup("VEL_COMB");
      tt->array_vals[41].s = tdrpStrDup("VEL_F_COMB");
      tt->array_vals[42].s = tdrpStrDup("WIDTH_COMB");
      tt->array_vals[43].s = tdrpStrDup("WIDTH_F_COMB");
      tt->array_vals[44].s = tdrpStrDup("CLUT_COMB");
      tt->array_vals[45].s = tdrpStrDup("ZDR_COMB");
      tt->array_vals[46].s = tdrpStrDup("ZDR_F_COMB");
      tt->array_vals[47].s = tdrpStrDup("RHOHV_COMB");
      tt->array_vals[48].s = tdrpStrDup("RHOHV_F_COMB");
      tt->array_vals[49].s = tdrpStrDup("PHIDP_COMB");
      tt->array_vals[50].s = tdrpStrDup("PHIDP_F_COMB");
      tt->array_vals[51].s = tdrpStrDup("SNRHC_COMB");
      tt->array_vals[52].s = tdrpStrDup("SNRHC_F_COMB");
      tt->array_vals[53].s = tdrpStrDup("SNRVC_COMB");
      tt->array_vals[54].s = tdrpStrDup("SNRVC_F_COMB");
      tt->array_vals[55].s = tdrpStrDup("DBMHC_COMB");
      tt->array_vals[56].s = tdrpStrDup("DBMHC_F_COMB");
      tt->array_vals[57].s = tdrpStrDup("DBMVC_COMB");
      tt->array_vals[58].s = tdrpStrDup("DBMVC_F_COMB");
      tt->array_vals[59].s = tdrpStrDup("NCP_COMB");
      tt->array_vals[60].s = tdrpStrDup("NCP_F_COMB");
      tt->array_vals[61].s = tdrpStrDup("CPA_COMB");
      tt->array_vals[62].s = tdrpStrDup("TDBZ_COMB");
      tt->array_vals[63].s = tdrpStrDup("SPIN_COMB");
      tt->array_vals[64].s = tdrpStrDup("ZDR_SDEV_COMB");
      tt->array_vals[65].s = tdrpStrDup("PHIDP_SDEV_COMB");
      tt->array_vals[66].s = tdrpStrDup("CMD_COMB");
      tt->array_vals[67].s = tdrpStrDup("CMD_FLAG_COMB");
      tt->array_vals[68].s = tdrpStrDup("CSR");
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("CENSORING");
    tt->comment_text = tdrpStrDup("You have the option of censoring the data based in input fields - i.e. omitting the data at gates which meet certain criteria.");
    tt++;
    
    // Parameter 'apply_censoring'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("apply_censoring");
    tt->descr = tdrpStrDup("Apply censoring based on field values and thresholds.");
    tt->help = tdrpStrDup("If TRUE, censoring will be performed. See 'censoring_fields' for details on how the censoring is applied.");
    tt->val_offset = (char *) &apply_censoring - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'censoring_fields'
    // ctype is '_censoring_field_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("censoring_fields");
    tt->descr = tdrpStrDup("Fields to be used for censoring.");
    tt->help = tdrpStrDup("Specify the fields to be used to determine whether a gate should be censored. The name refers to the input data field names. Valid field values lie in the range from min_valid_value to max_valid_value inclusive. If the value of a field at a gate lies within this range, it is considered valid. Each specified field is examined at each gate, and is flagged as valid if its value lies in the valid range. These field flags are then combined as follows: first, all of the LOGICAL_OR flags are combined, yielding a single combined_or flag which is true if any of the LOGICAL_OR fields is true. The combined_or flag is then combined with all of the LOGICAL_AND fields, yielding a true value only if the combined_or flag and the LOGICAL_AND fields are all true. If this final flag is true, then the data at the gate is regarded as valid and is retained. If the final flag is false, the data at the gate is censored, and all of the fields at the gate are set to missing.");
    tt->array_offset = (char *) &_censoring_fields - &_start_;
    tt->array_n_offset = (char *) &censoring_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(censoring_field_t);
    tt->array_n = 2;
    tt->struct_def.name = tdrpStrDup("censoring_field_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_censoring_fields->name - (char *) _censoring_fields;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("min_valid_value");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_censoring_fields->min_valid_value - (char *) _censoring_fields;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("max_valid_value");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_censoring_fields->max_valid_value - (char *) _censoring_fields;
      tt->struct_def.fields[3].ftype = tdrpStrDup("logical_t");
      tt->struct_def.fields[3].fname = tdrpStrDup("combination_method");
      tt->struct_def.fields[3].ptype = ENUM_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_censoring_fields->combination_method - (char *) _censoring_fields;
        tt->struct_def.fields[3].enum_def.name = tdrpStrDup("logical_t");
        tt->struct_def.fields[3].enum_def.nfields = 2;
        tt->struct_def.fields[3].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[3].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[3].enum_def.fields[0].name = tdrpStrDup("LOGICAL_AND");
        tt->struct_def.fields[3].enum_def.fields[0].val = LOGICAL_AND;
        tt->struct_def.fields[3].enum_def.fields[1].name = tdrpStrDup("LOGICAL_OR");
        tt->struct_def.fields[3].enum_def.fields[1].val = LOGICAL_OR;
    tt->n_struct_vals = 8;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("CMD_WX");
      tt->struct_vals[1].d = 0;
      tt->struct_vals[2].d = 0.35;
      tt->struct_vals[3].e = LOGICAL_AND;
      tt->struct_vals[4].s = tdrpStrDup("CMD_CLUT");
      tt->struct_vals[5].d = 0.35;
      tt->struct_vals[6].d = 1;
      tt->struct_vals[7].e = LOGICAL_AND;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("SPECIFYING FIELDS TO BE COMBINED");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'add_combined_fields'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("add_combined_fields");
    tt->descr = tdrpStrDup("Option to combine some fields to produce derived fields");
    tt->help = tdrpStrDup("We can combine pairs of fields using simple algorithms. This created derived fields. The fields to be combined must already have been specified as 'output_fields' above.");
    tt->val_offset = (char *) &add_combined_fields - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'combined_fields'
    // ctype is '_combined_field_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("combined_fields");
    tt->descr = tdrpStrDup("Specs of fields to be combined.");
    tt->help = tdrpStrDup("field_name_1 and field_name_2 must be in the output_field_names list, or in the input file if all fields are used. If 'require_both' is TRUE, both fields needs to be non-missing to produce an output field. MEAN: arimthmetic mean. UNBIASED_MEAN: first remove any consistent bias between field1 and field2, by adjusting field2 to field 1. Then compute the arithmetic mean. This reduces noise in the fields without changing the value of field1. GEOM_MEAN: geometric mean. MAX: maximum of the two fields. MIN: minimum of the two fields. SUM: field1 + field2. DIFF: field1 - field2.");
    tt->array_offset = (char *) &_combined_fields - &_start_;
    tt->array_n_offset = (char *) &combined_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(combined_field_t);
    tt->array_n = 2;
    tt->struct_def.name = tdrpStrDup("combined_field_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name_1");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_combined_fields->field_name_1 - (char *) _combined_fields;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("field_name_2");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_combined_fields->field_name_2 - (char *) _combined_fields;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("combined_name");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_combined_fields->combined_name - (char *) _combined_fields;
      tt->struct_def.fields[3].ftype = tdrpStrDup("string");
      tt->struct_def.fields[3].fname = tdrpStrDup("long_name");
      tt->struct_def.fields[3].ptype = STRING_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_combined_fields->long_name - (char *) _combined_fields;
      tt->struct_def.fields[4].ftype = tdrpStrDup("combine_method_t");
      tt->struct_def.fields[4].fname = tdrpStrDup("combine_method");
      tt->struct_def.fields[4].ptype = ENUM_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_combined_fields->combine_method - (char *) _combined_fields;
        tt->struct_def.fields[4].enum_def.name = tdrpStrDup("combine_method_t");
        tt->struct_def.fields[4].enum_def.nfields = 7;
        tt->struct_def.fields[4].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[4].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[4].enum_def.fields[0].name = tdrpStrDup("COMBINE_MEAN");
        tt->struct_def.fields[4].enum_def.fields[0].val = COMBINE_MEAN;
        tt->struct_def.fields[4].enum_def.fields[1].name = tdrpStrDup("COMBINE_UNBIASED_MEAN");
        tt->struct_def.fields[4].enum_def.fields[1].val = COMBINE_UNBIASED_MEAN;
        tt->struct_def.fields[4].enum_def.fields[2].name = tdrpStrDup("COMBINE_GEOM_MEAN");
        tt->struct_def.fields[4].enum_def.fields[2].val = COMBINE_GEOM_MEAN;
        tt->struct_def.fields[4].enum_def.fields[3].name = tdrpStrDup("COMBINE_MAX");
        tt->struct_def.fields[4].enum_def.fields[3].val = COMBINE_MAX;
        tt->struct_def.fields[4].enum_def.fields[4].name = tdrpStrDup("COMBINE_MIN");
        tt->struct_def.fields[4].enum_def.fields[4].val = COMBINE_MIN;
        tt->struct_def.fields[4].enum_def.fields[5].name = tdrpStrDup("COMBINE_SUM");
        tt->struct_def.fields[4].enum_def.fields[5].val = COMBINE_SUM;
        tt->struct_def.fields[4].enum_def.fields[6].name = tdrpStrDup("COMBINE_DIFF");
        tt->struct_def.fields[4].enum_def.fields[6].val = COMBINE_DIFF;
      tt->struct_def.fields[5].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[5].fname = tdrpStrDup("require_both");
      tt->struct_def.fields[5].ptype = BOOL_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_combined_fields->require_both - (char *) _combined_fields;
    tt->n_struct_vals = 12;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("DBZ1");
      tt->struct_vals[1].s = tdrpStrDup("DBZ2");
      tt->struct_vals[2].s = tdrpStrDup("DBZ_MEAN");
      tt->struct_vals[3].s = tdrpStrDup("mean_of_DBZ1_and_DBZ2");
      tt->struct_vals[4].e = COMBINE_MEAN;
      tt->struct_vals[5].b = pTRUE;
      tt->struct_vals[6].s = tdrpStrDup("DBZ1");
      tt->struct_vals[7].s = tdrpStrDup("DBZ2");
      tt->struct_vals[8].s = tdrpStrDup("DBZ_MAX");
      tt->struct_vals[9].s = tdrpStrDup("max_of_DBZ1_and_DBZ2");
      tt->struct_vals[10].e = COMBINE_MAX;
      tt->struct_vals[11].b = pFALSE;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("WRITING OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_table_to_stdout'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_table_to_stdout");
    tt->descr = tdrpStrDup("Write comma-delimited file to standard out.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_table_to_stdout - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'delimiter_string'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("delimiter_string");
    tt->descr = tdrpStrDup("String to use to delimit values in table.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &delimiter_string - &_start_;
    tt->single_val.s = tdrpStrDup(",");
    tt++;
    
    // Parameter 'comment_start_string'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("comment_start_string");
    tt->descr = tdrpStrDup("String to use at start of comments - i.e. label line.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &comment_start_string - &_start_;
    tt->single_val.s = tdrpStrDup("#");
    tt++;
    
    // Parameter 'missing_data_string'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("missing_data_string");
    tt->descr = tdrpStrDup("String to use for missing data values.");
    tt->help = tdrpStrDup("This string will be used to represent missing data in the output.");
    tt->val_offset = (char *) &missing_data_string - &_start_;
    tt->single_val.s = tdrpStrDup("NaN");
    tt++;
    
    // Parameter 'add_col_num_to_col_labels'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("add_col_num_to_col_labels");
    tt->descr = tdrpStrDup("Option to add the column number to the column labels.");
    tt->help = tdrpStrDup("The column number, in parens, will be added to the label. For example, DBZ_WX will become DBZ_WX(11) if this is column index 11. Indices are 0-based.");
    tt->val_offset = (char *) &add_col_num_to_col_labels - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
