/*
 * movie_pu_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `movie_pu.G'.
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
 * Notify callback function for `time_interval_tx'.
 */
Panel_setting
time_interv_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "cidd_gui: time_interv_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `start_time_tx'.
 */
Panel_setting
start_time_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "cidd_gui: start_time_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `st_frame_tx'.
 */
Panel_setting
start_frame_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	int	value = (int) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "cidd_gui: start_frame_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `end_frame_tx'.
 */
Panel_setting
end_frame_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	int	value = (int) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "cidd_gui: end_frame_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}

/*
 * Notify callback function for `movie_dwell_sl'.
 */
void
movie_delay_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: movie_delay_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `movie_frame_sl'.
 */
void
movie_frame_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: movie_frame_proc: value: %d\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `movie_type_st'.
 */
void
movie_type_proc(item, value, event)
	Panel_item	item;
	int		value;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "cidd_gui: movie_type_proc: value: %u\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}

/*
 * Notify callback function for `fcast_per_tx'.
 */
Panel_setting
set_fcast_period_proc(item, event)
	Panel_item	item;
	Event		*event;
{
	movie_pu_movie_pu_objects *ip = (movie_pu_movie_pu_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	char *	value = (char *) xv_get(item, PANEL_VALUE);
	
	fprintf(stderr, "cidd_gui: set_fcast_period_proc: value: %s\n", value);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return panel_text_notify(item, event);
}
