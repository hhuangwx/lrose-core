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

/************************************************************************
 * params.hh
 *
 * Text for print_params
 *
 * RAP, NCAR, Boulder CO
 *
 * June 1990
 *
 * Mike Dixon
 ************************************************************************/

static const char *ParamsText =
  "############\n"
  "# debugging\n"
  "\n"
  "Rview.x_sync: false\n"
  "Rview.debug: false\n"
  "\n"
  "##########\n"
  "# instance\n"
  "\n"
  "Rview.instance: test\n"
  "\n"
  "########################################################################\n"
  "# mode and requested time\n"
  "#\n"
  "# mode may be realtime or archive.\n"
  "# In archive mode, the time_requested is used.\n"
  "#\n"
  "\n"
  "Rview.time_requested: 1997 06 23 20 00 00\n"
  "Rview.mode: realtime\n"
  "Rview.time_label: UTC\n"
  "Rview.localtime: false\n"
  "\n"
  "######################################################################\n"
  "# basic setup\n"
  "\n"
  "# field_requested is the initial field displayed\n"
  "\n"
  "Rview.field_requested: 0\n"
  "\n"
  "# scan_delta_t is number of secs moved in time using time button\n"
  "\n"
  "Rview.scan_delta_t: 180\n"
  "\n"
  "# z_requested is initial height\n"
  "\n"
  "Rview.z_requested: 2.0\n"
  "\n"
  "# delta_z is change in height using level button\n"
  "\n"
  "Rview.delta_z: 0.75\n"
  "\n"
  "# mouse double-clicking delay - secs - set to your taste\n"
  "\n"
  "Rview.double_click_delay: 0.3\n"
  "\n"
  "# The display is updated every 'update_interval' secs in case new data\n"
  "\n"
  "Rview.update_interval: 10\n"
  "\n"
  "# base_timer_interval is the basic interval for the interrupt timer\n"
  "\n"
  "Rview.startup_timer_interval: 2.0\n"
  "Rview.base_timer_interval: 0.15\n"
  "\n"
  "# approx number of ticks per axis\n"
  "\n"
  "Rview.approx_nticks: 7\n"
  "\n"
  "############################################################\n"
  "# Geographical extent\n"
  "#\n"
  "# projection may be 'flat' for local plots or 'latlon' for \n"
  "# regional or larger plots.\n"
  "#\n"
  "# The grid origin is always in lat/lon units.\n"
  "#\n"
  "# min and max values are in km for flat proj,\n"
  "# lat/lon for latlon proj\n"
  "#\n"
  "\n"
  "Rview.projection: flat\n"
  "\n"
  "Rview.grid_lat: 39.787\n"
  "Rview.grid_lon: -104.546\n"
  "Rview.grid_rot: 0.0\n"
  "\n"
  "Rview.full_min_x: -200.0\n"
  "Rview.full_min_y: -200.0\n"
  "Rview.full_max_x: 200.0\n"
  "Rview.full_max_y: 200.0\n"
  "\n"
  "#######################################################################\n"
  "# Initial plot settings\n"
  "#\n"
  "\n"
  "Rview.plot_rings: true\n"
  "Rview.center_rings_on_origin: false\n"
  "Rview.plot_cappi_image: on\n"
  "Rview.plot_composite: true\n"
  "Rview.plot_cappi_contours: false\n"
  "\n"
  "Rview.plot_vsection_image: on\n"
  "Rview.plot_vsection_contours: false\n"
  "Rview.vsection_interp: true\n"
  "\n"
  "Rview.n_ideal_contourlabels: 5\n"
  "Rview.ps_contourlabel_fontsize: 8\n"
  "\n"
  "################################################\n"
  "# plot_maps controls initial map overlay setting\n"
  "# Options are false, limited or all.\n"
  "#\n"
  "# Map conf file lists the map files to be used\n"
  "#\n"
  "\n"
  "Rview.plot_maps: limited\n"
  "Rview.map_conf_file: $(TITAN_HOME)/display/maps/titan.conf\n"
  "\n"
  "#######################\n"
  "# colorscale directory\n"
  "#\n"
  "\n"
  "Rview.colorscale_dir: $(TITAN_HOME)/display/color_scales\n"
  "\n"
  "######################################################################\n"
  "# cursor bearing computations. If cursor is clicked twice, the bearing\n"
  "# between the last two clicks is indicated. If use_magnetic is\n"
  "# set, the bearing is given in deg Mag, otherwise in Deg T\n"
  "#\n"
  "\n"
  "Rview.cursor_magnetic: false\n"
  "Rview.magnetic_variation: 0.0\n"
  "Rview.cursor_dist_nm: true\n"
  "\n"
  "#######################################################################\n"
  "# printing copies\n"
  "#\n"
  "# The print_command defaults to 'lpr -h -P', which works for BSD printing.\n"
  "# For ATT printing, set it to 'lp -d'\n"
  "#\n"
  "# The print_command is followed by the printer name and name of the file\n"
  "# to be printed\n"
  "#\n"
  "\n"
  "Rview.ps_prologue_file: $(TITAN_HOME)/prologues/postscript\n"
  "Rview.output_file: $(TITAN_HOME)/output/Rview.ps\n"
  "Rview.ps_printer: lp\n"
  "Rview.print_command: lpr -h -P\n"
  "\n"
  "####################################################################\n"
  "# output files for the Web\n"
  "#\n"
  "# Using the right mouse button on the Copy button on either the\n"
  "# main window or the vertical cross-section window will create an\n"
  "# output file that can be used on the Web.  You can also specify\n"
  "# an interval at which to output Web files continuously.  The interval\n"
  "# is specified in minutes.  Web files are then output at that interval\n"
  "# starting at the first of that interval after the top of the hour.\n"
  "# For example, if the interval is every 10 minutes you will get Web\n"
  "# output files at 0, 10, 20, 30, 40 and 50 after the hour.\n"
  "#\n"
  "# When creating the Web output files, first an XWD file is created\n"
  "# from the appropriate pixmap.  Then, the XWD file is converted to\n"
  "# another type of file using a system command.  For the main window\n"
  "# this command depends on the setting of the cappi_web_output_timestamped_files\n"
  "# parameter.  If this parameter is false, the system command is:\n"
  "#\n"
  "#     <web_convert_cmd> <cappi_xwd_file> <cappi_web_file)\n"
  "#\n"
  "# If this parameter is true, then a file name is generated using the\n"
  "# data time and the following command is used:\n"
  "#\n"
  "#     <web_convert_cmd> <cappi_xwd_file> <generated file name>\n"
  "#\n"
  "# In this case, the generated file is always in GIF format.  The system\n"
  "# command for the vertical cross-section window is:\n"
  "#\n"
  "#     <web_convert_cmd> <vsection_xwd_file> <vsection_web_file>\n"
  "#\n"
  "\n"
  "Rview.web_convert_cmd: convert\n"
  "\n"
  "Rview.output_cappi_web_files: false\n"
  "Rview.cappi_web_output_timestamped_files: false\n"
  "Rview.cappi_web_output_interval: 5\n"
  "Rview.trigger_cappi_web_output_on_new_data: false\n"
  "Rview.cappi_gif_dir: $(TITAN_HOME)/gifs/cappi\n"
  "Rview.cappi_xwd_file: $(TITAN_HOME)/output/cappi.xwd\n"
  "Rview.cappi_web_file: $(TITAN_HOME)/output/cappi.gif\n"
  "\n"
  "Rview.output_vsection_web_files: false\n"
  "Rview.vsection_web_output_interval: 30\n"
  "Rview.trigger_vsection_web_output_on_new_data: false\n"
  "Rview.vsection_xwd_file: $(TITAN_HOME)/output/vsection.xwd\n"
  "Rview.vsection_web_file: $(TITAN_HOME)/output/vsection.gif\n"
  "\n"
  "#################################################################\n"
  "# auto_advance\n"
  "#\n"
  "# Option to automatically advance through time, from start to end,\n"
  "# at the given delta time, copying or saving gifs of each image\n"
  "#\n"
  "\n"
  "Rview.auto_advance: false\n"
  "Rview.auto_advance_start_time: 1995 05 01 18 00 00\n"
  "Rview.auto_advance_end_time: 1999 12 31 23 59 59\n"
  "Rview.auto_advance_delta_time: 86400\n"
  "Rview.save_copy_on_auto_advance: false\n"
  "Rview.save_gif_on_auto_advance: true\n"
  "Rview.save_if_no_data: false\n"
  "\n"
  "#######################################################\n"
  "# Option to use TimeHist or time_hist\n"
  "#\n"
  "# Rview starts up TimeHist (or time_hist) using the following command\n"
  "#\n"
  "\n"
  "Rview.use_time_hist: true\n"
  "Rview.time_hist_command_line: TimeHist -params $(TITAN_HOME)/display/params/TimeHist.test &\n"
  "\n"
  "#######################################################################\n"
  "# Storm tracks. A check for new data is made every track_check_interval\n"
  "# secs. The data is in shared memory with the given key.\n"
  "\n"
  "Rview.use_track_data: true\n"
  "\n"
  "# If you are using track data you need to specify the URL for the DsTitanServer\n"
  "\n"
  "Rview.titan_server_url: titanp:://localhost::titan/storms\n"
  "\n"
  "# How often to check for new track data (secs)\n"
  "\n"
  "Rview.track_check_interval: 10\n"
  "\n"
  "# The shmem key for communicating track data to TimeHist\n"
  "\n"
  "Rview.track_shmem_key: 46000\n"
  "\n"
  "# how far in past and future to plot tracks - mins\n"
  "\n"
  "Rview.track_data_time_margin: 10.0\n"
  "Rview.past_plot_period: 30.0\n"
  "Rview.future_plot_period: 30.0\n"
  "\n"
  "# how to plot tracks\n"
  "\n"
  "Rview.plot_tracks: all_tracks\n"
  "Rview.plot_current: true\n"
  "Rview.plot_past: limited\n"
  "Rview.plot_future: false\n"
  "Rview.plot_forecast: limited\n"
  "Rview.track_graphic: polygons\n"
  "Rview.fill_graphic: false\n"
  "Rview.plot_vectors: true\n"
  "Rview.annotate_tracks: vil\n"
  "\n"
  "# Plot track forecasts?\n"
  "\n"
  "Rview.n_forecast_steps: 5\n"
  "Rview.forecast_interval: 6.0\n"
  "Rview.arrow_head_km: 1\n"
  "\n"
  "# Draw in the storm identification runs\n"
  "\n"
  "Rview.runs_included: true\n"
  "Rview.plot_runs: false\n"
  "Rview.fill_runs: false\n"
  "\n"
  "#############################################################################\n"
  "# symbolic products.\n"
  "#\n"
  "# Symbolic product params are specified in the file 'product_params_path_name'\n"
  "# which is a TDRP file.\n"
  "\n"
  "Rview.plot_products: false\n"
  "Rview.product_params_path_name: ProdParams.test\n"
  "\n"
  "#########################################\n"
  "# verification data plotting\n"
  "#\n"
  "# Option to plot verification data, e.g. hail occurrence\n"
  "\n"
  "Rview.plot_verify: false\n"
  "Rview.verify_file: $(TITAN_HOME)/verify/hail_pad_data\n"
  "Rview.verify_time_margin: 300\n"
  "\n"
  "##########################################################\n"
  "# Aircraft position\n"
  "#\n"
  "\n"
  "Rview.plot_ac_posn: false\n"
  "Rview.use_spdb_for_ac_posn: true\n"
  "Rview.ac_posn_db_dir: $(DATA_DIR)/spdb/ac_posn\n"
  "Rview.ac_posn_archive_dir: $(DATA_DIR)/ascii/ac_posn\n"
  "Rview.ac_posn_realtime_file: $(DATA_DIR)/ascii/ac_posn/realtime\n"
  "Rview.ac_posn_fwd_time_margin: 300\n"
  "Rview.ac_posn_back_time_margin: 300\n"
  "Rview.ac_posn_n_ident: 3\n"
  "Rview.ac_posn_idents: ZJRA ZJRB ZCAN 00HP\n"
  "Rview.ac_posn_colors: white orange cyan green\n"
  "#Rview.ac_posn_labels: Rain1 Rain2 Rain3 Rain4\n"
  "Rview.ac_posn_linestyles: 1 100.0 0.0, 1 4.0 2.0, 1 1.0 4.0, 1 1.0 3.0, 1 4.0 1.0\n"
  "Rview.ac_posn_max_speed_kts: 250\n"
  "Rview.ac_posn_max_bad_points: 2\n"
  "\n"
  "# plot flares?\n"
  "\n"
  "Rview.plot_flares: false\n"
  "\n"
  "# You can plot ejectables as a cross, plus or both (asterisk)\n"
  "\n"
  "Rview.plot_ejectables_as_cross: true\n"
  "Rview.plot_ejectables_as_plus: true\n"
  "Rview.ejectable_icon_size_km: 0.3\n"
  "\n"
  "# set the colors for the end-burners, burn-in-place, and combination\n"
  "\n"
  "Rview.end_burn_color: gold\n"
  "Rview.burn_in_place_color: blue\n"
  "Rview.end_burn_and_bip_color: magenta\n"
  "\n"
  "# line width varies with the number of flares burning.\n"
  "# If width_per_flare is 1, line width will be number of burning flares.\n"
  "# If width_per_flare is 2, line width will be 2 * number of burning flares.\n"
  "# If width_per_flare is 0, line widths will always be 1.\n"
  "\n"
  "Rview.line_width_per_flare: 2\n"
  "\n"
  "# linestyes not yet implemeted\n"
  "\n"
  "#Rview.end_burn_linestyle: 1 1.0 3.0\n"
  "#Rview.burn_in_place_linestyle: 1 4.0 1.0\n"
  "#Rview.end_burn_and_bip_linestyle: 1 10.0 10.0\n"
  "\n"
  "##############\n"
  "# X resources\n"
  "# ===========\n"
  "#\n"
  "\n"
  "Rview.x_foreground: white\n"
  "Rview.x_background: black\n"
  "\n"
  "# location and size of main window\n"
  "\n"
  "Rview.x_mainx: 0\n"
  "Rview.x_mainy: 0\n"
  "Rview.x_mainx_sign: 1\n"
  "Rview.x_mainy_sign: 1\n"
  "Rview.x_mainwidth: 900\n"
  "Rview.x_mainheight: 870\n"
  "Rview.x_minmainwidth: 300\n"
  "Rview.x_minmainheight: 250\n"
  "Rview.x_mainborder: 5\n"
  "Rview.x_subborder: 1\n"
  "\n"
  "# location and size of vert section window\n"
  "\n"
  "Rview.x_vsection_x_from_main: 600\n"
  "Rview.x_vsection_y_from_main: 500\n"
  "Rview.x_vsection_width: 500\n"
  "Rview.x_vsection_height: 400\n"
  "\n"
  "# location and size of help popup window\n"
  "\n"
  "Rview.x_help_x_from_main: 200\n"
  "Rview.x_help_y_from_main: 200\n"
  "Rview.x_help_width: 500\n"
  "Rview.x_help_height: 400\n"
  "\n"
  "# interface button width\n"
  "\n"
  "Rview.x_max_button_width: 80\n"
  "\n"
  "# color scale width\n"
  "\n"
  "Rview.x_scalewidth: 100\n"
  "\n"
  "# margins\n"
  "\n"
  "Rview.x_xaxismargin: 25\n"
  "Rview.x_yaxismargin: 35\n"
  "Rview.x_xaxisendmargin: 30\n"
  "Rview.x_yaxisendmargin: 15\n"
  "Rview.x_ticklength: 6\n"
  "Rview.x_topmargin: 25\n"
  "Rview.x_tick_clearance: 3\n"
  "Rview.x_text_margin: 6\n"
  "\n"
  "# legend dimensions. The legend element height is the height of each\n"
  "# color block in the scale window.\n"
  "\n"
  "Rview.x_max_legend_element_ht: 25\n"
  "Rview.x_legend_element_width: 30\n"
  "\n"
  "# fonts\n"
  "\n"
  "Rview.x_button_font: 8x13\n"
  "Rview.x_title_font: 8x13\n"
  "Rview.x_scale_font: 6x10\n"
  "Rview.x_ringlabel_font: 6x10\n"
  "Rview.x_ticklabel_font: 6x10\n"
  "Rview.x_track_annotation_font: 8x13\n"
  "Rview.x_text_font: 8x13\n"
  "Rview.x_contourlabel_font: 6x10\n"
  "\n"
  "# colors\n"
  "\n"
  "Rview.x_xor_color_num: 50000\n"
  "\n"
  "Rview.x_ring_color: forestgreen\n"
  "Rview.x_crosshair_color: #b00\n"
  "Rview.x_vsection_pos_color: red\n"
  "Rview.x_zoom_box_color: red\n"
  "Rview.x_pos_contour_color: red\n"
  "Rview.x_zero_contour_color: yellow\n"
  "Rview.x_neg_contour_color: blue\n"
  "Rview.x_tick_color: yellow\n"
  "Rview.x_ticklabel_color: yellow\n"
  "Rview.x_track_annotation_color: yellow\n"
  "Rview.x_track_case_color: green\n"
  "Rview.x_text_color: yellow\n"
  "Rview.x_titletext_color: gray\n"
  "Rview.x_buttontext_color: red\n"
  "Rview.x_scaletext_color: gray\n"
  "Rview.x_border_color: CadetBlue\n"
  "Rview.x_hlight_background: mediumblue\n"
  "Rview.x_contourlabel_color: gray50\n"
  "\n"
  "Rview.x_current_storm_color: cyan\n"
  "Rview.x_past_storm_color: yellow\n"
  "Rview.x_past_storm_color_2: gold\n"
  "Rview.x_future_storm_color: seagreen2\n"
  "Rview.x_future_storm_color_2: seagreen\n"
  "Rview.x_forecast_storm_color: red\n"
  "Rview.x_forecast_storm_color_2: gray50\n"
  "Rview.x_current_storm_line_width: 2\n"
  "Rview.x_past_storm_line_width: 1\n"
  "Rview.x_future_storm_line_width: 1\n"
  "Rview.x_forecast_storm_line_width: 2\n"
  "\n"
  "Rview.x_past_vector_color: magenta\n"
  "Rview.x_future_vector_color: magenta\n"
  "Rview.x_forecast_vector_color: red\n"
  "Rview.x_storm_vector_width: 2\n"
  "\n"
  "# dim percentage for unselected tracks\n"
  "\n"
  "Rview.color_dim_percent: 70.0\n"
  "\n"
  "# line widths\n"
  "\n"
  "Rview.x_vsection_pos_width: 1\n"
  "Rview.x_zoom_box_width: 1\n"
  "Rview.x_tick_width: 0\n"
  "Rview.x_ring_width: 0\n"
  "Rview.x_crosshair_width: 0\n"
  "\n"
  "# line width multiplier for selected storms\n"
  "# line widths are multiplied by this value when storm is selected\n"
  "\n"
  "Rview.width_mult_selected: 1\n"
  "\n"
  "######################\n"
  "# Postscript resources\n"
  "# ====================\n"
  "#\n"
  "\n"
  "Rview.draw_copy_title: true\n"
  "Rview.draw_copy_header: true\n"
  "Rview.ps_unitscale: 72\n"
  "\n"
  "# paget layout\n"
  "\n"
  "Rview.ps_pagelength: 11.0\n"
  "Rview.ps_pagewidth: 8.5\n"
  "\n"
  "Rview.ps_printwidth: 8.5\n"
  "Rview.ps_maxprintwidth: 11.0\n"
  "Rview.ps_minprintwidth: 3.0\n"
  "\n"
  "# margins\n"
  "\n"
  "Rview.ps_lengthmargin: 0.7\n"
  "Rview.ps_widthmargin: 0.7\n"
  "\n"
  "# dimensions of main image\n"
  "\n"
  "Rview.ps_imagewidth: 6.0\n"
  "Rview.ps_imageheight: 6.0\n"
  "\n"
  "# dimensions of color scale and title\n"
  "\n"
  "Rview.ps_scalewidth: 1.5\n"
  "Rview.ps_titleheight: 0.5\n"
  "\n"
  "Rview.ps_plot_to_scale_margin: 0.25\n"
  "Rview.ps_title_to_plot_margin: 0.4\n"
  "\n"
  "# axis margins in main image\n"
  "\n"
  "Rview.ps_xaxismargin: 0.5\n"
  "Rview.ps_yaxismargin: 0.5\n"
  "Rview.ps_xaxisendmargin: .3\n"
  "Rview.ps_yaxisendmargin: .25\n"
  "Rview.ps_ticklength: 0.06\n"
  "Rview.ps_topmargin: 0.5\n"
  "Rview.ps_tick_clearance: 0.05\n"
  "Rview.ps_text_margin: 0.07\n"
  "\n"
  "# legend dimensions. The legend element height is the height of each\n"
  "# color block in the scale window.\n"
  "\n"
  "Rview.ps_max_legend_element_ht: 0.4\n"
  "Rview.ps_legend_element_width: 0.5\n"
  "\n"
  "#\n"
  "# linestyles\n"
  "#\n"
  "#  width dash_length space_length <graylevel>\n"
  "#\n"
  "# graylevel is optional - if not specified, will be set to 0 (black)\n"
  "#\n"
  "\n"
  "Rview.ps_current_storm_linestyle: 2 100.0 0.0 0.8\n"
  "\n"
  "Rview.ps_past_storm_linestyle: 1 100.0 0.0 0.6\n"
  "Rview.ps_past_storm_linestyle_2: 1 100.0 0.0 0.9\n"
  "\n"
  "Rview.ps_future_storm_linestyle: 1 1.0 1.0 0.4\n"
  "Rview.ps_future_storm_linestyle_2: 1 1.0 1.0 0.7\n"
  "\n"
  "Rview.ps_forecast_storm_linestyle: 1 4.0 2.0 0.2\n"
  "Rview.ps_forecast_storm_linestyle_2: 1 4.0 2.0 0.5\n"
  "\n"
  "Rview.ps_past_vector_linestyle: 1 100.0 0.0\n"
  "Rview.ps_future_vector_linestyle: 1 100.0 0.0\n"
  "Rview.ps_forecast_vector_linestyle: 2 100.0 0.0\n"
  "\n"
  "Rview.ps_pos_contour_linestyle: 1 100.0 0.0\n"
  "Rview.ps_zero_contour_linestyle: 1 1.0 1.0\n"
  "Rview.ps_neg_contour_linestyle: 1 4.0 2.0\n"
  "\n"
  "# line widths\n"
  "\n"
  "Rview.ps_border_width: 1\n"
  "Rview.ps_crosshair_width: 0\n"
  "Rview.ps_ring_width: 0\n"
  "Rview.ps_tick_width: 0\n"
  "\n"
  "# fonts\n"
  "\n"
  "Rview.ps_fontname: Helvetica\n"
  "Rview.ps_title_fontsize: 18\n"
  "Rview.ps_scale_fontsize: 12\n"
  "Rview.ps_ringlabel_fontsize: 8\n"
  "Rview.ps_ticklabel_fontsize: 8\n"
  "Rview.ps_track_annotation_fontsize: 8\n"
  "Rview.ps_text_fontsize: 12\n"
  "\n"
  "##########################################################################\n"
  "# Data fields and their servers.\n"
  "#\n"
  "# These are not treated in the same way as the other params.\n"
  "# They are read in by read_field_control().\n"
  "# Lines start with '#fc' - '##fc' comments them out\n"
  "\n"
  "# Time offset for field data requests (secs)\n"
  "# Used for verfying forecasts against data from the forecast lead time\n"
  "Rview.field_data_time_offset_secs: 0\n"
  "\n"
  "#-------------------------------------------------------------------------\n"
  "#  Field controls\n"
  "#\n"
  "# #fc Label URL         Field        Time  X Color  Ps Color  Contours\n"
  "#                   name or number  window  file      file    lo-hi-int\n"
  "#-------------------------------------------------------------------------\n"
  "\n"
  "# if field_name_from_params is true, the program will use the label from\n"
  "# the param file as the field name. If false, it will use the field name\n"
  "# from the data.\n"
  "\n"
  "Rview.field_name_from_params: false\n"
  "\n"
  "#fc dbz mdvp:://localhost::mdv/radar/cart DBZ  1080  dbz_color dbz_gray 0.0 70.0 5.0\n"
  "\n"
  "##fc dbz mdvp:://localhost::mdv/denCart  0  1080  dbz_color dbz_gray 0.0 70.0 5.0\n"
  "\n"
  "##fc dbz1 mdvp:://remote_host:10000:mdv/cdata1 0  360  dbz_color dbz_gray 0.0 70.0 5.0\n"
  "\n";
