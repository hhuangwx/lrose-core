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
// Code for program Mdvx2Vil
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
    tt->comment_hdr = tdrpStrDup("Program name: Mdv2Vil");
    tt->comment_text = tdrpStrDup("Computes VIL and related values.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUG AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
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
    
    // Parameter 'Mode'
    // ctype is '_mode'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("Mode");
    tt->descr = tdrpStrDup("Operation mode");
    tt->help = tdrpStrDup("Archive mode automatically invoked by -interval option.");
    tt->val_offset = (char *) &Mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'MaxRealtimeValidAge'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("MaxRealtimeValidAge");
    tt->descr = tdrpStrDup("Maximum valid age for files");
    tt->help = tdrpStrDup("REALTIME mode only.");
    tt->val_offset = (char *) &MaxRealtimeValidAge - &_start_;
    tt->single_val.i = 1800;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("INPUT and OUTPUT DIRECTORIES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'TriggerUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("TriggerUrl");
    tt->descr = tdrpStrDup("URL to trigger off, typically of the form\nmdvp:://host.domain:[port]:dir/dir");
    tt->help = tdrpStrDup("Program runs when new data appear here.");
    tt->val_offset = (char *) &TriggerUrl - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/input");
    tt++;
    
    // Parameter 'OutUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutUrl");
    tt->descr = tdrpStrDup("Output mdv URL, typically of the form\nmdvp:://host.domain:[port]:dir/dir");
    tt->help = tdrpStrDup("Output data are written here.");
    tt->val_offset = (char *) &OutUrl - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/vil");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("COMPUTING VIL");
    tt->comment_text = tdrpStrDup("In this application, VIL is referred to as totalVil, as opposed to the deltaVil product. VIL and totalVil are synonymous.");
    tt++;
    
    // Parameter 'output_totalVil'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_totalVil");
    tt->descr = tdrpStrDup("Output VIL to mdv file");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_totalVil - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'dbz_field'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("dbz_field");
    tt->descr = tdrpStrDup("Reflectivity field name");
    tt->help = tdrpStrDup("Field name of the reflectivity data in the mdv file");
    tt->val_offset = (char *) &dbz_field - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'min_height'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_height");
    tt->descr = tdrpStrDup("Minimum Height (in km)");
    tt->help = tdrpStrDup("Minimum Height from which to calculate VIL");
    tt->val_offset = (char *) &min_height - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("STORM SEVERITY based on DELTA VIL");
    tt->comment_text = tdrpStrDup("DELTA VIL is computed as the VIL above some level (say the -5C level) minus the VIL below that level. Regions in storms with an overhang (echo vault) will show a positive dvil. This is an indicator of a severe storm.");
    tt++;
    
    // Parameter 'output_dVil'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_dVil");
    tt->descr = tdrpStrDup("Output DVIL calculation to mdv file");
    tt->help = tdrpStrDup("DVIL is the difference between the upper mass and lower mass around the specified difference_height");
    tt->val_offset = (char *) &output_dVil - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'difference_height'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("difference_height");
    tt->descr = tdrpStrDup("Height (in km) used for DVIL calculation");
    tt->help = tdrpStrDup("Typically set to the height of the -5 C temperature.");
    tt->val_offset = (char *) &difference_height - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("STORM SEVERITY based on SSS");
    tt->comment_text = tdrpStrDup("Thanks to Pieter Visser of the South African Weather Service. <visser@weathersa.co.za>");
    tt++;
    
    // Parameter 'output_SSS_index'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_SSS_index");
    tt->descr = tdrpStrDup("Output the Storm Severity index calculation to mdv file");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_SSS_index - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("SSS CALCULATION PARAMETERS");
    tt->comment_text = tdrpStrDup("The SSS field is used to partition the grid into the following storm categories:\n\t1 = Weak Base\n\t2 = Weak Volume\n\t3 = Weak Top\n\t4 = Severe Base\n\t5 = Severe Volume\n\t6 = Severe Top\n\t7 = Very Severe Base\n\t8 = Very Severe Volume\n\t9 = Very Severe Top\nThe sss_weak_dbz_max and sss_severe_dbz_max fields are used for classifying each grid square into the 3 different storm severity categories: weak, severe and very severe. Grid points that have a reflectivity value less than the sss_weak_dbz_max parameter are classified as weak. Grid points that have a reflectivity value between the sss_weak_dbz_max parameter and the sss_severe_dbz_max parameter are classified as severe. Grid points that have a reflectivity value greater than the sss_severe_dbz_max parameter are classified as very severe.\nOnce the storm severity is determined, the other parameters are used to classify the type of storm in the following manner:\n\tif (centerMass < sss_base_center_mass_max) then\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight < sss_base_height_max) then\n\t\t\t\tstorm type = base\n\t\tendif\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight >= sss_base_height_max) then\n\t\t\t\tstorm type = volumetric\n\t\tendif\n\t\tif (stdDeviation < sss_std_deviation_limit) then\n\t\t\tstorm type = base\n\t\tendif\n\telse if (centerMass < sss_top_center_mass_min) then\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight < sss_base_height_max) then\n\t\t\t\tstorm type = base\n\t\tendif\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight == sss_base_height_max) then\n\t\t\t\tstorm type = volumetric\n\t\tendif\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight >= sss_top_height_min) then\n\t\t\t\tstorm type = top\n\t\tendif\n\t\tif (stdDeviation < sss_std_deviation_limit) then\n\t\t\tstorm type = volumetric\n\t\tendif\n\telse\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight < sss_top_height_min) then\n\t\t\t\tstorm type = volumetric\n\t\tendif\n\t\tif (stdDeviation >= sss_std_deviation_limit and\n\t\t\tmaxDbzHeight >= sss_top_height_min) then\n\t\t\t\tstorm type = top\n\t\tendif\n\t\tif (stdDeviation < sss_std_deviation_limit) then\n\t\t\tstorm type = top\n\t\tendif\n\tendif\n");
    tt++;
    
    // Parameter 'sss_weak_dbz_max'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_weak_dbz_max");
    tt->descr = tdrpStrDup("Maximum dbz value for storms classified as weak");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_weak_dbz_max - &_start_;
    tt->single_val.d = 45;
    tt++;
    
    // Parameter 'sss_severe_dbz_max'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_severe_dbz_max");
    tt->descr = tdrpStrDup("Maximum dbz value for storms classified as severe");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_severe_dbz_max - &_start_;
    tt->single_val.d = 55;
    tt++;
    
    // Parameter 'sss_std_deviation_limit'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_std_deviation_limit");
    tt->descr = tdrpStrDup("Standard deviation limit used for SSS calculations");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_std_deviation_limit - &_start_;
    tt->single_val.d = 2;
    tt++;
    
    // Parameter 'sss_base_center_mass_max'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_base_center_mass_max");
    tt->descr = tdrpStrDup("Base center mass maximum used for SSS calculations");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_base_center_mass_max - &_start_;
    tt->single_val.d = 6.5;
    tt++;
    
    // Parameter 'sss_top_center_mass_min'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_top_center_mass_min");
    tt->descr = tdrpStrDup("Top center mass minimum used for SSS calculations");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_top_center_mass_min - &_start_;
    tt->single_val.d = 8;
    tt++;
    
    // Parameter 'sss_base_height_max'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_base_height_max");
    tt->descr = tdrpStrDup("Base height maximum used for SSS calculations");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_base_height_max - &_start_;
    tt->single_val.d = 6;
    tt++;
    
    // Parameter 'sss_top_height_min'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sss_top_height_min");
    tt->descr = tdrpStrDup("Top height minimum used for SSS calculations");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sss_top_height_min - &_start_;
    tt->single_val.d = 7;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup(" ------------ GRID PARAMETERS --------\nThese specify the grid on which the\ncomputations will be performed.\nThese are used only if RemapGrid is set\nto TRUE. If RemapGrid is FALSE then it is assumed\nthat the fields are already on the same grid.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'RemapGrid'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("RemapGrid");
    tt->descr = tdrpStrDup("Set to TRUE to remap the data - useful if visible is at\nfour times the resolution of the IR channels.");
    tt->help = tdrpStrDup("Defaults to FALSE");
    tt->val_offset = (char *) &RemapGrid - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'grid_origin_lat'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_origin_lat");
    tt->descr = tdrpStrDup("Latitude of grid origin");
    tt->help = tdrpStrDup("Must be specified.");
    tt->val_offset = (char *) &grid_origin_lat - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -90;
    tt->max_val.d = 90;
    tt->single_val.d = 34;
    tt++;
    
    // Parameter 'grid_origin_lon'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_origin_lon");
    tt->descr = tdrpStrDup("Longitude of grid origin");
    tt->help = tdrpStrDup("Must be specified.");
    tt->val_offset = (char *) &grid_origin_lon - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -180;
    tt->max_val.d = 180;
    tt->single_val.d = -77;
    tt++;
    
    // Parameter 'grid_rotation'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_rotation");
    tt->descr = tdrpStrDup("Rotation (in degrees) of grid from true north");
    tt->help = tdrpStrDup("Usually 0 - applied to flat earth only");
    tt->val_offset = (char *) &grid_rotation - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = -360;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'grid_lat1'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_lat1");
    tt->descr = tdrpStrDup("First true latitude for LAMBERT projection.");
    tt->help = tdrpStrDup("Applies only to LAMBERT.");
    tt->val_offset = (char *) &grid_lat1 - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -90;
    tt->max_val.d = 90;
    tt->single_val.d = 25.1;
    tt++;
    
    // Parameter 'grid_lat2'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_lat2");
    tt->descr = tdrpStrDup("Second true latitude for LAMBERT projection.");
    tt->help = tdrpStrDup("Applies only to LAMBERT.");
    tt->val_offset = (char *) &grid_lat2 - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.d = -90;
    tt->max_val.d = 90;
    tt->single_val.d = 25;
    tt++;
    
    // Parameter 'grid_projection'
    // ctype is '_projection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("grid_projection");
    tt->descr = tdrpStrDup("Projection type of grid");
    tt->help = tdrpStrDup("Projections currently supported are FLAT, LATLON and LAMBERT");
    tt->val_offset = (char *) &grid_projection - &_start_;
    tt->enum_def.name = tdrpStrDup("projection_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("FLAT");
      tt->enum_def.fields[0].val = FLAT;
      tt->enum_def.fields[1].name = tdrpStrDup("LATLON");
      tt->enum_def.fields[1].val = LATLON;
      tt->enum_def.fields[2].name = tdrpStrDup("LAMBERT");
      tt->enum_def.fields[2].val = LAMBERT;
    tt->single_val.e = FLAT;
    tt++;
    
    // Parameter 'grid_nx'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("grid_nx");
    tt->descr = tdrpStrDup("Number of cells in the grid in X");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_nx - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 100;
    tt++;
    
    // Parameter 'grid_ny'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("grid_ny");
    tt->descr = tdrpStrDup("Number of cells in the grid in Y");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_ny - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 100;
    tt++;
    
    // Parameter 'grid_dx'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dx");
    tt->descr = tdrpStrDup("Size of the cells in the output grid in X");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_dx - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_dy'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dy");
    tt->descr = tdrpStrDup("Size of the cells in the output grid in Y");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_dy - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_minx'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_minx");
    tt->descr = tdrpStrDup("X at grid's lower left corner");
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection.");
    tt->val_offset = (char *) &grid_minx - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'grid_miny'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_miny");
    tt->descr = tdrpStrDup("Y at grid's lower left corner");
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection.");
    tt->val_offset = (char *) &grid_miny - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'Comment 8'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 8");
    tt->comment_hdr = tdrpStrDup("------ End of grid parameters. ");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
