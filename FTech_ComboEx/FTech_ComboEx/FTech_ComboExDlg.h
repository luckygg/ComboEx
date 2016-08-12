
// FTech_ComboExDlg.h : header file
//

#pragma once
#include "ComboEx.h"
#include "buttonex.h"

// CFTech_ComboExDlg dialog
class CFTech_ComboExDlg : public CDialogEx
{
// Construction
public:
	CFTech_ComboExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_COMBOEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboEx m_cbTest;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
};
