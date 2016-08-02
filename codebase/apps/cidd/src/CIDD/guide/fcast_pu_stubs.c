/*
 * fcast_pu_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `fcast_pu.G'.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include "cidd_gui.h"


/*
 * Notify callback function for `fcast_st'.
 */
void
set_fcast_tm_proc(Panel_item item, int value, Event *event)
{
	fcast_pu_fcast_pu_objects *ip = (fcast_pu_fcast_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: set_fcast_tm_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}
