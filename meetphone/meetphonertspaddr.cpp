// meetphonertspaddr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "meetphone.h"
#include "meetphonertspaddr.h"


// Cmeetphonertspaddr �Ի���

IMPLEMENT_DYNAMIC(Cmeetphonertspaddr, CDialog)

Cmeetphonertspaddr::Cmeetphonertspaddr(CWnd* pParent /*=NULL*/)
	: CDialog(Cmeetphonertspaddr::IDD, pParent)
	, m_sRtspAddr(_T(""))
{

}

Cmeetphonertspaddr::~Cmeetphonertspaddr()
{
}

void Cmeetphonertspaddr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RTSP, m_sRtspAddr);
}


BEGIN_MESSAGE_MAP(Cmeetphonertspaddr, CDialog)
	ON_BN_CLICKED(IDOK, &Cmeetphonertspaddr::OnBnClickedOk)
END_MESSAGE_MAP()


// Cmeetphonertspaddr ��Ϣ�������

void Cmeetphonertspaddr::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
