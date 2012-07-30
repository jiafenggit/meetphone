#pragma once
#include "afxwin.h"
#include "meetphonemember.h"
#include "afxcmn.h"
#include "listctrlex.h"

// Cmeetphonemeet �Ի���

class Cmeetphonemeet : public CDialog
{
	DECLARE_DYNAMIC(Cmeetphonemeet)

public:
	Cmeetphonemeet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cmeetphonemeet();

// �Ի�������
	enum { IDD = IDD_MEETPHONE_MEET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg LONG OnMemberMaximizeMsg(WPARAM wP,LPARAM lP);
	afx_msg LONG OnMemberRestoreMsg(WPARAM wP,LPARAM lP);
	afx_msg LRESULT OnMemberAdd(WPARAM wP,LPARAM lP);
	afx_msg LRESULT OnMemberPreviewHwnd(WPARAM wP,LPARAM lP);
private:
	void InitMemberList();
	BOOL ReloadMemberList();
	HWND AddMeetMember(CString &memberName);

private:
	CList<Cmeetphonemember*, Cmeetphonemember*&> m_ListMember;
	CListCtrlEx m_hListMember;
	CStatic m_hStaticLocal;
	Cmeetphonemember *m_hLocalView;
	CImageList  m_hActionImage;
public:
	CString m_sConfUID;
	
	afx_msg void OnLvnDeleteitemListMember(NMHDR *pNMHDR, LRESULT *pResult);
};
