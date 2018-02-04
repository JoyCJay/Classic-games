// LineStatic.cpp : implementation file
//

#include "stdAfx.h"
#include "llk.h"
#include "LineStatic.h"
#include "LlkDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineStatic

CLineStatic::CLineStatic()
{
	m_lineNum = 0;
}

CLineStatic::~CLineStatic()
{
}


BEGIN_MESSAGE_MAP(CLineStatic, CStatic)
	//{{AFX_MSG_MAP(CLineStatic)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineStatic message handlers

HBRUSH CLineStatic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CLineStatic::DrawLine(CDC *pDC)
{
	POINT p1, p2, p3, p4;
	CPen *pRedPen = new CPen;
	pRedPen->CreatePen(PS_SOLID, 2, RGB(255,0,0));
	CGdiObject *pOldPen = pDC->SelectObject(pRedPen);
	switch(m_lineNum)
	{
	case 1:	
		p1.x = m_src1.y * 40 + 20;
		p1.y = m_src1.x * 40 + 20;
		p2.x = m_src2.y * 40 + 20;
		p2.y = m_src2.x * 40 + 20;

		pDC->MoveTo(p1);
		pDC->LineTo(p2);

		break;
	case 2:
		p1.x = m_src1.y * 40 + 20;
		p1.y = m_src1.x * 40 + 20;
		p2.x = m_src2.y * 40 + 20;
		p2.y = m_src2.x * 40 + 20;
		p3.x = m_crossP1.y * 40 + 20;
		p3.y = m_crossP1.x * 40 + 20;

		pDC->MoveTo(p1);
		pDC->LineTo(p3);
		pDC->LineTo(p2);

		break;
	case 3:
		p1.x = m_src1.y * 40 + 20;
		p1.y = m_src1.x * 40 + 20;
		p2.x = m_src2.y * 40 + 20;
		p2.y = m_src2.x * 40 + 20;
		p3.x = m_crossP1.y * 40 + 20;
		p3.y = m_crossP1.x * 40 + 20;
		p4.x = m_crossP2.y * 40 + 20;
		p4.y = m_crossP2.x * 40 + 20;		

		pDC->MoveTo(p1);
		pDC->LineTo(p3);
		pDC->LineTo(p4);
		pDC->LineTo(p2);

		break;
	default:
		break;
	}
	pDC->SelectObject(pOldPen);
}

void CLineStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	if(m_lineNum)
	{
		DrawLine(&dc);
		SetTimer(1, 100, NULL);
	}

}

void CLineStatic::OnTimer(UINT nIDEvent) 
{
	m_lineNum = 0;//防止在OnPaint()里再画线
	CLlkDlg *parent = (CLlkDlg *)GetParent();
	parent->RefreshMap();
	Invalidate();
	KillTimer(1);
}
