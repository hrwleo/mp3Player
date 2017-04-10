
// Mp3PlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Mp3Player.h"
#include "Mp3PlayerDlg.h"
#include "afxdialogex.h"

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <mciapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW

#define byte unsigned char
#undef  THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//实现全局成员函数 2017-4-10 herongwei
void CMp3PlayerDlg::forfor()
{
	int i = 0;
	for (i; i <= fi; i++)
	{
		file1[i] = file[i];
	}
}

void CMp3PlayerDlg::forfor1()
{
	int i = 0;
	for (i; i <= fi; i++)
	{
		file[i] = file1[i];
	}
}

BOOL CMp3PlayerDlg::IsEqual4(char *pa, char *pb)
{
	return ((pa[0] == pb[0]) && (pa[1] == pb[1]) && (pa[2] == pb[2]) && (pa[3] == pb[3]));
}

DWORD CMp3PlayerDlg::getinfo(DWORD item)
{
	MCI_STATUS_PARMS mcistatusparams;
	mcistatusparams.dwCallback = (DWORD)GetSafeHwnd();
	mcistatusparams.dwItem = item;
	mcistatusparams.dwReturn = 0;
	mciSendCommand(m_count, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mcistatusparams);

	return mcistatusparams.dwReturn;
}


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMp3PlayerDlg 对话框



CMp3PlayerDlg::CMp3PlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMp3PlayerDlg::IDD, pParent)
{
	//初始化
	aa = "";
	hour = minite = second = 0;
	fi = -1;
	fr = 0;


	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONAPPMUSIC);
}

void CMp3PlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_SLIDER1, m_sl);
}

BEGIN_MESSAGE_MAP(CMp3PlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PER, &CMp3PlayerDlg::OnBnClickedPer)
	ON_BN_CLICKED(IDC_PLAYER, &CMp3PlayerDlg::OnBnClickedPlayer)
	ON_BN_CLICKED(IDC_STOP, &CMp3PlayerDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_NEXT, &CMp3PlayerDlg::OnBnClickedNext)
	ON_BN_CLICKED(IDC_OPEN, &CMp3PlayerDlg::OnBnClickedOpen)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMp3PlayerDlg::OnLbnSelchangeList1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMp3PlayerDlg 消息处理程序

BOOL CMp3PlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMp3PlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMp3PlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMp3PlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMp3PlayerDlg::OnBnClickedPer()
{
	// TODO:  在此添加控件通知处理程序代码
	hour = 0;
	minite = 0;
	second = 0;

	fr--;
	if (fr--)
	{
		fr = 0;
	}
	if (fr >= 0)
	{
		m_list.SetCurSel(fr);
		aa = file[fr];
		OnBnClickedStop();
		OnBnClickedPlayer();
		UpdateData(false);


	}
}


void CMp3PlayerDlg::OnBnClickedPlayer()
{
	// TODO:  在此添加控件通知处理程序代码
	if (aa=="")
	{
		OnBnClickedOpen();
	}
	else{
		if (m_flag && aa !="")
		{
			m_flag = false;
			MCI_OPEN_PARMS mciopenparms; //打开
			MCI_PLAY_PARMS mciplayparms; //播放

			mciopenparms.lpstrElementName = aa; // 播放路径
			mciopenparms.lpstrDeviceType = NULL; //文件类型

			// 向MCI设备发送命令信息
			mciSendCommand(0, MCI_OPEN, MCI_DEVTYPE_WAVEFORM_AUDIO,(DWORD)(LPVOID) &mciopenparms);
			m_count = mciopenparms.wDeviceID;
			mciopenparms.dwCallback = (DWORD)GetSafeHwnd();
			
			cdlen = getinfo(MCI_STATUS_LENGTH);   //得到歌曲长度
			cdto = MCI_MAKE_HMS(MCI_HMS_HOUR(cdlen), MCI_HMS_MINUTE(cdlen), MCI_HMS_SECOND(cdlen));
			mciplayparms.dwFrom = cdfrom;
			mciplayparms.dwTo = cdto;

			mciSendCommand(m_count, MCI_PLAY, MCI_TO | MCI_FROM, (DWORD)(LPVOID)&mciplayparms);
			m_sl.SetRange(0, cdlen);
			SetTimer(0, 1000, NULL);
			UpdateData(false);
		}
		else
		{
			m_flag = true;
			KillTimer(0);
			DWORD dwsf = getinfo(MCI_STATUS_POSITION);
			cdfrom = MCI_MAKE_MSF(MCI_MSF_MINUTE(dwsf), MCI_MSF_SECOND(dwsf), MCI_MSF_FRAME(dwsf));
			mciSendCommand(m_count, MCI_CLOSE, 0, NULL);
			m_count = 0;
		}
	}
}


