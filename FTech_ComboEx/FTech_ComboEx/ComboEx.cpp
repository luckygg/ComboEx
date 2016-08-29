// ComboEx.cpp : implementation file
//

#include "stdafx.h"
#include "ComboEx.h"


// CComboEx

IMPLEMENT_DYNAMIC(CComboEx, CComboBox)

CComboEx::CComboEx()
{
	RegisterWindowClass();
	m_pwndBtn	= NULL;
	m_pwndLB	= NULL;
	m_nLBHeight = 100;
	m_pParent	= NULL;
}

CComboEx::~CComboEx()
{
	if (m_pwndBtn != NULL)
	{
		m_pwndBtn->DestroyWindow();
		delete m_pwndBtn;
		m_pwndBtn = NULL;
	}

	if (m_pwndLB != NULL)
	{
		m_pwndLB->DestroyWindow();
		delete m_pwndLB;
		m_pwndLB = NULL;
	}
}


BEGIN_MESSAGE_MAP(CComboEx, CComboBox)
	ON_CONTROL(LBN_SELCHANGE,IDX_LISTBOX_CTRL,OnClickedListBox)
END_MESSAGE_MAP()

void CComboEx::RegisterWindowClass(void)
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	wndcls.lpfnWndProc      = ::DefWindowProc;
	wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
	wndcls.hInstance        = hInst;
	wndcls.hIcon            = NULL;
	wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);
	wndcls.lpszMenuName     = NULL;
	wndcls.lpszClassName    = COMBOEX_WINCLASSNAME;

	AfxRegisterClass(&wndcls);
}

bool CComboEx::InitControl(CWnd* pWnd)
{
	if (pWnd == NULL) return false;

	m_pParent = pWnd;

	CRect rect;
	GetClientRect(&rect);

	CRect rcWnd;
	GetWindowRect(&rcWnd);
	pWnd->ScreenToClient(&rcWnd);
	
	rect.bottom += m_nLBHeight;
	rcWnd.bottom+=m_nLBHeight;
	
	MoveWindow(rcWnd);

	m_pwndBtn = new CButtonEx();
	m_pwndLB = new CListBoxEx();

	m_pwndBtn->CreateContol(this,CRect(rect.left,rect.top,rect.right,20),IDX_BUTTON_CTRL);

	m_pwndLB->CreateContol(this,CRect(rect.left,20,rect.right,rect.bottom),IDX_LISTBOX_CTRL);

	m_pwndLB->ShowWindow(SW_HIDE);

	return true;
}

void CComboEx::SetSizeLBHeight(int nHeight)
{
	m_nLBHeight = nHeight;

	CRect rect;
	GetClientRect(&rect);

	CRect rcWnd;
	GetWindowRect(&rcWnd);
	m_pParent->ScreenToClient(&rcWnd);

	rect.bottom  = m_nLBHeight;
	rcWnd.bottom += m_nLBHeight;

	MoveWindow(rcWnd);
	
	m_pwndLB->MoveWindow(CRect(rect.left,20,rect.right,rect.bottom));
}

// CComboEx message handlers

BOOL CComboEx::OnCommand(WPARAM wParam, LPARAM lParam) 
{ 
	if(wParam == m_pwndBtn->GetDlgCtrlID())
	{
		if (m_pwndLB->IsWindowVisible() == TRUE)
			m_pwndLB->ShowWindow(SW_HIDE);
		else
		{
			m_pwndLB->ShowWindow(SW_SHOW);
			m_pwndLB->SetFocus();
		}
	} 
	
	return CComboBox::OnCommand(wParam, lParam); 
}

void CComboEx::OnClickedListBox()
{
	CString text=L"";
	int pos = m_pwndLB->GetCurSel();
	m_pwndLB->GetText(pos,text);

	m_pwndBtn->SetText(text);
	m_pwndLB->ShowWindow(SW_HIDE);
}

