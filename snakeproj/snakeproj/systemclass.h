#ifndef _SYSTEMCLASS_H_
#define _SYSTEMcLASS_H_
//Filename : systemclass.h


//전처리
//Pre-processing directives
#define WIN32_LEAN_ANd_MEAN


//includes
#include <Windows.h>

#include "inputclass.h"
#include "graphicsclass.h"


class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();
	
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};

//Function prototypes
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//전역변수들
//globals
static SystemClass* ApplicationHandle = 0;

#endif
