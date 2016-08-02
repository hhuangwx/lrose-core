
//////////////////////////////////////////////////////////////
//
// Header file for SelStnFormClassUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, SelStnFormClass is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the SelStnFormClass files
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
#ifndef SELSTNFORMCLASSUI_H
#define SELSTNFORMCLASSUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


class SelStnFormClassUI : public VkComponent
{ 

  public:

    SelStnFormClassUI ( const char *, Widget );
    SelStnFormClassUI ( const char * );
    ~SelStnFormClassUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: SelStnFormClass public


    //---- End editable code block: SelStnFormClass public


  protected:


    // Widgets created by this class

    Widget  _alltoggle;
    Widget  _button27;
    Widget  _button28;
    Widget  _button29;
    Widget  _button30;
    Widget  _knowntoggle;
    Widget  _label1;
    Widget  _label3;
    Widget  _radiobox;
    Widget  _scrolledWindow2;
    Widget  _selStnFormClassUI;
    Widget  _selStnscrolledList1;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void uifAllStnChanged ( Widget, XtPointer );
    virtual void uifApplySel ( Widget, XtPointer );
    virtual void uifClose ( Widget, XtPointer );
    virtual void uifKnownOnlyChanged ( Widget, XtPointer );
    virtual void uifStnListBrowse ( Widget, XtPointer );
    virtual void uifStnListSel ( Widget, XtPointer );
    virtual void uifUseDefault ( Widget, XtPointer );
    virtual void uifUseSel ( Widget, XtPointer );

    //---- Start editable code block: SelStnFormClass protected


    //---- End editable code block: SelStnFormClass protected


  private: 

    // Array of default resources

    static String      _defaultSelStnFormClassUIResources[];


    // Callbacks to interface with Motif

    static void uifAllStnChangedCallback ( Widget, XtPointer, XtPointer );
    static void uifApplySelCallback ( Widget, XtPointer, XtPointer );
    static void uifCloseCallback ( Widget, XtPointer, XtPointer );
    static void uifKnownOnlyChangedCallback ( Widget, XtPointer, XtPointer );
    static void uifStnListBrowseCallback ( Widget, XtPointer, XtPointer );
    static void uifStnListSelCallback ( Widget, XtPointer, XtPointer );
    static void uifUseDefaultCallback ( Widget, XtPointer, XtPointer );
    static void uifUseSelCallback ( Widget, XtPointer, XtPointer );

    //---- Start editable code block: SelStnFormClass private


    //---- End editable code block: SelStnFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

