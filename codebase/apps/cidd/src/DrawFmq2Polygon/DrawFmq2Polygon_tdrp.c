/*******************************************
 * DrawFmq2Polygon_tdrp.c
 *
 * TDRP C code file 'DrawFmq2Polygon' module.
 *
 * Code for program DrawFmq2Polygon
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "DrawFmq2Polygon_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[6];
static DrawFmq2Polygon_tdrp_struct *Params;
static char *Module = "DrawFmq2Polygon";

/*************************************************************
 * DrawFmq2Polygon_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   DrawFmq2Polygon_tdrp_struct *params: loads up this struct
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

int DrawFmq2Polygon_tdrp_load_from_args(int argc, char **argv,
                         DrawFmq2Polygon_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  DrawFmq2Polygon_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than DrawFmq2Polygon_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   DrawFmq2Polygon_tdrp_struct *params: loads up this struct
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

int DrawFmq2Polygon_tdrp_load(char *param_file_path,
               DrawFmq2Polygon_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  DrawFmq2Polygon_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See DrawFmq2Polygon_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int DrawFmq2Polygon_tdrp_load_defaults(DrawFmq2Polygon_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  DrawFmq2Polygon_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void DrawFmq2Polygon_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_print()
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

void DrawFmq2Polygon_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int DrawFmq2Polygon_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int DrawFmq2Polygon_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void DrawFmq2Polygon_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int DrawFmq2Polygon_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int DrawFmq2Polygon_tdrp_array2D_realloc(char *param_name,
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
 * DrawFmq2Polygon_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *DrawFmq2Polygon_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * DrawFmq2Polygon_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *DrawFmq2Polygon_tdrp_init(DrawFmq2Polygon_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  DrawFmq2Polygon_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(DrawFmq2Polygon_tdrp_struct));
  params->struct_size = sizeof(DrawFmq2Polygon_tdrp_struct);

  /* Parameter 'instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("instance");
  tt->descr = tdrpStrDup("Process instance");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("generic");
  tt++;
  
  /* Parameter 'draw_fmq_url' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("draw_fmq_url");
  tt->descr = tdrpStrDup("Input URL for Draw fmq ");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.draw_fmq_url) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("fmqp:://localhost::fmq/draw.fmq");
  tt++;
  
  /* Parameter 'debug' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug messaging option");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'log_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("log_dir");
  tt->descr = tdrpStrDup("Directory for log file output");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.log_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("");
  tt++;
  
  /* Parameter 'HIP' */
  /* ctype is 'DrawFmq2Polygon_HIB_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("HIP");
  tt->descr = tdrpStrDup("Polygon types to recognise. Match labels with those defined in CIDD's DRAW_EXPORT param section");
  tt->help = tdrpStrDup(" ID_label: - Type of product to match on.  Dest_url: - Destination URL for SPDB Boundries ");
  tt->val_offset = (char *) &(pp.HIP.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.HIP.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._HIP) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.HIP_n) - (char *) &pp;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(DrawFmq2Polygon_HIB_t);
  tt->array_n = 3;
  tt->struct_def.name = tdrpStrDup("HIB_t");
  tt->struct_def.nfields = 2;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("string");
    tt->struct_def.fields[0].fname = tdrpStrDup("ID_label");
    tt->struct_def.fields[0].ptype = STRING_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.HIP.val->ID_label) - (char *) pp.HIP.val;
    tt->struct_def.fields[1].ftype = tdrpStrDup("string");
    tt->struct_def.fields[1].fname = tdrpStrDup("dest_url");
    tt->struct_def.fields[1].ptype = STRING_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.HIP.val->dest_url) - (char *) pp.HIP.val;
  tt->n_struct_vals = 6;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].s = tdrpStrDup("Polygon-E");
    tt->struct_vals[1].s = tdrpStrDup("spdbp:://localhost::spdb/polygon/test-e");
    tt->struct_vals[2].s = tdrpStrDup("Polygon-F");
    tt->struct_vals[3].s = tdrpStrDup("spdbp:://localhost::spdb/polygon/test-f");
    tt->struct_vals[4].s = tdrpStrDup("Polygon-S");
    tt->struct_vals[5].s = tdrpStrDup("spdbp:://localhost::spdb/polygon/test-s");
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
