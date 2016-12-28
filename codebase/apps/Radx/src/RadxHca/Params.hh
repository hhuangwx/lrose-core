// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program RadxHca
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
    REALTIME = 0,
    ARCHIVE = 1,
    FILELIST = 2
  } mode_t;

  typedef enum {
    FIR_LEN_125 = 0,
    FIR_LEN_60 = 1,
    FIR_LEN_40 = 2,
    FIR_LEN_30 = 3,
    FIR_LEN_20 = 4,
    FIR_LEN_10 = 5
  } fir_filter_len_t;

  typedef enum {
    CLASS_GC = 0,
    CLASS_BS = 1,
    CLASS_DS = 2,
    CLASS_WS = 3,
    CLASS_CR = 4,
    CLASS_GR = 5,
    CLASS_BD = 6,
    CLASS_RA = 7,
    CLASS_HR = 8,
    CLASS_RH = 9
  } hca_class_t;

  typedef enum {
    FEATURE_DBZ = 0,
    FEATURE_ZDR = 1,
    FEATURE_RHOHV = 2,
    FEATURE_LOG_KDP = 3,
    FEATURE_SD_DBZ = 4,
    FEATURE_SD_PHIDP = 5
  } feature_field_t;

  typedef enum {
    SNR = 0,
    DBZ = 1,
    VEL = 2,
    WIDTH = 3,
    NCP = 4,
    ZDR = 5,
    LDR = 6,
    RHOHV = 7,
    PHIDP = 8,
    KDP = 9,
    PSOB = 10,
    ZDP = 11,
    DBZ_ATTEN_CORRECTION = 12,
    ZDR_ATTEN_CORRECTION = 13,
    DBZ_ATTEN_CORRECTED = 14,
    ZDR_ATTEN_CORRECTED = 15,
    DBZ_FOR_KDP = 16,
    ZDR_FOR_KDP = 17,
    RHOHV_FOR_KDP = 18,
    SNR_FOR_KDP = 19,
    ZDR_SDEV_FOR_KDP = 20,
    VALID_FLAG_FOR_KDP = 21,
    PHIDP_FOR_KDP = 22,
    PHIDP_MEAN_FOR_KDP = 23,
    PHIDP_MEAN_UNFOLD_FOR_KDP = 24,
    PHIDP_SDEV_FOR_KDP = 25,
    PHIDP_JITTER_FOR_KDP = 26,
    PHIDP_UNFOLD_FOR_KDP = 27,
    PHIDP_FILT_FOR_KDP = 28,
    PHIDP_COND_FOR_KDP = 29,
    PHIDP_COND_FILT_FOR_KDP = 30,
    RAY_HEIGHT = 31,
    SNR_MEAN_SEACLUT = 32,
    RHOHV_MEAN_SEACLUT = 33,
    PHIDP_SDEV_SEACLUT = 34,
    ZDR_SDEV_SEACLUT = 35,
    DBZ_ELEV_GRADIENT_SEACLUT = 36,
    RHOHV_MEAN_INTEREST_SEACLUT = 37,
    PHIDP_SDEV_INTEREST_SEACLUT = 38,
    ZDR_SDEV_INTEREST_SEACLUT = 39,
    DBZ_ELEV_GRADIENT_INTEREST_SEACLUT = 40,
    SEACLUT_FLAG = 41,
    PARTICLE_ID = 42,
    TEMP_FOR_PID = 43
  } output_field_id_t;

  typedef enum {
    OUTPUT_ENCODING_FL32 = 0,
    OUTPUT_ENCODING_INT32 = 1,
    OUTPUT_ENCODING_INT16 = 2,
    OUTPUT_ENCODING_INT08 = 3
  } output_encoding_t;

  typedef enum {
    OUTPUT_SCALING_DYNAMIC = 0,
    OUTPUT_SCALING_SPECIFIED = 1
  } output_scaling_t;

  typedef enum {
    OUTPUT_FORMAT_CFRADIAL = 0,
    OUTPUT_FORMAT_DORADE = 1,
    OUTPUT_FORMAT_FORAY = 2,
    OUTPUT_FORMAT_NEXRAD = 3,
    OUTPUT_FORMAT_UF = 4,
    OUTPUT_FORMAT_MDV_RADIAL = 5
  } output_format_t;

  typedef enum {
    CLASSIC = 0,
    NC64BIT = 1,
    NETCDF4 = 2,
    NETCDF4_CLASSIC = 3
  } netcdf_style_t;

  typedef enum {
    START_AND_END_TIMES = 0,
    START_TIME_ONLY = 1,
    END_TIME_ONLY = 2,
    SPECIFY_FILE_NAME = 3
  } filename_mode_t;

  // struct typedefs

  typedef struct {
    double value;
    double interest;
  } interest_map_point_t;

  typedef struct {
    hca_class_t hca_class;
    feature_field_t feature;
    double x1;
    double x2;
    double x3;
    double x4;
    double weight;
  } hca_interest_map_t;

  typedef struct {
    double min_val;
    double max_val;
  } data_range_t;

  typedef struct {
    output_field_id_t id;
    char* name;
    char* long_name;
    char* standard_name;
    char* units;
    output_encoding_t encoding;
    output_scaling_t scaling;
    double scale;
    double offset;
  } output_field_t;

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

  tdrp_bool_t register_with_procmap;

  int procmap_register_interval;

  tdrp_bool_t use_multiple_threads;

  int n_compute_threads;

  char* input_dir;

  mode_t mode;

  int max_realtime_data_age_secs;

  char* input_file_search_ext;

  char* input_file_search_substr;

  tdrp_bool_t aggregate_sweep_files_on_read;

  tdrp_bool_t remove_rays_with_antenna_transitions;

  int transition_nrays_margin;

  tdrp_bool_t trim_surveillance_sweeps_to_360deg;

  tdrp_bool_t set_max_range;

  double max_range_km;

  tdrp_bool_t set_ngates_constant;

  tdrp_bool_t set_fixed_angle_limits;

  double lower_fixed_angle_limit;

  double upper_fixed_angle_limit;

  tdrp_bool_t override_radar_location;

  double radar_latitude_deg;

  double radar_longitude_deg;

  double radar_altitude_meters;

  char* DBZ_field_name;

  char* VEL_field_name;

  tdrp_bool_t WIDTH_available;

  char* WIDTH_field_name;

  tdrp_bool_t NCP_available;

  char* NCP_field_name;

  tdrp_bool_t SNR_available;

  char* SNR_field_name;

  double noise_dbz_at_100km;

  char* ZDR_field_name;

  char* PHIDP_field_name;

  char* RHOHV_field_name;

  fir_filter_len_t KDP_fir_filter_len;

  int KDP_n_filt_iterations_unfolded;

  int KDP_n_filt_iterations_conditioned;

  tdrp_bool_t KDP_use_iterative_filtering;

  double KDP_phidp_difference_threshold;

  int KDP_ngates_for_stats;

  double KDP_phidp_sdev_max;

  double KDP_phidp_jitter_max;

  double KDP_min_valid_abs_kdp;

  tdrp_bool_t KDP_check_snr;

  double KDP_snr_threshold;

  tdrp_bool_t KDP_check_rhohv;

  double KDP_rhohv_threshold;

  tdrp_bool_t KDP_check_zdr_sdev;

  double KDP_zdr_sdev_max;

  tdrp_bool_t KDP_debug;

  tdrp_bool_t KDP_write_ray_files;

  char* KDP_ray_files_dir;

  tdrp_bool_t apply_precip_attenuation_correction;

  tdrp_bool_t specify_coefficients_for_attenuation_correction;

  double dbz_attenuation_coefficient;

  double dbz_attenuation_exponent;

  double zdr_attenuation_coefficient;

  double zdr_attenuation_exponent;

  tdrp_bool_t locate_sea_clutter;

  tdrp_bool_t override_standard_pseudo_earth_radius;

  double pseudo_earth_radius_ratio;

  double seaclut_min_snr_db;

  interest_map_point_t *_seaclut_rhohv_mean_interest_map;
  int seaclut_rhohv_mean_interest_map_n;

  double seaclut_rhohv_mean_weight;

  interest_map_point_t *_seaclut_phidp_sdev_interest_map;
  int seaclut_phidp_sdev_interest_map_n;

  double seaclut_phidp_sdev_weight;

  interest_map_point_t *_seaclut_zdr_sdev_interest_map;
  int seaclut_zdr_sdev_interest_map_n;

  double seaclut_zdr_sdev_weight;

  interest_map_point_t *_seaclut_dbz_elev_gradient_interest_map;
  int seaclut_dbz_elev_gradient_interest_map_n;

  double seaclut_dbz_elev_gradient_weight;

  double seaclut_interest_threshold;

  char* dbz_elevation_gradient_field_name;

  char* ray_height_field_name;

  double seaclut_max_elev_deg;

  tdrp_bool_t compute_hca;

  hca_interest_map_t *_hca_interest_maps;
  int hca_interest_maps_n;

  tdrp_bool_t compute_pid;

  char* pid_thresholds_file_path;

  double PID_snr_threshold;

  double PID_snr_upper_threshold;

  double PID_min_valid_interest;

  tdrp_bool_t PID_apply_median_filter_to_DBZ;

  int PID_DBZ_median_filter_len;

  tdrp_bool_t PID_apply_median_filter_to_ZDR;

  int PID_ZDR_median_filter_len;

  tdrp_bool_t PID_apply_median_filter_to_RHOHV;

  int PID_RHOHV_median_filter_len;

  tdrp_bool_t PID_apply_median_filter_to_LDR;

  int PID_LDR_median_filter_len;

  tdrp_bool_t PID_replace_missing_LDR;

  double PID_LDR_replacement_value;

  int PID_ngates_for_sdev;

  tdrp_bool_t PID_output_particle_interest_fields;

  tdrp_bool_t apply_median_filter_to_PID;

  int PID_median_filter_len;

  tdrp_bool_t use_soundings_from_spdb;

  char* sounding_spdb_url;

  int sounding_search_time_margin_secs;

  char* sounding_location_name;

  tdrp_bool_t sounding_check_pressure_range;

  data_range_t sounding_required_pressure_range_hpa;

  tdrp_bool_t sounding_check_height_range;

  data_range_t sounding_required_height_range_m;

  tdrp_bool_t sounding_check_pressure_monotonically_decreasing;

  double sounding_height_correction_km;

  tdrp_bool_t sounding_use_wet_bulb_temp;

  tdrp_bool_t read_site_temp_from_spdb;

  char* site_temp_spdb_url;

  char* site_temp_station_name;

  int site_temp_search_margin_secs;

  output_field_t *_output_fields;
  int output_fields_n;

  output_format_t output_format;

  netcdf_style_t netcdf_style;

  tdrp_bool_t output_native_byte_order;

  tdrp_bool_t output_compressed;

  int compression_level;

  tdrp_bool_t write_output_volume;

  char* output_dir;

  filename_mode_t output_filename_mode;

  char* output_filename;

  tdrp_bool_t append_day_dir_to_output_dir;

  tdrp_bool_t append_year_dir_to_output_dir;

  tdrp_bool_t write_individual_sweeps;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[148];

  const char *_className;

  bool _exitDeferred;

};

#endif

