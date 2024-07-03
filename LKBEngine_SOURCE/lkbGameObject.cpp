#include "lkbGameObject.h"
#include "lkbInput.h"
#include "lkbTime.h"
#include "lkbTransform.h"

namespace lkb {

	GameObject::GameObject()
	{
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}


	void GameObject::Initialize()
	{
		for (Component* comp : mComponents) {
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{

		// 내가 오른쪽 키를 입력받았다면
			// x좌표가 플러스
			// 왼쪽 -> x가 마이너스
			// 위아래는 y가 플러스 마이너스 왔다갔다 하면 됨.
		/*const int speed = 100.0f;
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
		}*/

		for (Component* comp : mComponents) {
			comp->Update();
		}
	}


	void GameObject::Render(HDC hdc)
	{

		for (Component* comp : mComponents) {
			comp->Render(hdc);
		}
	}

	void GameObject::LateUpdate()
	{

		for (Component* comp : mComponents) {
			comp->LateUpdate();
		}
	}
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}

