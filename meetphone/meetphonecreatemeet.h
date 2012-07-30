#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>

// Cmeetphonecreatemeet �Ի���

class Cmeetphonecreatemeet : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonecreatemeet)

public:
	Cmeetphonecreatemeet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonecreatemeet();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_CREATE_MEET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit m_hEditName;
	CComboBox m_hComboMixer;
	CListCtrl m_hListMember;
	CImageList  m_hActionImage;
	std::vector<int> m_ListMember;
	
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_sEditName;
	CString m_sComboMixer;
	CString m_StrFormData;
	afx_msg void OnLvnDeleteitemListMember(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangingListMember(NMHDR *pNMHDR, LRESULT *pResult);
};
