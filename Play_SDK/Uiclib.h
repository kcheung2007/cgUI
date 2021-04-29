/*===========================================================================*\
||                                                                           ||
||  (c) 1995 by Play Incorporated                                            ||
||                                                                           ||
||  FILE:           UICLIB.H                                                 ||
||                                                                           ||
||  DESCRIPTION:    Header file with everything a UICLIB client needs.       ||
||                  Defines all attribute flags, max text lengths, etc.      ||
||                                                                           ||
||  MODIFICATIONS:  10/22/95     T.Sprague       created                     ||
||                                                                           ||
\*===========================================================================*/
#ifndef UICLIB_H_INCLUDED
#define UICLIB_H_INCLUDED YUP!

//#include "pciids.h"      // interface IDs for UIC lib
//#include "pcclsids.h"    // class IDs for UIC lib

#include "plyctl.h"
#include "pcadvs.h"      // header for IPCtrlAdviseSink interface
#include "panel.h"
#include "plytxt.h"
#include "plyglo.h"
#include "stdbg.h"
#include "pstrlist.h"
#include "PlayClsId.h"

#define FSTY_BOLD       0x01
#define FSTY_ITALIC     0x02
#define FSTY_UNDERLINE  0x04
#define FSTY_ANTIALIAS_DISABLED 0x80

#define BMTYPE_KNOBFRAMES   0x0001
#define BMTYPE_HANDLEFACE   0x0002
#define BMTYPE_LABEL        0x0004
#define BMTYPE_BTNFRAMES    0x0008

// currently used only internally
#define BMTYPE_HANDLE_UP    0x1000
#define BMTYPE_HANDLE_EX    0x2000
#define BMTYPE_HANDLE_DOWN  0x4000
#define BMTYPE_HANDLE_GHOST 0x8000

#define STDBM_MAINFRAME     0
#define STDBM_EDGE          1
#define STDBM_WORKSPACE     2
#define STDBM_POPUP         3


//
// these are defines for placement attributes in PlayPanels
//
#define PPLACE_NEWROW           0x01
#define PPLACE_ADJACENT         0x02
#define PPLACE_ALIGNTOP         0x04
#define PPLACE_ALIGNBOTTOM      0x08
#define PPLACE_ADJROW           0x10

//
// these are defines for a control's text placement relative to its handle
//
#define TPLACE_ON_CENTER        0x00
#define TPLACE_ON_LEFT          0x01
#define TPLACE_ON_RIGHT         0x02
#define TPLACE_ABOVE_LEFT       0x11
#define TPLACE_ABOVE_CENTER     0x10
#define TPLACE_ABOVE_RIGHT      0x12
#define TPLACE_LEFTSIDE         0x21
#define TPLACE_RIGHTSIDE        0x22
#define TPLACE_BELOW_LEFT       0x41
#define TPLACE_BELOW_CENTER     0x40
#define TPLACE_BELOW_RIGHT      0x42

