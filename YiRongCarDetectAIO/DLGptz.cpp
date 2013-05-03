// DLGptz.cpp : implementation file
//

#include "stdafx.h"
#include "YiRongCarDetectAIO.h"
#include "DLGptz.h"

#include "DLGLogin.h"
extern CDLGLogin DlgLogin;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLGptz dialog


CDLGptz::CDLGptz(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGptz::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGptz)
	m_edit_speed = 0;
	m_edit_set = 0;
	//}}AFX_DATA_INIT
}


void CDLGptz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGptz)

	DDX_Control(pDX, IDC_AUTO, m_auto);
	DDX_Control(pDX, IDC_BUTTON_GO, m_go);
	DDX_Control(pDX, IDC_BUTTON_SET, m_set);
	DDX_Control(pDX, IDC_DOWN, m_down);
	DDX_Control(pDX, IDC_DOWNLEFT, m_downleft);
	DDX_Control(pDX, IDC_DOWNRIGHT, m_downright);
	DDX_Control(pDX, IDC_FOCUS_SUB, m_focussub);
	DDX_Control(pDX, IDC_FOCUS_ADD, m_focusadd);
	DDX_Control(pDX, IDC_IRIS_ADD, m_irisadd);
	DDX_Control(pDX, IDC_IRIS_SUB, m_irissub);
	DDX_Control(pDX, IDC_LEFT, m_left);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_SPEED_ADD, m_speedadd);
	DDX_Control(pDX, IDC_SPEED_SUB, m_speedsub);
	DDX_Control(pDX, IDC_UP, m_up);
	DDX_Control(pDX, IDC_ZOOM_SUB, m_zoomsub);
	DDX_Control(pDX, IDC_ZOOM_ADD, m_zoomadd);
	DDX_Control(pDX, IDC_UPRIGHT, m_upright);
	DDX_Control(pDX, IDC_UPLEFT, m_upleft);

	DDX_Text(pDX, IDC_EDIT_SPEED, m_edit_speed);
	DDX_Text(pDX, IDC_EDIT_SET, m_edit_set);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGptz, CDialog)
	//{{AFX_MSG_MAP(CDLGptz)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_UPLEFT, OnUpleft)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_UPRIGHT, OnUpright)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_AUTO, OnAuto)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_DOWNLEFT, OnDownleft)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_DOWNRIGHT, OnDownright)
	ON_BN_CLICKED(IDC_FOCUS_ADD, OnFocusAdd)
	ON_BN_CLICKED(IDC_IRIS_ADD, OnIrisAdd)
	ON_BN_CLICKED(IDC_ZOOM_ADD, OnZoomAdd)
	ON_BN_CLICKED(IDC_FOCUS_SUB, OnFocusSub)
	ON_BN_CLICKED(IDC_IRIS_SUB, OnIrisSub)
	ON_BN_CLICKED(IDC_ZOOM_SUB, OnZoomSub)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_GO, OnButtonGo)
	ON_BN_CLICKED(IDC_SPEED_SUB, OnSpeedSub)
	ON_BN_CLICKED(IDC_SPEED_ADD, OnSpeedAdd)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGptz message handlers
