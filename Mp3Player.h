
// Mp3Player.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMp3PlayerApp: 
// �йش����ʵ�֣������ Mp3Player.cpp
//

class CMp3PlayerApp : public CWinApp
{
public:
	CMp3PlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMp3PlayerApp theApp;