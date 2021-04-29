/* COPYRIGHT NOTICE:
********************************************************
*  Copyright (c) 2000 InnoVision Technology, Inc.      *
*  All rights reserved.                                *
*  PROPRIETARY AND CONFIDENTIAL                        *
*  DO NOT DISTRIBUTE                                   *
********************************************************
*/
// cgUIDoc.cpp : implementation of the CCgUIDoc class
//

#include "stdafx.h"
#include "cgUI.h"

#include "cgUIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCgUIDoc

IMPLEMENT_DYNCREATE(CCgUIDoc, CDocument)

BEGIN_MESSAGE_MAP(CCgUIDoc, CDocument)
	//{{AFX_MSG_MAP(CCgUIDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCgUIDoc construction/destruction

CCgUIDoc::CCgUIDoc()
{
	TRACE0( "cgUIDoc.cpp : CCgUIDoc::CCgUIDoc() - constructor\n" );

}//end of constructor - CCgUIDoc::CCgUIDoc()

CCgUIDoc::~CCgUIDoc()
{	
}//end of destructor - CCgUIDoc::~CCgUIDoc()

BOOL CCgUIDoc::OnNewDocument()
{
	TRACE0( "cgUIDoc.cpp : CCgUIDoc::OnNewDocument\n" );
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)	
	return TRUE;
}//end of CCgUIDoc::OnNewDocument()


/////////////////////////////////////////////////////////////////////////////
// CCgUIDoc serialization

void CCgUIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}//end of CCgUIDoc::Serialize(CArchive& ar)

/////////////////////////////////////////////////////////////////////////////
// CCgUIDoc diagnostics

#ifdef _DEBUG
void CCgUIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCgUIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

//////////////////////////////////////////////////////////////////////////////////////////
// CCgUIDoc commands
//////////////////////////////////////////////////////////////////////////////////////////

