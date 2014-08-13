#include "graphicsclass.h"

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR); 
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Diret3D", L"Error", MB_OK);
		return false;
	}
	return true;
}

void GraphicsClass::Shutdown()
{
	m_D3D->Shutdown();
	delete m_D3D;
	m_D3D = 0;
	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	//Render the graphics scene.
	result = Render();
	if(!result){

			return false;
	}

	return true;
}

bool GraphicsClass::Render()
{
	//시작 버퍼 클리어
	m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	//스크린에 현재 씬을 넘겨줌
	m_D3D->EndScene();
	return true;
}