//
// these are "attribute numbers" for the various 
// attributes of the controls
// (PCATTR = Play Control Attribute)
//
#define PCATTR_TEXT_CLR             1
#define PCATTR_CLR_TXT_NORMAL       PCATTR_TEXT_CLR
#define PCATTR_TEXT_CLR_HIGH        2
#define PCATTR_CLR_TXT_ACTIVE       PCATTR_TEXT_CLR_HIGH
#define PCATTR_LIGHT_CLR            3
#define PCATTR_LIGHT_POSITION       4
#define PCATTR_LIGHT_INTENSITY      5
#define PCATTR_SURFACE_COLORMAP     6
#define PCATTR_EDGE_SIZE            7
#define PCATTR_FONT_NAME            8
#define PCATTR_FONT_SIZE            9
#define PCATTR_FONT_STYLE           10
#define PCATTR_TXT_BORDER_X         11
#define PCATTR_TXT_BORDER_Y         12
#define PCATTR_BTN_TOGGLE           13
#define PCATTR_GLOW_SPILL           14
#define PCATTR_POT_MAX              15
#define PCATTR_POT_MIN              16
#define PCATTR_EDIT_TEXT_CLR        17
#define PCATTR_DROPFRAME            18
#define PCATTR_NUM_FLOAT            19
#define PCATTR_EDIT_TEXT_CLR_HIGH   20
#define PCATTR_TEXT                 21
#define PCATTR_BTN_MUEX             22
#define PCATTR_HOME_PANEL           23
#define PCATTR_UP_VERIFY            24
#define PCATTR_HANDLE_SHAPE         25
#define PCATTR_EDIT_TEXT_CLR_EX     26
#define PCATTR_TEXT_PLACEMENT       27
#define PCATTR_CTL_CLR              28
#define PCATTR_CTL_CLR_HIGH         29
#define PCATTR_CTL_CLR_EX           30
#define PCATTR_GLOW_CLR             31
#define PCATTR_CLR_GLOW             PCATTR_GLOW_CLR
#define PCATTR_USER_ID	            32
//#define PCATTR_FRACTAL_GRAIN        33
#define PCATTR_TRANSPARENCY         34
#define PCATTR_USER_POPUP           35
#define PCATTR_ADVISESINK           36
#define PCATTR_GLOW_CLR_EX          37
#define PCATTR_TEXT_CLR_EX          38
//#define PCATTR_CLR_FRACT_3_HIGH     39
#define PCATTR_POPUPSIZE            41
#define PCATTR_TEXT_CLR_GHOST       42
#define PCATTR_CTL_CLR_GHOST        43
#define PCATTR_POT_HSLIDER          44
#define PCATTR_SCROLLBAR_VERTICAL   45  
#define PCATTR_SB_DISABLE_ZOOM      46  
#define PCATTR_USER_DRAWN           47
#define PCATTR_EDIT_FONT_NAME       48
#define PCATTR_EDIT_FONT_SIZE       49
#define PCATTR_EDIT_FONT_STYLE      50
#define PCATTR_GLOW_ALPHA           51
#define PCATTR_GLOW_ALPHA_EX        52
#define PCATTR_BULB_ALPHA           53
#define PCATTR_TEXT_NUMBER			54
#define PCATTR_SLIDER_MAX_TOP		55	// Is max value at top of vert slider?
#define PCATTR_USER_DWORD			56
#define PCATTR_FRAME_ON				57	// Draw frame around flat/number edit boxes
#define PCATTR_SHOW_FIELD			58	// Show field in timecode box.
#define PCATTR_STRING_SHOW_FRONT	59	// To show the front or end of string in box.
#define PCATTR_FLATTEN				60	// Flatten a string or number box.
#define PCATTR_DYNAMIC_TEXT			61	// If text is read from pnl file or not.
#define PCATTR_STRING_USE_ELLIPSE	62	// To use ellipses in stringboxes or not.
#define PCATTR_INCREMENT_ADVISE		63	// Advise app on incremental changes in numbers.
#define PCATTR_INCREMENT_FACTOR		64	// How much sliders increment by per mouse move.
#define PCATTR_PRECISION			65	// How many characters to display after decimal point.
#define PCATTR_BTN_FORCE_TEXT		66	// Force text to draw even on button with graphic.
#define PCATTR_FASTANDDIRTY			67	// If timecode boxes are updating fast (clipgrab).
#define PCATTR_BTN_USE_ALPHA		68	// To use alpha as hit area on button.
#define PCATTR_TC_PAL               69  // to set timeboxes to interpret numbers as PAL timecode
#define PCATTR_DISABLE_HANDLE       70  // to prevent control (buttons) from drawing their handle (default=0)
#define PCATTR_DISABLETEXTSTATEMASK 71  // mask of states to disable drawing control's text.( default=0) (draw text if !(state&disablemask) ) applies to handle face alpha also
#define PCATTR_FORGETBITMAPS        72  // forget the names of any bitmaps the control had dropped on it
#define PCATTR_REGIONDATA           73  // set region where control should receive input ( its window region) (set to NULL to kill its region and make it square again)
#define PCATTR_REGIONOFFSETX        74  // offset from top-left of control's window where region should be placed
#define PCATTR_REGIONOFFSETY        75  // 
#define PCATTR_DISABLE_TRACK        76  // to prevent sliders/scrollbars from drawing the "dent" it sits in.
#define PCATTR_TEXT_OFFSET          77  // pointer to POINT struct for where to offset text
#define PCATTR_TEXT_OFFSET_HIGH     78  // pointer to POINT struct for where to offset text when control is highlighted
#define PCATTR_SB_MIN_ZOOM          79  // pointer to double for minimum zoom factor.  (0.0<=min<=1.0)
#define PCATTR_SB_ZOOM_TYPE         80  // set this attr to 1 to give low end of zoom more resolution
#define PCATTR_LB_DISABLE_CHECKMARK 81  // disable the checkmark in listbox controls
#define PCATTR_DISABLE_FILEDROP     82  // show the NO cursor if someone is going to drop a file on this control
#define PCATTR_HIGHLIGHT_PICON      83  // valid only for label controls, it will highlight the label bitmap as if it's a picon
#define PCATTR_POT_LOGSCALE         84  // so a control will scale itself so that it's linear internal range will translate to logarithmic range in it's min/max values
#define PCATTR_EDIT_TEXT_PLACEMENT  85  // for string box controls, to align the text inside the pill  use TPLACE_ON_ flags as values.
#define PCATTR_STRBOX_PASS_CHARS    86  // for string box controls, to have it pass unused characters (like TAB) to parent window
#define PCATTR_STRBOX_APP_SELECT_ALL 87 // set to TRUE if you want string boxes to select all visible text when you set their EDIT_ACTIVE state ON
#define PCATTR_LAF_FLAGS            88  // bitmask for flags to set "Look And Feel" types on the controls See LAF_ #defines

