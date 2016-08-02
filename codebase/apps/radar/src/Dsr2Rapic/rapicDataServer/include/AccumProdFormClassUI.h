
//////////////////////////////////////////////////////////////
//
// Header file for AccumProdFormClassUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, AccumProdFormClass is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the AccumProdFormClass files
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
#ifndef ACCUMPRODFORMCLASSUI_H
#define ACCUMPRODFORMCLASSUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations

//---- End editable code block: headers and declarations


// Externally defined classes referenced by this class:


class VkOptionMenu;
class VkMenuAction;
class VkMenuToggle;
class VkMenuItem;
class AccumProdFormClassUI : public VkComponent
{ 

  public:

    AccumProdFormClassUI ( const char *, Widget );
    AccumProdFormClassUI ( const char * );
    ~AccumProdFormClassUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: AccumProdFormClass public


    //---- End editable code block: AccumProdFormClass public


  protected:


    // Classes created by this class

    class StnSelFormClass *_stnSelFormClassUI;

    // Widgets created by this class

    Widget  _accumPeriodTextField;
    Widget  _accumProdFormClassUI;
    Widget  _cappiHeightTextField;
    Widget  _label25;
    Widget  _label39;
    Widget  _label48;
    Widget  _label53;
    Widget  _rainRateClipTextField;

    VkOptionMenu  *_accumPeriodOptionMenu;
    VkOptionMenu  *_cappiHeightOptionMenu;
    VkOptionMenu  *_modeOptionMenu;
    VkOptionMenu  *_scanTypesOptionMenu;

    VkMenuItem *_option0metres;
    VkMenuItem *_option1000metres;
    VkMenuItem *_option12hour;
    VkMenuItem *_option1500metres;
    VkMenuItem *_option1hour;
    VkMenuItem *_option24hour;
    VkMenuItem *_option2hour;
    VkMenuItem *_option3000metres;
    VkMenuItem *_option30min;
    VkMenuItem *_option3hour;
    VkMenuItem *_option5000metres;
    VkMenuItem *_option500metres;
    VkMenuItem *_option6hour;
    VkMenuItem *_optionA2;
    VkMenuItem *_optionA3;
    VkMenuItem *_optionAccumPeriod;
    VkMenuItem *_optionB2;
    VkMenuItem *_optionB3;
    VkMenuItem *_optionCAPPIHeight;
    VkMenuItem *_separator12;
    VkMenuItem *_separator13;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void uifAccPeriod12hr ( Widget, XtPointer );
    virtual void uifAccPeriod1hr ( Widget, XtPointer );
    virtual void uifAccPeriod24hr ( Widget, XtPointer );
    virtual void uifAccPeriod2hr ( Widget, XtPointer );
    virtual void uifAccPeriod30min ( Widget, XtPointer );
    virtual void uifAccPeriod3hr ( Widget, XtPointer );
    virtual void uifAccPeriod6hr ( Widget, XtPointer );
    virtual void uifAccumOnTheHour ( Widget, XtPointer );
    virtual void uifAccumPeriodText ( Widget, XtPointer );
    virtual void uifAccumRunning ( Widget, XtPointer );
    virtual void uifCAPPIHeightText ( Widget, XtPointer );
    virtual void uifCAPPIHt0 ( Widget, XtPointer );
    virtual void uifCAPPIHt1000 ( Widget, XtPointer );
    virtual void uifCAPPIHt1500 ( Widget, XtPointer );
    virtual void uifCAPPIHt3000 ( Widget, XtPointer );
    virtual void uifCAPPIHt500 ( Widget, XtPointer );
    virtual void uifCAPPIHt5000 ( Widget, XtPointer );
    virtual void uifRainRateClipText ( Widget, XtPointer );
    virtual void uifUseAll ( Widget, XtPointer );
    virtual void uifVolOnly ( Widget, XtPointer );

    //---- Start editable code block: AccumProdFormClass protected


    //---- End editable code block: AccumProdFormClass protected


  private: 

    // Array of default resources

    static String      _defaultAccumProdFormClassUIResources[];


    // Callbacks to interface with Motif

    static void uifAccPeriod12hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod1hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod24hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod2hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod30minCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod3hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccPeriod6hrCallback ( Widget, XtPointer, XtPointer );
    static void uifAccumOnTheHourCallback ( Widget, XtPointer, XtPointer );
    static void uifAccumPeriodTextCallback ( Widget, XtPointer, XtPointer );
    static void uifAccumRunningCallback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHeightTextCallback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt0Callback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt1000Callback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt1500Callback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt3000Callback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt500Callback ( Widget, XtPointer, XtPointer );
    static void uifCAPPIHt5000Callback ( Widget, XtPointer, XtPointer );
    static void uifRainRateClipTextCallback ( Widget, XtPointer, XtPointer );
    static void uifUseAllCallback ( Widget, XtPointer, XtPointer );
    static void uifVolOnlyCallback ( Widget, XtPointer, XtPointer );

    //---- Start editable code block: AccumProdFormClass private


    //---- End editable code block: AccumProdFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

