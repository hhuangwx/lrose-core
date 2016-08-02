/*******************************************
 * Dsr2MdvLookup_tdrp.c
 *
 * TDRP C code file 'Dsr2MdvLookup' module.
 *
 * Code for program Dsr2MdvLookup
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "Dsr2MdvLookup_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[18];
static Dsr2MdvLookup_tdrp_struct *Params;
static char *Module = "Dsr2MdvLookup";

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

int Dsr2MdvLookup_tdrp_load_from_args(int argc, char **argv,
                         Dsr2MdvLookup_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  Dsr2MdvLookup_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

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

int Dsr2MdvLookup_tdrp_load(char *param_file_path,
               Dsr2MdvLookup_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  Dsr2MdvLookup_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See Dsr2MdvLookup_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int Dsr2MdvLookup_tdrp_load_defaults(Dsr2MdvLookup_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  Dsr2MdvLookup_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void Dsr2MdvLookup_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

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

void Dsr2MdvLookup_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int Dsr2MdvLookup_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int Dsr2MdvLookup_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void Dsr2MdvLookup_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

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

int Dsr2MdvLookup_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

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

int Dsr2MdvLookup_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *Dsr2MdvLookup_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * Dsr2MdvLookup_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *Dsr2MdvLookup_tdrp_init(Dsr2MdvLookup_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  Dsr2MdvLookup_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(Dsr2MdvLookup_tdrp_struct));
  params->struct_size = sizeof(Dsr2MdvLookup_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'Dsr2MdvLookup_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
  tt->enum_def.nfields = 4;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_WARNINGS");
    tt->enum_def.fields[1].val = DEBUG_WARNINGS;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[2].val = DEBUG_NORM;
    tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
    tt->enum_def.fields[3].val = DEBUG_EXTRA;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("Malloc debug level");
  tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'geom_type' */
  /* ctype is 'Dsr2MdvLookup_geom_type' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("geom_type");
  tt->descr = tdrpStrDup("Geometry type for MDV grid.");
  tt->help = tdrpStrDup("There are 3 geometry types: CART_GEOM - Cartesian volume grid (km x km x km) (default), PPI_GEOM - Cartesian ppi grid (deg x km x km), and POLAR_GEOM - polar grid [el x az x gate] (deg x deg x km).");
  tt->val_offset = (char *) &(pp.geom_type) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("geom_type");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("CART_GEOM");
    tt->enum_def.fields[0].val = CART_GEOM;
    tt->enum_def.fields[1].name = tdrpStrDup("PPI_GEOM");
    tt->enum_def.fields[1].val = PPI_GEOM;
    tt->enum_def.fields[2].name = tdrpStrDup("POLAR_GEOM");
    tt->enum_def.fields[2].val = POLAR_GEOM;
  tt->single_val.e = CART_GEOM;
  tt++;
  
  /* Parameter 'lookup_table_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("lookup_table_path");
  tt->descr = tdrpStrDup("File path for lookup table - output.");
  tt->help = tdrpStrDup("The generated lookup table file has this file path.");
  tt->val_offset = (char *) &(pp.lookup_table_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("polar2mdv_lookup");
  tt++;
  
  /* Parameter 'elev_target' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("elev_target");
  tt->descr = tdrpStrDup("Target elevation array (deg)");
  tt->help = tdrpStrDup("Array of target radar elevations. The actual elevation data is rounded to the values in this array.");
  tt->val_offset = (char *) &(pp.elev_target.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.elev_target.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._elev_target) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.elev_target_n) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(double);
  tt->array_n = 1;
  tt->min_val.d = -10;
  tt->max_val.d = 180;
  tt->array_vals = (tdrpVal_t *)
      tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt->array_vals[0].d = 0.5;
  tt++;
  
  /* Parameter 'nazimuths' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("nazimuths");
  tt->descr = tdrpStrDup("Number of radar beam azimuths in the azimuth array.");
  tt->help = tdrpStrDup("This is the expected number of radar azimuths. See also start_azimuth and delta_azimuth");
  tt->val_offset = (char *) &(pp.nazimuths) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 10;
  tt->max_val.l = 36000;
  tt->single_val.l = 360;
  tt++;
  
  /* Parameter 'start_azimuth' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("start_azimuth");
  tt->descr = tdrpStrDup("Azimuth of first entry in azimith array (deg).");
  tt->help = tdrpStrDup("The azimuths in the array are determined using this start value and the delta_azimuth. See also nazimuths and delta_azimuth.");
  tt->val_offset = (char *) &(pp.start_azimuth) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -360;
  tt->max_val.d = 360;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'delta_azimuth' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("delta_azimuth");
  tt->descr = tdrpStrDup("Delta azimuth between entries in the azimith array (deg).");
  tt->help = tdrpStrDup("The azimuths in the array are determined using the start_azimuth value and this delta_azimuth value. See also nazimuths and start_azimuth.");
  tt->val_offset = (char *) &(pp.delta_azimuth) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -90;
  tt->max_val.d = 90;
  tt->single_val.d = 1;
  tt++;
  
  /* Parameter 'use_azimuth_table' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("use_azimuth_table");
  tt->descr = tdrpStrDup("Option to use irregular azimuth array.");
  tt->help = tdrpStrDup("This option allows the user to set up an irregular azimuth array instead of the regular one using nazimuths, start_azimuth and delta_azimuth. If set, the file specified by azimuth_table_file is read in to create the irregular azimuth array.");
  tt->val_offset = (char *) &(pp.use_azimuth_table) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'azimuth_table_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("azimuth_table_path");
  tt->descr = tdrpStrDup("File path for irregular azimuth table - input.");
  tt->help = tdrpStrDup("The scan strategy for an irregular azimuth pattern in stored in this file. See also use_azimuth_table.");
  tt->val_offset = (char *) &(pp.azimuth_table_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("azimuth_table");
  tt++;
  
  /* Parameter 'beam_width' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("beam_width");
  tt->descr = tdrpStrDup("Radar beam-width.");
  tt->help = tdrpStrDup("The beam-width specifies how far to spread the influence of the data from the target elevations.");
  tt->val_offset = (char *) &(pp.beam_width) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0.0001;
  tt->max_val.d = 90;
  tt->single_val.d = 1;
  tt++;
  
  /* Parameter 'ngates' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("ngates");
  tt->descr = tdrpStrDup("Number of gates along a radial.");
  tt->help = tdrpStrDup("polar2mdv only supports constant gate spacing.");
  tt->val_offset = (char *) &(pp.ngates) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 1;
  tt->max_val.l = 100000;
  tt->single_val.l = 500;
  tt++;
  
  /* Parameter 'start_range' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("start_range");
  tt->descr = tdrpStrDup("Range to center of first gate (km).");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.start_range) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = -100;
  tt->max_val.d = 10000;
  tt->single_val.d = 0.1;
  tt++;
  
  /* Parameter 'gate_spacing' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("gate_spacing");
  tt->descr = tdrpStrDup("Distance between centers of adjacent gates (km).");
  tt->help = tdrpStrDup("Polar2mdv only supports constant gate spacing.");
  tt->val_offset = (char *) &(pp.gate_spacing) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.d = 0;
  tt->max_val.d = 100;
  tt->single_val.d = 0.1;
  tt++;
  
  /* Parameter 'radar_location' */
  /* ctype is 'Dsr2MdvLookup_radar_location' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("radar_location");
  tt->descr = tdrpStrDup("Radar location.");
  tt->help = tdrpStrDup("Lat and lon in degrees, altitude in km MSL.");
  tt->val_offset = (char *) &(pp.radar_location) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("radar_location");
  tt->struct_def.nfields = 3;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("double");
    tt->struct_def.fields[0].fname = tdrpStrDup("latitude");
    tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.radar_location.latitude) - (char *) &(pp.radar_location);
    tt->struct_def.fields[1].ftype = tdrpStrDup("double");
    tt->struct_def.fields[1].fname = tdrpStrDup("longitude");
    tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.radar_location.longitude) - (char *) &(pp.radar_location);
    tt->struct_def.fields[2].ftype = tdrpStrDup("double");
    tt->struct_def.fields[2].fname = tdrpStrDup("altitude");
    tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[2].rel_offset = 
      (char *) &(pp.radar_location.altitude) - (char *) &(pp.radar_location);
  tt->n_struct_vals = 3;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].d = 0;
    tt->struct_vals[1].d = 0;
    tt->struct_vals[2].d = 0;
  tt++;
  
  /* Parameter 'output_grid' */
  /* ctype is 'Dsr2MdvLookup_output_grid' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("output_grid");
  tt->descr = tdrpStrDup("MDV output grid parameters.");
  tt->help = tdrpStrDup("For CART_GEOM, all fields are used. For PPI_GEOM, nelevations (from elevation array) overrides nz. For POLAR_GEOM, nelevations overrides nz, nazimuths overrides ny, start_azimuth overrides miny, delta_azimuth overrides dy, ngates overrides nx, start_range overrides minx and gate_spacing overrides dx.");
  tt->val_offset = (char *) &(pp.output_grid) - (char *) &pp;
  tt->struct_def.name = tdrpStrDup("output_grid");
  tt->struct_def.nfields = 12;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("double");
    tt->struct_def.fields[0].fname = tdrpStrDup("origin_lat");
    tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.output_grid.origin_lat) - (char *) &(pp.output_grid);
    tt->struct_def.fields[1].ftype = tdrpStrDup("double");
    tt->struct_def.fields[1].fname = tdrpStrDup("origin_lon");
    tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.output_grid.origin_lon) - (char *) &(pp.output_grid);
    tt->struct_def.fields[2].ftype = tdrpStrDup("double");
    tt->struct_def.fields[2].fname = tdrpStrDup("rotation");
    tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[2].rel_offset = 
      (char *) &(pp.output_grid.rotation) - (char *) &(pp.output_grid);
    tt->struct_def.fields[3].ftype = tdrpStrDup("long");
    tt->struct_def.fields[3].fname = tdrpStrDup("nx");
    tt->struct_def.fields[3].ptype = LONG_TYPE;
    tt->struct_def.fields[3].rel_offset = 
      (char *) &(pp.output_grid.nx) - (char *) &(pp.output_grid);
    tt->struct_def.fields[4].ftype = tdrpStrDup("long");
    tt->struct_def.fields[4].fname = tdrpStrDup("ny");
    tt->struct_def.fields[4].ptype = LONG_TYPE;
    tt->struct_def.fields[4].rel_offset = 
      (char *) &(pp.output_grid.ny) - (char *) &(pp.output_grid);
    tt->struct_def.fields[5].ftype = tdrpStrDup("long");
    tt->struct_def.fields[5].fname = tdrpStrDup("nz");
    tt->struct_def.fields[5].ptype = LONG_TYPE;
    tt->struct_def.fields[5].rel_offset = 
      (char *) &(pp.output_grid.nz) - (char *) &(pp.output_grid);
    tt->struct_def.fields[6].ftype = tdrpStrDup("double");
    tt->struct_def.fields[6].fname = tdrpStrDup("minx");
    tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[6].rel_offset = 
      (char *) &(pp.output_grid.minx) - (char *) &(pp.output_grid);
    tt->struct_def.fields[7].ftype = tdrpStrDup("double");
    tt->struct_def.fields[7].fname = tdrpStrDup("miny");
    tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[7].rel_offset = 
      (char *) &(pp.output_grid.miny) - (char *) &(pp.output_grid);
    tt->struct_def.fields[8].ftype = tdrpStrDup("double");
    tt->struct_def.fields[8].fname = tdrpStrDup("minz");
    tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[8].rel_offset = 
      (char *) &(pp.output_grid.minz) - (char *) &(pp.output_grid);
    tt->struct_def.fields[9].ftype = tdrpStrDup("double");
    tt->struct_def.fields[9].fname = tdrpStrDup("dx");
    tt->struct_def.fields[9].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[9].rel_offset = 
      (char *) &(pp.output_grid.dx) - (char *) &(pp.output_grid);
    tt->struct_def.fields[10].ftype = tdrpStrDup("double");
    tt->struct_def.fields[10].fname = tdrpStrDup("dy");
    tt->struct_def.fields[10].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[10].rel_offset = 
      (char *) &(pp.output_grid.dy) - (char *) &(pp.output_grid);
    tt->struct_def.fields[11].ftype = tdrpStrDup("double");
    tt->struct_def.fields[11].fname = tdrpStrDup("dz");
    tt->struct_def.fields[11].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[11].rel_offset = 
      (char *) &(pp.output_grid.dz) - (char *) &(pp.output_grid);
  tt->n_struct_vals = 12;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].d = 0;
    tt->struct_vals[1].d = 0;
    tt->struct_vals[2].d = 0;
    tt->struct_vals[3].l = 0;
    tt->struct_vals[4].l = 0;
    tt->struct_vals[5].l = 0;
    tt->struct_vals[6].d = 0;
    tt->struct_vals[7].d = 0;
    tt->struct_vals[8].d = 0;
    tt->struct_vals[9].d = 0;
    tt->struct_vals[10].d = 0;
    tt->struct_vals[11].d = 0;
  tt++;
  
  /* Parameter 'extend_below' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("extend_below");
  tt->descr = tdrpStrDup("Option to extend the data below the lowest PPI.");
  tt->help = tdrpStrDup("If set, data from the lowest PPI is used to populate all points below that PPI in the grid. Only applies to CART_GEOM");
  tt->val_offset = (char *) &(pp.extend_below) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
