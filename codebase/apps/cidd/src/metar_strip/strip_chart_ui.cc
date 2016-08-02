// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/*
 * strip_chart_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `strip_chart.G'.
 * DO NOT EDIT BY HAND.
 */

#include <cstdio>
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
#include "strip_chart.h"

/*
 * Create object `menu1' in the specified instance.
 */
Xv_opaque
strip_chart_menu1_create(caddr_t ip, Xv_opaque owner)
{
  extern Menu		select_field_proc(Menu, Menu_generate);
  Xv_opaque	obj;

  if (gd.p->plot_flight_category) {
	obj = xv_create(XV_NULL, MENU_CHOICE_MENU,
		XV_KEY_DATA, INSTANCE, ip,
		MENU_GEN_PROC, select_field_proc,
		MENU_TITLE_ITEM, owner ? "" : "Show",
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Ceiling",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Visibility",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Flight cat",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Temperature",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Wind Speed",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Wind Dirn",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Humidity",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Pressure",
			NULL,
		NULL);
  } else {
	obj = xv_create(XV_NULL, MENU_CHOICE_MENU,
		XV_KEY_DATA, INSTANCE, ip,
		MENU_GEN_PROC, select_field_proc,
		MENU_TITLE_ITEM, owner ? "" : "Show",
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Ceiling",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Visibility",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Temperature",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Wind Speed",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Wind Dirn",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Humidity",
			NULL,
		MENU_ITEM,
			XV_KEY_DATA, INSTANCE, ip,
			MENU_STRING, "Pressure",
			NULL,
		NULL);
  }
  
  return obj;

}

/*
 * Initialize an instance of object `win1'.
 */
strip_chart_win1_objects *
strip_chart_win1_objects_initialize(strip_chart_win1_objects *ip, Xv_opaque owner)
{
	if (!ip && !(ip = (strip_chart_win1_objects *) calloc(1, sizeof (strip_chart_win1_objects))))
		return (strip_chart_win1_objects *) NULL;
	if (!ip->win1)
		ip->win1 = strip_chart_win1_win1_create(ip, owner);
	if (!ip->canvas1)
		ip->canvas1 = strip_chart_win1_canvas1_create(ip, ip->win1);
	return ip;
}

/*
 * Create object `win1' in the specified instance.
 */
Xv_opaque
strip_chart_win1_win1_create(strip_chart_win1_objects *ip, Xv_opaque owner)
{
	extern Notify_value	win1_event_proc(Xv_window, Event *, Notify_arg, Notify_event_type);
	Xv_opaque	obj;
	Xv_opaque		win1_image;
	static unsigned short	win1_bits[] = {
#include "strip_chart.icon"
	};
	
	win1_image = xv_create(XV_NULL, SERVER_IMAGE,
		SERVER_IMAGE_DEPTH, 1,
		SERVER_IMAGE_BITS, win1_bits,
		XV_WIDTH, 64,
		XV_HEIGHT, 64,
		NULL);
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 266,
		XV_HEIGHT, 234,
		XV_LABEL, "Station Trends",
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, TRUE,
		FRAME_ICON, xv_create(XV_NULL, ICON,
			ICON_IMAGE, win1_image,
			NULL),
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
		(Notify_func) win1_event_proc, NOTIFY_SAFE);
	return obj;
}

/*
 * Create object `canvas1' in the specified instance.
 */
Xv_opaque
strip_chart_win1_canvas1_create(strip_chart_win1_objects *ip, Xv_opaque owner)
{
	extern Notify_value	strip_chart_win1_canvas1_event_callback(Xv_window, Event *, Notify_arg, Notify_event_type);
	extern Xv_opaque	strip_chart_menu1_create(caddr_t, Xv_opaque);
	Xv_opaque	obj;
	
	obj = xv_create(owner, CANVAS,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		CANVAS_X_PAINT_WINDOW, TRUE,
		NULL);
	xv_set(canvas_paint_window(obj), WIN_MENU, strip_chart_menu1_create((caddr_t) ip, ip->win1), NULL);
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
		(Notify_func) strip_chart_win1_canvas1_event_callback, NOTIFY_SAFE);
	/*
	 * This line is here for backwards compatibility. It will be
	 * removed for the next release.
	 */
	xv_set(canvas_paint_window(obj), XV_KEY_DATA, INSTANCE, ip, NULL);
	return obj;
}

