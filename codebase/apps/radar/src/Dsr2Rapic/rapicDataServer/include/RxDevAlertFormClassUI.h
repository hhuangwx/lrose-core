
//////////////////////////////////////////////////////////////
//
// Header file for RxDevAlertFormClassUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, RxDevAlertFormClass is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the RxDevAlertFormClass files
//
//    Restrict changes to those sections between
//    the "//--- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//
//////////////////////////////////////////////////////////////
#ifndef RXDEVALERTFORMCLASSUI_H
#define RXDEVALERTFORMCLASSUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


class RxDevAlertFormClassUI : public VkComponent
{ 

  public:

    RxDevAlertFormClassUI ( const char *, Widget );
    RxDevAlertFormClassUI ( const char * );
    ~RxDevAlertFormClassUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: RxDevAlertFormClass public


    //---- End editable code block: RxDevAlertFormClass public


  protected:


    // Widgets created by this class

    Widget  _alertPostedTimeLabel;
    Widget  _alertTitleLabel;
    Widget  _alertTypeLabel;
    Widget  _button47;
    Widget  _button48;
    Widget  _commDevAlertFormClassUI;
    Widget  _devNameLabel;
    Widget  _label32;
    Widget  _label39;
    Widget  _label48;
    Widget  _label49;
    Widget  _realertPeriodText;
    Widget  _toggle1;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void changeRealertPeriod ( Widget, XtPointer );

    //---- Start editable code block: RxDevAlertFormClass protected


    //---- End editable code block: RxDevAlertFormClass protected


  private: 

    // Array of default resources

    static String      _defaultRxDevAlertFormClassUIResources[];


    // Callbacks to interface with Motif

    static void changeRealertPeriodCallback ( Widget, XtPointer, XtPointer );

    //---- Start editable code block: RxDevAlertFormClass private


    //---- End editable code block: RxDevAlertFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

