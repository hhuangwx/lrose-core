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
/*********************************************************************
 * read_params.c
 *
 * reads parameter values from the parameters data base into
 * the global struct
 *
 * Mike Dixon
 *
 * RAP, NCAR, Boulder, CO, USA
 *
 * December 1990
 *
 *********************************************************************/

#include "clutter_table_generate.h"

void read_params(void)

{

  Glob->dbz_field = uGetParamLong(Glob->prog_name,
				  "dbz_field",
				  DBZ_FIELD);

  Glob->dbz_margin = uGetParamDouble(Glob->prog_name,
				     "dbz_margin",
				     DBZ_MARGIN);

  Glob->dbz_threshold = uGetParamDouble(Glob->prog_name,
					"dbz_threshold",
					DBZ_THRESHOLD);

  Glob->rc_table_path = uGetParamString(Glob->prog_name,
					"rc_table_path",
					RC_TABLE_PATH);

  Glob->clutter_file_path = uGetParamString(Glob->prog_name,
					    "clutter_file_path",
					    CLUTTER_FILE_PATH);

  Glob->clutter_table_path = uGetParamString(Glob->prog_name,
					     "clutter_table_path",
					     CLUTTER_TABLE_PATH);

}
