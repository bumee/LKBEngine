#include "LKBApplication.h"
#include "lkbInput.h"
#include "lkbTime.h"

namespace lkb {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
	{
	
	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.setPosition(0, 0);

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

		mPlayer.Update();

		Time::Update();

	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}
