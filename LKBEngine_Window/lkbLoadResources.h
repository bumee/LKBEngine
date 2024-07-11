#pragma once
#include "..\\LKBEngine_SOURCE\lkbResources.h"

#include "..\\LKBEngine_SOURCE\lkbTexture.h"

namespace lkb {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"FirstCityBG", L"..\\Resources\\img\\map\\City2\\Bright\\City2.png");
		Resources::Load<graphics::Texture>(L"Soldier1", L"..\\Resources\\img\\Character\\Soldier_1\\Soldier_1.png");
		Resources::Load<graphics::Texture>(L"walk", L"..\\Resources\\img\\Character\\Soldier_1\\Walk.png");
		Resources::Load<graphics::Texture>(L"attack", L"..\\Resources\\img\\Character\\Soldier_1\\Attack.png");
		Resources::Load<graphics::Texture>(L"dead", L"..\\Resources\\img\\Character\\Soldier_1\\Dead.png");
		Resources::Load<graphics::Texture>(L"explosion", L"..\\Resources\\img\\Character\\Soldier_1\\Explosion.png");
		Resources::Load<graphics::Texture>(L"grenade", L"..\\Resources\\img\\Character\\Soldier_1\\Grenade.png");
		Resources::Load<graphics::Texture>(L"hurt", L"..\\Resources\\img\\Character\\Soldier_1\\Hurt.png");
		Resources::Load<graphics::Texture>(L"idle", L"..\\Resources\\img\\Character\\Soldier_1\\Idle.png");
		Resources::Load<graphics::Texture>(L"reload", L"..\\Resources\\img\\Character\\Soldier_1\\Recharge.png");
		Resources::Load<graphics::Texture>(L"run", L"..\\Resources\\img\\Character\\Soldier_1\\Run.png");
		Resources::Load<graphics::Texture>(L"shoot", L"..\\Resources\\img\\Character\\Soldier_1\\Shot_1.png");
	}
}

// 카메라

// 크기 조정하는거

// 스크립트