
// ObjectTrackingByOpticalFlow.h : ObjectTrackingByOpticalFlow DLL 
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH this file."
#endif

#include "resource.h"		// 

// CObjectTrackingByOpticalFlowApp
// 
//

class CObjectTrackingByOpticalFlowApp : public CWinApp
{
public:
	CObjectTrackingByOpticalFlowApp();

// 
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
	