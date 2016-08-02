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
 * parse_args.c: parse command line args
 *
 * RAP, NCAR, Boulder CO
 *
 * July 1996
 *
 * Mike Dixon
 *
 *********************************************************************/

#include "print_spdb.h"

static si32 load_time(char *time_str, char *label);

void parse_args(int argc,
		char **argv,
		int *check_params_p,
		int *print_params_p,
		tdrp_override_t *override,
		char **params_file_path_p)

{

  int error_flag = 0;
  int i;

  char usage[BUFSIZ];
  char tmp_str[BUFSIZ];

  /*
   * set usage string
   */

  sprintf(usage, "%s%s%s%s",
	  "Usage: ", Glob->prog_name, " [options as below]\n",
	  "options:\n"
	  "       [ --, -h, -help, -man ] produce this list.\n"
	  "       [ -check_params ] check parameter usage\n"
	  "       [ -closest yyyy/mm/dd_hh:mm:ss ] get data at this time\n"
	  "       [ -end_time yyyy/mm/dd_hh:mm:ss ] end time\n"
	  "       [ -debug ] print debug messages\n"
	  "       [ -db_dir ?] product data base dir\n"
	  "       [ -hdr_time yyyy/mm/dd_hh:mm:ss ] print hdr for this time\n"
	  "       [ -mdebug level ] set malloc debug level\n"
	  "       [ -params ?] params path name\n"
	  "       [ -print_params ] print parameter usage\n"
	  "       [ -start_time yyyy/mm/dd_hh:mm:ss ] start time\n"
	  "       [ -valid_time yyyy/mm/dd_hh:mm:ss ]\n"
	  "                               print data valid for this time\n"
	  "\n"
     	  "  If no starttime or endtime specified, the entire data base\n"
	  "  will be printed out."
	  "\n");
  
  /*
   * initialize
   */
  
  *check_params_p = FALSE;
  *print_params_p = FALSE;
  TDRP_init_override(override);
  Glob->closest_time = -1;
  Glob->start_time = -1;
  Glob->hdr_time = -1;
  Glob->valid_time = -1;
  Glob->end_time = 2147480; /* nearly largest si32 */

  /*
   * look for command options
   */

  for (i =  1; i < argc; i++) {

    if (!strcmp(argv[i], "--") ||
	!strcmp(argv[i], "-h") ||
	!strcmp(argv[i], "-help") ||
	!strcmp(argv[i], "-man")) {
      
      fprintf(stderr, "%s", usage);
      exit(0);
      
    } else if (!strcmp(argv[i], "-check_params")) {
      
      *check_params_p = TRUE;
      
    } else if (!strcmp(argv[i], "-debug")) {
      
      sprintf(tmp_str, "debug = DEBUG_NORM;");
      TDRP_add_override(override, tmp_str);
      
    } else if (!strcmp(argv[i], "-closest")) {
      
      if (i < argc - 1) {
	if ((Glob->closest_time = load_time(argv[i+1], "closest")) < 0) {
	  error_flag = 0;
	}
      } else {
	error_flag = TRUE;
      }

    } else if (!strcmp(argv[i], "-db_dir")) {
      
      if (i < argc - 1) {
	sprintf(tmp_str, "data_base_dir = \"%s\";", argv[i+1]);
	TDRP_add_override(override, tmp_str);
      } else {
	error_flag = TRUE;
      }
	
    } else if (!strcmp(argv[i], "-mdebug")) {
      
      if (i < argc - 1) {
	sprintf(tmp_str, "malloc_debug_level = %s;", argv[i+1]);
	TDRP_add_override(override, tmp_str);
      } else {
	error_flag = TRUE;
      }
	
    } else if (!strcmp(argv[i], "-params")) {
      
      if (i < argc - 1) {
	*params_file_path_p = argv[i+1];
      } else {
	error_flag = TRUE;
      }
      
    } else if (!strcmp(argv[i], "-print_params")) {
      
      *print_params_p = TRUE;
      
    } else if (!strcmp(argv[i], "-end_time")) {
      
      if (i < argc - 1) {
	if ((Glob->end_time = load_time(argv[i+1], "end")) < 0) {
	  error_flag = 0;
	}
      } else {
	error_flag = TRUE;
      }

    } else if (!strcmp(argv[i], "-start_time")) {
      
      if (i < argc - 1) {
	if ((Glob->start_time = load_time(argv[i+1], "start")) < 0) {
	  error_flag = 0;
	}
      } else {
	error_flag = TRUE;
      }

    } else if (!strcmp(argv[i], "-hdr_time")) {
      
      if (i < argc - 1) {
	if ((Glob->hdr_time = load_time(argv[i+1], "hdr")) < 0) {
	  error_flag = 0;
	}
      } else {
	error_flag = TRUE;
      }

    } else if (!strcmp(argv[i], "-valid_time")) {
      
      if (i < argc - 1) {
	if ((Glob->valid_time = load_time(argv[i+1], "valid")) < 0) {
	  error_flag = 0;
	}
      } else {
	error_flag = TRUE;
      }

    } /* if */
    
  } /* i */

  /*
   * print message if error flag set
   */

  if(error_flag) {
    fprintf(stderr, "%s", usage);
  }
  
  if (error_flag)
    exit(-1);
  
}

/*
 * load time from string - returns -1 on error
 */

static si32 load_time(char *time_str, char *label)


{

  UTIMstruct dtime;

  if (sscanf(time_str, "%ld/%ld/%ld_%ld:%ld:%ld",
	     &dtime.year,
	     &dtime.month,
	     &dtime.day,
	     &dtime.hour,
	     &dtime.min,
	     &dtime.sec) != 6) {
    
    fprintf(stderr, "ERROR - %s:parse_args:load_time\n", Glob->prog_name);
    fprintf(stderr, "Incorrect format for %s time.\n", label);
    fprintf(stderr, "Trying to decode '%s'\n", time_str);
    fprintf(stderr, "Format is yyyy/mm/dd_hh:mm:ss\n");
    return (-1L);
  }
    
  return (UTIMdate_to_unix(&dtime));

}
