
// meetphone.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "linphonecore.h"

#define CONFIG_FILE "meetphonerc"
#define SECRETS_FILE "meetphone-zidcache"
#define MEETPHONE_CONFIG_DIR "meetphone"
#define MEETPHONE_PLUGINS_DIR "./lib/liblinphone/plugins"
#define FACTORY_CONFIG_FILE "meetphonerc.factory"
#define WM_DELETE_DLG WM_USER + 100
#define WM_UPDATE_STATUS WM_USER + 101

#define WM_RELOAD_CONEFENCE WM_USER + 102
#define WM_RELOAD_MEMBER WM_USER + 103

#define WM_DELETE_MEETDLG WM_USER + 104

#define WM_MEMBER_MAXIMIZE WM_USER + 105
#define WM_MEMBER_RESTORE WM_USER + 106
#define WM_MEMBER_STOP_LOADING WM_USER + 107
#define WM_MEMBER_ADD WM_USER + 108
#define WM_MEMBER_PREVIEW_HWND WM_USER + 109
#define WM_MEMBER_RELOAD WM_USER + 110

#define APP_NAME "Meetphone"
#define VIDEOSELFVIEW_DEFAULT 1

// CmeetphoneApp:
// �йش����ʵ�֣������ meetphone.cpp
//

class CmeetphoneApp : public CWinAppEx
{
private:
	BOOL InitPipe(const char *addr_to_call);
	BOOL InitCoreapi();
	char *GetConfigFile(const char *filename);
	char *GetFactoryConfigFile();
public:
	CmeetphoneApp();
	
// ��д
public:
	CDialog *m_pLogWnd;
	CDialog *m_pSettingWnd;
	CDialog *m_pMeetWnd;
	CDialog *m_pMeetingWnd;
	virtual BOOL InitInstance();
	LinphoneCore *GetCore(){return m_pCore;};
	TCHAR *GetWorkingDir(){return m_WorkingDir;};
private:
	char m_FactoryConfigFile[1024];
	TCHAR m_WorkingDir[MAX_PATH];
	char *m_ConfigFile;
	char *m_SecretsFile;
	LinphoneCore *m_pCore;
	UINT m_nTimerID;
	UINT m_nLogTimerID;
	ULONG_PTR m_gdiplusToken;
public:
// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuDebug();
	afx_msg void OnMenuAbout();
	afx_msg void OnSetting();
	afx_msg void OnLogout();
};

extern CmeetphoneApp theApp;