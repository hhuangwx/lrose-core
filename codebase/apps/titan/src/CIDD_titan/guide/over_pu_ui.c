/*
 * over_pu_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `over_pu.G'.
 * DO NOT EDIT BY HAND.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/canvas.h>
#include <xview/panel.h>
#include <xview/scrollbar.h>
#include <xview/svrimage.h>
#include <xview/termsw.h>
#include <xview/text.h>
#include <xview/tty.h>
#include <xview/xv_xrect.h>
#include "over_pu_ui.h"

/*
 * Initialize an instance of object `over_pu'.
 */
over_pu_over_pu_objects *
over_pu_over_pu_objects_initialize(over_pu_over_pu_objects *ip, Xv_opaque owner)
{
	if (!ip && !(ip = (over_pu_over_pu_objects *) calloc(1, sizeof (over_pu_over_pu_objects))))
		return (over_pu_over_pu_objects *) NULL;
	if (!ip->over_pu)
		ip->over_pu = over_pu_over_pu_over_pu_create(ip, owner);
	if (!ip->over_cp)
		ip->over_cp = over_pu_over_pu_over_cp_create(ip, ip->over_pu);
	if (!ip->over_lst)
		ip->over_lst = over_pu_over_pu_over_lst_create(ip, ip->over_cp);
	if (!ip->over_pu_st)
		ip->over_pu_st = over_pu_over_pu_over_pu_st_create(ip, ip->over_cp);
	return ip;
}

/*
 * Create object `over_pu' in the specified instance.
 */
Xv_opaque
over_pu_over_pu_over_pu_create(over_pu_over_pu_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME_CMD,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 237,
		XV_HEIGHT, 150,
		XV_LABEL, "Maps",
		XV_SHOW, FALSE,
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, FALSE,
		FRAME_CMD_PUSHPIN_IN, TRUE,
		NULL);
	xv_set(xv_get(obj, FRAME_CMD_PANEL), WIN_SHOW, FALSE, NULL);
	return obj;
}

/*
 * Create object `over_cp' in the specified instance.
 */
Xv_opaque
over_pu_over_pu_over_cp_create(over_pu_over_pu_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		WIN_BORDER, FALSE,
		NULL);
	return obj;
}

/*
 * Create object `over_lst' in the specified instance.
 */
Xv_opaque
over_pu_over_pu_over_lst_create(over_pu_over_pu_objects *ip, Xv_opaque owner)
{
	extern int		over_list_proc(Panel_item, char *, Xv_opaque, Panel_list_op, Event *, int);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_LIST,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		PANEL_LIST_WIDTH, 200,
		PANEL_LIST_DISPLAY_ROWS, 3,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_CHOOSE_ONE, FALSE,
		PANEL_CHOOSE_NONE, TRUE,
		PANEL_NOTIFY_PROC, over_list_proc,
		NULL);
	return obj;
}

/*
 * Create object `over_pu_st' in the specified instance.
 */
Xv_opaque
over_pu_over_pu_over_pu_st_create(over_pu_over_pu_objects *ip, Xv_opaque owner)
{
	extern void		over_pu_proc(Panel_item, unsigned int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TOGGLE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 2,
		XV_Y, 2,
		PANEL_CHOICE_NCOLS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_NOTIFY_PROC, over_pu_proc,
		NULL);
	return obj;
}

