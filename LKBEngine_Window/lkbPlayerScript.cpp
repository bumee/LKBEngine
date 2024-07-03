#include "lkbPlayerScript.h"
#include "lkbInput.h"
#include "lkbTransform.h"
#include "lkbTime.h"
#include "lkbGameObject.h"

namespace lkb {
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::Right)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::getDeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Left)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::getDeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Up)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * Time::getDeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Down)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * Time::getDeltaTime();
			tr->SetPosition(pos);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}
