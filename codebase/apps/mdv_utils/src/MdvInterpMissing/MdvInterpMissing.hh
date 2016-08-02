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
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* RCS info
 *   $Author: dixon $
 *   $Locker:  $
 *   $Date: 2016/03/04 02:22:11 $
 *   $Id: MdvInterpMissing.hh,v 1.2 2016/03/04 02:22:11 dixon Exp $
 *   $Revision: 1.2 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * MdvInterpMissing: MdvInterpMissing program object.
 *
 * RAP, NCAR, Boulder CO
 *
 * July 2007
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef MdvInterpMissing_HH
#define MdvInterpMissing_HH

#include <map>
#include <string>
#include <sys/time.h>

#include <dsdata/DsTrigger.hh>
#include <euclid/EllipticalTemplate.hh>
#include <Mdv/Mdvx.hh>
#include <Mdv/MdvxPjg.hh>
#include <toolsa/DateTime.hh>

#include "Args.hh"
#include "Params.hh"

using namespace std;


class MdvInterpMissing
{
 public:

  ////////////////////
  // Public members //
  ////////////////////

  // Flag indicating whether the program status is currently okay.

  bool okay;


  ////////////////////
  // Public methods //
  ////////////////////

  //////////////////////////////
  // Constructors/Destructors //
  //////////////////////////////

  /*********************************************************************
   * Destructor
   */

  ~MdvInterpMissing(void);
  

  /*********************************************************************
   * Inst() - Retrieve the singleton instance of this class.
   */

  static MdvInterpMissing *Inst(int argc, char **argv);
  static MdvInterpMissing *Inst();
  

  /*********************************************************************
   * init() - Initialize the local data.
   *
   * Returns true if the initialization was successful, false otherwise.
   */

  bool init();
  

  /////////////////////
  // Running methods //
  /////////////////////

  /*********************************************************************
   * run() - run the program.
   */

  void run();
  

 private:

  /////////////////////
  // Private members //
  /////////////////////

  // Singleton instance pointer

  static MdvInterpMissing *_instance;
  
  // Program parameters.

  char *_progName;
  Args *_args;
  Params *_params;
  
  // Triggering object

  DsTrigger *_dataTrigger;
  
  // Template used for finding surrounding grid squares within the defined
  // radius of influence.  The actual grid points will change if the field
  // projections change.

  mutable EllipticalTemplate _template;
  

  /////////////////////
  // Private methods //
  /////////////////////

  /*********************************************************************
   * Constructor -- private because this is a singleton object
   */

  MdvInterpMissing(int argc, char **argv);
  

  /*********************************************************************
   * _fillMissingField() - Fill the in the missing data values for the given
   *                       field.
   *
   * Returns true on success, false on failure.
   */

  void _fillMissingField(MdvxField &field) const;
  

  /*********************************************************************
   * _fillMissingFields() - Fill the in the missing data values for all of the
   *                        fields in the given file.
   *
   * Returns true on success, false on failure.
   */

  void _fillMissingFields(Mdvx &mdvx) const;
  

  /*********************************************************************
   * _initTrigger() - Initialize the data trigger.
   *
   * Returns true on success, false on failure.
   */

  bool _initTrigger(void);
  

  /*********************************************************************
   * _processData() - Process data for the given trigger time.
   *
   * Returns true on success, false on failure.
   */

  bool _processData(const DateTime &trigger_time);
  

  /*********************************************************************
   * _readInputFile() - Read the indicated input file.
   *
   * Returns true on success, false on failure.
   */

  bool _readInputFile(Mdvx &input_file,
		      const DateTime &trigger_time) const;
  

  /*********************************************************************
   * _updateTemplate() - Update the radius of influence template based on
   *                     the current grid projection.
   */

  void _updateTemplate(const MdvxPjg &proj) const;
  

};


#endif
