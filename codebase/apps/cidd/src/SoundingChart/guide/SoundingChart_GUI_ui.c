/*
 * SoundingChart_GUI_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `SoundingChart_GUI.G'.
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
#include "SoundingChart_GUI_ui.h"

/*
 * Initialize an instance of object `window1'.
 */
SoundingChart_GUI_window1_objects *
SoundingChart_GUI_window1_objects_initialize(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	if (!ip && !(ip = (SoundingChart_GUI_window1_objects *) calloc(1, sizeof (SoundingChart_GUI_window1_objects))))
		return (SoundingChart_GUI_window1_objects *) NULL;
	if (!ip->window1)
		ip->window1 = SoundingChart_GUI_window1_window1_create(ip, owner);
	if (!ip->controls1)
		ip->controls1 = SoundingChart_GUI_window1_controls1_create(ip, ip->window1);
	if (!ip->width_sl)
		ip->width_sl = SoundingChart_GUI_window1_width_sl_create(ip, ip->controls1);
	if (!ip->time_msg)
		ip->time_msg = SoundingChart_GUI_window1_time_msg_create(ip, ip->controls1);
	if (!ip->canvas1)
		ip->canvas1 = SoundingChart_GUI_window1_canvas1_create(ip, ip->window1);
	return ip;
}

/*
 * Create object `window1' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_window1_window1_create(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	extern Notify_value	window_event_func(Xv_window, Event *, Notify_arg, Notify_event_type);
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 661,
		XV_HEIGHT, 597,
		XV_LABEL, "Base Window",
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, TRUE,
		NULL);
	xv_set(obj, WIN_CONSUME_EVENTS,
		WIN_MOUSE_BUTTONS,
		LOC_MOVE,
		LOC_DRAG,
		LOC_WINENTER,
		LOC_WINEXIT,
		WIN_ASCII_EVENTS,
		WIN_LEFT_KEYS,
		WIN_RIGHT_KEYS,
		WIN_TOP_KEYS,
		NULL, NULL);
	notify_interpose_event_func(obj,
		(Notify_func) window_event_func, NOTIFY_SAFE);
	return obj;
}

/*
 * Create object `controls1' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_window1_controls1_create(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, 32,
		WIN_BORDER, FALSE,
		NULL);
	return obj;
}

/*
 * Create object `width_sl' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_window1_width_sl_create(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	extern void		adust_width_proc(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_SLIDER,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 8,
		PANEL_SLIDER_WIDTH, 100,
		PANEL_TICKS, 0,
		PANEL_LABEL_STRING, "Sounding Width",
		PANEL_DIRECTION, PANEL_HORIZONTAL,
		PANEL_SLIDER_END_BOXES, TRUE,
		PANEL_SHOW_RANGE, FALSE,
		PANEL_SHOW_VALUE, FALSE,
		PANEL_MIN_VALUE, 0,
		PANEL_MAX_VALUE, 100,
		PANEL_VALUE, 0,
		PANEL_NOTIFY_PROC, adust_width_proc,
		NULL);
	return obj;
}

/*
 * Create object `time_msg' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_window1_time_msg_create(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 550,
		XV_Y, 8,
		PANEL_LABEL_STRING, "TIME String",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `canvas1' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_window1_canvas1_create(SoundingChart_GUI_window1_objects *ip, Xv_opaque owner)
{
	extern Notify_value	canvas_event_func(Xv_window, Event *, Notify_arg, Notify_event_type);
	extern void	canvas_repaint(Canvas, Xv_window, Rectlist *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, CANVAS,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, (int)xv_get(ip->controls1, XV_Y) +
		      (int)xv_get(ip->controls1, XV_HEIGHT),
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		CANVAS_REPAINT_PROC, canvas_repaint,
		NULL);
	xv_set(canvas_paint_window(obj), WIN_CONSUME_EVENTS,
		WIN_MOUSE_BUTTONS,
		LOC_MOVE,
		LOC_DRAG,
		LOC_WINENTER,
		LOC_WINEXIT,
		WIN_ASCII_EVENTS,
		WIN_LEFT_KEYS,
		WIN_RIGHT_KEYS,
		WIN_TOP_KEYS,
		NULL, NULL);
	notify_interpose_event_func(canvas_paint_window(obj),
		(Notify_func) canvas_event_func, NOTIFY_SAFE);
	/*
	 * This line is here for backwards compatibility. It will be
	 * removed for the next release.
	 */
	xv_set(canvas_paint_window(obj), XV_KEY_DATA, INSTANCE, ip, NULL);
	return obj;
}

/*
 * Initialize an instance of object `config_pu'.
 */
