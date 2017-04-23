
// LXDeviceAPI_Sample1View.cpp : CLXDeviceAPI_Sample1View 클래스의 구현
//


#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "LXDeviceAPI_Sample1.h"
#endif

#include "LXDeviceAPI_Sample1Doc.h"
#include "LXDeviceAPI_Sample1View.h"

#include "Mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include "DlgConfigure.h"


#define WM_STREAM_DEVICE WM_USER+203  // Define Message to get message from LXDeviceAPI.

// CLXDeviceAPI_Sample1View

IMPLEMENT_DYNCREATE(CLXDeviceAPI_Sample1View, CView)

BEGIN_MESSAGE_MAP(CLXDeviceAPI_Sample1View, CView)
	ON_COMMAND(ID_MENU_OPENAPI, &CLXDeviceAPI_Sample1View::OnMenuOpenapi)
	ON_COMMAND(ID_MENU_OPENDEVICE, &CLXDeviceAPI_Sample1View::OnMenuOpendevice)
	ON_COMMAND(ID_MENU_CLOSEDEVICE, &CLXDeviceAPI_Sample1View::OnMenuClosedevice)
	ON_COMMAND(ID_MENU_CLOSEAPI, &CLXDeviceAPI_Sample1View::OnMenuCloseapi)
	ON_COMMAND(ID_MENU_ONECLICKSTART, &CLXDeviceAPI_Sample1View::OnMenuOneclickstart)
	ON_COMMAND(ID_MENU_ONECLICKSTOP, &CLXDeviceAPI_Sample1View::OnMenuOneclickstop)
	ON_COMMAND(ID_CONFIGURE_DISPLAYMAXAMPLITUDE, &CLXDeviceAPI_Sample1View::OnConfigureDisplaymaxamplitude)
	ON_COMMAND(ID_MENU_SETMESSAGEDEVICE, &CLXDeviceAPI_Sample1View::OnMenuSetmessagedevice)
	ON_COMMAND(ID_MENU_STARTSTREAM, &CLXDeviceAPI_Sample1View::OnMenuStartstream)
	ON_COMMAND(ID_MENU_STOPSTREAM, &CLXDeviceAPI_Sample1View::OnMenuStopstream)
	ON_MESSAGE(WM_STREAM_DEVICE, &CLXDeviceAPI_Sample1View::OnStreamData)
	ON_COMMAND(ID_SETSAMPLEFREQUENCY_250HZ, &CLXDeviceAPI_Sample1View::OnSetsamplefrequency250hz)
	ON_COMMAND(ID_SETSAMPLEFREQUENCY_500HZ, &CLXDeviceAPI_Sample1View::OnSetsamplefrequency500hz)
	ON_COMMAND(ID_SETSAMPLEFREQUENCY_1000HZ, &CLXDeviceAPI_Sample1View::OnSetsamplefrequency1000hz)
	ON_COMMAND(ID_SETSAMPLEFREQUENCY_2000HZ, &CLXDeviceAPI_Sample1View::OnSetsamplefrequency2000hz)
	ON_COMMAND(ID_MENU_GETSAMPLEFREQUENCY, &CLXDeviceAPI_Sample1View::OnMenuGetsamplefrequency)
	ON_COMMAND(ID_MENU_GETFILTERFREQUENCY, &CLXDeviceAPI_Sample1View::OnMenuGetfilterfrequency)
	ON_COMMAND(ID_MENU_GETEEGREFELECTRODE, &CLXDeviceAPI_Sample1View::OnMenuGeteegrefelectrode)
	ON_COMMAND(ID_MENU_SETDEVICECONTROLPANEL, &CLXDeviceAPI_Sample1View::OnMenuSetdevicecontrolpanel)
	ON_COMMAND(ID_MENU_EVENTMARKINGONSTREAM, &CLXDeviceAPI_Sample1View::OnMenuEventmarkingonstream)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX8CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx8ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX16CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx16ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX24CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx24ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX32CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx32ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX40CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx40ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX48CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx48ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX56CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx56ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG64FX64CH, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx64ch)
	ON_COMMAND(ID_SELECTDEVICE_QEEG32FX, &CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg32fx)
	ON_COMMAND(ID_MENU_CHECKFORUPDATE, &CLXDeviceAPI_Sample1View::OnMenuCheckforupdate)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CLXDeviceAPI_Sample1View 생성/소멸

