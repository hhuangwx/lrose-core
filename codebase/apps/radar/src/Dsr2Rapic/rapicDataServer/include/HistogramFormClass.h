
//////////////////////////////////////////////////////////////
//
// Header file for HistogramFormClass
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
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
#ifndef HISTOGRAMFORMCLASS_H
#define HISTOGRAMFORMCLASS_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations

#include <Vk/VkSimpleWindow.h>
#include <GL/glx.h>
#include "histogram.h"

//---- End editable code block: headers and declarations


class HistogramFormClass : public VkComponent
{ 


  public:

    HistogramFormClass ( const char *, Widget );
    HistogramFormClass ( const char * );
    ~HistogramFormClass();
    void create ( Widget );
    const char *  className();

    static VkComponent *CreateHistogramFormClass( const char *name, Widget parent ); 

    //---- Start editable code block: HistogramFormClass public

	virtual void drawHistogram(histogramClass *histogram = 0, 
		unsigned char *cmap = 0, 
		int *histeqtable = 0);
	virtual void drawPalette(int cmap_size = 0, 
		unsigned char *cmap = 0);
	static const char *const histMouseButtonMoveCallback;
	virtual int scaledHorizMPos();	// scaled mouse position, 0 - palette size
	virtual void writeLabel(int val = 0);

    //---- End editable code block: HistogramFormClass public


  protected:


    // Widgets created by this class

    Widget  _histogramFormClass2;
    Widget  _histogramglwidget1;
    Widget  _histpalglwidget1;
    Widget  _label62;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void histogramExposed ( Widget, XtPointer );
    virtual void histogramGinit ( Widget, XtPointer );
    virtual void histogramInput ( Widget, XtPointer );
    virtual void histogramResized ( Widget, XtPointer );
    virtual void histpalExposed ( Widget, XtPointer );
    virtual void histpalGinit ( Widget, XtPointer );
    virtual void histpalResized ( Widget, XtPointer );

    //---- End editable code block: HistogramFormClass protected

    histogramClass *Histogram;
    int *HistEqTable;
    Window hist_window;
    Display* hist_display;
    GLXContext histogram_context, palette_context;
    long hist_w, hist_h, pal_w, pal_h;
    unsigned char	*Cmap;
    int	Cmap_size;
    int scaledhorizmpos;

    //---- End editable code block: HistogramFormClass protected


  private: 

    // Array of default resources

    static String      _defaultHistogramFormClassResources[];


    // Callbacks to interface with Motif

    static void histogramExposedCallback ( Widget, XtPointer, XtPointer );
    static void histogramGinitCallback ( Widget, XtPointer, XtPointer );
    static void histogramInputCallback ( Widget, XtPointer, XtPointer );
    static void histogramResizedCallback ( Widget, XtPointer, XtPointer );
    static void histpalExposedCallback ( Widget, XtPointer, XtPointer );
    static void histpalGinitCallback ( Widget, XtPointer, XtPointer );
    static void histpalResizedCallback ( Widget, XtPointer, XtPointer );

    static void* RegisterHistogramFormClassInterface();

    //---- Start editable code block: HistogramFormClass private


    //---- End editable code block: HistogramFormClass private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif

