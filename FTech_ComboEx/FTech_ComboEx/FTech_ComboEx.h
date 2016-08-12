
// FTech_ComboEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_ComboExApp:
// See FTech_ComboEx.cpp for the implementation of this class
//

class CFTech_ComboExApp : public CWinApp
{
public:
	CFTech_ComboExApp();

	ULONG_PTR m_gdiplusToken;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_ComboExApp theApp;