CLXDeviceAPI_Sample1View::CLXDeviceAPI_Sample1View()
	: NumSampleReturn(32)
	, NumChannel_Wave(67) // QEEG-64FX(64ch) : Number of Wave Channel 67 ( EEG 64ch + EOG 2ch + ECG 1ch)
	, Display_MaxAmplitude(800.f)
{
	

}

CLXDeviceAPI_Sample1View::~CLXDeviceAPI_Sample1View()
{
}

BOOL CLXDeviceAPI_Sample1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	
	return CView::PreCreateWindow(cs);
}


void CLXDeviceAPI_Sample1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	OnSelectdeviceQeeg64fx64ch(); // at first Let's select QEEG-64FX(64ch)

}


// CLXDeviceAPI_Sample1View 그리기

void CLXDeviceAPI_Sample1View::OnDraw(CDC* pDC)
{
	CLXDeviceAPI_Sample1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CRect client_Rect;
	GetClientRect(client_Rect);
	ACQPLOT_DLL_Window_Size_Changed_Or_Data_Set_Changed(
		this->m_hWnd,
		client_Rect,
		NumSampleReturn,		// plotting bitmap unit width 
		NumChannel_Wave+1,				// number of channel to display . +1 for Event Marking 
		NumSampleReturn,		//  number of samples per channel
		Display_MaxAmplitude,	//	Maximun Amplitude - y axis maximum amplitude. 
		FALSE, FALSE, FALSE, 4,	// dont' care
		4.0f, 					//  don't care. unit interval time. not exact.
		1						// plotting mode select. 
		);

	ACQPLOT_DLL_Array_Draw_Box_Axis(pDC, TRUE, TRUE, TRUE);

	///start. y-axis channel number. 챠트의 Y축에 채널번호 표현. 
	CString y_text[128]; 
	for (int idx_ch = 0; idx_ch < NumChannel_Wave; idx_ch++) //
	{
		y_text[idx_ch].Format(_T("ch%d"),idx_ch+1); 
	}
	y_text[NumChannel_Wave] = _T("Event"); // for Event Marking expression.

	ACQPLOT_DLL_Draw_Axis_Y_Text(pDC, y_text, _T("system"));

	///end. y-axis channel number. 챠트의 Y축에 채널번호 표현. 

}


// CLXDeviceAPI_Sample1View 진단

#ifdef _DEBUG
void CLXDeviceAPI_Sample1View::AssertValid() const
{
	CView::AssertValid();
}

