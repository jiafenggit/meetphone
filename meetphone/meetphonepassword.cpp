// meetphonepassword.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "meetphone.h"
#include "meetphonepassword.h"


// Cmeetphonepassword �Ի���

IMPLEMENT_DYNAMIC(Cmeetphonepassword, CDialog)

Cmeetphonepassword::Cmeetphonepassword(CWnd* pParent /*=NULL*/)
	: CDialog(Cmeetphonepassword::IDD, pParent)
	, m_sUsername(_T(""))
	, m_sPassword(_T(""))
{

}

Cmeetphonepassword::~Cmeetphonepassword()
{
}

void Cmeetphonepassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_sUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
}


BEGIN_MESSAGE_MAP(Cmeetphonepassword, CDialog)
END_MESSAGE_MAP()


// Cmeetphonepassword ��Ϣ�������
