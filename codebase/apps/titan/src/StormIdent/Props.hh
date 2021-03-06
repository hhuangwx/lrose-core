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
/////////////////////////////////////////////////////////////
// Props.hh
//
// Props class - storm properties computations
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// November 1998
//
///////////////////////////////////////////////////////////////

#ifndef Props_HH
#define Props_HH

#include <titan/storm.h>
using namespace std;

class Params;
class InputMdv;
class StormFile;
class Area;
class GridClump;
class Verify;

// layer statistics

typedef struct {
       
  int n;
  int n_vorticity;
  int sum_x;
  int sum_y;
       
  double sum_refl_x;
  double sum_refl_y;
  double sum_refl;
  double sum_mass;
  double sum_vel;
  double sum_vel2;
  double sum_vorticity;
  
  double area;
  double vol_centroid_x;
  double vol_centroid_y;
  double refl_centroid_x;
  double refl_centroid_y;
  double mass;
  double dbz_mean;
  double dbz_max;
  double vel_mean;
  double vel_sd;
  
  double vol_centroid_az;
  double vol_centroid_range;
  double vorticity;
  
} layer_stats_t;

// struct for the dbz histogram entries

typedef struct {
  int n_area;
  int n_vol;
  double percent_area;
  double percent_vol;
} dbz_hist_entry_t;

// struct for those variables which are summed

typedef struct {
  int n, n_vorticity;
  int x, y, z;
  double refl, refl_x, refl_y, refl_z;
  double precip, mass;
  double vel, vel2, vorticity;
} sum_stats_t;

#define MISSING_VAL -9999.0

////////////////////////////////
// Props

class Props {
  
public:

  // constructor

  Props(char *prog_name, Params *params,
	InputMdv *input_mdv, StormFile *storm_file,
	Verify *verify);

  // destructor
  
  virtual ~Props();

  // Constructor OK flag
  int OK;
  
  // ht of min valid layer in storm
  double minValidZ;

  // initialize for latest MDV input file
  void init();

  // compute properties for clump
  int compute(GridClump *grid_clump, int storm_num);

protected:
  
private:

  char *_progName;
  Params *_params;
  InputMdv *_inputMdv;
  StormFile *_stormFile;
  Area *_area;
  GridClump *_gridClump;
  Verify *_verify;

  int _rangeLimited;
  int _topMissing;
  int _hailPresent;
  int _secondTrip;

  int _nzValid;
  int _topLayer, _baseLayer;
  int _nDbzIntvls;
  int _nLayers;

  double _testElev;
  double _testRange;
  double _dbzScale, _dbzBias;
  double _velScale, _velBias;
  double _ZPInverseCoeff, _ZPInverseExpon;
  double _ZMInverseCoeff, _ZMInverseExpon;
  double _vortHemisphereFactor;
  double _minVortDist;
  
  int _highDbzByte;
  storm_file_global_props_t _gprops;
  sum_stats_t _sum;

  double *_means, *_eigenvalues;
  double **_eigenvectors;
  double **_tiltData;
  double **_dbzGradientData;
  layer_stats_t *_layer;
  dbz_hist_entry_t *_dbzHist;
  int _nZAlloc;
  int _nHistAlloc;

  void _alloc(int nz, int nhist);
  int _computeFirstPass();
  void _computeSecondPass();
  int _storeRuns();
  void _tiltCompute();
  void _dbzGradientCompute();
  int _checkSecondTrip();
     
  void _loadGprops(storm_file_global_props_t *gprops,
		   int storm_num,
		   int n_layers,
		   int base_layer,
		   int n_dbz_intvls,
		   int range_limited,
		   int top_missing,
		   int hail_present,
		   int second_trip);

  void _loadLprops(layer_stats_t *layer,
		   storm_file_layer_props_t *lprops);

  void _loadDbzHist(dbz_hist_entry_t *dbz_hist,
		    storm_file_dbz_hist_t *hist);

};

#endif



