#pragma once


// Cmeetphonepassword �Ի���

class Cmeetphonepassword : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonepassword)

public:
	Cmeetphonepassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonepassword();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sUsername;
	CString m_sPassword;
};
