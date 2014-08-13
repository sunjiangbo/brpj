
#ifndef _STREAM_CLIENT_SDK_
#define _STREAM_CLIENT_SDK_

#if OPEN_STREAM_CLIENT_SDK

class CStreamClientSDK
{
public:
	CStreamClientSDK();
	virtual ~CStreamClientSDK();


	long m_RealHandle[MAX_DEVICE_NUM];
	//long m_LoginHandle[MAX_DEVICE_NUM];
	long m_ptzRealHandle;
	//long m_ptzLoginHandle;
	long m_lPort[MAX_DEVICE_NUM];
	BOOL m_bPTZCtrl;

	CString CapturePath[MAX_DEVICE_NUM];

	void SDKInit();
	bool StartPlay(int screenNo,char *name,char *sip,
							char *user,char *psw,HWND hWnd,int subtype,
							char *Rtspurl,int RTP,int DecodeTag);
	void StopPlay(int screenNo);
	void Capture(int screenNo,char *filename);
	void PtzControl(LONG lRealHandle, int type, BOOL dwStop, int param);
	bool PtzStartPlay(char *sip,int nPort,int channel,char *user,char *psw,HWND hWnd);
	void PtzStopPlay();
	//通过port获取到窗口号
	int GetPortWndindex(long lport);
	int GetHandleWindID(long RealHandle);

	int StartRecord(int screenNo,char *filename);
	int StopRecord(int screenNo);

};

#endif

#endif