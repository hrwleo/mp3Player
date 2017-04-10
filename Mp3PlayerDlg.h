
// Mp3PlayerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

//添加多媒体相关的头文件
#include "MMsystem.h"
#pragma comment(lib,"winmm.lib")

// CMp3PlayerDlg 对话框
class CMp3PlayerDlg : public CDialogEx
{
// 构造
public:
	CMp3PlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MP3PLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

//动手实现声明成员
public:
	BOOL IsEqual4(char *pa, char *pb);
	CBitmap m_bg1;
	CBitmap m_bg;

	bool m_flag;
	DWORD getinfo(DWORD item);
	void forfor1();
	void forfor();

	int hour, minite, second;
	DWORD m_count;
	DWORD cdlen;
	CString aa, slen, filename;
	CString file[255];
	CString file1[255];
	CString filenames[255];

	int fi, fr;
	DWORD cdfrom, cdto;
	bool m_flag1, m_flag3;


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	CSliderCtrl m_sl;
	afx_msg void OnBnClickedPer();
	afx_msg void OnBnClickedPlayer();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
