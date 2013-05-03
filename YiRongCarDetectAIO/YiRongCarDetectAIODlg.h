// YiRongCarDetectAIODlg.h : header file
//

#if !defined(AFX_YIRONGCARDETECTAIODLG_H__A09C780B_7883_4399_B0B2_38E203A2550D__INCLUDED_)
#define AFX_YIRONGCARDETECTAIODLG_H__A09C780B_7883_4399_B0B2_38E203A2550D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DLGshortcut.h"
#include "DLGscreen.h"

#include "DLGdevicetree.h"
#include "DLGnormal.h"
#include "DLGptz.h"

////////////////lynn/////////////////
#include "IO.h"
////////////////lynn/////////////////

/////////////////////////////////////////////////////////////////////////////
// CYiRongCarDetectAIODlg dialog

class CYiRongCarDetectAIODlg : public CDialog
{
// Construction
public:
	CYiRongCarDetectAIODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CYiRongCarDetectAIODlg)
	enum { IDD = IDD_YIRONGCARDETECTAIO_DIALOG };
	CBitmapButton	m_b_tree;
	CBitmapButton	m_b_ptz;
	CBitmapButton	m_b_normal;
	CListCtrl	m_ListCar;

	//}}AFX_DATA

	//��ݰ�ť
	CDLGshortcut DlgShortCut;
	//��������Ļ
	CDLGscreen DlgScreen;
	//�豸��
	CDLGdevicetree	DlgDeviceTree;
	//����
	CDLGnormal	DlgNormal;
	//��̨
	CDLGptz		DlgPtz;

	CRect printf_Rect;	//ȫ��

	int	m_ListCarTotal;		//ʵʱ�б����������
	CRect		m_clientRect;		//�����������λ��
	//�л�λ��
	void UpdatePannelPosition();
	


	//�л���
	void TabMainInit(void);


	//���β���
	void OnOK();
	void OnCancel();
	void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);

	void ListMainInit(void);

	//��ʾ������Ϣ
	//windowflag =1 ��������
	//windowflag =0 ��ӡ��Ϣ
	void ShowRuntimeMessage(char *msgStr,int windowflag);
	void NewLogMessage(char *msgStr);
	//�������Ϣ��ʾ
	void ShowCameraMessage(char *camName,char *msgStr,int windowflag);

	afx_msg void OnMenuitemHistoryVideo();
	afx_msg void OnMenuitemHistoryCar();
	afx_msg void OnMenuitemHistoryAlarm();
	afx_msg void OnMenuitemSetBlack();

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYiRongCarDetectAIODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CYiRongCarDetectAIODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuitemLoginExit();
	afx_msg void OnMenuitemLoginIn();
	afx_msg void OnMenuitemLoginLock();
	afx_msg void OnMenuitemCapbmp();
	afx_msg void OnMenuitem1mode();
	afx_msg void OnUpdateMenuitem1mode(CCmdUI* pCmdUI);
	afx_msg void OnMenuitem4mode();
	afx_msg void OnUpdateMenuitem4mode(CCmdUI* pCmdUI);
	afx_msg void OnMenuitem9mode();
	afx_msg void OnUpdateMenuitem9mode(CCmdUI* pCmdUI);
	afx_msg void OnMenuitem16mode();
	afx_msg void OnUpdateMenuitem16mode(CCmdUI* pCmdUI);
	afx_msg void OnMenuitemPreview();
	afx_msg void OnMenuitemDetect();
	afx_msg void OnMenuitemAlarm();
	afx_msg void OnMenuitemRecord();
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuitemHelp();
	afx_msg void OnMenuitemSystemReport();
	afx_msg void OnMenuitemBlackIn();
	afx_msg void OnMenuitemBlackOut();
	afx_msg void OnMenuitemSetUser();
	afx_msg void OnMenuitemSetSystem();
	afx_msg void OnMenuitemSetSystemIn();
	afx_msg void OnMenuitemSetSystemOut();
	afx_msg void OnMenuitemSetRecord();
	afx_msg void OnMenuitemSetCar();
	afx_msg void OnMenuitemSetPtz();
	afx_msg void OnMenuitemCarstream();
	afx_msg void OnMenuitemLoginModify();
	afx_msg void OnLvnItemActivateList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonTree();
	afx_msg void OnButtonNormal();
	afx_msg void OnButtonPtz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YIRONGCARDETECTAIODLG_H__A09C780B_7883_4399_B0B2_38E203A2550D__INCLUDED_)