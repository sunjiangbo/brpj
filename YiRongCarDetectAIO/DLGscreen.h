#if !defined(AFX_DLGSCREEN_H__08A4A59F_824B_475D_B94C_9FA7A3CFCE9D__INCLUDED_)
#define AFX_DLGSCREEN_H__08A4A59F_824B_475D_B94C_9FA7A3CFCE9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGscreen.h : header file
//
#include "ScreenPannel.h"

#if ALLTAB_DETECT_CAR_MODE
#include "DLGSetCar.h"
#else
#include "DLGSetElecar.h"
#endif

#include "CarDetect.h"

/*
#if (ALLTAB_CAMERA_INC_TYPE == CAMERA_INC_DAHUA)
#include "DahuaSDK.h"
#else if(ALLTAB_CAMERA_INC_TYPE == CAMERA_INC_HAIKANG)
#include "HaiKangSDK.h"
#endif
*/
#include "myCamera.h"

//�豸��Ϣ
struct DEVICE_INFO 
{
	long int camID;
	CString area;				//����
	CString name;				//���������
	CString ip;
	CString user;
	CString psw;
	long port;
	bool isplay;
	int subtype;
	bool enableDetect;
	long playHandle;
	bool enableAlarm;
	int  venderID;				//0---����,1---��
};


/////////////////////////////////////////////////////////////////////////////
// CDLGscreen dialog

class CDLGscreen : public CDialog
{
// Construction
public:
	CDLGscreen(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGscreen)
	enum { IDD = IDD_SCREEN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	BOOL	OnInitDialog();
	void AutoSize();

	//���Ŵ���
	CScreenPannel m_screenPannel;

	struct DEVICE_INFO m_videoInfo[MAX_DEVICE_NUM];
	//����ʶ��
//	struct CarSetStruct CarSet[MAX_DEVICE_NUM];

#if OPEN_CARDETECT_CODE 
	CCarDetect	CarDetect[MAX_DEVICE_NUM];
#endif

/*
#if (ALLTAB_CAMERA_INC_TYPE == CAMERA_INC_DAHUA)
	CDahuaSDK     m_video;
#else if(ALLTAB_CAMERA_INC_TYPE == CAMERA_INC_HAIKANG)
	CHaikangSDK   m_video;
#endif
*/
	CMyCamera   m_video;

	//��ǰ��ʾ�������
	int m_curScreen;

	//����ѡ��Ĵ���
	void SetCurWindId(int nCuWinID);
	//��ȡ��ǰѡ��Ĵ���
	int GetCurWindId(void);
	//���ݲ��ž����ȡ����ID
	int GetHandleWindID(int RealHandle);
	//��ȡ��ǰ���ڵ����������״̬
	bool GetCurWindPlayState(int nCuWinID);
	//��ȡ��ǰ���ڵĲ��ž��
	long GetCurWindPlayHandle(int nCuWinID);
	//��ȡ��ǰ���ڵ����������������
	int GetCurWindSubType(int nCuWinID);
	//��ȡ��ǰѡ�񴰿ڵ��������ϸ��Ϣ
	void GetCurWindCamInfo(int nCuWinID,struct DEVICE_INFO &Info);
	//����/�رճ���ʶ��
	void EnableDetect(int nCuWinID,bool bEnable);
	//����/�رձ���
	void EnableAlarm(int nCuWinID,bool bEnable);
	//��ȡʶ��״̬
	bool GetDetectState(int nCuWinID);
	//��ȡ����״̬
	bool GetAlarmState(int nCuWinID);
	//����ʶ������
	void CarDetectSet(void);

	//ɾ���豸
	void DeleteDevice(CString sip);

	void SwitchMultiWnd(int nSplit);
	bool StartPlay(int id,char *area,char *name,char *ip,int port,
		char *user,char *psw,int subtype,int screenNo,int venderID);
	void StopPlay(int screenNo);
	void Capture(long pHandle,char *filename);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGscreen)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGscreen)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSCREEN_H__08A4A59F_824B_475D_B94C_9FA7A3CFCE9D__INCLUDED_)