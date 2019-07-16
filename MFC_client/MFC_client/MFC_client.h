// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MFC_client.h : main header file for the MFC_client application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFC_clientApp:
// See MFC_client.cpp for the implementation of this class
//

class CMFC_clientApp : public CWinAppEx
{
public:
	CMFC_clientApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_clientApp theApp;
