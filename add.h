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
	HHOOK Start();//��װ����
	BOOL Stop(); //ж�ع��ӡ�����
};

//extern "C" int APIENTRY������
//DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
//{
//	//���ʹ��lpReserved������ɾ����������UNREFERENCED_PARAMETER(lpReserved);
//	if (dwReason == DLL_PROCESS_ATTACH)
//	{
//		TRACE0("NOtePadHOOK.DLL Initializing!\n");���� //��չDLL����ʼ��һ�Ρ���
//		if (!AfxInitExtensionModule(ActiveKeyDLL, hInstance))
//			return 0;
//		new CDynLinkLibrary(ActiveKeyDLL);������������//��DLL���붯̬MFC����С���
//		glhInstance = hInstance;����//���뱣��DLLʵ�����
//	}
//	else if (dwReason == DLL_PROCESS_DETACH)
//	{
//		TRACE0("NotePadHOOK.DLL Terminating!\n");����//��ֹ������ӿ�ǰ����������
//		AfxTermExtensionModule(ActiveKeyDLL);
//	}
//	return 1;
//}