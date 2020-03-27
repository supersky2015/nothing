#include "add.h"
#include <string>
#include <atlstr.h>
void add(int a, int b)
{
	CString str;
	str.Format(_T("sum=%d"), a + b);
	MessageBox(NULL, str, _T("result"), MB_OK);
}

//Shared data section������
#pragma data_seg("sharedata")
HHOOK glhHook = NULL; //���Ӿ����������
HINSTANCE glhInstance = NULL; //DLLʵ�����
CKeyHook g_hook;
#pragma data_seg()

//���̹��Ӵ�������������
extern "C" LRESULT WINAPI KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == 0X79)//������F10��ʱ��������ҡ���
		{
			//���ʵ�ִ��롣
			POINT newPoint, oldPoint;
			GetCursorPos(&oldPoint);
			newPoint.x = oldPoint.x + 40;
			newPoint.y = oldPoint.y + 10;
			SetCursorPos(newPoint.x, newPoint.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//ģ�ⰴ��������������
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//ģ��ſ�������������
			keybd_event(VK_SHIFT, MapVirtualKey(VK_SHIFT, 0), 0, 0); //����SHIFT��������
			keybd_event(0x52, MapVirtualKey(0x52, 0), 0, 0);//����R��������
			keybd_event(0x52, MapVirtualKey(0x52, 0), KEYEVENTF_KEYUP, 0);//�ſ�R��������
			keybd_event(VK_SHIFT, MapVirtualKey(VK_SHIFT, 0), KEYEVENTF_KEYUP, 0);//�ſ�SHIFT����������������
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
//��װȫ�ֹ��ӡ�
HHOOK CKeyHook::Start()
{
	glhHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, 0, GetCurrentThreadId());//���ü��̹��ӡ�
	DWORD dw = GetLastError();
	return glhHook;
}
//ж��ȫ�ֹ��ӡ�������
BOOL CKeyHook::Stop()
{
	BOOL bResult = TRUE;
	if (glhHook)
		bResult = UnhookWindowsHookEx(glhHook);//ж�ؼ��̹��ӡ�������
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