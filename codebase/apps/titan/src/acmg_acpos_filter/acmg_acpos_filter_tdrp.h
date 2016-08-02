/*******************************************
 * acmg_acpos_filter_tdrp.h
 *
 * TDRP header file for 'acmg_acpos_filter' module.
 *
 * Code for program acmg_acpos_filter
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _acmg_acpos_filter_tdrp_h
#define _acmg_acpos_filter_tdrp_h

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
} acmg_acpos_filter_debug;

/*
 * typedef for main struct - acmg_acpos_filter_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug *****/

  acmg_acpos_filter_debug debug;

  /***** malloc_debug_level *****/

  long malloc_debug_level;

  /***** output_dir *****/

  char* output_dir;

  /***** output_file_ext *****/

  char* output_file_ext;

  /***** call_sign *****/

  char* call_sign;

} acmg_acpos_filter_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * acmg_acpos_filter_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   acmg_acpos_filter_tdrp_struct *params: loads up this struct
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

extern int acmg_acpos_filter_tdrp_load_from_args(int argc, char **argv,
                                acmg_acpos_filter_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * acmg_acpos_filter_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than acmg_acpos_filter_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   acmg_acpos_filter_tdrp_struct *params: loads up this struct
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

extern int acmg_acpos_filter_tdrp_load(char *param_file_path,
                      acmg_acpos_filter_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * acmg_acpos_filter_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See acmg_acpos_filter_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int acmg_acpos_filter_tdrp_load_defaults(acmg_acpos_filter_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * acmg_acpos_filter_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void acmg_acpos_filter_tdrp_sync(void);

/*************************************************************
 * acmg_acpos_filter_tdrp_print()
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

extern void acmg_acpos_filter_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * acmg_acpos_filter_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void acmg_acpos_filter_tdrp_free_all(void);

/*************************************************************
 * acmg_acpos_filter_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int acmg_acpos_filter_tdrp_check_all_set(FILE *out);

/*************************************************************
 * acmg_acpos_filter_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int acmg_acpos_filter_tdrp_check_is_set(char *param_name);

/*************************************************************
 * acmg_acpos_filter_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int acmg_acpos_filter_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * acmg_acpos_filter_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int acmg_acpos_filter_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * acmg_acpos_filter_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *acmg_acpos_filter_tdrp_table(void);

/*************************************************************
 * acmg_acpos_filter_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *acmg_acpos_filter_tdrp_init(acmg_acpos_filter_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

