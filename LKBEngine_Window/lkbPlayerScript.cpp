#include "lkbPlayerScript.h"
#include "lkbInput.h"
#include "lkbTransform.h"
#include "lkbTime.h"
#include "lkbGameObject.h"
#include "lkbAnimator.h"

namespace lkb {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::idle)
		, mAnimator(nullptr)
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
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState)
		{
		case lkb::PlayerScript::eState::idle:
			idle();
			break;
		case lkb::PlayerScript::eState::attack:
			break;
		case lkb::PlayerScript::eState::dead:
			break;
		case lkb::PlayerScript::eState::hurt:
			break;
		case lkb::PlayerScript::eState::grenade:
			break;
		case lkb::PlayerScript::eState::shoot:
			break;
		case lkb::PlayerScript::eState::run:
			break;
		case lkb::PlayerScript::eState::reload:
			break;
		case lkb::PlayerScript::eState::walk:
			move();
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::Right)) {
			mState = PlayerScript::eState::walk;
			mAnimator->PlayAnimation(L"walk");
		}

		else if (Input::GetKey(eKeyCode::Left)) {
			mState = PlayerScript::eState::walk;
			mAnimator->PlayAnimation(L"walk");
		}

		else if (Input::GetKey(eKeyCode::Up)) {
			mState = PlayerScript::eState::walk;
			mAnimator->PlayAnimation(L"walk");
		}

		else if (Input::GetKey(eKeyCode::Down)) {
			mState = PlayerScript::eState::walk;
			mAnimator->PlayAnimation(L"walk");
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::Right)) {
			pos.x += 150.0f * Time::getDeltaTime();
		}

		else if (Input::GetKey(eKeyCode::Left)) {
			pos.x -= 150.0f * Time::getDeltaTime();
		}

		else if (Input::GetKey(eKeyCode::Up)) {
			pos.y -= 150.0f * Time::getDeltaTime();
		}

		else if (Input::GetKey(eKeyCode::Down)) {
			pos.y += 150.0f * Time::getDeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down)) {
			mState = PlayerScript::eState::idle;
			mAnimator->PlayAnimation(L"idle", true);
		}
	}
}
