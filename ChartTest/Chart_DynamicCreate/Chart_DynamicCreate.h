
// Chart_DynamicCreate.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChart_DynamicCreateApp:
// �йش����ʵ�֣������ Chart_DynamicCreate.cpp
//

class CChart_DynamicCreateApp : public CWinApp
{
public:
	CChart_DynamicCreateApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChart_DynamicCreateApp theApp;