void CLXDeviceAPI_Sample1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLXDeviceAPI_Sample1Doc* CLXDeviceAPI_Sample1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLXDeviceAPI_Sample1Doc)));
	return (CLXDeviceAPI_Sample1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLXDeviceAPI_Sample1View 메시지 처리기




/*
Select Device

Device : LXDeviceID
QEEG-64FX(8ch) : 16408
QEEG-64FX(16ch) : 16416
QEEG-64FX(24ch) : 16424
QEEG-64FX(32ch) : 16432
QEEG-64FX(40ch) : 16440
QEEG-64FX(48ch) : 16448
QEEG-64FX(56ch) : 16456
QEEG-64FX(64ch) : 16464

QEEG-32FX : 300

*/

void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx8ch()
{
	SelectDevice(11, 16408, _T("QEEG64FX(8ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx16ch()
{
	SelectDevice(19, 16416, _T("QEEG64FX(16ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx24ch()
{
	SelectDevice(27, 16424, _T("QEEG64FX(24ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx32ch()
{
	SelectDevice(35, 16432, _T("QEEG64FX(32ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx40ch()
{
	SelectDevice(43, 16440, _T("QEEG64FX(40ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx48ch()
{
	SelectDevice(51, 16448, _T("QEEG64FX(48ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx56ch()
{
	SelectDevice(59, 16456, _T("QEEG64FX(56ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg64fx64ch()
{
	SelectDevice(67, 16464, _T("QEEG64FX(64ch)"));
}


void CLXDeviceAPI_Sample1View::OnSelectdeviceQeeg32fx()
{
	SelectDevice(35, 300, _T("QEEG32FX"));
}

void CLXDeviceAPI_Sample1View::SelectDevice(unsigned int num_channel_wave, unsigned int lx_device_id, CString cst_product_name)
{
	if (State_OpenDevice == 1) {
		AfxMessageBox(_T("Not available when OpenDevice. Try again after CloseDevice"));
		return;
	}

	NumChannel_Wave = num_channel_wave;
	LXDeviceID = lx_device_id;

	// Redraw
	OnUpdate(NULL, 0, 0);

	// Changing Program title. 
	AfxGetMainWnd()->SetWindowTextW(_T("LXDeviceAPI_Sample1 : ") + cst_product_name);
}


void CLXDeviceAPI_Sample1View::OnMenuOpenapi()
{
	OpenApi_LXDeviceAPI(1,0,0); // 2nd parameter 0 : don't chaek for api update when openapi.

//	OpenApi_LXDeviceAPI(1, 1, 0); // 2nd parameter 1 : chaek for api update when openapi. 
}


void CLXDeviceAPI_Sample1View::OnMenuOpendevice()
{

	int retv = OpenDevice_LXDeviceAPI(LXDeviceID, &stStreamData, NumSampleReturn, 0);

	if(retv > 0) // if success
	{
		m_iDeviceHandlingID = retv; 

		State_OpenDevice = 1; // set the state as Device Opened.
	}
	else
	{
//		AfxMessageBox(_T("Fail to OpenDevice"));
	}
}

void CLXDeviceAPI_Sample1View::OnMenuSetmessagedevice()
{
	SetMessageDevice_LXDeviceAPI(m_iDeviceHandlingID, MSGTYPEID0_DEVICE_LXDAPI ,this->m_hWnd, WM_STREAM_DEVICE,1); //
}



void CLXDeviceAPI_Sample1View::OnMenuStartstream()
{

	StartStream_LXDeviceAPI(m_iDeviceHandlingID);
}


void CLXDeviceAPI_Sample1View::OnMenuStopstream()
{
	StopStream_LXDeviceAPI(m_iDeviceHandlingID);
}


void CLXDeviceAPI_Sample1View::OnMenuClosedevice()
{
	CloseDevice_LXDeviceAPI(m_iDeviceHandlingID);

	State_OpenDevice = 0; // set the state as Device Not Opened.
	
}


void CLXDeviceAPI_Sample1View::OnMenuCloseapi()
{
	CloseApi_LXDeviceAPI();
}


/*
OpenAPI-> OpenDevice ->SetMessageDevice -> StartStream 
*/
void CLXDeviceAPI_Sample1View::OnMenuOneclickstart()
{
	int retv_openapi, retv_opendevice; 

	retv_openapi = OpenApi_LXDeviceAPI(1, 0, 0); // API Open.

	if (retv_openapi > 0)
	{
		retv_opendevice = OpenDevice_LXDeviceAPI(LXDeviceID, &stStreamData, NumSampleReturn, 0); // 
		if (retv_opendevice > 0)
		{
			State_OpenDevice = 1;

			m_iDeviceHandlingID = retv_opendevice; 
			SetMessageDevice_LXDeviceAPI(m_iDeviceHandlingID, MSGTYPEID0_DEVICE_LXDAPI, this->m_hWnd, WM_STREAM_DEVICE, 1);

			StartStream_LXDeviceAPI(m_iDeviceHandlingID);
		}
	}
}

/*
StopStream -> CloseDevice -> CloseAPI 
*/
void CLXDeviceAPI_Sample1View::OnMenuOneclickstop()
{
	if (m_iDeviceHandlingID > 0)
	{
		StopStream_LXDeviceAPI(m_iDeviceHandlingID);

		CloseDevice_LXDeviceAPI(m_iDeviceHandlingID);

		State_OpenDevice = 0;

		m_iDeviceHandlingID = 0;
	}
	CloseApi_LXDeviceAPI();
}


/*
 Set max amplitude for charitng the wave  
*/
void CLXDeviceAPI_Sample1View::OnConfigureDisplaymaxamplitude()
{
	CDlgConfigure dlg;

	dlg.m_MaxAmplitude = this->Display_MaxAmplitude; // 현재 설정된 값을 대화상자의 변수로 전달. 

	if(dlg.DoModal() == IDOK) // 설정대화상자 domodal 로 생성하고 대화상자의 OK버튼 클릭한 경우.
	{
		this->Display_MaxAmplitude = dlg.m_MaxAmplitude;// 대화상자의 edit 박스에 기록한 사용자 입력 값 받기.

		OnUpdate(NULL,0,0);// redraw 
	}
}


/*
 Set Sampling frequency as 250Hz
*/
void CLXDeviceAPI_Sample1View::OnSetsamplefrequency250hz()
{
	SetSampleFrequency_LXDeviceAPI(m_iDeviceHandlingID, 250);
}

/*
Set Sampling frequency as 500Hz
*/

void CLXDeviceAPI_Sample1View::OnSetsamplefrequency500hz()
{
	SetSampleFrequency_LXDeviceAPI(m_iDeviceHandlingID, 500);
}


/*
Set Sampling frequency as 1000Hz
*/
void CLXDeviceAPI_Sample1View::OnSetsamplefrequency1000hz()
{
	SetSampleFrequency_LXDeviceAPI(m_iDeviceHandlingID, 1000);
}

/*
Set Sampling frequency as 2000Hz
*/
void CLXDeviceAPI_Sample1View::OnSetsamplefrequency2000hz()
{
	SetSampleFrequency_LXDeviceAPI(m_iDeviceHandlingID, 2000);
}

void CLXDeviceAPI_Sample1View::OnMenuGetsamplefrequency()
{
	int sample_frequency; 
	CString cst; 

	if (GetSampleFrequency_LXDeviceAPI(m_iDeviceHandlingID, &sample_frequency) == 1)
	{
		cst.Format(_T("Sampling Frequency = %d Hz"), sample_frequency);

		AfxMessageBox(cst);
	}
}

void CLXDeviceAPI_Sample1View::OnMenuGetfilterfrequency()
{
	float f_hpf, f_lpf, f_notch;
	CString cst_hpf, cst_lpf, cst_notch;

	// Get EEG Filter info 
	if (GetFilterFrequency_LXDeviceAPI(m_iDeviceHandlingID,0, &f_hpf, &f_lpf, &f_notch) == 1) 
	{
		if (f_hpf < -1.f) 	cst_hpf = _T("HPF=off, ");
		else				cst_hpf.Format(_T("HPF=%.1fHz, "), f_hpf); 

		if (f_lpf < -1.f)	cst_lpf = _T("LPF=off, ");
		else				cst_lpf.Format(_T("LPF=%.1fHz, "), f_lpf);

		if (f_notch < -1.f)	cst_notch = _T("Notch=off");
		else				cst_notch.Format(_T("Notch=%.1fHz"), f_notch);

		AfxMessageBox(_T("EEG Filter : ") + cst_hpf + cst_lpf + cst_notch);
	}

	// Get EOG Filter info 
	if (GetFilterFrequency_LXDeviceAPI(m_iDeviceHandlingID, 1, &f_hpf, &f_lpf, &f_notch) == 1)
	{
		if (f_hpf < -1.f)
			cst_hpf = _T("HPF=off, ");
		else
			cst_hpf.Format(_T("HPF=%.1fHz, "), f_hpf);

		if (f_lpf < -1.f)
			cst_lpf = _T("LPF=off, ");
		else
			cst_lpf.Format(_T("LPF=%.1fHz, "), f_lpf);

		if (f_notch < -1.f)
			cst_notch = _T("Notch=off");
		else
			cst_notch.Format(_T("Notch=%.1fHz"), f_notch);

		AfxMessageBox(_T("EOG Filter : ") + cst_hpf + cst_lpf + cst_notch);
	}

	// Get ECG Filter info 
	if (GetFilterFrequency_LXDeviceAPI(m_iDeviceHandlingID, 2, &f_hpf, &f_lpf, &f_notch) == 1)
	{
		if (f_hpf < -1.f)
			cst_hpf = _T("HPF=off, ");
		else
			cst_hpf.Format(_T("HPF=%.1fHz, "), f_hpf);

		if (f_lpf < -1.f)
			cst_lpf = _T("LPF=off, ");
		else
			cst_lpf.Format(_T("LPF=%.1fHz, "), f_lpf);

		if (f_notch < -1.f)
			cst_notch = _T("Notch=off");
		else
			cst_notch.Format(_T("Notch=%.1fHz"), f_notch);

		AfxMessageBox(_T("ECG Filter : ") + cst_hpf + cst_lpf + cst_notch);
	}

}

void CLXDeviceAPI_Sample1View::OnMenuGeteegrefelectrode()
{
	int eeg_refelectrode; 
	CString cst_eegref; 

	if (GetEEGRefElectrode_LXDeviceAPI(m_iDeviceHandlingID,&eeg_refelectrode) == 1)
	{
		if (eeg_refelectrode == 0)
			cst_eegref = _T("A1");
		else if(eeg_refelectrode == 1)
			cst_eegref = _T("A2");
		else if (eeg_refelectrode == 2)
			cst_eegref = _T("A1+A2");
		else if (eeg_refelectrode == 3)
			cst_eegref = _T("Cz(ch18)");

		AfxMessageBox(_T("EEG Reference Electode = ") + cst_eegref); 
	}
}

void CLXDeviceAPI_Sample1View::OnMenuSetdevicecontrolpanel()
{
	static int para1=0; 
	SetDeviceControlPanel_LXDeviceAPI(m_iDeviceHandlingID, 0, para1);
	// toggling para1.
	if (para1) para1 = 0; 
	else para1 = 1; 
}

void CLXDeviceAPI_Sample1View::OnMenuCheckforupdate()
{
	CheckForUpdate_LXDeviceAPI(0); // parameter 0 : No Auto Close 
	//CheckForUpdate_LXDeviceAPI(1); // parameter 1 : Auto close check program if there is no update.
}


/*
Event Marking on Streaming 
*/

// when menu clicked, let's set the event_id as 20000 
void CLXDeviceAPI_Sample1View::OnMenuEventmarkingonstream()
{
	EventMarkingOnStream_LXDeviceAPI(m_iDeviceHandlingID, 20000); 
}

// when keyboard pressed. let's set the event_id as arrow ky down. up 30000, down 40000,left 50000, right 60000

void CLXDeviceAPI_Sample1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	switch (nChar)
	{
	case VK_UP:

		EventMarkingOnStream_LXDeviceAPI(m_iDeviceHandlingID, 30000);

		break;

	case VK_DOWN:

		EventMarkingOnStream_LXDeviceAPI(m_iDeviceHandlingID, 40000);

		break;

	case VK_LEFT:

		EventMarkingOnStream_LXDeviceAPI(m_iDeviceHandlingID, 50000);

		break;

	case VK_RIGHT:

		EventMarkingOnStream_LXDeviceAPI(m_iDeviceHandlingID, 60000);

		break;



	}

	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}





/*
Real Time Acquisition and Charting Example
*/

afx_msg LRESULT CLXDeviceAPI_Sample1View::OnStreamData(WPARAM wParam, LPARAM lParam)
{
	unsigned int uintWPARAM = (unsigned int)wParam;

	unsigned char msgtype_id = (unsigned char)(uintWPARAM >> 8); //get the lowest 2'nd byte(message type id).

	unsigned char msgtype_subid = (unsigned char)(uintWPARAM); //get the lowest 1st byte(message type sub id).

	switch (msgtype_id)
	{
	case MSGTYPEID0_DEVICE_LXDAPI: // for real time stream type messages. 

		switch (msgtype_subid)
		{
		case 0:

			GetStreamData_LXDeviceAPI(uintWPARAM); //  the new stream data is allocated on stStreamData which is ST_STREAMDATA_LXDAPI type variable.		

			/// Data arrange for Wave Stream Data for plotting. 
			for (int i = 0; i < NumSampleReturn * NumChannel_Wave; i++)
			{
				testfloat_Wave[i] = (float)stStreamData.Wave_StreamData_CS[i];
			}

			/// Data arrange for Event Marking for plotting.
			for (int idx_event = 0; idx_event < NumSampleReturn; idx_event++)
				testfloat_Wave[NumSampleReturn * NumChannel_Wave + idx_event] = (float)stStreamData.Event_StreamData_CS[idx_event];

			// Test plotting the wave and event marking. 
			ACQPLOT_DLL_Array_Datain_Strip(testfloat_Wave, NumChannel_Wave + 1, NumSampleReturn); // parameter 1 : wave data float type array. parameter 2 : total number of wave channel  + 1 for Event Marking. parameter 3 : Number of Samples per one channel.


			break;

		} // switch (msgtype_subid)

		break;  // case MSGTYPEID0_DEVICE_LXDAPI: // for real time stream type messages. 
	}// switch (msgtype_id)


	return 0;
}





