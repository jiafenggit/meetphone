#pragma once


// Cmeetphonertspaddr �Ի���

class Cmeetphonertspaddr : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonertspaddr)

public:
	Cmeetphonertspaddr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonertspaddr();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_RTSP_ADDR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_sRtspAddr;
};
