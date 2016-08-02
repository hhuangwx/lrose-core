/*
 * data_pu_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `data_pu.G'.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include "cidd_gui.h"
#include <group.h>


/*
 * Notify callback function for `data_st'.
 */
void
set_data_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	data_pu_data_pu_objects *ip = (data_pu_data_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: set_data_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}
