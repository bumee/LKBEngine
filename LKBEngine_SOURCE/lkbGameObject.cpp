#include "lkbGameObject.h"
#include "lkbInput.h"
#include "lkbTime.h"

lkb::GameObject::GameObject()
{
	mX = 0.0f;
	mY = 0.0f;
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
	const int speed = 100.0f;
	if (Input::GetKey(eKeyCode::A)) {
		mX -= speed * Time::getDeltaTime();
	}

	if (Input::GetKey(eKeyCode::D)) {
		mX += speed * Time::getDeltaTime();
	}

	if (Input::GetKey(eKeyCode::W)) {
		mY -= speed * Time::getDeltaTime();
	}

	if (Input::GetKey(eKeyCode::S)) {
		mY += speed * Time::getDeltaTime();
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
