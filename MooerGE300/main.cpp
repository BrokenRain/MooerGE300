#pragma once
#include "UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR		GetWindowClassName() const  { return _T("DUIMainFrame"); }
	virtual CDuiString  GetSkinFile()				{ return _T("duilib.xml"); }
	virtual CDuiString  GetSkinFolder()				{ return _T(""); }
	virtual void		Notify(TNotifyUI& msg) 
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btn_test"))
			{
				MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
			}
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	
	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}