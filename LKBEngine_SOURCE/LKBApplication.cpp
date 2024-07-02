#include "LKBApplication.h"
#include "lkbInput.h"
#include "lkbTime.h"
#include "lkbSceneManager.h"

namespace lkb {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
	{
	
	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hWnd, UINT width, UINT height)
	{
		adjustWindowRect(hWnd, width, height);
		createBuffer(width, height);

		initializeEtc();

		SceneManager::Initialize();
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;
		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);

		ShowWindow(hwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		///백버퍼에 있는걸 원본 버퍼에 복사(그려준다)
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();

		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();

		Time::Update();

		SceneManager::Update();

	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
}