#define PCATTR_SORTSTRINGS			89	// set to TRUE if you want sorted strings in Popups and ListBoxes
#define PCATTR_NODUPLICATE_STRINGS	90	// set to TRUE to remove duplicate strings in Popups and ListBoxes
#define PCATTR_RETURN_REALINDEX		91	// set to TRUE to force the return index of PlayPopup objects to be the value generated after sorting and removal of duplicate strings.
										// .. if this value is FALSE (default) then the returned index will correspond to the position used in AddString()
#define PCATTR_DODRAGDROP			92	// set to FALSE to prevent control from being registered for drag-n-drop.

// attributes for the panel
#define PPATTR_USER_DRAWN           40
#define PPATTR_CLOSERECT            0x1000 // value is LPRECT of closebutton in client coordinates
#define PPATTR_CAPTIONRECT          0x1001 // value is LPRECT of caption (movebar) in client coordinates
#define PPATTR_MINIMIZERECT         0x1002 // value is LPRECT of minimize button in client coordinates
#define PPATTR_MAXIMIZERECT         0x1003 // value is LPRECT of maximize button in client coordinates
#define PPATTR_NUM_PAGES            0x1004 // how many different pages this panel has, 
#define PPATTR_CURRENT_PAGE         0x1005 // which page to go to.  (For different background images)
#define PPATTR_STRETCHPOINTX        0x1006 // what column to replicate sideways from background bitmap if panel is sized larger
#define PPATTR_STRETCHPOINTY        0x1007 // what row to replicate vertically from background bitmap if panel is sized larger
#define PPATTR_CONTROLINDEX         0x1008 // subAttr is index of control to get.  (GetAttr() only)  the playontrol will be AddRef'd
#define PPATTR_NUMCONTROLS          0x1009 // return number of controls currently in panel (GetAttr() only)
#define PPATTR_CONTROLID            0x100a // subAttr is PCATTR_USER_ID of control to find (GetAttr() only) the playontrol will be AddRef'd
#define PPATTR_GROUPADVISESINK      0x100b // subAttr is group ID for advise to set, Set to NULL to clear that advise from the panel's list and from all controls in that group
                                           // group ID is high WORD of Control's USER_ID

