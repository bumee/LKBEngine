#include "lkbAnimator.h"

namespace lkb {
	Animator::Animator()
		: Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{

	}
	Animator::~Animator()
	{

	}
	void Animator::Initialize()
	{

	}
	void Animator::Update()
	{
		if (mActiveAnimation) {
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() && mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{

	}
	void Animator::Render(HDC hdc)
	{

	}
	void Animator::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		return nullptr;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
	}
}