BOOL CDLGptz::OnInitDialog()
{
	CDialog::OnInitDialog();
	//��ͼƬ
	ButtonBMP();


	//�������
	AutoSize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGptz::AutoSize()
{
	CRect rc(0, 0, 0, 0);
	GetClientRect(&rc);

//	GetParent()->GetClientRect(&rc);
//	((CTabCtrl*)GetParent())->AdjustRect(FALSE, &rc);
//	MoveWindow(rc);

	Invalidate();
}

void CDLGptz::InitPtzCommand()
{
	m_auto.SetButtonCommand(PTZ_CONTROL_AUTO);
	m_up.SetButtonCommand(PTZ_CONTROL_UP);
	m_down.SetButtonCommand(PTZ_CONTROL_DOWN);
	m_left.SetButtonCommand(PTZ_CONTROL_LEFT);
	m_right.SetButtonCommand(PTZ_CONTROL_RIGHT);
	m_upleft.SetButtonCommand(PTZ_CONTROL_UPLEFT);
	m_upright.SetButtonCommand(PTZ_CONTROL_UPRIGHT);
	m_downleft.SetButtonCommand(PTZ_CONTROL_DOWNLEFT);
	m_downright.SetButtonCommand(PTZ_CONTROL_DOWNRIGHT);
}

void CDLGptz::ButtonBMP() 
{

	m_auto.LoadBitmaps(IDB_PTZ_AUTO_OPEN,IDB_PTZ_AUTO_MOVE,NULL,IDB_PTZ_AUTO_CLOSE);
	m_auto.SizeToContent();		//����ӦͼƬ��С

	m_go.LoadBitmaps(IDB_PTZ_GO_OPEN,IDB_PTZ_GO_MOVE,NULL,IDB_PTZ_GO_CLOSE);
	m_go.SizeToContent();		//����ӦͼƬ��С

	m_set.LoadBitmaps(IDB_PTZ_SET_OPEN,IDB_PTZ_SET_MOVE,NULL,IDB_PTZ_SET_CLOSE);
	m_set.SizeToContent();		//����ӦͼƬ��С

	m_down.LoadBitmaps(IDB_PTZ_DOWN_OPEN,IDB_PTZ_DOWN_MOVE,NULL,IDB_PTZ_DOWN_CLOSE);
	m_down.SizeToContent();		//����ӦͼƬ��С

	m_downleft.LoadBitmaps(IDB_PTZ_LEFTDOWN_OPEN,IDB_PTZ_LEFTDOWN_MOVE,NULL,IDB_PTZ_LEFTDOWN_CLOSE);
	m_downleft.SizeToContent();		//����ӦͼƬ��С

	m_downright.LoadBitmaps(IDB_PTZ_RIGHTDOWN_OPEN,IDB_PTZ_RIGHTDOWN_MOVE,NULL,IDB_PTZ_RIGHTDOWN_CLOSE);
	m_downright.SizeToContent();		//����ӦͼƬ��С

	m_focusadd.LoadBitmaps(IDB_PTZ_FOCUSADD_OPEN,IDB_PTZ_FOCUSADD_MOVE,NULL,IDB_PTZ_FOCUSADD_CLOSE);
	m_focusadd.SizeToContent();		//����ӦͼƬ��С
	
	m_focussub.LoadBitmaps(IDB_PTZ_FOCUSSUB_OPEN,IDB_PTZ_FOCUSSUB_MOVE,NULL,IDB_PTZ_FOCUSSUB_CLOSE);
	m_focussub.SizeToContent();		//����ӦͼƬ��С

	m_irisadd.LoadBitmaps(IDB_PTZ_IRISADD_OPEN,IDB_PTZ_IRISADD_MOVE,NULL,IDB_PTZ_IRISADD_CLOSE);
	m_irisadd.SizeToContent();		//����ӦͼƬ��С
	
	m_irissub.LoadBitmaps(IDB_PTZ_IRISSUB_OPEN,IDB_PTZ_IRISSUB_MOVE,NULL,IDB_PTZ_IRISSUB_CLOSE);
	m_irissub.SizeToContent();		//����ӦͼƬ��С

	m_left.LoadBitmaps(IDB_PTZ_LEFT_OPEN,IDB_PTZ_LEFT_MOVE,NULL,IDB_PTZ_LEFT_CLOSE);
	m_left.SizeToContent();		//����ӦͼƬ��С
	
	m_right.LoadBitmaps(IDB_PTZ_RIGHT_OPEN,IDB_PTZ_RIGHT_MOVE,NULL,IDB_PTZ_RIGHT_CLOSE);
	m_right.SizeToContent();		//����ӦͼƬ��С

	m_speedadd.LoadBitmaps(IDB_PTZ_SPEEDADD_OPEN,IDB_PTZ_SPEEDADD_MOVE,NULL,IDB_PTZ_SPEEDADD_CLOSE);
	m_speedadd.SizeToContent();		//����ӦͼƬ��С
	
	m_speedsub.LoadBitmaps(IDB_PTZ_SPEEDSUB_OPEN,IDB_PTZ_SPEEDSUB_MOVE,NULL,IDB_PTZ_SPEEDSUB_CLOSE);
	m_speedsub.SizeToContent();		//����ӦͼƬ��С

	m_up.LoadBitmaps(IDB_PTZ_UP_OPEN,IDB_PTZ_UP_MOVE,NULL,IDB_PTZ_UP_CLOSE);
	m_up.SizeToContent();		//����ӦͼƬ��С

	m_zoomsub.LoadBitmaps(IDB_PTZ_ZOOMSUB_OPEN,IDB_PTZ_ZOOMSUB_MOVE,NULL,IDB_PTZ_ZOOMSUB_CLOSE);
	m_zoomsub.SizeToContent();		//����ӦͼƬ��С

	m_zoomadd.LoadBitmaps(IDB_PTZ_ZOOMADD_OPEN,IDB_PTZ_ZOOMADD_MOVE,NULL,IDB_PTZ_ZOOMADD_CLOSE);
	m_zoomadd.SizeToContent();		//����ӦͼƬ��С

	m_upright.LoadBitmaps(IDB_PTZ_RIGHTUP_OPEN,IDB_PTZ_RIGHTUP_MOVE,NULL,IDB_PTZ_RIGHTUP_CLOSE);
	m_upright.SizeToContent();		//����ӦͼƬ��С

	m_upleft.LoadBitmaps(IDB_PTZ_LEFTUP_OPEN,IDB_PTZ_LEFTUP_MOVE,NULL,IDB_PTZ_LEFTUP_CLOSE);
	m_upleft.SizeToContent();		//����ӦͼƬ��С

}

void CDLGptz::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	//������ͼ	
	CRect    rect;     
	GetClientRect(&rect);     
	
	//����Դ������λͼ     
	CBitmap    bitmap;     
	bitmap.LoadBitmap(IDB_BACK_PTZ);    
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	
	CDC    memdc;     
	memdc.CreateCompatibleDC(&dc);     
	memdc.SelectObject(bitmap); 
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	memdc.DeleteDC();

	CDialog::OnPaint();
}




