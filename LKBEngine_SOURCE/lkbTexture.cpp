#include "lkbTexture.h"
#include "LKBApplication.h"

// 해당 전역변수가 존재함을 알리는 문법
extern lkb::Application application;

namespace lkb::graphics {
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{

	}
	Texture::~Texture()
	{

	}
	HRESULT Texture::Load(const std::wstring& path)
	{

		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		// bmp 일때
		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr) {
				return S_FALSE;
			}
			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			// 비트맵 만들었으니 dc도 만들어줘야함
			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			// DC가 생성된 순간에 메모리 안에 들어있는 디폴트 도화지 버려줘야 함
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);

			DeleteObject(oldBitmap);

		}
		else if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr)
				return S_FALSE;
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();

			return S_OK;
		}

		// png 일때

		
		return E_NOTIMPL;
	}
}
