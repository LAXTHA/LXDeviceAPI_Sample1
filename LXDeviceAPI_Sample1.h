
// LXDeviceAPI_Sample1.h : LXDeviceAPI_Sample1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLXDeviceAPI_Sample1App:
// �� Ŭ������ ������ ���ؼ��� LXDeviceAPI_Sample1.cpp�� �����Ͻʽÿ�.
//

class CLXDeviceAPI_Sample1App : public CWinApp
{
public:
	CLXDeviceAPI_Sample1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLXDeviceAPI_Sample1App theApp;
