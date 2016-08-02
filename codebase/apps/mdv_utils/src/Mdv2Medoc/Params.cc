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
// Code for program Mdv2Medoc
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
    tt->comment_hdr = tdrpStrDup("Mdv2Medoc is a small converter that reads MDV\nformatted gridded data and writes MEDOC data suitable for\ndriving SCIPUFF. At the time of writing, the program\nreads three dimensional data from the MDV file. Two\ndimensional fields can be added, but they are of constant\nvalue and are NOT from the MDV file. Rather, they are specified\nin the parameter file for Mdv2Medoc. This suits our purposes\nfor now, but a future exercise of adding the ability to\nconvert two dimensional MDV data fields to MEDOC as well as\nappending the constant-value two dimensional fields specified\nin the parameter file would be a worthwhile goal.\nNiles Oien March 2005. \n\nConverting two dimensional MDV data fields to MEDOC is now working.\nYan Chen. Oct. 2008.");
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
    
    // Parameter 'TerrainUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("TerrainUrl");
    tt->descr = tdrpStrDup("URL for terrain file.");
    tt->help = tdrpStrDup("Terrain data can be in separate url.");
    tt->val_offset = (char *) &TerrainUrl - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/GLOBAL_STATIC");
    tt++;
    
    // Parameter 'OutDir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutDir");
    tt->descr = tdrpStrDup("Output directory");
    tt->help = tdrpStrDup("Medoc format dara are written here.");
    tt->val_offset = (char *) &OutDir - &_start_;
    tt->single_val.s = tdrpStrDup("Some/Dir/Structure");
    tt++;
    
    // Parameter 'baseName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("baseName");
    tt->descr = tdrpStrDup("Base name.");
    tt->help = tdrpStrDup("Used in the output file name.");
    tt->val_offset = (char *) &baseName - &_start_;
    tt->single_val.s = tdrpStrDup("VDRAS");
    tt++;
    
    // Parameter 'Instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Instance");
    tt->descr = tdrpStrDup("Instance to check in to Procmap with");
    tt->help = tdrpStrDup("Set to something unique.");
    tt->val_offset = (char *) &Instance - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
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
    
    // Parameter 'Debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("Debug");
    tt->descr = tdrpStrDup("Set to print debugging messages.");
    tt->help = tdrpStrDup("Defaults to FALSE");
    tt->val_offset = (char *) &Debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'In3DFieldName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("In3DFieldName");
    tt->descr = tdrpStrDup("Input 3D field names to process.");
    tt->help = tdrpStrDup("Must have matching entry in Out3DFieldName and Out3DUnits arrays.");
    tt->array_offset = (char *) &_In3DFieldName - &_start_;
    tt->array_n_offset = (char *) &In3DFieldName_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 4;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("uwind");
      tt->array_vals[1].s = tdrpStrDup("vwind");
      tt->array_vals[2].s = tdrpStrDup("wwind");
      tt->array_vals[3].s = tdrpStrDup("temp");
    tt++;
    
    // Parameter 'Out3DFieldName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Out3DFieldName");
    tt->descr = tdrpStrDup("Output 3D field names.");
    tt->help = tdrpStrDup("Used in Medoc files.");
    tt->array_offset = (char *) &_Out3DFieldName - &_start_;
    tt->array_n_offset = (char *) &Out3DFieldName_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 4;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("U");
      tt->array_vals[1].s = tdrpStrDup("V");
      tt->array_vals[2].s = tdrpStrDup("W");
      tt->array_vals[3].s = tdrpStrDup("T");
    tt++;
    
    // Parameter 'Out3DUnits'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Out3DUnits");
    tt->descr = tdrpStrDup("Output units for 3D fields.");
    tt->help = tdrpStrDup("Used in Medoc files.");
    tt->array_offset = (char *) &_Out3DUnits - &_start_;
    tt->array_n_offset = (char *) &Out3DUnits_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 4;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("M/S");
      tt->array_vals[1].s = tdrpStrDup("M/S");
      tt->array_vals[2].s = tdrpStrDup("M/S");
      tt->array_vals[3].s = tdrpStrDup("C");
    tt++;
    
    // Parameter 'In2DFieldName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("In2DFieldName");
    tt->descr = tdrpStrDup("Input 2D field names to process.");
    tt->help = tdrpStrDup("Must have matching entry in Out2DFieldName and Out2DUnits arrays.");
    tt->array_offset = (char *) &_In2DFieldName - &_start_;
    tt->array_n_offset = (char *) &In2DFieldName_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("pbl_hgt");
      tt->array_vals[1].s = tdrpStrDup("shflux");
    tt++;
    
    // Parameter 'Out2DFieldName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Out2DFieldName");
    tt->descr = tdrpStrDup("Output 2D field names.");
    tt->help = tdrpStrDup("Used in Medoc files.");
    tt->array_offset = (char *) &_Out2DFieldName - &_start_;
    tt->array_n_offset = (char *) &Out2DFieldName_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("PBL_HITE");
      tt->array_vals[1].s = tdrpStrDup("SFC_HTFX");
    tt++;
    
    // Parameter 'Out2DUnits'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Out2DUnits");
    tt->descr = tdrpStrDup("Output units for 2D fields.");
    tt->help = tdrpStrDup("Used in Medoc files.");
    tt->array_offset = (char *) &_Out2DUnits - &_start_;
    tt->array_n_offset = (char *) &Out2DUnits_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("M");
      tt->array_vals[1].s = tdrpStrDup("W/M2");
    tt++;
    
    // Parameter 'InTerrainName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("InTerrainName");
    tt->descr = tdrpStrDup("Input terrain field name.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &InTerrainName - &_start_;
    tt->single_val.s = tdrpStrDup("terrain");
    tt++;
    
    // Parameter 'OutTerrainName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutTerrainName");
    tt->descr = tdrpStrDup("Output terrain field name.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &OutTerrainName - &_start_;
    tt->single_val.s = tdrpStrDup("TOPO");
    tt++;
    
    // Parameter 'OutTerrainUnits'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutTerrainUnits");
    tt->descr = tdrpStrDup("Output units for terrain.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &OutTerrainUnits - &_start_;
    tt->single_val.s = tdrpStrDup("M");
    tt++;
    
    // Parameter 'overrideMdvLatLon'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("overrideMdvLatLon");
    tt->descr = tdrpStrDup("Option to override lat, lon from MDV file.");
    tt->help = tdrpStrDup("Can be useful with SCIPUFF.");
    tt->val_offset = (char *) &overrideMdvLatLon - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'lat'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("lat");
    tt->descr = tdrpStrDup("Latitude to use if override option is invoked.");
    tt->help = tdrpStrDup("Relevant only if overrideLatLon is TRUE.");
    tt->val_offset = (char *) &lat - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'lon'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("lon");
    tt->descr = tdrpStrDup("Longitude to use if override option is invoked.");
    tt->help = tdrpStrDup("Relevant only if overrideLatLon is TRUE.");
    tt->val_offset = (char *) &lon - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'two_d_variables'
    // ctype is '_two_d_variable_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("two_d_variables");
    tt->descr = tdrpStrDup("Array of two dimensional constant variables to output.");
    tt->help = tdrpStrDup("Useful for working with SCIPUFF.");
    tt->array_offset = (char *) &_two_d_variables - &_start_;
    tt->array_n_offset = (char *) &two_d_variables_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(two_d_variable_t);
    tt->array_n = 4;
    tt->struct_def.name = tdrpStrDup("two_d_variable_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_two_d_variables->name - (char *) _two_d_variables;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("units");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_two_d_variables->units - (char *) _two_d_variables;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("value");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_two_d_variables->value - (char *) _two_d_variables;
    tt->n_struct_vals = 12;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("TOPO");
      tt->struct_vals[1].s = tdrpStrDup("METERS");
      tt->struct_vals[2].d = 0;
      tt->struct_vals[3].s = tdrpStrDup("HFLUX");
      tt->struct_vals[4].s = tdrpStrDup("C-M/S");
      tt->struct_vals[5].d = 0.24;
      tt->struct_vals[6].s = tdrpStrDup("ZI");
      tt->struct_vals[7].s = tdrpStrDup("M");
      tt->struct_vals[8].d = 1200;
      tt->struct_vals[9].s = tdrpStrDup("ZRUF");
      tt->struct_vals[10].s = tdrpStrDup("M");
      tt->struct_vals[11].d = 0.16;
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup(" ------------ GRID PARAMETERS --------\nThese specify the grid on which the\ncomputations will be performed.\nThese are used only if RemapGrid is set\nto TRUE. If RemapGrid is FALSE then it is assumed\nthat the fields are already on the same grid.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'RemapGrid'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("RemapGrid");
    tt->descr = tdrpStrDup("Set to TRUE to remap the data.");
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
    tt->help = tdrpStrDup("Must be specified. Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Must be specified. Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Usually 0 - applied to flat earth only. Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Applies only to LAMBERT. Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Applies only to LAMBERT. Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Projections currently supported are FLAT, LATLON and LAMBERT.  Relevant only if RemapGrid is TRUE.");
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
    tt->descr = tdrpStrDup("Number of cells in the grid in Y Relevant only if RemapGrid is TRUE.");
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
    tt->descr = tdrpStrDup("Size of the cells in the output grid in X Relevant only if RemapGrid is TRUE.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_dx - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_dy'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dy");
    tt->descr = tdrpStrDup("Size of the cells in the output grid in Y Relevant only if RemapGrid is TRUE.");
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
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection. Relevant only if RemapGrid is TRUE.");
    tt->val_offset = (char *) &grid_minx - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'grid_miny'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_miny");
    tt->descr = tdrpStrDup("Y at grid's lower left corner");
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection. Relevant only if RemapGrid is TRUE.");
    tt->val_offset = (char *) &grid_miny - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("------ End of grid parameters. ");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("Vertical parameters : ");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'applyVlevels'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("applyVlevels");
    tt->descr = tdrpStrDup("Option to apply min_vlevel and max_vlevel restrictions.");
    tt->help = tdrpStrDup("Default is not to do this.");
    tt->val_offset = (char *) &applyVlevels - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'min_vlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_vlevel");
    tt->descr = tdrpStrDup("Minimum vlevel to process, units same as input levels.");
    tt->help = tdrpStrDup("Relevant only if applyVlevels is TRUE.");
    tt->val_offset = (char *) &min_vlevel - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'max_vlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_vlevel");
    tt->descr = tdrpStrDup("Minimum vlevel to process, units same as input levels.");
    tt->help = tdrpStrDup("Relevant only if applyVlevels is TRUE.");
    tt->val_offset = (char *) &max_vlevel - &_start_;
    tt->single_val.d = 100;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("Sigma Z parameters:");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'use_sigma_z'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_sigma_z");
    tt->descr = tdrpStrDup("Option to use sigma z levels in header part.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &use_sigma_z - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'sigma_z_values'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("sigma_z_values");
    tt->descr = tdrpStrDup("Sigma Z values used in header part, only if use_sigma_z is TRUE.");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_sigma_z_values - &_start_;
    tt->array_n_offset = (char *) &sigma_z_values_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 28;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 0.999186;
      tt->array_vals[1].d = 0.996994;
      tt->array_vals[2].d = 0.994046;
      tt->array_vals[3].d = 0.990731;
      tt->array_vals[4].d = 0.98703;
      tt->array_vals[5].d = 0.982896;
      tt->array_vals[6].d = 0.97828;
      tt->array_vals[7].d = 0.973123;
      tt->array_vals[8].d = 0.967361;
      tt->array_vals[9].d = 0.960923;
      tt->array_vals[10].d = 0.953729;
      tt->array_vals[11].d = 0.945686;
      tt->array_vals[12].d = 0.936695;
      tt->array_vals[13].d = 0.926638;
      tt->array_vals[14].d = 0.915387;
      tt->array_vals[15].d = 0.902798;
      tt->array_vals[16].d = 0.888708;
      tt->array_vals[17].d = 0.872931;
      tt->array_vals[18].d = 0.855251;
      tt->array_vals[19].d = 0.835426;
      tt->array_vals[20].d = 0.800435;
      tt->array_vals[21].d = 0.744186;
      tt->array_vals[22].d = 0.673007;
      tt->array_vals[23].d = 0.582294;
      tt->array_vals[24].d = 0.465517;
      tt->array_vals[25].d = 0.32766;
      tt->array_vals[26].d = 0.182417;
      tt->array_vals[27].d = 0.0273403;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
