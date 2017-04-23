
// LXDeviceAPI_Sample1View.h : CLXDeviceAPI_Sample1View Ŭ������ �������̽�
//

#pragma once

#if (My32bit == 1) // DLL implicit linking for 32bit 

#pragma comment(lib,"LIB_32bit\\LXDeviceAPI.lib") 
#pragma comment(lib,"LIB_32bit\\AcqPlot.lib")


#elif (My64bit == 1) // DLL implicit linking for 64bit 

#pragma comment(lib,"LIB_64bit\\LXDeviceAPI.lib") 
#pragma comment(lib,"LIB_64bit\\AcqPlot.lib")

#endif


#include "LXDeviceAPI.h" // for using LXDeviceAPI
#include "AcqPlotDll.h"  // for charting the wave. 

class CLXDeviceAPI_Sample1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CLXDeviceAPI_Sample1View();
	DECLARE_DYNCREATE(CLXDeviceAPI_Sample1View)

// Ư���Դϴ�.
public:
	CLXDeviceAPI_Sample1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CLXDeviceAPI_Sample1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuOpenapi();
	afx_msg void OnMenuOpendevice();
	afx_msg void OnMenuClosedevice();
	afx_msg void OnMenuCloseapi();
	afx_msg void OnMenuOneclickstart();
	afx_msg void OnMenuOneclickstop();
	afx_msg void OnConfigureDisplaymaxamplitude();
// 
public:
	
	ST_STREAMDATA_LXDAPI stStreamData; // To get stream data from LXDeviceAPI.

	int m_iDeviceHandlingID = 0;
	unsigned int NumSampleReturn = 32;
	unsigned int NumChannel_Wave = 67; // 67 wave channel is for QEEG-64FX(64ch)
	unsigned int LXDeviceID = 0; 
	float Display_MaxAmplitude;
	int State_OpenDevice = 0; // 

	float testfloat_Wave[4096]; // Notice! array for plotting.array size should be larger than NumSampleReturn * (NumChannel_Wave+1). if 4096, the maximum is 64 channel 64samples, 

	afx_msg void OnMenuSetmessagedevice();
	afx_msg void OnMenuStartstream();
	afx_msg void OnMenuStopstream();
protected:
	afx_msg LRESULT OnStreamData(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnSetsamplefrequency250hz();
	afx_msg void OnSetsamplefrequency500hz();
	afx_msg void OnSetsamplefrequency1000hz();
	afx_msg void OnSetsamplefrequency2000hz();
	afx_msg void OnMenuGetsamplefrequency();
	afx_msg void OnMenuGetfilterfrequency();
	afx_msg void OnMenuGeteegrefelectrode();
	afx_msg void OnMenuSetdevicecontrolpanel();
	afx_msg void OnMenuEventmarkingonstream();
	afx_msg void OnSelectdeviceQeeg64fx8ch();
	afx_msg void OnSelectdeviceQeeg64fx16ch();
	afx_msg void OnSelectdeviceQeeg64fx24ch();
	afx_msg void OnSelectdeviceQeeg64fx32ch();
	afx_msg void OnSelectdeviceQeeg64fx40ch();
	afx_msg void OnSelectdeviceQeeg64fx48ch();
	afx_msg void OnSelectdeviceQeeg64fx56ch();
	afx_msg void OnSelectdeviceQeeg64fx64ch();
	afx_msg void OnSelectdeviceQeeg32fx();
	void SelectDevice(unsigned int num_channel_wave, unsigned int lx_device_id, CString cst_product_name);
	virtual void OnInitialUpdate();
	afx_msg void OnMenuCheckforupdate();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // LXDeviceAPI_Sample1View.cpp�� ����� ����
inline CLXDeviceAPI_Sample1Doc* CLXDeviceAPI_Sample1View::GetDocument() const
   { return reinterpret_cast<CLXDeviceAPI_Sample1Doc*>(m_pDocument); }
#endif

