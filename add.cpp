#include "add.h"
#include <string>
#include <atlstr.h>
void add(int a, int b)
{
	CString str;
	str.Format(_T("sum=%d"), a + b);
	MessageBox(NULL, str, _T("result"), MB_OK);
}

//Shared data section　　　
#pragma data_seg("sharedata")
HHOOK glhHook = NULL; //钩子句柄。　　　
HINSTANCE glhInstance = NULL; //DLL实例句柄
CKeyHook g_hook;
#pragma data_seg()

//键盘钩子处理函数。　　　
extern "C" LRESULT WINAPI KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == 0X79)//当按下F10键时，激活外挂。　
		{
			//外挂实现代码。
			POINT newPoint, oldPoint;
			GetCursorPos(&oldPoint);
			newPoint.x = oldPoint.x + 40;
			newPoint.y = oldPoint.y + 10;
			SetCursorPos(newPoint.x, newPoint.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//模拟按下鼠标左键。　　
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//模拟放开鼠标左键。　　
			keybd_event(VK_SHIFT, MapVirtualKey(VK_SHIFT, 0), 0, 0); //按下SHIFT键。　　
			keybd_event(0x52, MapVirtualKey(0x52, 0), 0, 0);//按下R键。　　
			keybd_event(0x52, MapVirtualKey(0x52, 0), KEYEVENTF_KEYUP, 0);//放开R键。　　
			keybd_event(VK_SHIFT, MapVirtualKey(VK_SHIFT, 0), KEYEVENTF_KEYUP, 0);//放开SHIFT键。　　　　　　
			SetCursorPos(oldPoint.x, oldPoint.y);
		}
	}
	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}
CKeyHook::CKeyHook() 
{}
CKeyHook::~CKeyHook()
{
	if (glhHook)
		Stop();
}
//安装全局钩子。
HHOOK CKeyHook::Start()
{
	glhHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, 0, GetCurrentThreadId());//设置键盘钩子。
	DWORD dw = GetLastError();
	return glhHook;
}
//卸载全局钩子。　　　
BOOL CKeyHook::Stop()
{
	BOOL bResult = TRUE;
	if (glhHook)
		bResult = UnhookWindowsHookEx(glhHook);//卸载键盘钩子。　　　
	return bResult;
}
void Start(HINSTANCE hInst)
{
	glhInstance = hInst;
	g_hook.Start();
}
void Stop()
{
	CKeyHook hook;
	g_hook.Stop();
}