SoundingChart_GUI_config_pu_objects *
SoundingChart_GUI_config_pu_objects_initialize(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	if (!ip && !(ip = (SoundingChart_GUI_config_pu_objects *) calloc(1, sizeof (SoundingChart_GUI_config_pu_objects))))
		return (SoundingChart_GUI_config_pu_objects *) NULL;
	if (!ip->config_pu)
		ip->config_pu = SoundingChart_GUI_config_pu_config_pu_create(ip, owner);
	if (!ip->controls2)
		ip->controls2 = SoundingChart_GUI_config_pu_controls2_create(ip, ip->config_pu);
	if (!ip->data_msg)
		ip->data_msg = SoundingChart_GUI_config_pu_data_msg_create(ip, ip->controls2);
	if (!ip->grid_wind_st)
		ip->grid_wind_st = SoundingChart_GUI_config_pu_grid_wind_st_create(ip, ip->controls2);
	if (!ip->Grid_st)
		ip->Grid_st = SoundingChart_GUI_config_pu_Grid_st_create(ip, ip->controls2);
	if (!ip->sound_wind_st)
		ip->sound_wind_st = SoundingChart_GUI_config_pu_sound_wind_st_create(ip, ip->controls2);
	if (!ip->sound_st)
		ip->sound_st = SoundingChart_GUI_config_pu_sound_st_create(ip, ip->controls2);
	if (!ip->refs_st)
		ip->refs_st = SoundingChart_GUI_config_pu_refs_st_create(ip, ip->controls2);
	if (!ip->clear_bt)
		ip->clear_bt = SoundingChart_GUI_config_pu_clear_bt_create(ip, ip->controls2);
	return ip;
}

/*
 * Create object `config_pu' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_config_pu_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME_CMD,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 314,
		XV_HEIGHT, 231,
		XV_LABEL, "Sounding Chart Configuration",
		XV_SHOW, FALSE,
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, FALSE,
		FRAME_CMD_PUSHPIN_IN, TRUE,
		NULL);
	xv_set(xv_get(obj, FRAME_CMD_PANEL), WIN_SHOW, FALSE, NULL);
	return obj;
}

/*
 * Create object `controls2' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_controls2_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
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
 * Create object `data_msg' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_data_msg_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 98,
		XV_Y, 8,
		PANEL_LABEL_STRING, "Data Message",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `grid_wind_st' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_grid_wind_st_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		show_grid_wind(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TOGGLE, PANEL_FEEDBACK, PANEL_MARKED,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 10,
		XV_Y, 40,
		PANEL_CHOICE_NROWS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "Model     ",
		PANEL_NOTIFY_PROC, show_grid_wind,
		PANEL_CHOICE_STRINGS,
			"Colors",
			"Plot",
			"Winds",
			NULL,
		PANEL_VALUE, 0,
		NULL);
	return obj;
}

/*
 * Create object `Grid_st' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_Grid_st_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		grid_select(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE, PANEL_DISPLAY_LEVEL, PANEL_CURRENT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 84,
		XV_Y, 68,
		PANEL_CHOICE_NCOLS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "FIELD:",
		PANEL_NOTIFY_PROC, grid_select,
		PANEL_CHOICE_STRING, 0, "None",
		NULL);
	return obj;
}

/*
 * Create object `sound_wind_st' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_sound_wind_st_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		show_sound_winds(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TOGGLE, PANEL_FEEDBACK, PANEL_MARKED,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 96,
		PANEL_CHOICE_NROWS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "Sounding",
		PANEL_NOTIFY_PROC, show_sound_winds,
		PANEL_CHOICE_STRINGS,
			"Colors",
			"Plot",
			"Winds",
			NULL,
		PANEL_VALUE, 0,
		NULL);
	return obj;
}

/*
 * Create object `sound_st' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_sound_st_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		sounding_select(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_CHOICE, PANEL_DISPLAY_LEVEL, PANEL_CURRENT,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 80,
		XV_Y, 128,
		PANEL_CHOICE_NCOLS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "FIELD:",
		PANEL_NOTIFY_PROC, sounding_select,
		PANEL_CHOICE_STRING, 0, "None",
		NULL);
	return obj;
}

/*
 * Create object `refs_st' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_refs_st_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		set_ref_points_proc(Panel_item, int, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_TOGGLE, PANEL_FEEDBACK, PANEL_MARKED,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 172,
		PANEL_CHOICE_NCOLS, 1,
		PANEL_LAYOUT, PANEL_HORIZONTAL,
		PANEL_LABEL_STRING, "Output Reference Points",
		PANEL_NOTIFY_PROC, set_ref_points_proc,
		PANEL_CHOICE_STRING, 0, "",
		PANEL_VALUE, 0,
		NULL);
	return obj;
}

/*
 * Create object `clear_bt' in the specified instance.
 */
Xv_opaque
SoundingChart_GUI_config_pu_clear_bt_create(SoundingChart_GUI_config_pu_objects *ip, Xv_opaque owner)
{
	extern void		clear_refs_proc(Panel_item, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 204,
		PANEL_LABEL_STRING, "Clear reference points",
		PANEL_NOTIFY_PROC, clear_refs_proc,
		NULL);
	return obj;
}

