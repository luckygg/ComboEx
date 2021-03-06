#pragma once

//----------------------------------------------------------
// ComboEx Control
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2016-09-07 18:57
// Modified by William Kim
//----------------------------------------------------------

#include "ButtonEx.h"
#include "ListBoxEx.h"

#define IDX_LABEL_CTRL		1002
#define IDX_BUTTON_CTRL		1003
#define IDX_LISTBOX_CTRL	1004

#define COMBOEX_WINCLASSNAME L"COMBOEX_CLASS"

#define WM_CLICK_MESSAGE  (WM_USER+1)
// CComboEx

class CComboEx : public CComboBox
{
	DECLARE_DYNAMIC(CComboEx)

public:
	CComboEx();
	virtual ~CComboEx();

	//----- Init Control -----//
	bool InitControl(CWnd* pWnd);
	void SetEnable(bool bEnable) { m_bEnable = bEnable; m_pwndBtn->SetEnable(bEnable); Invalidate(); }
	
	//-------------------- List Box Control --------------------//
	//----- Add Item -----//
	int AddString(CString strItem) { return m_pwndLB->AddString(strItem); }
	int InsertString(int nIndex, CString strItem) { m_pwndLB->InsertString(nIndex, strItem); }

	//----- Set Size -----//
	void SetSizeLBText		(float fSize) { m_pwndLB->SetSizeText(fSize);		}
	void SetSizeLBBorder	(float fSize) { m_pwndLB->SetSizeBorder(fSize);		}
	void SetSizeLBHeight	(int nHeight);
	void SetItemLBHeight	(int nHeight) { m_pwndLB->SetItemHeight(nHeight);	}	

	//----- Set Color -----//
	void SetColorLBBkg			(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorBkg(nA,nR,nG,nB);			}
	void SetColorLBBorder		(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorBorder(nA,nR,nG,nB);		}
	void SetColorLBTextHot		(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorTextHot(nA,nR,nG,nB);		}
	void SetColorLBTextNormal	(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorTextNormal(nA,nR,nG,nB);	}
	void SetColorLBItemHot		(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorItemHot(nA,nR,nG,nB);		}
	void SetColorLBItemNomal	(int nA, int nR, int nG, int nB) { m_pwndLB->SetColorItemNomal(nA,nR,nG,nB);	}
	void SetColorLBItemNomal	(int nA1, int nR1, int nG1, int nB1, int nA2, int nR2, int nG2, int nB2) { m_pwndLB->SetColorItemNomal(nA1,nR1,nG1,nB1,nA2,nR2,nG2,nB2); }
	void SetColorLBBkg			(int nA, COLORREF clrColor) { m_pwndLB->SetColorBkg(nA,clrColor);			}
	void SetColorLBBorder		(int nA, COLORREF clrColor) { m_pwndLB->SetColorBorder(nA,clrColor);		}
	void SetColorLBTextHot		(int nA, COLORREF clrColor) { m_pwndLB->SetColorTextHot(nA,clrColor);		}
	void SetColorLBTextNormal	(int nA, COLORREF clrColor) { m_pwndLB->SetColorTextNormal(nA,clrColor);	}
	void SetColorLBItemHot		(int nA, COLORREF clrColor) { m_pwndLB->SetColorItemHot(nA,clrColor);		}
	void SetColorLBItemNomal	(int nA, COLORREF clrColor) { m_pwndLB->SetColorItemNomal(nA,clrColor);		}
	void SetColorLBItemNomal	(int nA1, COLORREF clrColor1, int nA2, COLORREF clrColor2) { m_pwndLB->SetColorItemNomal(nA1,clrColor1,nA2,clrColor2); }

	//----- Set Offset -----//
	void SetOffsetLBText(int nX, int nY) { m_pwndLB->SetOffsetText(nX,nY); }

	//----- Set Text Alignment -----//
	void SetAlignLBTextLT() { m_pwndLB->SetAlignTextLT(); }
	void SetAlignLBTextCT() { m_pwndLB->SetAlignTextCT(); } 				   
	void SetAlignLBTextRT() { m_pwndLB->SetAlignTextRT(); } 
	void SetAlignLBTextLM() { m_pwndLB->SetAlignTextLM(); } 
	void SetAlignLBTextCM() { m_pwndLB->SetAlignTextCM(); } 
	void SetAlignLBTextRM() { m_pwndLB->SetAlignTextRM(); } 
	void SetAlignLBTextLB() { m_pwndLB->SetAlignTextLB(); } 
	void SetAlignLBTextCB() { m_pwndLB->SetAlignTextCB(); } 
	void SetAlignLBTextRB() { m_pwndLB->SetAlignTextRB(); } 

