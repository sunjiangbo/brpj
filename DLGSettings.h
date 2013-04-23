#if !defined(AFX_DLGSETTINGS_H__4EE5CA2D_F23A_4BC5_A495_307E2EFCDD0E__INCLUDED_)
#define AFX_DLGSETTINGS_H__4EE5CA2D_F23A_4BC5_A495_307E2EFCDD0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLGSettings.h : header file
//

//视频/图片命名规则定义
#define DATETIME_PRODUCTNAME			0		//日期+产品名称
#define DATETIME_BARCODE				1		//日期+一维码
#define BARCODE_DATETIME				2		//一维码+日期
#define PRODUCTNAME_DATETIME			3		//产品名称+日期
#define DATETIME_PRODUCTNAME_BARCODE	4		//日期+产品名称+一维码
#define BARCODE_DATETIME_PRODUCTNAME	5		//一维码+日期+产品名称

/////////////////////////////////////////////////////////////////////////////
// CDLGSettings dialog

class CDLGSettings : public CDialog
{
// Construction
public:
	CDLGSettings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLGSettings)
	enum { IDD = IDD_SETTINGS };
	CString	m_record;
	CString	m_shotframe;
	int		m_comboRecord;
	int		m_comboShotframe;
	//}}AFX_DATA

	BOOL OnInitDialog();

	TCHAR SystemIniPath[ZOG_MAX_PATH_STR];

	void readini(char *path);
	void writeini(char *path);

	void Read2Dlg();
	void Dlg2Write();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLGSettings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLGSettings)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonRecord();
	afx_msg void OnButtonShotframe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETTINGS_H__4EE5CA2D_F23A_4BC5_A495_307E2EFCDD0E__INCLUDED_)
