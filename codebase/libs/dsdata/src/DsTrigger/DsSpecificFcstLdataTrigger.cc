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

// RCS info
//   $Author: dixon $
//   $Locker:  $
//   $Date: 2016/03/03 18:06:33 $
//   $Id: DsSpecificFcstLdataTrigger.cc,v 1.5 2016/03/03 18:06:33 dixon Exp $
//   $Revision: 1.5 $
//   $State: Exp $
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
/*********************************************************************
 * DsSpecificFcstLdataTrigger: Class implementing a DsTrigger that issues
 *                             a trigger whenever a new file for a specific
 *                             forecast period is detected in the Ldata
 *                             information.  This trigger can only be used
 *                             with MDV URLs pointing to data in a RAP
 *                             forecast-style directory structure.
 *
 * RAP, NCAR, Boulder CO
 *
 * March 2005
 *
 * Nancy Rehak
 *
 *********************************************************************/

#include <algorithm>

#include <dsdata/DsSpecificFcstLdataTrigger.hh>

using namespace std;


/**********************************************************************
 * Constructors
 */

DsSpecificFcstLdataTrigger::DsSpecificFcstLdataTrigger() :
  DsTrigger(TYPE_TIME_TRIGGER),
  _objectInitialized(false)
{
  // Do nothing
}


/**********************************************************************
 * Destructor
 */

DsSpecificFcstLdataTrigger::~DsSpecificFcstLdataTrigger()
{
  // Do nothing
}


/**********************************************************************
 * init() - Initialize the object.  The object must be initialized
 *          before it can be used.
 *
 * url: URL to watch.
 *
 * fcst_periods: list of forecast periods, in seconds, to use for
 *               triggering.  If files are received with forecast
 *               periods not in this list, they will not cause a
 *               trigger event.
 *
 * max_valid_age: the max valid age for data (secs)
 *                The object will not return data which has not arrived
 *                within this period. 
 *
 * heartbeat_func: pointer to heartbeat_func.
 *                 If NULL this is ignored.
 *                 If non-NULL, this is called once per delay_msecs while
 *                 the routine is polling for new data.
 *
 * delay_msecs: polling delay in millisecs.
 *              The object will sleep for this time between polling attempts.
 *
 * Returns 0 on success, -1 on error.
 *
 * Use getErrStr() for error message.
 */

int DsSpecificFcstLdataTrigger::init(const string &url,
				     const vector< int > fcst_periods,
				     const bool use_gen_time,
				     const int max_valid_age,
				     const heartbeat_func_t heartbeat_func,
				     const int delay_msec)
{
  const string method_name = "DsSpecificFcstLdataTrigger::init()";
  
  _clearErrStr();

  if (_ldataTrigger.init(url, max_valid_age, heartbeat_func, delay_msec) != 0)
  {
    _errStr = "ERROR - " + method_name + "\n";
    _errStr += _ldataTrigger.getErrStr();

    return -1;
  }

  // Save the triggering forecast periods

  _fcstPeriods = fcst_periods;
  _useGenTime = use_gen_time;
  
  _objectInitialized = true;
  
  return 0;
}


/**********************************************************************
 * next() - Get the next trigger and set the triggerInfo accordingly
 *
 * Returns 0 upon success, -1 upon failure.
 */

int DsSpecificFcstLdataTrigger::next()
{
  const string method_name = "DsSpecificFcstLdataTrigger::next()";
  
  assert(_objectInitialized);
  _clearErrStr();
  
  while (true)
  {
    if (_ldataTrigger.next() != 0)
    {
      _errStr = "ERROR - " + method_name + "\n";
      _errStr += _ldataTrigger.getErrStr();
      
      return -1;
    }
    
    int fcst_secs = _ldataTrigger._ldataInfo.getLeadTime();
    
    if (find(_fcstPeriods.begin(), _fcstPeriods.end(), fcst_secs)
	!= _fcstPeriods.end())
    {
      _triggerInfo = _ldataTrigger._triggerInfo;
      if (!_useGenTime)
	_triggerInfo.setIssueTime(_triggerInfo.getForecastTime());
	
      return 0;
    }
    
  } /* endwhile */
  
  // We should never get here

  return -1;
}


/**********************************************************************
 * endOfData() - Check whether we are at the end of the data.
 */

bool DsSpecificFcstLdataTrigger::endOfData() const
{
  assert(_objectInitialized);
  
  return false;
}


/**********************************************************************
 * reset() - Reset to start of data list
 */

void DsSpecificFcstLdataTrigger::reset()
{
  assert(_objectInitialized);
  
  // Do nothing
}
