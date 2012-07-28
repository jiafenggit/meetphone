#pragma once
#include "afxwin.h"


// Cmeetphonemultimedia �Ի���

class Cmeetphonemultimedia : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonemultimedia)

public:
	Cmeetphonemultimedia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonemultimedia();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_MULTIMEDIA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPlay();
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedButtonBrowse();
	afx_msg void OnCbnSelchangeComboWebcams();
	afx_msg void OnCbnSelchangeComboVideoSize();
	afx_msg void OnBnClickedCheckEchocancel();
private:
	CComboBox m_hComboPlayBack;
	CComboBox m_hComboRing;
	CComboBox m_hComboCapture;
	CEdit m_hEditRing;
	CButton m_hCheckEchoCancel;
	CButton m_hButtonBrowse;
	CButton m_hButtonPlay;
	CComboBox m_hComboWebcams;
	CComboBox m_hComboVideoSize;
	int m_iLastWebcam;
};
