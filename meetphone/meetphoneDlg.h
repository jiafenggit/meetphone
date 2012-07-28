
// meetphoneDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CmeetphoneDlg �Ի���
class CmeetphoneDlg : public CDialog
{
// ����
public:
	CmeetphoneDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEETPHONE_LOGIN };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


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
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticLogin();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LONG OnDelDlgMsg(WPARAM wP,LPARAM lP);
	afx_msg LONG OnDelMeetDlgMsg(WPARAM wP,LPARAM lP);
	afx_msg LONG OnUpdateStatus(WPARAM wP,LPARAM lP);
protected:
	CStatic m_hLoginStatic;
	CEdit m_hLoginServer;
	CEdit m_hLoginUser;
	CStatusBar m_StatusBar;
};
