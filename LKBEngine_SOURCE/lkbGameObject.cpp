#include "lkbGameObject.h"

lkb::GameObject::GameObject()
{

}

lkb::GameObject::~GameObject()
{

}

void lkb::GameObject::Update()
{
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

void lkb::GameObject::Render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); //새로운 핑크색 선택

	HPEN pinkpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));

	HPEN oldPen = (HPEN)SelectObject(hdc, pinkpen); //기존의 검은 펜 반환


	Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); //핑크색 사각형 그리고


	SelectObject(hdc, oldPen); //기존 검은펜 다시 잡아주고

	SelectObject(hdc, oldBrush); //다시 원래 색인 하얀색을 선택

	DeleteObject(brush); //다 사용한 파란색 브러쉬는 메모리에서 지워주자 !
	DeleteObject(pinkpen); //새로 만든 핑크펜은 메모리에서 지워주기
}

void lkb::GameObject::LateUpdate()
{

}

void lkb::GameObject::setPosition(float x, float y)
{
	mX = x;
	mY = y;
}

float lkb::GameObject::getPositionX()
{
	return mX;
}

float lkb::GameObject::getPositionY()
{
	return mY;
}
