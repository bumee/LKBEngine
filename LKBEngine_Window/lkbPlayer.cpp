#include "lkbPlayer.h"
#include "lkbInput.h"
#include "lkbTransform.h"
#include "lkbTime.h"

namespace lkb {
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}