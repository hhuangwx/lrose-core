
//////////////////////////////////////////////////////////////
//
// Header file for CommReqFormClass
//
//    This file is generated by RapidApp 1.2
//
//    This class is derived from CommReqFormClassUI which 
//    implements the user interface created in 
//    RapidApp. This class contains virtual
//    functions that are called from the user interface.
//
//    When you modify this header file, limit your changes to those
//    areas between the "//---- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//////////////////////////////////////////////////////////////
#ifndef COMMREQFORMCLASS_H
#define COMMREQFORMCLASS_H
#include "CommReqFormClassUI.h"
//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


//---- CommReqFormClass class declaration

class CommReqFormClass : public CommReqFormClassUI
{

  public:

    CommReqFormClass ( const char *, Widget );
    CommReqFormClass ( const char * );
    ~CommReqFormClass();
    const char *  className();

    static VkComponent *CreateCommReqFormClass( const char *name, Widget parent ); 

    //---- Start editable code block: CommReqFormClass public


    //---- End editable code block: CommReqFormClass public



  protected:

    //---- Start editable code block: CommReqFormClass protected


    //---- End editable code block: CommReqFormClass protected



  private:

    static void* RegisterCommReqFormClassInterface();

    //---- Start editable code block: CommReqFormClass private


    //---- End editable code block: CommReqFormClass private


};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

