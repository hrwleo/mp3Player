
// Mp3PlayerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

//��Ӷ�ý����ص�ͷ�ļ�
#include "MMsystem.h"
#pragma comment(lib,"winmm.lib")

// CMp3PlayerDlg �Ի���
class CMp3PlayerDlg : public CDialogEx
{
// ����
public:
	CMp3PlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MP3PLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

//����ʵ��������Ա
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


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
