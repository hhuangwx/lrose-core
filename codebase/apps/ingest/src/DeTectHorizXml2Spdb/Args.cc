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
/**
 *
 * @file Args.cc
 *
 * @class Args
 *
 * Class controlling the command line arguments for this program.
 *  
 * @date 9/6/2011
 *
 */

#include <fstream>
#include <iostream>
#include <string>

#include <string.h>

#include <toolsa/os_config.h>
#include <tdrp/tdrp.h>
#include <toolsa/DateTime.hh>
#include <toolsa/str.h>
#include <toolsa/umisc.h>

#include "Args.hh"

using namespace std;

/**********************************************************************
 * Constructor
 */

Args::Args (int argc, char **argv, char *prog_name) :
  _progName(prog_name)
{
  string tmp_str;

  // Intialize

  bool okay = true;
  
  TDRP_init_override(&override);
  
  // search for command options
  
  for (int i =  1; i < argc; i++)
  {
    if (STRequal_exact(argv[i], "--") ||
	STRequal_exact(argv[i], "-help") ||
	STRequal_exact(argv[i], "-man"))
    {
      _usage(stdout);
      exit(0);
    }
    else if (STRequal_exact(argv[i], "-debug"))
    {
      tmp_str = "debug = true;";
      TDRP_add_override(&override, tmp_str.c_str());
    }
    else if (STRequal_exact(argv[i], "-verbose"))
    {
      tmp_str = "verbose = true;";
      TDRP_add_override(&override, tmp_str.c_str());
    }
    else if (STRequal_exact(argv[i], "-horiz"))
    {
      if (i >= argc - 1)
      {
	okay = false;
      }
      else
      {
	tmp_str = string("horizontal_xml_path = \"") + argv[++i] + "\";";
	TDRP_add_override(&override, tmp_str.c_str());
      }
    }
    else if (STRequal_exact(argv[i], "-metadata"))
    {
      if (i >= argc - 1)
      {
	okay = false;
      }
      else
      {
	tmp_str = string("metadata_xml_path = \"") + argv[++i] + "\";";
	TDRP_add_override(&override, tmp_str.c_str());
      }
    }
  } /* i */

  if (!okay)
  {
    _usage(stderr);
    exit(-1);
  }
}


/**********************************************************************
 * Destructor
 */

Args::~Args(void)
{
  TDRP_free_override(&override);
}
  

/**********************************************************************
 *              Private Member Functions                              *
 **********************************************************************/

/**********************************************************************
 * _usage()
 */

void Args::_usage(FILE *stream)
{
  fprintf(stream, "%s%s%s",
	  "This program converts a set of DeTect horizontal tracking XML\n"
	  "files into a GenPoly SPDB database.\n"
	  "\n"
	  "Usage:\n\n", _progName.c_str(), " [options]\n\n"
	  "  Options:\n"
	  "       [ --, -help, -man ]\n"
	  "           produce this list.\n"
	  "       [ -debug ]\n"
	  "           turn debugging on\n"
	  "       [ -horiz <file> ]\n"
	  "           specify the path for the horizontal table XML file\n"
	  "       [ -metadata <file> ]\n"
	  "           specify the path for the metadata table XML file\n"
	  "\n"
    );


  TDRP_usage(stream);
}
