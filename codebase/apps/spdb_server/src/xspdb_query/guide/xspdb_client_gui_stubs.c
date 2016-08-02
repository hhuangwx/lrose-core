/*
 * xspdb_client_gui_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `xspdb_client_gui.G'.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include "xspdb_client_gui_ui.h"
#include <group.h>


/*
 * Global object definitions.
 */
xspdb_client_gui_window1_objects	*Xspdb_client_gui_window1;

#ifdef MAIN

/*
 * Instance XV_KEY_DATA key.  An instance is a set of related
 * user interface objects.  A pointer to an object's instance
 * is stored under this key in every object.  This must be a
 * global variable.
 */
Attr_attribute	INSTANCE;

main(argc, argv)
	int	argc;
	char	**argv;
{
	/*
	 * Initialize XView.
	 */
	xv_init(XV_INIT_ARGC_PTR_ARGV, &argc, argv, NULL);
	INSTANCE = xv_unique_key();
	
	/*
	 * Initialize user interface components.
	 * Do NOT edit the object initializations by hand.
	 */
	Xspdb_client_gui_window1 = xspdb_client_gui_window1_objects_initialize(NULL, NULL);
	
	
	/*
	 * Turn control over to XView.
	 */
	xv_main_loop(Xspdb_client_gui_window1->window1);
	exit(0);
}

#endif


/*
 * Notify callback function for `begin_tx'.
 */
Panel_setting
begin_tm_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "xspdb_client_gui: begin_tm_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */
	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `textfield1'.
 */
Panel_setting
time_delta_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	int	value = (int) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "xspdb_client_gui: time_delta_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `source_tx'.
 */
Panel_setting
source_string_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "xspdb_client_gui: source_string_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `end_tx'.
 */
Panel_setting
end_tm_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "xspdb_client_gui: end_tm_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `prod_typ_st'.
 */
void
prod_typ_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "xspdb_client_gui: prod_typ_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `submit_bt'.
 */
void
submit_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("xspdb_client_gui: submit_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `req_typ_st'.
 */
void
reqest_type_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "xspdb_client_gui: reqest_type_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `prod_id_tx'.
 */
Panel_setting
prod_id_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "xspdb_client_gui: prod_id_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `clear_bt'.
 */
void
clear_text_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("xspdb_client_gui: clear_text_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `now_bt'.
 */
void
set_now_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	xspdb_client_gui_window1_objects *ip = (xspdb_client_gui_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("xspdb_client_gui: set_now_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}
