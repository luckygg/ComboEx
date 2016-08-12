
// FTech_ComboExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_ComboEx.h"
#include "FTech_ComboExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_ComboExDlg dialog




CFTech_ComboExDlg::CFTech_ComboExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_ComboExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_ComboExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_cbTest);
}

BEGIN_MESSAGE_MAP(CFTech_ComboExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CFTech_ComboExDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFTech_ComboExDlg message handlers

BOOL CFTech_ComboExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_cbTest.InitControl(this);
	m_cbTest.SetItemLBHeight(20);
	m_cbTest.AddString(L"TEXT1");
	m_cbTest.AddString(L"TEXT2");
	m_cbTest.AddString(L"TEXT3");
	m_cbTest.AddString(L"TEXT4");
	m_cbTest.AddString(L"TEXT5");
	m_cbTest.AddString(L"TEXT6");
	m_cbTest.SetColorLBItemNomal(255,61,61,61);
	m_cbTest.SetColorLBItemHot(255,81,81,81);
	m_cbTest.SetColorLBBkg(255,61,61,61);
	m_cbTest.SetSizeLBText(15);
	m_cbTest.SetColorLBTextHot(255,160,160,160);
	m_cbTest.SetAlignLBTextCM();

	m_cbTest.LoadBtnImageFromFile(L"combo.png");
	m_cbTest.SetColorBtnBorder(255,97,97,97);
	CRect rcBtn = m_cbTest.GetSizeBtn();
	m_cbTest.SetSizeBtnImage(rcBtn.left,rcBtn.top,rcBtn.Width(),rcBtn.Height());
	m_cbTest.SetSizeBtnText(14);
	m_cbTest.SetColorBtnText(255,160,160,255);
	m_cbTest.SetAlignBtnTextCM();
	m_cbTest.SetOffsetBtnText(-20,0);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_ComboExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_ComboExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFTech_ComboExDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}

void CFTech_ComboExDlg::OnBnClickedButton1()
{
	m_cbTest.SetSizeLBHeight(100);
}
