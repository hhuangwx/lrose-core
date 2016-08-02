
//////////////////////////////////////////////////////////////
//
// Header file for SeqCtlSmallForm
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//
//    If you do modify this class, limit your changes to adding
//    members below the "//--- End generated code section" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//
//////////////////////////////////////////////////////////////
#ifndef SEQCTLSMALLFORM_H
#define SEQCTLSMALLFORM_H
#include <Vk/VkComponent.h>


//---- End generated headers


class SeqCtlSmallForm : public VkComponent
{ 


  public:

    SeqCtlSmallForm ( const char *, Widget );
    SeqCtlSmallForm ( const char * );
    ~SeqCtlSmallForm();
    void create ( Widget );
    const char *  className();

    static VkComponent *CreateSeqCtlSmallForm( const char *name, Widget parent ); 

    //--- End generated code section



  protected:


    // Widgets created by this class

    Widget  _seqBwdButton;
    Widget  _seqCtlSmallForm2;
    Widget  _seqFwdButton;
    Widget  _seqLatestButton;
    Widget  _seqLoopButton;
    Widget  _seqStopButton;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void doSeqStart ( Widget, XtPointer );
    virtual void doSeqStepBwd ( Widget, XtPointer );
    virtual void doSeqStepFwd ( Widget, XtPointer );
    virtual void doSeqStepLast ( Widget, XtPointer );
    virtual void doSeqStop ( Widget, XtPointer );

    //--- End generated code section



  private: 

    // Array of default resources

    static String      _defaultSeqCtlSmallFormResources[];


    // Callbacks to interface with Motif

    static void doSeqStartCallback ( Widget, XtPointer, XtPointer );
    static void doSeqStepBwdCallback ( Widget, XtPointer, XtPointer );
    static void doSeqStepFwdCallback ( Widget, XtPointer, XtPointer );
    static void doSeqStepLastCallback ( Widget, XtPointer, XtPointer );
    static void doSeqStopCallback ( Widget, XtPointer, XtPointer );

    //--- End generated code section

};
//---- End of generated code

#endif

