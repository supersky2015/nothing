#pragma once
#include <Windows.h>
extern "C" __declspec(dllexport) void add(int a, int b);
//__declspec(dllexport)
#include <Windows.h>
extern "C" __declspec(dllexport) void Start(HINSTANCE hInst);
extern "C" __declspec(dllexport) void Stop();
class  CKeyHook
{
public:
	CKeyHook();
	~CKeyHook();
	HHOOK Start();//安装钩子
	BOOL Stop(); //卸载钩子　　　
};

//extern "C" int APIENTRY　　　
//DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
//{
//	//如果使用lpReserved参数则删除下面这行UNREFERENCED_PARAMETER(lpReserved);
//	if (dwReason == DLL_PROCESS_ATTACH)
//	{
//		TRACE0("NOtePadHOOK.DLL Initializing!\n");　　 //扩展DLL仅初始化一次　　
//		if (!AfxInitExtensionModule(ActiveKeyDLL, hInstance))
//			return 0;
//		new CDynLinkLibrary(ActiveKeyDLL);　　　　　　//把DLL加入动态MFC类库中　　
//		glhInstance = hInstance;　　//插入保存DLL实例句柄
//	}
//	else if (dwReason == DLL_PROCESS_DETACH)
//	{
//		TRACE0("NotePadHOOK.DLL Terminating!\n");　　//终止这个链接库前调用它　　
//		AfxTermExtensionModule(ActiveKeyDLL);
//	}
//	return 1;
//}