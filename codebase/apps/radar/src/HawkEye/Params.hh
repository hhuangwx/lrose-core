// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2015
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Research Applications Laboratory(RAL)
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program HawkEye
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
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    IWRF_FMQ_INPUT = 0,
    IWRF_TCP_INPUT = 1,
    SIMULATED_INPUT = 2,
    SIMULATED_RHI_INPUT = 3,
    DSR_FMQ_INPUT = 4
  } input_mode_t;

  typedef enum {
    POLAR_DISPLAY = 0,
    BSCAN_DISPLAY = 1
  } display_mode_t;

  typedef enum {
    PPI_FULL = 0,
    PPI_AIRBORNE = 1
  } ppi_display_type_t;

  typedef enum {
    RANGE_AXIS_UP = 0,
    RANGE_AXIS_DOWN = 1,
    RANGE_AXIS_ALTITUDE = 2
  } range_axis_mode_t;

  typedef enum {
    LEGEND_TOP_LEFT = 0,
    LEGEND_TOP_RIGHT = 1,
    LEGEND_BOTTOM_LEFT = 2,
    LEGEND_BOTTOM_RIGHT = 3
  } legend_pos_t;

  typedef enum {
    DWELL_STATS_MEAN = 0,
    DWELL_STATS_MEDIAN = 1,
    DWELL_STATS_MAXIMUM = 2,
    DWELL_STATS_MINIMUM = 3,
    DWELL_STATS_MIDDLE = 4
  } bscan_dwell_stats_t;

  typedef enum {
    CREATE_IMAGES_THEN_EXIT = 0,
    CREATE_IMAGES_ON_REALTIME_SCHEDULE = 1,
    CREATE_IMAGES_ON_ARCHIVE_SCHEDULE = 2
  } images_creation_mode_t;

  // struct typedefs

  typedef struct {
    tdrp_bool_t azimuth;
    tdrp_bool_t elevation;
    tdrp_bool_t fixed_angle;
    tdrp_bool_t volume_number;
    tdrp_bool_t sweep_number;
    tdrp_bool_t n_samples;
    tdrp_bool_t n_gates;
    tdrp_bool_t gate_length;
    tdrp_bool_t pulse_width;
    tdrp_bool_t prf_mode;
    tdrp_bool_t prf;
    tdrp_bool_t nyquist;
    tdrp_bool_t max_range;
    tdrp_bool_t unambiguous_range;
    tdrp_bool_t measured_power_h;
    tdrp_bool_t measured_power_v;
    tdrp_bool_t scan_name;
    tdrp_bool_t scan_mode;
    tdrp_bool_t polarization_mode;
    tdrp_bool_t latitude;
    tdrp_bool_t longitude;
    tdrp_bool_t altitude;
    tdrp_bool_t altitude_rate;
    tdrp_bool_t sun_elevation;
    tdrp_bool_t sun_azimuth;
    tdrp_bool_t speed;
    tdrp_bool_t heading;
    tdrp_bool_t track;
  } show_status_t;

  typedef struct {
    char* label;
    char* raw_name;
    char* filtered_name;
    char* units;
    char* color_map;
    char* shortcut;
  } field_t;

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

  tdrp_bool_t register_with_procmap;

  char* instance;

  input_mode_t input_mode;

  char* input_fmq_url;

  tdrp_bool_t seek_to_start_of_fmq;

  char* input_tcp_host;

  int input_tcp_port;

  int beam_queue_size;

  tdrp_bool_t begin_in_archive_mode;

  char* archive_start_time;

  char* archive_end_time;

  char* archive_data_url;

  show_status_t show_status_in_gui;

  char* color_scale_dir;

  field_t *_fields;
  int fields_n;

  double background_render_mins;

  tdrp_bool_t use_field_label_in_title;

  double max_range_km;

  display_mode_t display_mode;

  tdrp_bool_t override_radar_name;

  char* radar_name;

  tdrp_bool_t display_site_name;

  tdrp_bool_t override_site_name;

  char* site_name;

  int main_window_width;

  int main_window_height;

  int main_window_start_x;

  int main_window_start_y;

  int color_scale_width;

  int label_font_size;

  char* background_color;

  char* grid_and_range_ring_color;

  int range_ring_label_font_size;

  int click_cross_size;

  ppi_display_type_t ppi_display_type;

  double ppi_aspect_ratio;

  int rhi_window_width;

  int rhi_window_height;

  int rhi_window_start_x;

  int rhi_window_start_y;

  tdrp_bool_t rhi_display_180_degrees;

  double rhi_aspect_ratio;

  double bscan_time_span_secs;

  tdrp_bool_t bscan_truncate_start_time;

  int bscan_subsec_precision;

  double bscan_realtime_fraction_saved;

  double bscan_min_secs_between_reading_beams;

  double bscan_min_secs_between_rendering_beams;

  tdrp_bool_t bscan_specify_range_limits;

  double bscan_min_range_km;

  double bscan_max_range_km;

  double bscan_min_altitude_km;

  double bscan_max_altitude_km;

  tdrp_bool_t bscan_altitude_in_feet;

  tdrp_bool_t bscan_range_in_feet;

  range_axis_mode_t bscan_range_axis_mode;

  tdrp_bool_t bscan_censor_data_below_surface;

  char* bscan_surface_field;

  double bscan_min_range_to_surface_km;

  double bscan_surface_range_margin_km;

  double bscan_max_field_val_below_surface;

  int bscan_top_margin;

  int bscan_bottom_margin;

  int bscan_left_margin;

  int bscan_right_margin;

  int bscan_axis_tick_len;

  int bscan_n_ticks_ideal;

  int bscan_text_margin;

  int bscan_title_font_size;

  int bscan_axis_label_font_size;

  int bscan_axis_values_font_size;

  char* bscan_axes_color;

  char* bscan_grid_color;

  char* bscan_labels_color;

  tdrp_bool_t bscan_draw_time_grid_lines;

  tdrp_bool_t bscan_draw_range_grid_lines;

  tdrp_bool_t bscan_draw_instrument_height_line;

  char* bscan_instrument_height_color;

  tdrp_bool_t bscan_add_distance_to_time_axis;

  int bscan_n_segments_for_computing_distance;

  tdrp_bool_t bscan_plot_starting_latlon_as_legend;

  legend_pos_t bscan_starting_latlon_legend_pos;

  tdrp_bool_t bscan_plot_mean_track_and_speed_as_legend;

  legend_pos_t bscan_mean_track_and_speed_legend_pos;

  tdrp_bool_t bscan_archive_dwell_auto;

  double bscan_archive_dwell_secs;

  bscan_dwell_stats_t bscan_dwell_stats;

  char* images_output_dir;

  tdrp_bool_t images_write_to_day_dir;

  char* images_file_name_category;

  char* images_file_name_platform;

  char* images_file_name_extension;

  char* images_file_name_delimiter;

  tdrp_bool_t images_include_time_part_in_file_name;

  tdrp_bool_t images_include_seconds_in_time_part;

  tdrp_bool_t images_include_field_label_in_file_name;

  tdrp_bool_t images_write_latest_data_info;

  tdrp_bool_t images_auto_create;

  images_creation_mode_t images_creation_mode;

  int images_schedule_interval_secs;

  int images_schedule_delay_secs;

  int sim_sleep_msecs;

  int sim_n_gates;

  double sim_start_range_km;

  double sim_gate_spacing_km;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[131];

  const char *_className;

  bool _exitDeferred;

};

#endif

