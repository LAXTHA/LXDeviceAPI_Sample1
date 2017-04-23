#ifndef _LXDeviceAPI_H
#define _LXDeviceAPI_H

// Predefined Message Type ID for SetMessageDevice
#define MSGTYPEID0_DEVICE_LXDAPI 0
#define MSGTYPEID1_DEVICE_LXDAPI 1
#define MSGTYPEID2_DEVICE_LXDAPI 2
#define MSGTYPEID3_DEVICE_LXDAPI 3
#define MSGTYPEID4_DEVICE_LXDAPI 4
#define MSGTYPEID5_DEVICE_LXDAPI 5
#define MSGTYPEID6_DEVICE_LXDAPI 6
#define MSGTYPEID7_DEVICE_LXDAPI 7
#define MSGTYPEID8_DEVICE_LXDAPI 8
#define MSGTYPEID9_DEVICE_LXDAPI 9

// Predefined Message Type ID for SetMessageAPI
#define MSGTYPEID0_API_LXDAPI 10
#define MSGTYPEID1_API_LXDAPI 11
#define MSGTYPEID2_API_LXDAPI 12
#define MSGTYPEID3_API_LXDAPI 13
#define MSGTYPEID4_API_LXDAPI 14
#define MSGTYPEID5_API_LXDAPI 15
#define MSGTYPEID6_API_LXDAPI 16
#define MSGTYPEID7_API_LXDAPI 17
#define MSGTYPEID8_API_LXDAPI 18
#define MSGTYPEID9_API_LXDAPI 19

// struct for data abstracted
typedef struct _LXDataAbs_LXDAPI	// 
{
	unsigned int	NumAui;			// Aui[]�� �迭ũ��.
	unsigned int	NumAd;			// Ad[]�� �迭ũ��.
	unsigned int	NumX;
	unsigned int	NumY;
	unsigned int	NumZ;
	unsigned int*	Aui;			// Aui[NumAui]				
	unsigned int*	Aui_X;
	unsigned int*	Aui_Y;
	unsigned int*	Aui_XY;
	unsigned int*	Aui_XYZ;
	double*			Ad;				// Ad[NumAd]
	double*			Ad_X;
	double*			Ad_Y;
	double*			Ad_XY;
	double*			Ad_XYZ;
}ST_ABS_LXDAPI,*LPST_ABS_LXDAPI;

// struct for stream.
typedef struct _stStreamData_LXDAPI
{
	unsigned int	LXDeviceID;			// ��ġ���̵�(��ġ�𵨰� 1:1����). �� ��Ʈ�� �����Ͱ� � ��ġ���� �߻��� ������ ǥ��.
	unsigned int	DeviceHandlingID;	// ��ġ�� ���������� �ĺ��ϴ� �������̵�. (LXDeviceID�� ������ ��ġ 2�� �̻�� ��Ž� ��ġ���� �ĺ������� ���̵�.)
	unsigned int	StreamID;			// �� ��Ʈ�������� ���̵�.(����ü ���� 1���� StreamDataID  1�� ����)
	unsigned int	StreamType;			// 
	unsigned int	NumSampleReturn;	// ��Ʈ������ ���۵Ǵ� �� ä�δ� ���ø�����. 
	unsigned int	MaxSampleBuffer;	// ��Ʈ�� ������ ���۰� ���尡���� �ִ� ���ü���.
	unsigned int	NumSampleBuffer;	// ���ۿ� �����ִ� ���ø�����. - ���� ��Ʈ�� ���۽����� ���ۿ� �����ִ� ���ø� ������.
	double			mTimeInterSample;	// ���û����� �ð���. ����:�и���.
	unsigned int	Wave_NumChannel;	// ��Ʈ������ ���۵Ǵ� ����ä���� ����.
	unsigned int	Event_NumChannel;	// ��Ʈ������ ���۵Ǵ� �̺�Ʈä���� ����..
	unsigned int*	Wave_Source_C;		// wave �� ä�κ� ���۵Ǵ� ���� �ǹ�. eeg, ppg �� ��������� �������� ǥ��.
	unsigned int*	Wave_Polarity_C;	// wave �� ä���� �ؼ�Ư��.2 ��ؼ�,  1 �ܱؼ�.
	unsigned int*	Event_Source_C;		// event �� ä�κ��� ���۵Ǵ� �̺�Ʈ �ҽ� : Ű����, �ۿ����Լ�ȣ�⿡ ���Ѱ�, ��ġ���� �ϵ���������� ���۵Ȱ�. ���� 3��.
	unsigned int*	Wave_Dimension_C;	// wave �� ä�η� ���۵Ǵ� ���� ����. �迭 ������ ���� �����ȴ�. ����-���� ����ǥ ���� �ľ��Ұ�. V,A,SEC ���� ����.
	unsigned int*	Event_StreamData_CS;// event ��Ʈ�� �����͸� ���� 1���� �迭. �迭ũ�� = Stream_NumSamples*Num_ChannelMark
	int*			Wave_DimScale_C;	// ���� ���� �¼�. M, G��.
	double*			Wave_MaxAmplitude_C;// wave �� ä�δ� ���۵Ǵ� ���� ������ �ִ� �ִ� ����. �迭������� ���� �����ȴ�. MaxAmplitudeWave[Num_ChannelWave]
	double*			Wave_StreamData_CS;	// wave ��Ʈ�������͸� ���� 1���� �迭. �迭������� Stream_NumSamples �� ���ӵǾ� �������� ����(�迭ũ�� = Stream_NumSamples*Num_ChannelWave)�Ǿ�� �ϸ�, �����޸� �Ҵ��� API���ο��� �̷�����. ä���ε��� i, �����ε��� j �� �����ϴ¹� Sream[j+i*Stream_NumSample]

	LPST_ABS_LXDAPI	pst_Abs;			// abstracted.- don't care.

}ST_STREAMDATA_LXDAPI;


