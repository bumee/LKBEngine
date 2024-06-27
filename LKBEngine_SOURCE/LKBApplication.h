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

		void Initialize(HWND hWnd);

		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		// 플레이어
		GameObject mPlayer;
	};
}

