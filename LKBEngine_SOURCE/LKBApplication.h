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

		HDC GetHdc() { return mHdc; }
		UINT GetHeight() { return mHeight; }
		UINT GetWidth() { return mWidth; }

	private:
		void adjustWindowRect(HWND hWnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		float mSpeed;

		UINT mWidth;
		UINT mHeight;
		
	};
}

