// meetphonemember.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "meetphone.h"
#include "meetphonemember.h"
#include "Vfw.h"

typedef struct Yuv2RgbCtx{
	uint8_t *rgb;
	size_t rgblen;
	MSVideoSize dsize;
	MSVideoSize ssize;
	MSScalerContext *sws;
}Yuv2RgbCtx;

typedef struct _DDDisplay{
	HWND window;
	HDRAWDIB ddh;
	MSVideoSize wsize; /*the initial requested window size*/
	MSVideoSize vsize; /*the video size received for main input*/
	MSVideoSize lsize; /*the video size received for local display */
	Yuv2RgbCtx mainview;
	Yuv2RgbCtx locview;
	int sv_corner;
	float sv_scalefactor;
	float sv_posx,sv_posy;
	int background_color[3];
	bool_t need_repaint;
	bool_t autofit;
	bool_t mirroring;
	bool_t own_window;
	char window_title[64];
}DDDisplay;

// Cmeetphonemember �Ի���

IMPLEMENT_DYNAMIC(Cmeetphonemember, CDialog)

Cmeetphonemember::Cmeetphonemember(CWnd* pParent /*=NULL*/)
: CDialog(Cmeetphonemember::IDD, pParent)
{
}

Cmeetphonemember::~Cmeetphonemember()
{
}

void Cmeetphonemember::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MEMBER_NAME, m_hMemberName);
	DDX_Control(pDX, IDC_LOADING, m_hLoading);
}


BEGIN_MESSAGE_MAP(Cmeetphonemember, CDialog)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_MESSAGE(WM_MEMBER_STOP_LOADING,OnMemberStopLoadingMsg)
END_MESSAGE_MAP()


// Cmeetphonemember ��Ϣ�������

BOOL Cmeetphonemember::OnInitDialog()
{
	CDialog::OnInitDialog();
	if (m_hLoading.Load(_T("res/loading.gif")))
		m_hLoading.Draw();
	m_hMemberName.SetWindowText(m_sMemberName);
	return TRUE;
}

void Cmeetphonemember::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if(IsZoomed()){
		ShowWindow(SW_HIDE);
		m_pParentWnd->PostMessage(WM_MEMBER_RESTORE, (WPARAM)this);
		//Delay restore when parent recv this message to prevent black blank
	} else {
		ShowWindow(SW_HIDE);
		m_pParentWnd->PostMessage(WM_MEMBER_MAXIMIZE, (WPARAM)this);
		ShowWindow(SW_MAXIMIZE);
	}

	CDialog::OnLButtonDblClk(nFlags, point);
}

void Cmeetphonemember::OnSize(UINT nType, int cx, int cy)
{
	if (nType==SIZE_RESTORED || nType==SIZE_MAXIMIZED){
		DDDisplay *wd=(DDDisplay*)GetWindowLongPtr(m_hWnd,GWLP_USERDATA);
		ms_message("Resized to %i,%i",cx,cy);
		if (wd!=NULL){
			wd->need_repaint=TRUE;
		}else{
			ms_error("Could not retrieve CDDisplay from window !");
		}
	}
	CDialog::OnSize(nType, cx, cy);
}

void Cmeetphonemember::OnPaint()
{
	CPaintDC dc(this);
	DDDisplay *wd=(DDDisplay*)GetWindowLongPtr(m_hWnd,GWLP_USERDATA);
	if (wd!=NULL){
		CW2A memberName(m_sMemberName);
		strcpy(wd->window_title, memberName);
		wd->need_repaint=TRUE;
	}
}

LONG Cmeetphonemember::OnMemberStopLoadingMsg(WPARAM wP,LPARAM lP)
{
	m_hLoading.ShowWindow(SW_HIDE);
	return 0;
}