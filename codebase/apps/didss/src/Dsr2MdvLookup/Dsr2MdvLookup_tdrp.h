/*******************************************
 * Dsr2MdvLookup_tdrp.h
 *
 * TDRP header file for 'Dsr2MdvLookup' module.
 *
 * Code for program Dsr2MdvLookup
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _Dsr2MdvLookup_tdrp_h
#define _Dsr2MdvLookup_tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

typedef enum {
  DEBUG_OFF = 0,
  DEBUG_WARNINGS = 1,
  DEBUG_NORM = 2,
  DEBUG_EXTRA = 3
} Dsr2MdvLookup_debug;

typedef enum {
  CART_GEOM = 0,
  PPI_GEOM = 1,
  POLAR_GEOM = 2
} Dsr2MdvLookup_geom_type;

typedef struct {
  double latitude;
  double longitude;
  double altitude;
} Dsr2MdvLookup_radar_location;

typedef struct {
  double origin_lat;
  double origin_lon;
  double rotation;
  long nx;
  long ny;
  long nz;
  double minx;
  double miny;
  double minz;
  double dx;
  double dy;
  double dz;
} Dsr2MdvLookup_output_grid;

/*
 * typedef for main struct - Dsr2MdvLookup_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug *****/

  Dsr2MdvLookup_debug debug;

  /***** malloc_debug_level *****/

  long malloc_debug_level;

  /***** geom_type *****/

  Dsr2MdvLookup_geom_type geom_type;

  /***** lookup_table_path *****/

  char* lookup_table_path;

  /***** elev_target *****/

  struct {
    double *val;
    int len;
  } elev_target;
  double *_elev_target;
  int elev_target_n;

  /***** nazimuths *****/

  long nazimuths;

  /***** start_azimuth *****/

  double start_azimuth;

  /***** delta_azimuth *****/

  double delta_azimuth;

  /***** use_azimuth_table *****/

  tdrp_bool_t use_azimuth_table;

  /***** azimuth_table_path *****/

  char* azimuth_table_path;

  /***** beam_width *****/

  double beam_width;

  /***** ngates *****/

  long ngates;

  /***** start_range *****/

  double start_range;

  /***** gate_spacing *****/

  double gate_spacing;

  /***** radar_location *****/

  Dsr2MdvLookup_radar_location radar_location;

  /***** output_grid *****/

  Dsr2MdvLookup_output_grid output_grid;

  /***** extend_below *****/

  tdrp_bool_t extend_below;

} Dsr2MdvLookup_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * Dsr2MdvLookup_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   Dsr2MdvLookup_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int Dsr2MdvLookup_tdrp_load_from_args(int argc, char **argv,
                                Dsr2MdvLookup_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * Dsr2MdvLookup_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than Dsr2MdvLookup_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   Dsr2MdvLookup_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int Dsr2MdvLookup_tdrp_load(char *param_file_path,
                      Dsr2MdvLookup_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * Dsr2MdvLookup_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See Dsr2MdvLookup_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int Dsr2MdvLookup_tdrp_load_defaults(Dsr2MdvLookup_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * Dsr2MdvLookup_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void Dsr2MdvLookup_tdrp_sync(void);

/*************************************************************
 * Dsr2MdvLookup_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

extern void Dsr2MdvLookup_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * Dsr2MdvLookup_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void Dsr2MdvLookup_tdrp_free_all(void);

/*************************************************************
 * Dsr2MdvLookup_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int Dsr2MdvLookup_tdrp_check_all_set(FILE *out);

/*************************************************************
 * Dsr2MdvLookup_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int Dsr2MdvLookup_tdrp_check_is_set(char *param_name);

/*************************************************************
 * Dsr2MdvLookup_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int Dsr2MdvLookup_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * Dsr2MdvLookup_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int Dsr2MdvLookup_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * Dsr2MdvLookup_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *Dsr2MdvLookup_tdrp_table(void);

/*************************************************************
 * Dsr2MdvLookup_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *Dsr2MdvLookup_tdrp_init(Dsr2MdvLookup_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