/// LXDeviceAPI.DLL Exported Functions. 

extern "C" __declspec(dllimport) int OpenApi_LXDeviceAPI(int api_window, int api_selfupdate, int mode);
extern "C" __declspec(dllimport) int SetMessageAPI_LXDeviceAPI(int msgtype_id, HWND hwnd_msgrcv, int msg_id, int onoff);
extern "C" __declspec(dllimport) int OpenDevice_LXDeviceAPI(int LXDeviceID, ST_STREAMDATA_LXDAPI* pst_streamdata, int numsample_return, int mode);
extern "C" __declspec(dllimport) int SetMessageDevice_LXDeviceAPI(int device_handling_id, int msgtype_id, HWND hwnd_msgrcv, int msg_id, int onoff);
extern "C" __declspec(dllimport) int StartStream_LXDeviceAPI(int device_handling_id);
extern "C" __declspec(dllimport) int StopStream_LXDeviceAPI(int device_handling_id);
extern "C" __declspec(dllimport) int CloseDevice_LXDeviceAPI(int device_handling_id);
extern "C" __declspec(dllimport) int CloseApi_LXDeviceAPI(void);
extern "C" __declspec(dllimport) int GetStreamData_LXDeviceAPI(unsigned int message_wparam);
extern "C" __declspec(dllimport) int SetSampleFrequency_LXDeviceAPI(int device_handling_id, int sample_frequency);
extern "C" __declspec(dllimport) int GetSampleFrequency_LXDeviceAPI(int device_handling_id, int * sample_frequency);
extern "C" __declspec(dllimport) int GetFilterFrequency_LXDeviceAPI(int device_handling_id, int signal_source, float * freq_hpf, float * freq_lpf, float * freq_notch);
extern "C" __declspec(dllimport) int GetEEGRefElectrode_LXDeviceAPI(int device_handling_id, int * eeg_refelectrode);
extern "C" __declspec(dllimport) int SetDeviceControlPanel_LXDeviceAPI(int device_handling_id, int para0, int para1);
extern "C" __declspec(dllimport) int EventMarkingOnStream_LXDeviceAPI(int device_handling_id, unsigned int event_id); // from version 1.0.2.0
extern "C" __declspec(dllimport) int CheckForUpdate_LXDeviceAPI(int closeifnoupdate); // from version 1.0.3.0

#endif //#ifndef _LXDeviceAPI_H

