/*
 * extras_pu_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `extras_pu.G'.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include <group.h>
#include "cidd_gui.h"
#include "extras_pu_ui.h"


#ifdef MAIN


#endif


/*
 * Global object definitions.
 */
extras_pu_extras_pu_objects	*Extras_pu_extras_pu;
/*
 * Instance XV_KEY_DATA key.  An instance is a set of related
 * user interface objects.  A pointer to an object's instance
 * is stored under this key in every object.  This must be a
 * global variable.
 */
Attr_attribute	INSTANCE;

/*
 * Menu handler for `cont_mu'.
 */
Menu
cont_field_mu_gen(Menu menu, Menu_generate op)
{
	extras_pu_extras_pu_objects * ip = (extras_pu_extras_pu_objects *) xv_get(menu, XV_KEY_DATA, INSTANCE);
	
	switch (op) {
	case MENU_DISPLAY:
		break;

	case MENU_DISPLAY_DONE:
		break;

	case MENU_NOTIFY:
		fputs("extras_pu: cont_field_mu_gen: MENU_NOTIFY\n", stderr);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		break;

	case MENU_NOTIFY_DONE:
		break;
	}
	return menu;
}

/*
 * Notify callback function for `map_set_color_bt'.
 */
void
set_ov_color_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("extras_pu: set_ov_color_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `ov_field_num_st'.
 */
void
ov_field_num_sel_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: ov_field_num_sel_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `overlay_list'.
 */
int
over_select_proc(Panel_item item, char *string, Xv_opaque client_data, Panel_list_op op, Event *event, int row)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch(op) {
	case PANEL_LIST_OP_DESELECT:
		fprintf(stderr, "extras_pu: over_select_proc: PANEL_LIST_OP_DESELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_SELECT:
		fprintf(stderr, "extras_pu: over_select_proc: PANEL_LIST_OP_SELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_VALIDATE:
		fprintf(stderr, "extras_pu: over_select_proc: PANEL_LIST_OP_VALIDATE: %s\n",string);
		break;

	case PANEL_LIST_OP_DELETE:
		fprintf(stderr, "extras_pu: over_select_proc: PANEL_LIST_OP_DELETE: %s\n",string);
		break;
	}
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return XV_OK;
}

/*
 * Notify callback function for `over_fld_st'.
 */
void
overlay_fld_on_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	short	i;
	
	fputs("extras_pu: overlay_fld_on_proc\n", stderr);
	for (i = 0; i < 1; i++) {
		if (value & 01)
			fprintf(stderr, "\t%dth item selected\n", i);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		value >>= 1;
	}
}

/*
 * Event callback function for `ov_fld_mu_bt'.
 */
void
set_ov_fld_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: set_ov_fld_proc: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	panel_default_handle_event(item, event);
}

/*
 * Notify callback function for `ov_fld_min_tx'.
 */
Panel_setting
overlay_fld_min_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "extras_pu: overlay_fld_min_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `ov_fld_max_tx'.
 */
Panel_setting
overlay_fld_max_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "extras_pu: overlay_fld_max_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `layer_mode_st'.
 */
void
layer_mode_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: layer_mode_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `cont_layer_st'.
 */
void
cont_layer_set_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: cont_layer_set_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Event callback function for `cont_bt'.
 */
void
set_cont_field_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: set_cont_field_proc: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	panel_default_handle_event(item, event);
}

/*
 * Notify callback function for `cont_st'.
 */
void
cont_activate_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	short	i;
	
	fputs("extras_pu: cont_activate_proc\n", stderr);
	for (i = 0; i < 1; i++) {
		if (value & 01)
			fprintf(stderr, "\t%dth item selected\n", i);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		value >>= 1;
	}
}

/*
 * Notify callback function for `cont_label_st'.
 */
void
cont_label_set_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	short	i;
	
	fputs("extras_pu: cont_label_set_proc\n", stderr);
	for (i = 0; i < 1; i++) {
		if (value & 01)
			fprintf(stderr, "\t%dth item selected\n", i);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		value >>= 1;
	}
}

/*
 * Notify callback function for `cont_fr_tx'.
 */
Panel_setting
cont_fr_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "extras_pu: cont_fr_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `cont_int_tx'.
 */
Panel_setting
cont_int_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "extras_pu: cont_int_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `ref_st'.
 */
void
ref_mark_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	short	i;
	
	fputs("extras_pu: ref_mark_proc\n", stderr);
	for (i = 0; i < 2; i++) {
		if (value & 01)
			fprintf(stderr, "\t%dth item selected\n", i);
		
		/* gxv_start_connections DO NOT EDIT THIS SECTION */

		/* gxv_end_connections */

		value >>= 1;
	}
}

/*
 * Notify callback function for `cont_to_tx'.
 */
Panel_setting
cont_to_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "extras_pu: cont_to_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Event callback function for `cont_color_msg'.
 */
void
cont_color_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: cont_color_proc: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	panel_default_handle_event(item, event);
}

/*
 * Event callback function for `ref_mark_color_msg'.
 */
void
ref_color_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: ref_color_proc: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	panel_default_handle_event(item, event);
}

/*
 * Notify callback function for `vect_set_color_bt'.
 */
void
vect_set_color_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("extras_pu: vect_set_color_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `wind_on_list'.
 */
int
vect_field_num_set_proc(Panel_item item, char *string, Xv_opaque client_data, Panel_list_op op, Event *event, int row)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	switch(op) {
	case PANEL_LIST_OP_DESELECT:
		fprintf(stderr, "extras_pu: vect_field_num_set_proc: PANEL_LIST_OP_DESELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_SELECT:
		fprintf(stderr, "extras_pu: vect_field_num_set_proc: PANEL_LIST_OP_SELECT: %s\n",string);
		break;

	case PANEL_LIST_OP_VALIDATE:
		fprintf(stderr, "extras_pu: vect_field_num_set_proc: PANEL_LIST_OP_VALIDATE: %s\n",string);
		break;

	case PANEL_LIST_OP_DELETE:
		fprintf(stderr, "extras_pu: vect_field_num_set_proc: PANEL_LIST_OP_DELETE: %s\n",string);
		break;
	}
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return XV_OK;
}

/*
 * Notify callback function for `prod_font_sl'.
 */
void
prod_font_sel_proc(Panel_item item, int value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: prod_font_sel_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `prod_line_sl'.
 */
void
prod_line_width_proc(Panel_item item, int value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: prod_line_width_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `wind_sl'.
 */
void
wind_scale_proc(Panel_item item, int value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: wind_scale_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `prod_tm_sel_st'.
 */
void
prod_time_sel_proc(Panel_item item, int	 value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: prod_time_sel_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `dim_sl'.
 */
void
dim_im_proc(Panel_item item, int value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: dim_im_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `prod_tm_wdth_sl'.
 */
void
prod_time_width_proc(Panel_item item, int value, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "extras_pu: prod_time_width_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `save_bt'.
 */
void
save_h_image_proc(Panel_item item, Event *event)
{
	extras_pu_extras_pu_objects *ip = (extras_pu_extras_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("extras_pu: save_h_image_proc\n", stderr);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}
