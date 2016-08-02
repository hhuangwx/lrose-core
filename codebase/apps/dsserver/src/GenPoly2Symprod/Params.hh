////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program GenPoly2Symprod
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
 * @class Params
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
    DEBUG_VERBOSE = 2
  } debug_t;

  typedef enum {
    LINETYPE_SOLID = 0,
    LINETYPE_DASH = 1,
    LINETYPE_DOT_DASH = 2
  } line_type_t;

  typedef enum {
    CAPSTYLE_BUTT = 0,
    CAPSTYLE_NOT_LAST = 1,
    CAPSTYLE_PROJECTING = 2,
    CAPSTYLE_ROUND = 3
  } capstyle_t;

  typedef enum {
    JOINSTYLE_BEVEL = 0,
    JOINSTYLE_MITER = 1,
    JOINSTYLE_ROUND = 2
  } joinstyle_t;

  typedef enum {
    VERT_ALIGN_TOP = 1,
    VERT_ALIGN_CENTER = 2,
    VERT_ALIGN_BOTTOM = 3
  } vert_align_t;

  typedef enum {
    HORIZ_ALIGN_LEFT = 1,
    HORIZ_ALIGN_CENTER = 2,
    HORIZ_ALIGN_RIGHT = 3
  } horiz_align_t;

  // struct typedefs

  typedef struct {
    char* field_name;
    char* format_string;
    tdrp_bool_t display_units;
    char* text_color;
    char* background_color;
    int x_offset;
    int y_offset;
    char* font_name;
    int font_size;
    vert_align_t vert_align;
    horiz_align_t horiz_align;
  } field_display_t;

  typedef struct {
    tdrp_bool_t displayGenTime;
    tdrp_bool_t displayValidTime;
    tdrp_bool_t displayExpireTime;
    char* text_color;
    char* background_color;
    int x_offset;
    int y_offset;
    char* font_name;
    int font_size;
    vert_align_t vert_align;
    horiz_align_t horiz_align;
  } time_display_t;

  typedef struct {
    tdrp_bool_t use_speed_dir_fields;
    char* speed_field_name;
    char* dir_field_name;
    char* u_field_name;
    char* v_field_name;
  } vector_field_names_t;

  typedef struct {
    char* background_color;
    char* font_name;
    int font_size;
    int x_offset;
    int y_offset;
    vert_align_t vert_align;
    horiz_align_t horiz_align;
  } text_item_t;

  typedef struct {
    char* text_color;
    char* background_color;
    int x_offset;
    int y_offset;
    char* font_name;
    int font_size;
    vert_align_t vert_align;
    horiz_align_t horiz_align;
  } text_display_t;

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

  tdrp_bool_t no_threads;

  int port;

  int qmax;

  int max_clients;

  tdrp_bool_t polyline_dashed;

  char* polyline_color;

  tdrp_bool_t polyline_color_mapped;

  double *_polyline_color_mapped_x;
  int polyline_color_mapped_x_n;

  char* *_polyline_color_mapped_y;
  int polyline_color_mapped_y_n;

  line_type_t suggested_line_type;

  long suggested_line_width;

  long suggested_arrow_line_width;

  capstyle_t suggested_capstyle;

  joinstyle_t suggested_joinstyle;

  field_display_t *_display_fields;
  int display_fields_n;

  tdrp_bool_t show_field_names;

  time_display_t display_time;

  tdrp_bool_t plot_vectors;

  long forecast_lead_time;

  vector_field_names_t vector_field_names;

  char* vector_color;

  double arrow_head_len;

  double arrow_head_half_angle;

  tdrp_bool_t fixed_length_arrows;

  double arrow_shaft_length;

  tdrp_bool_t plot_genpoly_id;

  char* id_format_string;

  text_item_t id_label;

  tdrp_bool_t plot_text;

  text_display_t text_info;

  tdrp_bool_t render_met_mode;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[41];

  const char *_className;

  bool _exitDeferred;

};

#endif

