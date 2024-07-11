#include "lkbMonsterScript.h"
#include "lkbInput.h"
#include "lkbTransform.h"
#include "lkbTime.h"
#include "lkbGameObject.h"
#include "lkbAnimator.h"

namespace lkb {
	MonsterScript::MonsterScript()
		: mState(PlayerScript::eState::idle)
		, mAnimator(nullptr)
		, lookingRight(true)
	{
	}
	MonsterScript::~PlayerScript()
	{
	}
	void MonsterScript::Initialize()
	{

	}
	void MonsterScript::Update()
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
	void MonsterScript::LateUpdate()
	{
	}
	void MonsterScript::Render(HDC hdc)
	{
	}
	void MonsterScript::idle()
	{
		if (Input::GetKey(eKeyCode::Right)) {
			mState = MonsterScript::eState::walk;
			lookingRight = true;
			mAnimator->PlayAnimation(L"walk");
		}

		else if (Input::GetKey(eKeyCode::Left)) {
			mState = MonsterScript::eState::walk;
			lookingRight = false;
			mAnimator->PlayAnimation(L"walk_left");
		}

		else if (Input::GetKey(eKeyCode::Up)) {
			mState = MonsterScript::eState::walk;
			if (lookingRight) {
				mAnimator->PlayAnimation(L"walk");
			}
			else {
				mAnimator->PlayAnimation(L"walk_left");
			}
		}

		else if (Input::GetKey(eKeyCode::Down)) {
			mState = MonsterScript::eState::walk;
			if (lookingRight) {
				mAnimator->PlayAnimation(L"walk");
			}
			else {
				mAnimator->PlayAnimation(L"walk_left");
			}
		}
	}
	void MonsterScript::move()
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
			mState = MonsterScript::eState::idle;
			if (lookingRight) {
				mAnimator->PlayAnimation(L"idle");
			}
			else {
				mAnimator->PlayAnimation(L"idle_left");
			}
		}
	}
}
