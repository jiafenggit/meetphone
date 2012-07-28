#pragma once
#include "afxcmn.h"
#include "tabctrlex.h"
#include "meetphonenetwork.h"
#include "meetphonemultimedia.h"
#include "meetphonecodec.h"


// Cmeetphonesetting �Ի���

class Cmeetphonesetting : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonesetting)

public:
	Cmeetphonesetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonesetting();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTcnSelchangeSettingTab(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
private:
	CTabCtrlEx m_hTab;
	Cmeetphonenetwork	m_hNetwork;
	Cmeetphonemultimedia m_hMultimedia;
	Cmeetphonecodec m_hCodec;
	CDialog *m_pDialog[3];
};
