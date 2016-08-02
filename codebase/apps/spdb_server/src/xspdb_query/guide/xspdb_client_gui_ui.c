/*
 * xspdb_client_gui_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `xspdb_client_gui.G'.
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
#include <gcm.h>
#include <group.h>
#include "xspdb_client_gui_ui.h"

/*
 * Initialize an instance of object `window1'.
 */
xspdb_client_gui_window1_objects *
xspdb_client_gui_window1_objects_initialize(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	if (!ip && !(ip = (xspdb_client_gui_window1_objects *) calloc(1, sizeof (xspdb_client_gui_window1_objects))))
		return (xspdb_client_gui_window1_objects *) NULL;
	if (!ip->window1)
		ip->window1 = xspdb_client_gui_window1_window1_create(ip, owner);
	if (!ip->controls1)
		ip->controls1 = xspdb_client_gui_window1_controls1_create(ip, ip->window1);
	if (!ip->now_bt)
		ip->now_bt = xspdb_client_gui_window1_now_bt_create(ip, ip->controls1);
	if (!ip->source_tx)
		ip->source_tx = xspdb_client_gui_window1_source_tx_create(ip, ip->controls1);
	if (!ip->prod_typ_st)
		ip->prod_typ_st = xspdb_client_gui_window1_prod_typ_st_create(ip, ip->controls1);
	if (!ip->prod_id_tx)
		ip->prod_id_tx = xspdb_client_gui_window1_prod_id_tx_create(ip, ip->controls1);
	if (!ip->req_typ_st)
		ip->req_typ_st = xspdb_client_gui_window1_req_typ_st_create(ip, ip->controls1);
	if (!ip->group1)
		ip->group1 = xspdb_client_gui_window1_group1_create(ip, ip->controls1);
	if (!ip->end_tx)
		ip->end_tx = xspdb_client_gui_window1_end_tx_create(ip, ip->controls1);
	if (!ip->time_delta_ntx)
		ip->time_delta_ntx = xspdb_client_gui_window1_time_delta_ntx_create(ip, ip->controls1);
	if (!ip->min_msg)
		ip->min_msg = xspdb_client_gui_window1_min_msg_create(ip, ip->controls1);
	if (!ip->submit_bt)
		ip->submit_bt = xspdb_client_gui_window1_submit_bt_create(ip, ip->controls1);
	if (!ip->clear_bt)
		ip->clear_bt = xspdb_client_gui_window1_clear_bt_create(ip, ip->controls1);
	window_fit(ip->controls1);
	
	if (!ip->textpane1)
		ip->textpane1 = xspdb_client_gui_window1_textpane1_create(ip, ip->window1);
	window_fit(ip->window1);
	
	xv_set(ip->controls1, XV_WIDTH, WIN_EXTEND_TO_EDGE, NULL);
	xv_set(ip->textpane1,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		NULL);
	return ip;
}

/*
 * Create object `window1' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_window1_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 624,
		XV_HEIGHT, 727,
		XV_LABEL, "XSPDB_CLIENT",
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `controls1' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_controls1_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, 102,
		WIN_BORDER, FALSE,
		NULL);
	return obj;
}

/*
 * Create object `now_bt' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_now_bt_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		set_now_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 6,
		PANEL_LABEL_STRING, "Set to Current Time",
		PANEL_NOTIFY_PROC, set_now_proc,
		NULL);
	return obj;
}

/*
 * Create object `source_tx' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_source_tx_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	source_string_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 300,
		XV_Y, 8,
		PANEL_VALUE_DISPLAY_LENGTH, 20,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Source String:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, source_string_proc,
		NULL);
	return obj;
}

/*
 * Create object `prod_typ_st' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_prod_typ_st_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		prod_typ_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE, PANEL_DISPLAY_LEVEL, PANEL_CURRENT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 300,
		XV_Y, 26,
		PANEL_CHOICE_NCOLS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "Product Type",
		PANEL_NOTIFY_PROC, prod_typ_proc,
		PANEL_CHOICE_STRINGS,
			"Generic",
			"Standard",
			NULL,
		NULL);
	return obj;
}

/*
 * Create object `prod_id_tx' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_prod_id_tx_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	prod_id_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 300,
		XV_Y, 54,
		PANEL_VALUE_DISPLAY_LENGTH, 8,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Product ID:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, prod_id_proc,
		NULL);
	return obj;
}

/*
 * Create object `req_typ_st' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_req_typ_st_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		reqest_type_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 300,
		XV_Y, 74,
		PANEL_CHOICE_NROWS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_CHOOSE_NONE, FALSE,
		PANEL_LABEL_STRING, "Request:",
		PANEL_NOTIFY_PROC, reqest_type_proc,
		PANEL_CHOICE_STRINGS,
			"Interval",
			"Closest",
			"Before",
			"After",
			NULL,
		NULL);
	return obj;
}

/*
 * Create object `group1' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_group1_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, GROUP,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 300,
		XV_Y, 8,
		GROUP_TYPE, GROUP_NONE,
		GROUP_MEMBERS,
			ip->source_tx,
			ip->prod_typ_st,
			ip->prod_id_tx,
			ip->req_typ_st,
			NULL,
		NULL);
	return obj;
}

/*
 * Create object `end_tx' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_end_tx_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	end_tm_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 28,
		PANEL_VALUE_DISPLAY_LENGTH, 20,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Interest Time:",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, end_tm_proc,
		NULL);
	return obj;
}

/*
 * Create object `time_delta_ntx' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_time_delta_ntx_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern Panel_setting	time_delta_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_NUMERIC_TEXT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 48,
		PANEL_VALUE_DISPLAY_LENGTH, 6,
		PANEL_VALUE_STORED_LENGTH, 80,
		PANEL_LABEL_STRING, "Within",
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_MAX_VALUE, 1000000000,
		PANEL_MIN_VALUE, 0,
		PANEL_VALUE, 0,
		PANEL_READ_ONLY, FALSE,
		PANEL_NOTIFY_PROC, time_delta_proc,
		NULL);
	return obj;
}

/*
 * Create object `min_msg' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_min_msg_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 154,
		XV_Y, 50,
		PANEL_LABEL_STRING, "Minutes",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `submit_bt' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_submit_bt_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		submit_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 72,
		PANEL_LABEL_STRING, "SUBMIT Request",
		PANEL_NOTIFY_PROC, submit_proc,
		NULL);
	return obj;
}

/*
 * Create object `clear_bt' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_clear_bt_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		clear_text_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 136,
		XV_Y, 72,
		PANEL_LABEL_STRING, "CLEAR Text",
		PANEL_NOTIFY_PROC, clear_text_proc,
		NULL);
	return obj;
}

/*
 * Create object `textpane1' in the specified instance.
 */
Xv_opaque
xspdb_client_gui_window1_textpane1_create(ip, owner)
	xspdb_client_gui_window1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, TEXTSW,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, (int)xv_get(ip->controls1, XV_Y) +
		      (int)xv_get(ip->controls1, XV_HEIGHT),
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		OPENWIN_SHOW_BORDERS, TRUE,
		NULL);
	gcm_initialize_colors(obj, "white", "black");
	return obj;
}

