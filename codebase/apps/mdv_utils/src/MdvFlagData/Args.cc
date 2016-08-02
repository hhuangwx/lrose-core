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
//////////////////////////////////////////////////////////
// Args.cc : command line args
//
// Mike Dixon, RAP, NCAR,
// P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Aug 2001
//
//////////////////////////////////////////////////////////

#include "Args.hh"
#include "Params.hh"
#include <string.h>
#include <toolsa/umisc.h>
using namespace std;

// Constructor

Args::Args ()

{
  startTime = 0;
  endTime = 0;
  TDRP_init_override(&override);
  additional_tdrp_file = NULL;
}


// Destructor

Args::~Args ()

{
  TDRP_free_override(&override);
}

// Parse command line
// Returns 0 on success, -1 on failure

int Args::parse (int argc, char **argv,
                 const string &prog_name)

{

  char tmp_str[BUFSIZ];

  // intialize

  int iret = 0;

  // loop through args

  for (int i =  1; i < argc; i++) {
    if (!strcmp(argv[i], "-additional_tdrp_file")) {
      i++;
      if (i >= argc){
        fprintf(stderr,"*** Error: -additional_tdrp_file needs an argument.\n");
        exit(-1);
      }
      additional_tdrp_file = argv[i];

    } else if (!strcmp(argv[i], "--") ||
        !strcmp(argv[i], "-h") ||
        !strcmp(argv[i], "-help") ||
        !strcmp(argv[i], "-man")) {

      _usage(cout, prog_name);
      exit (0);

    } else if (!strcmp(argv[i], "-debug")) {

      sprintf(tmp_str, "debug = DEBUG_NORM;");
      TDRP_add_override(&override, tmp_str);

    } else if (!strcmp(argv[i], "-verbose")) {

      sprintf(tmp_str, "debug = DEBUG_VERBOSE;");
      TDRP_add_override(&override, tmp_str);

    } else if (!strcmp(argv[i], "-mode")) {

      if (i < argc - 1) {
        sprintf(tmp_str, "mode = %s;", argv[i+1]);
        TDRP_add_override(&override, tmp_str);
      } else {
        iret = -1;
      }
    } else if (!strcmp(argv[i], "-f")) {

      sprintf(tmp_str, "mode = FILELIST;");
      TDRP_add_override(&override, tmp_str);

      if (i < argc - 1) {
        // load up file list vector. Break at next arg which
        // start with -
        for (int j = i + 1; j < argc; j++) {
          if (argv[j][0] == '-') {
            break;
          } else {
            inputFileList.push_back(argv[j]);
          }
        }
      } else {
        iret = -1;
      }
    } 
 
  } // i

  if (iret) {
    _usage(cerr, prog_name);
  }

  return (iret);

}

void Args::_usage(ostream &out,
                  const string &prog_name)

{

  out << "Usage: " << prog_name << " [options as below]\n"
      << "options:\n"
      << "       [ --, -h, -help, -man ] produce this list.\n"
      << "       [ -debug ] print debug messages\n"
      << "       [ -f files ] specify input file list.\n"
      << "         forces FILELIST mode\n"
      << "       [ -prefix file prefix ] specify output file prefix.\n"
      << "       [ -mode ?] REALTIME, REALTIME_FCST,  or FILELIST\n"
      << "       [ -verbose ] print verbose debug messages\n"
      << "       [ -additional_tdrp_file ] specify a TDRP file whose\n"
      << "          params will override those in the params file.\n"
      << endl;

  Params::usage(out);

}

