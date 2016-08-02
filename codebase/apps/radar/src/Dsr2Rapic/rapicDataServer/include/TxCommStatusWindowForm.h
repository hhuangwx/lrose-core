
//////////////////////////////////////////////////////////////
//
// Header file for TxCommStatusWindowForm
//
//    This file is generated by RapidApp 1.2
//
//    This class is derived from TxCommStatusWindowFormUI which 
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
#ifndef TXCOMMSTATUSWINDOWFORM_H
#define TXCOMMSTATUSWINDOWFORM_H
#include "TxCommStatusWindowFormUI.h"
//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


//---- TxCommStatusWindowForm class declaration

class TxCommStatusWindowForm : public TxCommStatusWindowFormUI
{

  public:

    TxCommStatusWindowForm ( const char *, Widget );
    TxCommStatusWindowForm ( const char * );
    ~TxCommStatusWindowForm();
    const char *  className();

    static VkComponent *CreateTxCommStatusWindowForm( const char *name, Widget parent ); 

    //---- Start editable code block: TxCommStatusWindowForm public


    //---- End editable code block: TxCommStatusWindowForm public



  protected:

    //---- Start editable code block: TxCommStatusWindowForm protected


    //---- End editable code block: TxCommStatusWindowForm protected



  private:

    static void* RegisterTxCommStatusWindowFormInterface();

    //---- Start editable code block: TxCommStatusWindowForm private


    //---- End editable code block: TxCommStatusWindowForm private


};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

