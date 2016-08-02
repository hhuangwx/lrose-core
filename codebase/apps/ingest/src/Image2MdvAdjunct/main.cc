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

#include <cstdio>


/**
 *
 * @file main.cc
 *
 *
 * Small adjunct to Image2Mdv that tries to take some of the legwork out of
 * getting a background image into CIDD.
 *
 *
 * @author Niles Oien
 *
 */

#include "Params.hh"
#include <cmath>

int main(int argc, char *argv[]){

  //
  // Read the command-line specified param file.
  //
  Params params;

  if (params.loadFromArgs(argc,argv,NULL,NULL)){
    fprintf(stderr, "Specify params file with -params option.\n");
    return(-1);
  }  

  //
  // Read the world file.
  //
  char worldFile[1024];
  char *dot = strstr(params.inImageFile, ".");
  if (4 != strlen(dot)){
    //
    // Not a 3-letter extension.
    //
    sprintf(worldFile,"%sw", params.inImageFile);
  } else {
    int i=0; int go=1;
    do{
      if (params.inImageFile[i] != '.'){
        worldFile[i] = params.inImageFile[i];
        worldFile[i+1] = char(0);
        i++;
      } else {
        go = 0;
      }
    } while ( go );
    sprintf(worldFile,"%s.%c%cw",
             worldFile, *(dot + 1), params.inImageFile[strlen(params.inImageFile)-1]);
  }

  FILE *fp = fopen(worldFile, "r");
  if (fp == NULL){
    fprintf(stderr,"Failed to open %s\n", worldFile);
    return -1;
  }

  double dx;
  if (1 != fscanf(fp, "%lf", &dx)){
    fprintf(stderr, "Failed to read dx from %s\n", worldFile);
    return -1;
  }

  double rot1;
  if (1 != fscanf(fp, "%lf", &rot1)){
    fprintf(stderr, "Failed to read first rotation param from %s\n", 
	    worldFile);
    return -1;
  }

  if (rot1 != 0.0){
    fprintf(stderr, "First rotation is non-zero. I cannot cope.\n");
    return -1;
  }

  double rot2;
  if (1 != fscanf(fp, "%lf", &rot2)){
    fprintf(stderr, "Failed to read second rotation param from %s\n", 
	    worldFile);
    return -1;
  }

  if (rot2 != 0.0){
    fprintf(stderr, "Second rotation is non-zero. I cannot cope.\n");
    return -1;
  }


  double dy;
  if (1 != fscanf(fp, "%lf", &dy)){
    fprintf(stderr, "Failed to read dy from %s\n", worldFile);
    return -1;
  }
  dy = -dy;

  double _inMinLon;
  if (1 != fscanf(fp, "%lf", &_inMinLon)){
    fprintf(stderr, "Failed to read upper left longitude from %s\n", 
	    worldFile);
    return -1;
  }

  double _inMaxLat;
  if (1 != fscanf(fp, "%lf", &_inMaxLat)){
    fprintf(stderr, "Failed to read upper left latitude from %s\n", 
	    worldFile);
    return -1;
  }

  fclose (fp);

  //
  // Open the output csh script
  //
  FILE *ofp = fopen("Runner", "w");
  if (fp == NULL){
    fprintf(stderr,"Failed to create file Runner\n");
    return -1;
  }

  fprintf(ofp,"#!/bin/csh\n\n");
  fprintf(ofp,"# Script automatically generated by Image2MdvAdjunct\n");
  fprintf(ofp,"# Niles Oien oien@ucar.edu\n\n");

  fprintf(ofp, "# Set environment variable TMPDIR to a directory with lots of space...\n\n");
  fprintf(ofp,"setenv TMPDIR %s\n\n", params.tempDir);

  fprintf(ofp, "# Delete results from previous runs : \nrm -f *.mdv\n\n");


  //
  // Loop through the set of output dimensions.
  //
  for (int i=0; i < params.outDimensions_n; i++){

    //
    // Add "fudge factor" offsets.
    //
    double inMinLon = _inMinLon + params._outDimensions[i].offsetLon;
    double inMaxLat = _inMaxLat + params._outDimensions[i].offsetLat;
    
    double inMaxLon = inMinLon + params.inDimensions.nx*dx;
    double inMinLat = inMaxLat - params.inDimensions.ny*dy;


    //
    // Calculate new ny to preserve aspect ratio.
    //
    int newNy = (int)rint(double(params._outDimensions[i].nx) * 
			  (params._outDimensions[i].maxLat - params._outDimensions[i].minLat) / 
			  (params._outDimensions[i].maxLon - params._outDimensions[i].minLon));

    fprintf(ofp,"echo Processing for domain %s %g,%g to %g,%g in %d,%d points\n\n", 
	    params._outDimensions[i].domainName,
	    params._outDimensions[i].minLat, params._outDimensions[i].minLon,
	    params._outDimensions[i].maxLat, params._outDimensions[i].maxLon,
	    params._outDimensions[i].nx, newNy);

    //
    // Do the calc to figure out how to extract the subimage
    // at the original resolution with the convert command.
    // Do the calc to figure out where to start.
    //
    double fraction = (params._outDimensions[i].minLon - inMinLon) / (inMaxLon - inMinLon);
    int startExtractX = (int)floor(double(params.inDimensions.nx) * fraction);

    if ((startExtractX < 0) || (startExtractX > params.inDimensions.nx-1)){
      fprintf(stderr, "startExtractX is %d for %s, valid range is 0 to %d (fraction is %lf)\n",
	      startExtractX, params._outDimensions[i].domainName, params.inDimensions.nx-1, fraction);
      fprintf(stderr, "Input image runs from %lf, %lf to %lf, %lf\n",
	      inMinLat, inMinLon, inMaxLat, inMaxLon);
      fprintf(stderr,"Regional location goes from %lf, %lf to %lf, %lf\n",
	      params._outDimensions[i].minLat, params._outDimensions[i].minLon,
	      params._outDimensions[i].maxLat, params._outDimensions[i].maxLon);
      exit(-1);
    }

    fraction = (params._outDimensions[i].minLat - inMinLat)  / (inMaxLat - inMinLat);
    int startExtractY = (int)floor(double(params.inDimensions.ny) * fraction);

    if ((startExtractY < 0) || (startExtractY > params.inDimensions.ny-1)){
      fprintf(stderr, "startExtractY is %d for %s, valid range is 0 to %d (fraction is %lf)\n",
	      startExtractY, params._outDimensions[i].domainName, params.inDimensions.ny-1, fraction);
      fprintf(stderr, "Input image runs from %lf, %lf to %lf, %lf\n",
	      inMinLat, inMinLon, inMaxLat, inMaxLon);
      fprintf(stderr,"Regional location goes from %lf, %lf to %lf, %lf\n",
	      params._outDimensions[i].minLat, params._outDimensions[i].minLon,
	      params._outDimensions[i].maxLat, params._outDimensions[i].maxLon);
      exit(-1);
    }

    fraction = (params._outDimensions[i].maxLon - inMinLon) / (inMaxLon - inMinLon);
    int endExtractX = (int)ceil(double(params.inDimensions.nx) * fraction);

    if ((endExtractX < 0) || (endExtractX > params.inDimensions.nx-1)){
      fprintf(stderr, "endExtractX is %d for %s, valid range is 0 to %d (fraction is %lf)\n",
	      endExtractX, params._outDimensions[i].domainName, params.inDimensions.nx-1, fraction);
      fprintf(stderr, "Input image runs from %lf, %lf to %lf, %lf\n",
	      inMinLat, inMinLon, inMaxLat, inMaxLon);
      fprintf(stderr,"Regional location goes from %lf, %lf to %lf, %lf\n",
	      params._outDimensions[i].minLat, params._outDimensions[i].minLon,
	      params._outDimensions[i].maxLat, params._outDimensions[i].maxLon);
      exit(-1);
    }

    fraction = (params._outDimensions[i].maxLat - inMinLat) / (inMaxLat - inMinLat);
    int endExtractY = (int)ceil(double(params.inDimensions.ny) * fraction);

    if ((endExtractY < 0) || (endExtractY > params.inDimensions.ny-1)){
      fprintf(stderr, "endExtractY is %d for %s, valid range is 0 to %d (fraction is %lf)\n",
	      endExtractY, params._outDimensions[i].domainName, params.inDimensions.ny-1, fraction);
      fprintf(stderr, "Input image runs from %lf, %lf to %lf, %lf\n",
	      inMinLat, inMinLon, inMaxLat, inMaxLon);
      fprintf(stderr,"Regional location goes from %lf, %lf to %lf, %lf\n",
	      params._outDimensions[i].minLat, params._outDimensions[i].minLon,
	      params._outDimensions[i].maxLat, params._outDimensions[i].maxLon);
      exit(-1);
    }


    if (params.negateInY){
      startExtractY = params.inDimensions.ny - startExtractY;
      endExtractY = params.inDimensions.ny - endExtractY;
      int temp = endExtractY; endExtractY = startExtractY; startExtractY = temp;
    }

    int numExtractX = endExtractX - startExtractX + 1;
    int numExtractY = endExtractY - startExtractY + 1;



    fprintf(ofp, "# First conversion for %s : \nconvert %s -crop %dx%d+%d+%d %s_1.%s\n\n",
	    params._outDimensions[i].domainName,
	    params.inImageFile, numExtractX, numExtractY, 
	    startExtractX, startExtractY, params._outDimensions[i].domainName,
	    params.imageType);


    fprintf(ofp, "# Second conversion for %s : \nconvert -resize %dx%d %s_1.%s %s.%s\n\n",
	    params._outDimensions[i].domainName,
	    params._outDimensions[i].nx, newNy,
	    params._outDimensions[i].domainName, 
	    params.imageType, params._outDimensions[i].domainName,
	    params.imageType);

    if (params.deleteInterims){
      fprintf(ofp,"# Delete interim image : \nrm -f %s_1.%s\n\n",
	      params._outDimensions[i].domainName, params.imageType);
    }

    double newDx = (params._outDimensions[i].maxLon - params._outDimensions[i].minLon)/
      double(params._outDimensions[i].nx);

    double newDy = (params._outDimensions[i].maxLat - params._outDimensions[i].minLat)/
      double(newNy);

    //
    // Create Image2Mdv param file.
    //
    char paramFile[1024];
    sprintf(paramFile,"Image2Mdv.%s", params._outDimensions[i].domainName);

    FILE *pfp = fopen(paramFile,"w");
    if (pfp == NULL){
      fprintf(stderr,"Failed to open Image2Mdv param file %s\n",
	      paramFile);
      exit(-1);
    }

    fprintf(pfp,"// Image2Mdv param file %s created by Image2MdvAdjunct, Niles Oien\n\n",
	    paramFile);

    if (!(params.deleteInterims)){
      fprintf(pfp,"debug = TRUE;\n\n");
    }

    fprintf(pfp,"grid = { %lf, %lf, %lf, %lf};\n\nin_projection = PROJ_LATLON;\n\n",
	    params._outDimensions[i].minLon + newDx / 2.0,
	    params._outDimensions[i].minLat + newDy / 2.0,
	    newDx, newDy);

    fprintf(pfp,"erase_files = FALSE;\n\n");

    fprintf(pfp,"proj = { %lf, %lf, 0, 0, 0, 0 };\n\n",
	    params._outDimensions[i].minLon + newDx / 2.0,
	    params._outDimensions[i].minLat + newDy / 2.0);
    

    fclose(pfp);

    //
    // OK, now have param file - use it.
    //
    fprintf(ofp, "Image2Mdv -params %s -i %s.%s -o ./%s.mdv\n\n\n\n", paramFile,
	    params._outDimensions[i].domainName, params.imageType, params._outDimensions[i].domainName);

  }

  //
  // Delete these param files.
  //
  fprintf(ofp, "\\rm -f Image2Mdv.*\n\n");

  fclose(ofp);

  system("chmod 777 Runner");

  if (params.runScript)
    system("./Runner");
  else
    fprintf(stdout,"Done, now go run the \"Runner\" script.\n");

  return 0;

}
