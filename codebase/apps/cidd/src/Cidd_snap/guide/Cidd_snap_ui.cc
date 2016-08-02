//
// Cidd_snap_ui.cc - User interface object initialization functions.
// This file was generated by `gxv++' from `Cidd_snap.G'.
// DO NOT EDIT BY HAND.
//

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
#include "Cidd_snap_ui.h"

//
// Initialize an instance of object `window1'.
//
void
Cidd_snap_window1_objects::objects_initialize(Xv_opaque owner)
{
	window1 = window1_create(owner);
	controls1 = controls1_create(window1);
	button1 = button1_create(controls1);
	msg1 = msg1_create(controls1);
	canvas1 = canvas1_create(window1);
}

//
// Create object `window1' in the specified instance.
//
Xv_opaque
Cidd_snap_window1_objects::window1_create(Xv_opaque owner)
{
	extern Notify_value	win_event_func(Xv_window, Event *, Notify_arg, Notify_event_type);
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, this,
		XV_WIDTH, 507,
		XV_HEIGHT, 415,
		XV_LABEL, "CIDD Snapshot",
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
		(Notify_func) win_event_func, NOTIFY_SAFE);
	return obj;
}

//
// Create object `controls1' in the specified instance.
//
Xv_opaque
Cidd_snap_window1_objects::controls1_create(Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, this,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, 25,
		WIN_BORDER, FALSE,
		NULL);
	return obj;
}

//
// Create object `button1' in the specified instance.
//
Xv_opaque
Cidd_snap_window1_objects::button1_create(Xv_opaque owner)
{
	extern void		exit_func(Panel_item, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, this,
		XV_X, 404,
		XV_Y, 2,
		PANEL_LABEL_STRING, "Exit",
		PANEL_NOTIFY_PROC, exit_func,
		NULL);
	return obj;
}

//
// Create object `msg1' in the specified instance.
//
Xv_opaque
Cidd_snap_window1_objects::msg1_create(Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, this,
		XV_X, 18,
		XV_Y, 6,
		PANEL_LABEL_STRING, "Message",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

//
// Create object `canvas1' in the specified instance.
//
Xv_opaque
Cidd_snap_window1_objects::canvas1_create(Xv_opaque owner)
{
	extern Notify_value	can_event_func(Xv_window, Event *, Notify_arg, Notify_event_type);
	extern void	can_repaint_proc(Canvas, Xv_window, Display *, Window, Xv_xrectlist *);
	extern void	resize_can_proc(Canvas, int, int);
	Xv_opaque	obj;
	
	obj = xv_create(owner, CANVAS,
		XV_KEY_DATA, INSTANCE, this,
		XV_X, 0,
		XV_Y, (int)xv_get(controls1, XV_Y) +
		      (int)xv_get(controls1, XV_HEIGHT),
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		CANVAS_REPAINT_PROC, can_repaint_proc,
		CANVAS_X_PAINT_WINDOW, TRUE,
		CANVAS_RESIZE_PROC, resize_can_proc,
		NULL);
	xv_create(obj, SCROLLBAR, SCROLLBAR_DIRECTION, SCROLLBAR_HORIZONTAL, NULL);
	xv_create(obj, SCROLLBAR, SCROLLBAR_DIRECTION, SCROLLBAR_VERTICAL, NULL);
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
		(Notify_func) can_event_func, NOTIFY_SAFE);
	//
	// This line is here for backwards compatibility. It will be
	// removed for the next release.
	//
	xv_set(canvas_paint_window(obj), XV_KEY_DATA, INSTANCE, this, NULL);
	return obj;
}

