#include "lkbSpriteRenderer.h"
#include "lkbGameObject.h"
#include "lkbTransform.h"

namespace lkb {

	SpriteRenderer::SpriteRenderer()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Initialize()
	{

	}

	void SpriteRenderer::Update()
	{

	}


	void SpriteRenderer::LateUpdate()
	{

	}

	void SpriteRenderer::Render(HDC hdc)
	{
		//HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); //새로운 핑크색 선택

		//HPEN pinkpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));

		//HPEN oldPen = (HPEN)SelectObject(hdc, pinkpen); //기존의 검은 펜 반환

		//Transform* tr = GetOwner()->GetComponent<Transform>();

		//SelectObject(hdc, oldPen); //기존 검은펜 다시 잡아주고


		//Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY()); //핑크색 사각형 그리고


		//SelectObject(hdc, oldBrush); //다시 원래 색인 하얀색을 선택

		//DeleteObject(brush); //다 사용한 파란색 브러쉬는 메모리에서 지워주자 !
		//DeleteObject(pinkpen); //새로 만든 핑크펜은 메모리에서 지워주기

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}