// "Look-And-Feel" flags
#define LAF_20LOOK  1 // a flag that means different things to different controls... buttons are raised rather than inset, etc.

//
// Handle shapes
//
#define HSHP_DEFAULT                0
//#define HSHP_ELLIPSE                1

//
// these are type of control links that may be established
//
#define PCLINK_TURNOFF      1
#define PCLINK_TOGGLE       2
#define PCLINK_INCREMENT    3
#define PCLINK_DECREMENT    4
#define PCLINK_COPYVALUE    5
#define PCLINK_INVERTCOPY   6
#define PCLINK_TURNON       7

//
// These define the sizes that can be gotten or suggested with
// GetSize() and SuggestSize()
//
#define SIZE_WINDOW         0
#define SIZE_HANDLE         1
#define SIZE_TRACK          2
#define SIZE_HANDLE_ACTUAL  3
//
// These numbers are OR'd together to make a button's state
//
#define PCST_BTN_DOWN           0x00000001
#define PCST_CAPTURING          0x00000002
#define PCST_EDIT_ACTIVE        0x00000004
#define PCST_EXCITED            0x00000008
#define PCST_RESERVED           0x00000010
#define PCST_GHOSTED            0x00000020
#define PCST_DISABLED           0x00000040
#define PCST_SELECTED           0x00000080
#define PCST_HIDDEN				0x00000100

// the states that are common to all controls, settable by app programmer
#define PC_COMMON_STATES        ( PCST_GHOSTED | PCST_DISABLED | PCST_SELECTED | PCST_EXCITED | PCST_HIDDEN)

// The mask to retrieve strings from the listbox.
#define PCSTR_ALL				0x00000000
#define PCSTR_ON				0x00000001
#define PCSTR_OFF				0x00000002

// The mask to turn on certain buttons in message boxes.
#define PMB_OK					0x00000001
#define PMB_CANCEL				0x00000002
#define PMB_RETRY				0x00000004
#define PMB_HELP				0x00000008
#define PMB_NONE				0x00000010

// 
// these are the numbers revealing the control's type
//
#define PCTL_BTN_MOM        1
#define PCTL_BTN_TGL        2
#define PCTL_KNOB           3
#define PCTL_SLIDER         4
#define PCTL_EDIT           5
#define PCTL_TIMECODE       6
#define PCTL_NUMBER         7
#define PCTL_LISTBOX        8
#define PCTL_LABEL          9
#define PCTL_HSLIDER       10
#define PCTL_SCROLLBAR     11
#define PCTL_NUMEDIT	   12
#define PCTL_SCROOMBAR     13

class CPCtrlAdviseSink : public IPCtrlAdviseSink2
{
public:
    CPCtrlAdviseSink() { m_cRef = 1; } ;
    virtual ~CPCtrlAdviseSink() {} ;

    virtual HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) )
            {
                *ppv = (IUnknown *)this;
                AddRef();
                hr = S_OK;
            } else if ( IsEqualGUID( iid, IID_IPCtrlAdviseSink ) )
            {
                *ppv = (IPCtrlAdviseSink *)this;
                AddRef();
                hr = S_OK;
            } else if (IsEqualGUID(iid, IID_IPCtrlAdviseSink2))
			{
				*ppv = (IPCtrlAdviseSink2 *)this;
				AddRef();
				hr = S_OK;
			}
			else
            {
                *ppv = NULL;
                hr = E_NOINTERFACE;
            }

            return( hr );
        };

    long m_cRef;
    virtual ULONG STDMETHODCALLTYPE AddRef() 
        {
#ifdef _WIN32S
            return(++m_cRef);
#else
            return(InterlockedIncrement(&m_cRef));
#endif
        };
    virtual ULONG STDMETHODCALLTYPE Release()  
        {
#ifdef _WIN32S
            int c = --m_cRef;
#else
            int c = InterlockedDecrement( &m_cRef );
#endif
            if ( !c )
                delete this;
            return(c);
        };

    virtual HRESULT __stdcall OnCtlDown( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };
    
    virtual HRESULT __stdcall OnCtlMove( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };
    
    virtual HRESULT __stdcall OnCtlUp( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };
    
    virtual HRESULT __stdcall OnLBtnUp( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };
    
    virtual HRESULT __stdcall OnLBtnDown( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };
    
    virtual HRESULT __stdcall OnRBtnDown( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };

    virtual HRESULT __stdcall OnRBtnUp( IPlayControl *pPlayCtl )
        { return( E_NOTIMPL ); };

    virtual HRESULT __stdcall OnMouseMove( IPlayControl *pPlayCtl, WPARAM wParam, LPARAM lParam )
        { return( E_NOTIMPL ); };

    virtual HRESULT __stdcall OnDropFiles( IPlayControl *pPlayCtl, WPARAM wParam, LPARAM lParam )
        { return( E_NOTIMPL ); };

    virtual HRESULT __stdcall OnCtlCancel( IPlayControl __RPC_FAR *pPlayCtl)
		{ return (E_NOTIMPL ); };
};