void CMp3PlayerDlg::OnBnClickedStop()
{
	// TODO:  在此添加控件通知处理程序代码
	KillTimer(0);
	cdfrom = MCI_MAKE_HMS(0, 0, 0);
	mciSendCommand(m_count, MCI_CLOSE, 0, NULL);
	m_count = 0;
	m_flag = true;
}


void CMp3PlayerDlg::OnBnClickedNext()
{
	// TODO:  在此添加控件通知处理程序代码
	hour = 0;
	minite = 0;
	second = 0;
	fr++;
	if (fr>fi)
	{
		fr = fi;
	}
	if (fr<=fi)
	{
		m_list.SetCurSel(fr);
		aa = file[fr];
		OnBnClickedStop();
		OnBnClickedPlayer();
		UpdateData(false);
	}
}


void CMp3PlayerDlg::OnBnClickedOpen()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog fs(true);
	fs.m_ofn.lpstrFilter = "ALL Support Type Music\0*.*\0\0";
	POSITION pos = fs.GetStartPosition();
	if (fs.DoModal() == IDOK)
	{
		while (pos!=NULL)
		{
			fi++;
			file[fi] = fs.GetNextPathName(pos);
			filenames[fi] = fs.GetFileName();

			if (aa=="")
			{
				filename = filenames[fi];
				aa = file[fi];
				fr = fi;
				OnBnClickedStop();
				OnBnClickedPlayer();
				m_flag = false;
			}

			m_list.AddString(file[fi]);
			m_list.SetCurSel(fr);
			UpdateData(false);
		}
		forfor();
	}
}


void CMp3PlayerDlg::OnLbnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
	hour = 0;
	second = 0;
	minite = 0;

	int i = m_list.GetCurSel();
	CString tp;
	tp.Format("%d", i);
	fr = i;
	aa = file[i];
	OnBnClickedStop();
	OnBnClickedPlayer();
	UpdateData(false);
}


void CMp3PlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString stime, kk;
	second++;
	CClientDC dc(this);
	dc.SetBkColor(RGB(251, 193, 220));
	dc.SetTextColor(RGB(255, 0, 0));

	if (second == 60)
	{
		minite++;
		second = 0;
	}
	if (minite == 60)
	{
		hour++;
		minite = 0;
	}
	if (hour == 60)
	{
		hour = 0;
	}
	stime.Format("歌曲播放时间: %02d:%02d:%02d   ", hour, minite, second);
	dc.TextOut(10, 20, stime);

	m_sl.SetPos(cdfrom);
	DWORD cdf = getinfo(MCI_STATUS_POSITION);
	cdfrom = MCI_MAKE_MSF(MCI_MSF_MINUTE(cdf), MCI_MSF_SECOND(cdf), MCI_MSF_FRAME(cdf));

	UpdateData(false);
	if (getinfo(MCI_STATUS_POSITION)==cdlen)
	{
		hour = 0; 
		minite = 0;
		second = 0;
		OnBnClickedNext();
	}
	CDialogEx::OnTimer(nIDEvent);
}
