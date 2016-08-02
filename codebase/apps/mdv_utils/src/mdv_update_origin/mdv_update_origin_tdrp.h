/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/*******************************************
 * mdv_update_origin_tdrp.h
 *
 * TDRP header file for 'mdv_update_origin' module.
 *
 * Code for program mdv_update_origin
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _mdv_update_origin_tdrp_h
#define _mdv_update_origin_tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

/*
 * typedef for main struct - mdv_update_origin_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug_flag *****/

  tdrp_bool_t debug_flag;

  /***** malloc_debug_level *****/

  long malloc_debug_level;

  /***** new_grid_origin_lat *****/

  double new_grid_origin_lat;

  /***** new_grid_origin_lon *****/

  double new_grid_origin_lon;

} mdv_update_origin_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * mdv_update_origin_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   mdv_update_origin_tdrp_struct *params: loads up this struct
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

extern int mdv_update_origin_tdrp_load_from_args(int argc, char **argv,
                                mdv_update_origin_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * mdv_update_origin_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than mdv_update_origin_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   mdv_update_origin_tdrp_struct *params: loads up this struct
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

extern int mdv_update_origin_tdrp_load(char *param_file_path,
                      mdv_update_origin_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * mdv_update_origin_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See mdv_update_origin_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int mdv_update_origin_tdrp_load_defaults(mdv_update_origin_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * mdv_update_origin_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void mdv_update_origin_tdrp_sync(void);

/*************************************************************
 * mdv_update_origin_tdrp_print()
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

extern void mdv_update_origin_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * mdv_update_origin_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void mdv_update_origin_tdrp_free_all(void);

/*************************************************************
 * mdv_update_origin_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int mdv_update_origin_tdrp_check_all_set(FILE *out);

/*************************************************************
 * mdv_update_origin_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int mdv_update_origin_tdrp_check_is_set(char *param_name);

/*************************************************************
 * mdv_update_origin_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int mdv_update_origin_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * mdv_update_origin_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int mdv_update_origin_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * mdv_update_origin_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *mdv_update_origin_tdrp_table(void);

/*************************************************************
 * mdv_update_origin_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *mdv_update_origin_tdrp_init(mdv_update_origin_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

