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
// Noaa Port Warnings, Watches and Advisory to Spdb Translator
// This version watches an output dir for new files
// And processes them directly into Spdb
// F. Hage June 2006

#include <toolsa/pmu.h>
#include <iostream>
#include <strings.h>
#include <didss/DsInputPath.hh>

#include "Params.hh"
#include "WWA2Spdb.hh"

//
// Constructor
//
WWA2Spdb::WWA2Spdb(){
  nFiles = 0;
}
//////////////////////////////////////////////  
//
// Destructor
//
WWA2Spdb::~WWA2Spdb(){
}

//////////////////////////////////////////////////
// Main method - run.
//
int WWA2Spdb::init( int argc, char **argv ){

  //
  // Parse command line args.
  //
  if (ParseArgs(argc,argv)) return -1;
  //
  // Get TDRP args and check in to PMU.
  //
  if (P.loadFromArgs(argc,argv,NULL,NULL)){
    cerr << "Specify params file with -params option." << endl ;
    return(-1);
  }                       
  
  PMU_auto_init("WWA2Spdb", P.Instance, PROCMAP_REGISTER_INTERVAL);     

  if (nFiles > 0) P.Mode = Params::ARCHIVE;

  return 0;

}

//////////////////////////////////////////////////////
//
//
//
int WWA2Spdb::run(){
  //
  // Set up for input.
  // Depends on what mode we're in.
  //
  if (P.Mode == Params::ARCHIVE){

    for (int k=0; k < nFiles; k++){
      cerr << "Processing " << filePaths[k] << endl;
      process_file(filePaths[k]);
    }


  } else { // in realtime mode.

   if (P.Debug) cerr << "Watching " << P.InputDir << " for files newer than " << P.MaxRealtimeFileAge <<
				 "secs" << endl;

    DsInputPath input("WWA2Spdb",
		      P.Debug,
		      P.InputDir,
		      P.MaxRealtimeFileAge,
		      PMU_auto_register,
		      false,
		      false);

    PMU_auto_register("Waiting for data");
 
    char *FilePath;
    input.reset();

	if(strlen(P.InputExt) > 0) input.setSearchExt(P.InputExt);
 
    //
    // In fact, we never leave this while loop.
    //
    while ((FilePath = input.next()) != NULL) {
 
      for (int k=0; k <  P.ProcessingDelay; k++){
	sleep(1);
	PMU_auto_register("Sleeping before processing");
      }

      // Read the file and decode directly into Spdb
	  time_t now = time(0);
      cerr << "Processing " << FilePath << " at "  << ctime(&now);
      process_file(FilePath);

    } // while loop.             

  } // End of if we are in realtime.

  //
  //
  return 0;

}


///////////////////////////////////////////////
// Parse command line args.
//
int WWA2Spdb::ParseArgs(int argc, char *argv[]){

  for (int i=1; i<argc; i++){
 
    if ( (strstr(argv[i], "-h") != NULL) ||
         (strstr(argv[i], "--") != NULL) ||
         (strstr(argv[i], "-?") != NULL)) {                
      cout << "USAGE : WWA2Spdb [-print_params to get parameters]" << endl;
      cout << "[-h or -- or -? to get this help message]" << endl;
      cout << "[-f filelist to run in archive mode]" << endl;
      return -1;

    }
    
    if (!strcmp(argv[i], "-f")){
      i++;
      if (i == argc) {
	cerr << "Must specify at least one input file after -f" << endl;
	exit(-1);
      }

      P.Mode = Params::ARCHIVE;

      if(i < argc) {
	int j;

	int go=1; j = i;
	do{
	  if (argv[j][0] == '-') {
	    go = 0;
	  }
	  j++;
	  if (j > argc-1) go = 0;
	} while (go);
	
	//
	// compute number of files
	//

	nFiles = j - i;

	cerr << nFiles << " files specified on command line." << endl;

	// set file name array

	filePaths = argv + i;

	
      }
      
    } // if
    
  }
  return 0;
}
