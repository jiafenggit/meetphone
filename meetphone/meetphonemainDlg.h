#pragma once
#include "afxwin.h"
#include "resource.h"
#include "afxcmn.h"
#include "listctrlex.h"

// CmeetphonemainDlg �Ի���

class CmeetphonemainDlg : public CDialog
{
	DECLARE_DYNAMIC(CmeetphonemainDlg)

public:
	CmeetphonemainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CmeetphonemainDlg();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_MAIN };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLvnItemchangedListConference(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListConference(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LONG OnReloadMemberMsg(WPARAM wP,LPARAM lP);
	afx_msg LONG OnReloadConferenceListMsg(WPARAM wP,LPARAM lP);
	afx_msg void OnLvnDeleteitemListConference(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnDeleteitemListMember(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListMember(NMHDR *pNMHDR, LRESULT *pResult);

private:
	HICON m_hIcon;
	CImageList  m_hActionImage;
	CListCtrlEx m_ConfList;
	CListCtrlEx m_MemberList;

private:
	BOOL InitConferenceList();
	BOOL InitMemberList();
	BOOL ReloadConferenceList();
	BOOL ReloadMemberList(CString &confUID);

};
