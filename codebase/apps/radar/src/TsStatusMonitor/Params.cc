////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program TsStatusMonitor
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
        << "   [ -params path ] specify params file path\n"
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
    tt->comment_hdr = tdrpStrDup("TsStatusMonitor reads IWRF time-series data from a file message queue (FMQ). It locates monitoring XML-formatted information in the time series, and writes that information out to SPDB, and in a form suitable for Nagios.");
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
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT - from file message queue (FMQ)");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'fmq_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("fmq_name");
    tt->descr = tdrpStrDup("FMQ name. For FMQ input_mode only.");
    tt->help = tdrpStrDup("Path to FMQ files. There are 2 files, one with a .buf extension and one with a .stat extention. This path does not include the extensions.");
    tt->val_offset = (char *) &fmq_name - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/fmq/ts");
    tt++;
    
    // Parameter 'data_valid_interval_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("data_valid_interval_secs");
    tt->descr = tdrpStrDup("Maximum interval with no data (secs).");
    tt->help = tdrpStrDup("After this time elapses with no data, the status data is considered invalid until the data restarts.");
    tt->val_offset = (char *) &data_valid_interval_secs - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("XML STATUS INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'xml_entries'
    // ctype is '_xml_entry_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("xml_entries");
    tt->descr = tdrpStrDup("Details of XML entries to process.");
    tt->help = tdrpStrDup("\txml_outer_tag: the main tag for the entry\n\txml_inner_tag: the sub tag for the entry\n\tentry_type: the type of data stored\n\tok_boolean: BOOLEAN only: the value for an OK state\n\tboolean_failure_is_critical: true if FAILURE is critical, false if failure indicates IMPAIRED\n\tok_value_lower_limit: INT or DOUBLE: the lower limit for an OK state\n\tok_value_upper_limit: INT or DOUBLE: the upper limit for an OK state\n\timpaired_value_lower_limit: INT or DOUBLE: the lower limit for an IMPAIRED state\n\timpaired_value_upper_limit: INT or DOUBLE: the upper limit for an IMPAIRED state\n\tgraph_min_val: minimum value for history graph\n\tgraph_max_val: maximim value for history graph\n\tcomment: if set, appears at end of status line\n.");
    tt->array_offset = (char *) &_xml_entries - &_start_;
    tt->array_n_offset = (char *) &xml_entries_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(xml_entry_t);
    tt->array_n = 3;
    tt->struct_def.name = tdrpStrDup("xml_entry_t");
    tt->struct_def.nfields = 14;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("xml_outer_tag");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_xml_entries->xml_outer_tag - (char *) _xml_entries;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("xml_inner_tag");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_xml_entries->xml_inner_tag - (char *) _xml_entries;
      tt->struct_def.fields[2].ftype = tdrpStrDup("xml_entry_type_t");
      tt->struct_def.fields[2].fname = tdrpStrDup("entry_type");
      tt->struct_def.fields[2].ptype = ENUM_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_xml_entries->entry_type - (char *) _xml_entries;
        tt->struct_def.fields[2].enum_def.name = tdrpStrDup("xml_entry_type_t");
        tt->struct_def.fields[2].enum_def.nfields = 4;
        tt->struct_def.fields[2].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[2].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[2].enum_def.fields[0].name = tdrpStrDup("XML_ENTRY_BOOLEAN");
        tt->struct_def.fields[2].enum_def.fields[0].val = XML_ENTRY_BOOLEAN;
        tt->struct_def.fields[2].enum_def.fields[1].name = tdrpStrDup("XML_ENTRY_INT");
        tt->struct_def.fields[2].enum_def.fields[1].val = XML_ENTRY_INT;
        tt->struct_def.fields[2].enum_def.fields[2].name = tdrpStrDup("XML_ENTRY_DOUBLE");
        tt->struct_def.fields[2].enum_def.fields[2].val = XML_ENTRY_DOUBLE;
        tt->struct_def.fields[2].enum_def.fields[3].name = tdrpStrDup("XML_ENTRY_STRING");
        tt->struct_def.fields[2].enum_def.fields[3].val = XML_ENTRY_STRING;
      tt->struct_def.fields[3].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[3].fname = tdrpStrDup("ok_boolean");
      tt->struct_def.fields[3].ptype = BOOL_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_xml_entries->ok_boolean - (char *) _xml_entries;
      tt->struct_def.fields[4].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[4].fname = tdrpStrDup("boolean_failure_is_critical");
      tt->struct_def.fields[4].ptype = BOOL_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_xml_entries->boolean_failure_is_critical - (char *) _xml_entries;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("ok_value_lower_limit");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_xml_entries->ok_value_lower_limit - (char *) _xml_entries;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("ok_value_upper_limit");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &_xml_entries->ok_value_upper_limit - (char *) _xml_entries;
      tt->struct_def.fields[7].ftype = tdrpStrDup("double");
      tt->struct_def.fields[7].fname = tdrpStrDup("impaired_value_lower_limit");
      tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &_xml_entries->impaired_value_lower_limit - (char *) _xml_entries;
      tt->struct_def.fields[8].ftype = tdrpStrDup("double");
      tt->struct_def.fields[8].fname = tdrpStrDup("impaired_value_upper_limit");
      tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &_xml_entries->impaired_value_upper_limit - (char *) _xml_entries;
      tt->struct_def.fields[9].ftype = tdrpStrDup("string");
      tt->struct_def.fields[9].fname = tdrpStrDup("label");
      tt->struct_def.fields[9].ptype = STRING_TYPE;
      tt->struct_def.fields[9].rel_offset = 
        (char *) &_xml_entries->label - (char *) _xml_entries;
      tt->struct_def.fields[10].ftype = tdrpStrDup("string");
      tt->struct_def.fields[10].fname = tdrpStrDup("units");
      tt->struct_def.fields[10].ptype = STRING_TYPE;
      tt->struct_def.fields[10].rel_offset = 
        (char *) &_xml_entries->units - (char *) _xml_entries;
      tt->struct_def.fields[11].ftype = tdrpStrDup("double");
      tt->struct_def.fields[11].fname = tdrpStrDup("graph_min_val");
      tt->struct_def.fields[11].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[11].rel_offset = 
        (char *) &_xml_entries->graph_min_val - (char *) _xml_entries;
      tt->struct_def.fields[12].ftype = tdrpStrDup("double");
      tt->struct_def.fields[12].fname = tdrpStrDup("graph_max_val");
      tt->struct_def.fields[12].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[12].rel_offset = 
        (char *) &_xml_entries->graph_max_val - (char *) _xml_entries;
      tt->struct_def.fields[13].ftype = tdrpStrDup("string");
      tt->struct_def.fields[13].fname = tdrpStrDup("comment");
      tt->struct_def.fields[13].ptype = STRING_TYPE;
      tt->struct_def.fields[13].rel_offset = 
        (char *) &_xml_entries->comment - (char *) _xml_entries;
    tt->n_struct_vals = 42;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("HcrTransmitterStatus");
      tt->struct_vals[1].s = tdrpStrDup("SerialConnected");
      tt->struct_vals[2].e = XML_ENTRY_BOOLEAN;
      tt->struct_vals[3].b = pTRUE;
      tt->struct_vals[4].b = pTRUE;
      tt->struct_vals[5].d = 0;
      tt->struct_vals[6].d = 0;
      tt->struct_vals[7].d = 0;
      tt->struct_vals[8].d = 0;
      tt->struct_vals[9].s = tdrpStrDup("");
      tt->struct_vals[10].s = tdrpStrDup("");
      tt->struct_vals[11].d = 0;
      tt->struct_vals[12].d = 1;
      tt->struct_vals[13].s = tdrpStrDup("");
      tt->struct_vals[14].s = tdrpStrDup("HcrTransmitterStatus");
      tt->struct_vals[15].s = tdrpStrDup("CathodeVoltage");
      tt->struct_vals[16].e = XML_ENTRY_DOUBLE;
      tt->struct_vals[17].b = pTRUE;
      tt->struct_vals[18].b = pTRUE;
      tt->struct_vals[19].d = 0;
      tt->struct_vals[20].d = 10;
      tt->struct_vals[21].d = 11;
      tt->struct_vals[22].d = 20;
      tt->struct_vals[23].s = tdrpStrDup("");
      tt->struct_vals[24].s = tdrpStrDup("V");
      tt->struct_vals[25].d = 0;
      tt->struct_vals[26].d = 30;
      tt->struct_vals[27].s = tdrpStrDup("");
      tt->struct_vals[28].s = tdrpStrDup("HcrReceiverStatus");
      tt->struct_vals[29].s = tdrpStrDup("PvAftPressure");
      tt->struct_vals[30].e = XML_ENTRY_DOUBLE;
      tt->struct_vals[31].b = pTRUE;
      tt->struct_vals[32].b = pTRUE;
      tt->struct_vals[33].d = 10;
      tt->struct_vals[34].d = 20;
      tt->struct_vals[35].d = 5;
      tt->struct_vals[36].d = 10;
      tt->struct_vals[37].s = tdrpStrDup("");
      tt->struct_vals[38].s = tdrpStrDup("psi");
      tt->struct_vals[39].d = 0;
      tt->struct_vals[40].d = 30;
      tt->struct_vals[41].s = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("MONITOR TEST PULSE POWER");
    tt->comment_text = tdrpStrDup("If test pulse monitoring is active, an extra XML block will be generate to hold the test pulse powers. The main tag for this block is specified in test_pulse_tag. Within the test pulse block, the following values will the stored, as applicable:\n\tTestPulsePowerHcDb\n\tTestPulsePowerVcDb\n\tTestPulsePowerHxDb\n\tTestPulsePowerVxDb.");
    tt++;
    
    // Parameter 'monitor_test_pulse'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("monitor_test_pulse");
    tt->descr = tdrpStrDup("Option to compute test pulse power and add to monitoring.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &monitor_test_pulse - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'test_pulse_xml_tag'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("test_pulse_xml_tag");
    tt->descr = tdrpStrDup("Tag to delineate test pulse block in output XML.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &test_pulse_xml_tag - &_start_;
    tt->single_val.s = tdrpStrDup("KaBandTestPulse");
    tt++;
    
    // Parameter 'test_pulse_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("test_pulse_range_km");
    tt->descr = tdrpStrDup("Range to test pulse (km).");
    tt->help = tdrpStrDup("We compute the gate number from this range. The power at this gate is averaged over the monitoring interval.");
    tt->val_offset = (char *) &test_pulse_range_km - &_start_;
    tt->single_val.d = 145;
    tt++;
    
    // Parameter 'test_pulse_n_samples'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("test_pulse_n_samples");
    tt->descr = tdrpStrDup("Number of samples used to compute test pulse power.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &test_pulse_n_samples - &_start_;
    tt->single_val.i = 5000;
    tt++;
    
    // Parameter 'dual_pol_alternating_mode'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("dual_pol_alternating_mode");
    tt->descr = tdrpStrDup("If this is a dual-polarization system, is it operating in fast alternating mode?");
    tt->help = tdrpStrDup("If true, the HV flag is used to determine which receiver path to use.");
    tt->val_offset = (char *) &dual_pol_alternating_mode - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'dual_pol_switching_receivers'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("dual_pol_switching_receivers");
    tt->descr = tdrpStrDup("If this is a dual-polarization system, does it have switching receivers?");
    tt->help = tdrpStrDup("If true, then there is a co-pol receiver path and a cross-pol receiver path. If false, there is an H and V receiver path.");
    tt->val_offset = (char *) &dual_pol_switching_receivers - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("MONITOR GATE 0 VELOCITY");
    tt->comment_text = tdrpStrDup("This is used to make sure the radar is cohering correctly. Only applicable to magnetron radars.");
    tt++;
    
    // Parameter 'monitor_g0_velocity'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("monitor_g0_velocity");
    tt->descr = tdrpStrDup("Option to monitor the gate 0 velocity - intended for the ka-band.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &monitor_g0_velocity - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'g0_velocity_xml_tag'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("g0_velocity_xml_tag");
    tt->descr = tdrpStrDup("Tag to delineate G0 velocity blocki in output XML.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &g0_velocity_xml_tag - &_start_;
    tt->single_val.s = tdrpStrDup("KaBandG0Velocity");
    tt++;
    
    // Parameter 'g0_velocity_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("g0_velocity_range_km");
    tt->descr = tdrpStrDup("Range to test pulse (km).");
    tt->help = tdrpStrDup("We compute the gate number from this range. The velocity at this gate is averaged over the monitoring interval.");
    tt->val_offset = (char *) &g0_velocity_range_km - &_start_;
    tt->single_val.d = 0.15;
    tt++;
    
    // Parameter 'g0_velocity_n_samples'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("g0_velocity_n_samples");
    tt->descr = tdrpStrDup("Number of samples used to compute g0 velocity.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &g0_velocity_n_samples - &_start_;
    tt->single_val.i = 1024;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("NAGIOS OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_to_nagios'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_to_nagios");
    tt->descr = tdrpStrDup("If true, writes  one file only and then quit.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_to_nagios - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'nagios_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("nagios_file_path");
    tt->descr = tdrpStrDup("File path for NAGIOS data.");
    tt->help = tdrpStrDup("This file is overwritten at regular intervals.");
    tt->val_offset = (char *) &nagios_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/nagios/spol_monitoring");
    tt++;
    
    // Parameter 'nagios_interval_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nagios_interval_secs");
    tt->descr = tdrpStrDup("Interval at which the data is written to NAGIOS (secs).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_interval_secs - &_start_;
    tt->single_val.i = 30;
    tt++;
    
    // Parameter 'nagios_nsecs_missing_for_warning'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nagios_nsecs_missing_for_warning");
    tt->descr = tdrpStrDup("Length of missing data to generate a warning (secs).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_nsecs_missing_for_warning - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'nagios_nsecs_missing_for_critical'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nagios_nsecs_missing_for_critical");
    tt->descr = tdrpStrDup("Length of missing data to generate a critical state (secs).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_nsecs_missing_for_critical - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("CHECK FOR ANTENNA MOVEMENT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'check_for_moving_antenna'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("check_for_moving_antenna");
    tt->descr = tdrpStrDup("Option to only process status if antenna is moving.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &check_for_moving_antenna - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'antenna_movement_xml_tag'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("antenna_movement_xml_tag");
    tt->descr = tdrpStrDup("Tag to delineate antenna movement block in output XML.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &antenna_movement_xml_tag - &_start_;
    tt->single_val.s = tdrpStrDup("AntennaMovement");
    tt++;
    
    // Parameter 'movement_check_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("movement_check_interval");
    tt->descr = tdrpStrDup("Minimim time between checks for movement (secs).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &movement_check_interval - &_start_;
    tt->single_val.i = 2;
    tt++;
    
    // Parameter 'stationary_max_angle_change'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("stationary_max_angle_change");
    tt->descr = tdrpStrDup("Maximum angle change for stationary mode (deg).");
    tt->help = tdrpStrDup("For the antenna to be considered stationary, it must not move by more than this angle in the lockon period.");
    tt->val_offset = (char *) &stationary_max_angle_change - &_start_;
    tt->single_val.d = 0.01;
    tt++;
    
    // Parameter 'nagios_monitor_antenna_movement'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("nagios_monitor_antenna_movement");
    tt->descr = tdrpStrDup("Option to add movement monitoring to nagios.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_monitor_antenna_movement - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'nagios_antenna_movement_warn_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nagios_antenna_movement_warn_secs");
    tt->descr = tdrpStrDup("Number of stationary seconds to generate a warning.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_antenna_movement_warn_secs - &_start_;
    tt->single_val.i = 30;
    tt++;
    
    // Parameter 'nagios_antenna_movement_crit_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("nagios_antenna_movement_crit_secs");
    tt->descr = tdrpStrDup("Number of stationary seconds to generate a critical condition.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_antenna_movement_crit_secs - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'nagios_antenna_movement_label'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("nagios_antenna_movement_label");
    tt->descr = tdrpStrDup("Name for antenna movement entry in nagios.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &nagios_antenna_movement_label - &_start_;
    tt->single_val.s = tdrpStrDup("SBandAntennaMovement");
    tt++;
    
    // Parameter 'Comment 8'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 8");
    tt->comment_hdr = tdrpStrDup("SPDB OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_to_spdb'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_to_spdb");
    tt->descr = tdrpStrDup("If true, writes status out to SPDB in XML format.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_to_spdb - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'spdb_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdb_url");
    tt->descr = tdrpStrDup("URL for SPDB output.");
    tt->help = tdrpStrDup("SPDB data is written to this location.");
    tt->val_offset = (char *) &spdb_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::/tmp/spdb/spol_monitoring");
    tt++;
    
    // Parameter 'spdb_interval_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("spdb_interval_secs");
    tt->descr = tdrpStrDup("Interval at which the data is written to SPDB (secs).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &spdb_interval_secs - &_start_;
    tt->single_val.i = 10;
    tt++;
    
    // Parameter 'compress_spdb'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("compress_spdb");
    tt->descr = tdrpStrDup("If true, compress the SPDB chunks on write.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &compress_spdb - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
