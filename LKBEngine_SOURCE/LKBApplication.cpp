#include "LKBApplication.h"

namespace lkb {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mX(0.0f)
		, mY(0.0f)
	{
	
	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.01f;

		// 내가 오른쪽 키를 입력받았다면
		// x좌표가 플러스
		// 왼쪽 -> x가 마이너스
		// 위아래는 y가 플러스 마이너스 왔다갔다 하면 됨.
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			mY += 0.01f;
		}
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); //새로운 핑크색 선택

		HPEN pinkpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));

		HPEN oldPen = (HPEN)SelectObject(mHdc, pinkpen); //기존의 검은 펜 반환


		Rectangle(mHdc, 100 + mX, 100 + mY , 200 + mX, 200 + mY); //핑크색 사각형 그리고


		SelectObject(mHdc, oldPen); //기존 검은펜 다시 잡아주고

		SelectObject(mHdc, oldBrush); //다시 원래 색인 하얀색을 선택

		DeleteObject(brush); //다 사용한 파란색 브러쉬는 메모리에서 지워주자 !
		DeleteObject(pinkpen); //새로 만든 핑크펜은 메모리에서 지워주기
	}
}
