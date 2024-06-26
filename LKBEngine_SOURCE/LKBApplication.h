#pragma once
#include "Commoninclude.h"

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
	};
}