//�����¼���Ӧ///////////////////////////////
void CDLGptz::OnUpleft() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnUp() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnUpright() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnLeft() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnAuto() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnRight() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnDownleft() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnDown() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnDownright() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnFocusAdd() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnIrisAdd() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnZoomAdd() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnFocusSub() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnIrisSub() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnZoomSub() 
{
	// TODO: Add your control notification handler code here
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
}

void CDLGptz::OnButtonSet() 
{
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edit_set = 0;

}

void CDLGptz::OnButtonGo() 
{
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edit_set = 0;
}

void CDLGptz::OnSpeedSub() 
{
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
	// TODO: Add your control notification handler code here
	
	m_edit_speed = 0;
	UpdateData(FALSE);
				
}

void CDLGptz::OnSpeedAdd() 
{
	if(!DlgLogin.CurrentUser.ptz)
	{
		MessageBox("�� ��̨���� Ȩ�ޣ�����ϵ����Ա",MESSAGEBOX_TITLE);
		return ;
	}
	// TODO: Add your control notification handler code here
	m_edit_speed = 0;
	UpdateData(FALSE);
}


HBRUSH CDLGptz::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor==CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT); // ����͸������
		// TODO: Change any attributes of the DC here
		pDC->SetTextColor(RGB(0, 0, 0)); // �����ı���ɫ
		// TODO: Return a non-NULL brush if the parent's handler should not be called
		hbr=(HBRUSH)GetStockObject(HOLLOW_BRUSH); // ����͸����ˢ	
		// TODO: Return a different brush if the default is not desired
	}
	return hbr;
}