#pragma once
#include "Commoninclude.h"
#include "lkbGameObject.h"

namespace lkb
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd, UINT width, UINT height);

		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		float mSpeed;

		UINT mWidth;
		UINT mHeight;

		// 플레이어
		GameObject mPlayer;
	};
}

