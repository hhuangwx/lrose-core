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
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program MdvPull
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    ARCHIVE = 0,
    REALTIME = 1
  } mode_t;

  typedef enum {
    VALID_TIME = 0,
    GEN_TIME = 1
  } search_mode_t;

  typedef enum {
    PROJ_LATLON = 0,
    PROJ_LAMBERT_CONF = 3,
    PROJ_MERCATOR = 4,
    PROJ_POLAR_STEREO = 5,
    PROJ_FLAT = 8,
    PROJ_OBLIQUE_STEREO = 12,
    PROJ_TRANS_MERCATOR = 15,
    PROJ_ALBERS = 16,
    PROJ_LAMBERT_AZIM = 17,
    PROJ_VERT_PERSP = 18
  } projection_t;

  typedef enum {
    ENCODING_ASIS = 0,
    ENCODING_INT8 = 1,
    ENCODING_INT16 = 2,
    ENCODING_FLOAT32 = 5
  } encoding_type_t;

  typedef enum {
    COMPRESSION_ASIS = -1,
    COMPRESSION_NONE = 0,
    COMPRESSION_RLE = 1,
    COMPRESSION_LZO = 2,
    COMPRESSION_ZLIB = 3,
    COMPRESSION_BZIP = 4,
    COMPRESSION_GZIP = 5,
    COMPRESSION_GZIP_VOL = 6,
    COMPRESSION_TYPES_N = 7
  } compression_type_t;

  typedef enum {
    OUTPUT_FORMAT_MDV = 0,
    OUTPUT_FORMAT_XML = 1,
    OUTPUT_FORMAT_NCF = 2
  } output_format_t;

  typedef enum {
    DATA_PACK_FLOAT = 0,
    DATA_PACK_SHORT = 1,
    DATA_PACK_BYTE = 2,
    DATA_PACK_ASIS = 3
  } data_pack_t;

  typedef enum {
    CLASSIC = 0,
    NC64BIT = 1,
    NETCDF4 = 2,
    NETCDF4_CLASSIC = 3
  } ncf_format_t;

  typedef enum {
    FILE_TYPE_CF = 0,
    FILE_TYPE_CF_RADIAL = 1,
    FILE_TYPE_DORADE = 2,
    FILE_TYPE_UF = 3
  } radial_file_type_t;

  // struct typedefs

  typedef struct {
    float min_lat;
    float min_lon;
    float max_lat;
    float max_lon;
  } horiz_limits_t;

  typedef struct {
    char* old_field_name;
    char* new_field_name;
  } field_names_t;

  typedef struct {
    int nx;
    int ny;
    double minx;
    double miny;
    double dx;
    double dy;
  } grid_params_t;

  typedef struct {
    char* institution;
    char* references;
    char* comment;
  } ncf_global_attributes_t;

  typedef struct {
    char* mdv_field_name;
    char* ncf_field_name;
    char* ncf_standard_name;
    char* ncf_long_name;
    char* ncf_units;
    tdrp_bool_t do_linear_transform;
    float linear_multiplier;
    float linear_const;
    data_pack_t packed_data_type;
  } ncf_field_transform_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

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

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

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

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

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

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

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

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

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

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

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

  int arrayRealloc(const char *param_name,
                   int new_array_n);

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

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  char* instance;

  int reg_interval;

  mode_t mode;

  int new_data_poll_interval;

  int realtime_lookback_secs;

  int realtime_lookforward_secs;

  search_mode_t search_mode;

  char* source_url;

  tdrp_bool_t set_field_names;

  char* *_field_names;
  int field_names_n;

  tdrp_bool_t set_horiz_limits;

  horiz_limits_t horiz_limits;

  tdrp_bool_t set_vlevel_limits;

  float lower_vlevel;

  float upper_vlevel;

  tdrp_bool_t composite;

  tdrp_bool_t rename_fields;

  field_names_t *_new_names;
  int new_names_n;

  tdrp_bool_t remap_xy;

  tdrp_bool_t auto_remap_to_latlon;

  projection_t remap_projection;

  grid_params_t remap_grid;

  double remap_rotation;

  double remap_origin_lat;

  double remap_origin_lon;

  double remap_lat1;

  double remap_lat2;

  double remap_central_scale;

  double remap_tangent_lat;

  double remap_tangent_lon;

  tdrp_bool_t remap_pole_is_north;

  double remap_persp_radius;

  double remap_false_northing;

  double remap_false_easting;

  tdrp_bool_t remap_set_offset_origin;

  double remap_offset_origin_latitude;

  double remap_offset_origin_longitude;

  encoding_type_t encoding_type;

  compression_type_t compression_type;

  char* output_url;

  tdrp_bool_t write_latest_data_info;

  output_format_t output_format;

  tdrp_bool_t write_using_extended_paths;

  tdrp_bool_t ncf_set_global_attributes;

  ncf_global_attributes_t ncf_global_attributes;

  tdrp_bool_t ncf_transform_fields;

  ncf_field_transform_t *_ncf_field_transforms;
  int ncf_field_transforms_n;

  tdrp_bool_t ncf_compress_data;

  int ncf_compression_level;

  char* ncf_base_name;

  char* ncf_file_prefix;

  char* ncf_file_suffix;

  ncf_format_t ncf_file_format;

  radial_file_type_t ncf_polar_radar_file_type;

  tdrp_bool_t ncf_output_latlon_arrays;

  tdrp_bool_t ncf_output_mdv_attributes;

  tdrp_bool_t ncf_output_mdv_chunks;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[68];

  const char *_className;

  bool _exitDeferred;

};

#endif

