/*
 * v_win_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `v_win.G'.
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

void	route_labels_proc(Panel_item, int, Event *);

/*
 * Menu handler for `v_field_mu'.
 */
Menu
v_field_mu_gen_proc(Menu menu, Menu_generate op)
{
	v_win_v_win_pu_objects * ip = (v_win_v_win_pu_objects *) xv_get(menu, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("cidd_gui: v_field_mu_gen_proc: MENU_NOTIFY\n", stderr);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return menu;
}

/*
 * Event callback function for `canvas1'.
 */
Notify_value
v_can_events(Xv_window win, Event *event, Notify_arg arg, Notify_event_type type)
{
	v_win_v_win_pu_objects *ip = (v_win_v_win_pu_objects *) xv_get(xv_get(win, CANVAS_PAINT_CANVAS_WINDOW), XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: v_can_events: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	if (event_action(event) == ACTION_MENU && event_is_down(event)) {
		Menu	menu = (Menu) xv_get(win, WIN_MENU);

		if (menu)
			menu_show(menu, win, event, 0);
	}

	/* gxv_end_connections */

	return notify_next_event_func(win, (Notify_event) event, arg, type);
}

/*
 * Repaint callback function for `canvas1'.
 */
void
v_can_repaint(Canvas canvas, Xv_window paint_window, Display *display, Window xid, Xv_xrectlist *rects)
{
	fputs("cidd_gui: v_can_repaint\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `route_st'.
 */
void
show_route_pu_proc(Panel_item item, unsigned int value, Event *event)
{
	v_win_v_win_pu_objects *ip = (v_win_v_win_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	short	i;
	
	fputs("cidd_gui: show_route_pu_proc\n", stderr);
	for (i = 0; i < 1; i++) {
		if (value & 01)
			fprintf(stderr, "\t%dth item selected\n", i);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		value >>= 1;
	}
}

/*
 * Notify callback function for `dismiss_bt'.
 */
void
v_panel_dismiss(Panel_item item, Event *event)
{
	v_win_v_win_pu_objects *ip = (v_win_v_win_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("cidd_gui: v_panel_dismiss\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * User-defined action for `route_labels_st'.
 */
void
route_labels_proc(Panel_item item, int value, Event *event)
{
	v_win_v_win_pu_objects *ip = (v_win_v_win_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("cidd_gui: route_labels_proc\n", stderr);
}