class CPlayPopupAdviseSink : public IPlayPopupAdviseSink
{
public:
    CPlayPopupAdviseSink() { m_cRef = 1; } ;
    virtual ~CPlayPopupAdviseSink() {} ;

    virtual HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) ||
                 IsEqualGUID( iid, IID_IPlayPopupAdviseSink )    )
            {
                *ppv = (IPlayPopupAdviseSink *)this;
                AddRef();
                hr = S_OK;
            } else
            {
                *ppv = NULL;
                hr = E_NOINTERFACE;
            }

            return( hr );
        };

    long m_cRef;
    virtual ULONG STDMETHODCALLTYPE AddRef() {return(++m_cRef);};
    virtual ULONG STDMETHODCALLTYPE Release()  
        {
            long c = --m_cRef;
            if ( !c )
                delete this;
            return(c);
        };

    virtual HRESULT __stdcall OnSelection( IPlayPopup __RPC_FAR *pPopup,int index)
        { return( E_NOTIMPL ); };
        
    virtual HRESULT __stdcall IsValid( IPlayPopup __RPC_FAR *pPopup,int index)
        { return( E_NOTIMPL ); };
    
};

class CPlayPagedPanelAdviseSink : public IPlayPagedPanelAdviseSink
{
public:
    CPlayPagedPanelAdviseSink() { m_cRef = 1; } ;
    virtual ~CPlayPagedPanelAdviseSink() {} ;

    virtual HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppv )
        {
            HRESULT hr;

            if ( IsEqualGUID( iid, IID_IUnknown ) ||
                 IsEqualGUID( iid, IID_IPlayPagedPanelAdviseSink )    )
            {
                *ppv = (IPlayPagedPanelAdviseSink *)this;
                AddRef();
                hr = S_OK;
            } else
            {
                *ppv = NULL;
                hr = E_NOINTERFACE;
            }

            return( hr );
        };

    long m_cRef;
    virtual ULONG STDMETHODCALLTYPE AddRef() {return(++m_cRef);};
    virtual ULONG STDMETHODCALLTYPE Release()  
        {
            long c = --m_cRef;
            if ( !c )
                delete this;
            return(c);
        };
    
    // Tell the app to store Revert info for the given page.
    // If the app returns anything but S_OK, the revert
    // button will be ghosted and disabled for this page.
    virtual HRESULT __stdcall StoreRevertInfo( DWORD dwPageID ){ return E_NOTIMPL; }

    // Tell the app to revert to its stored info for the 
    // given page.  The return value is ignored.
    virtual HRESULT __stdcall Revert( DWORD dwPageID ){ return E_NOTIMPL; }

	// This will be called between the time when the page is selected from the
	// popup menu, but before the page is actually shown. This can allow the app
	// to update the controls on the page if it wants/needs to.
	virtual HRESULT __stdcall OnShowPage(DWORD dwPageID){ return E_NOTIMPL; }

	virtual HRESULT __stdcall OnClose(void) { return E_NOTIMPL; }
};

#endif UICLIB_H_INCLUDED
