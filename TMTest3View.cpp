
// TMTest3View.cpp : implementation of the CTMTest3View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TMTest3.h"
#endif

#include "TMTest3Doc.h"
#include "TMTest3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTMTest3View

IMPLEMENT_DYNCREATE(CTMTest3View, CView)

BEGIN_MESSAGE_MAP(CTMTest3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTMTest3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTMTest3View construction/destruction

CTMTest3View::CTMTest3View()
{
	// TODO: add construction code here

}

CTMTest3View::~CTMTest3View()
{
}

BOOL CTMTest3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTMTest3View drawing

void CTMTest3View::OnDraw(CDC* /*pDC*/)
{
	CTMTest3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTMTest3View printing


void CTMTest3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTMTest3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTMTest3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTMTest3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTMTest3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTMTest3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTMTest3View diagnostics

#ifdef _DEBUG
void CTMTest3View::AssertValid() const
{
	CView::AssertValid();
}

void CTMTest3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTMTest3Doc* CTMTest3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTMTest3Doc)));
	return (CTMTest3Doc*)m_pDocument;
}
#endif //_DEBUG


// CTMTest3View message handlers
