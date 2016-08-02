/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
#ifndef	fields_pu_HEADER
#define	fields_pu_HEADER

/*
 * fields_pu_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `fields_pu.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;

extern Xv_opaque	fields_pu_field_mu_create();

typedef struct {
	Xv_opaque	fields_pu;
	Xv_opaque	fields_controls;
	Xv_opaque	display_list;
	Xv_opaque	f_config_sel_bt;
	Xv_opaque	f_config_msg1;
	Xv_opaque	f_config_msg2;
	Xv_opaque	f_config_msg3;
	Xv_opaque	f_config_msg4;
	Xv_opaque	f_config_tx1;
	Xv_opaque	f_config_tx2;
	Xv_opaque	f_config_tx3;
	Xv_opaque	f_config_tx6;
	Xv_opaque	f_config_tx5;
	Xv_opaque	f_config_tx4;
	Xv_opaque	f_config_msg6;
	Xv_opaque	f_config_tx9;
	Xv_opaque	f_config_msg7;
	Xv_opaque	group2;
	Xv_opaque	ren_meth_st;
	Xv_opaque	update_st;
	Xv_opaque	max_st;
	Xv_opaque	use_servmap_st;
	Xv_opaque	group1;
	Xv_opaque	f_config_msg8;
	Xv_opaque	f_config_tx7;
	Xv_opaque	f_config_tx8;
	Xv_opaque	f_config_color_apply_bt;
	Xv_opaque	group3;
	Xv_opaque	group4;
} fields_pu_fields_pu_objects;

extern fields_pu_fields_pu_objects	*fields_pu_fields_pu_objects_initialize();

extern Xv_opaque	fields_pu_fields_pu_fields_pu_create();
extern Xv_opaque	fields_pu_fields_pu_fields_controls_create();
extern Xv_opaque	fields_pu_fields_pu_display_list_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_sel_bt_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg1_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg2_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg3_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg4_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx1_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx2_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx3_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx6_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx5_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx4_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg6_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx9_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg7_create();
extern Xv_opaque	fields_pu_fields_pu_group2_create();
extern Xv_opaque	fields_pu_fields_pu_ren_meth_st_create();
extern Xv_opaque	fields_pu_fields_pu_update_st_create();
extern Xv_opaque	fields_pu_fields_pu_max_st_create();
extern Xv_opaque	fields_pu_fields_pu_use_servmap_st_create();
extern Xv_opaque	fields_pu_fields_pu_group1_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_msg8_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx7_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_tx8_create();
extern Xv_opaque	fields_pu_fields_pu_f_config_color_apply_bt_create();
extern Xv_opaque	fields_pu_fields_pu_group3_create();
extern Xv_opaque	fields_pu_fields_pu_group4_create();
#endif