	//-------------------- Button Control --------------------//
	//----- Set & Get Text -----//
	void SetBtnText(CString strText) { m_pwndBtn->SetText(strText); }

	//----- Set Offset -----//
	void SetOffsetBtnText	(int nX, int nY) { m_pwndBtn->SetOffsetText(nX,nY); }

	//----- Set & Get Size -----//
	void SetSizeBtnText	(float fSize) { m_pwndBtn->SetSizeText(fSize); }
	void SetSizeBtnBorder	(float fSize) { m_pwndBtn->SetSizeBorder(fSize); }
	void SetSizeBtnImage	(int nLeft, int nTop, int nWidth, int nHeight) { m_pwndBtn->SetSizeImage(nLeft,nTop,nWidth,nHeight); }
	CRect GetSizeBtn() { CRect rcSize; m_pwndBtn->GetClientRect(&rcSize); return rcSize; }

	//----- Set Color -----//
	void SetColorBtnBkg		(int nA, int nR, int nG, int nB) { m_pwndBtn->SetColorBkg(nA,nR,nG,nB);		}
	void SetColorBtnBorder	(int nA, int nR, int nG, int nB) { m_pwndBtn->SetColorBorder(nA,nR,nG,nB);	}
	void SetColorBtnText	(int nA, int nR, int nG, int nB) { m_pwndBtn->SetColorText(nA,nR,nG,nB);	}
	void SetColorBtnBkg		(int nA, COLORREF clrColor) { m_pwndBtn->SetColorBkg(nA,clrColor);		}
	void SetColorBtnBorder	(int nA, COLORREF clrColor) { m_pwndBtn->SetColorBorder(nA,clrColor);	}
	void SetColorBtnText	(int nA, COLORREF clrColor) { m_pwndBtn->SetColorText(nA,clrColor);		}

	//----- Set Text Alignment -----//
	void SetAlignBtnTextLT() { m_pwndBtn->SetAlignTextLT(); } 
	void SetAlignBtnTextCT() { m_pwndBtn->SetAlignTextCT(); } 				   
	void SetAlignBtnTextRT() { m_pwndBtn->SetAlignTextRT(); } 
	void SetAlignBtnTextLM() { m_pwndBtn->SetAlignTextLM(); } 
	void SetAlignBtnTextCM() { m_pwndBtn->SetAlignTextCM(); } 
	void SetAlignBtnTextRM() { m_pwndBtn->SetAlignTextRM(); } 
	void SetAlignBtnTextLB() { m_pwndBtn->SetAlignTextLB(); } 
	void SetAlignBtnTextCB() { m_pwndBtn->SetAlignTextCB(); } 
	void SetAlignBtnTextRB() { m_pwndBtn->SetAlignTextRB(); } 

	//----- Set Image -----//
	bool LoadBtnImageFromFile(CString strPath) { return m_pwndBtn->LoadImageFromFile(strPath); }
	bool LoadBtnImageFromResource(UINT ID, bool bPNG) { return m_pwndBtn->LoadImageFromResource(ID, bPNG); }

	int GetCountItem() { return m_pwndLB->GetCount(); }
	CString GetItemText(int nIndex) { CString value=L""; m_pwndLB->GetText(nIndex, value); return value; }
	void SelectItem(int nIndex) { CString value=L""; value = GetItemText(nIndex); SetBtnText(value); m_pwndLB->SetCurSel(nIndex); }
	int GetSelectedItemIndex() { return m_pwndLB->GetCurSel(); }
	CString GetSelectedItemText() { int n = GetSelectedItemIndex(); if (n>-1) return GetItemText(n); else return L""; }
private :
	CWnd*		m_pParent;
	CButtonEx*	m_pwndBtn;
	CListBoxEx*	m_pwndLB;
	int			m_nLBHeight;
	CRect		m_rcWnd;
	CRect		m_rcCtrl;
	bool		m_bEnable;

	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	void RegisterWindowClass(void);
	afx_msg void OnClickedListBox();
protected:
	DECLARE_MESSAGE_MAP()
};


