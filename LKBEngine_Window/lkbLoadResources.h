#pragma once
#include "..\\LKBEngine_SOURCE\lkbResources.h"

#include "..\\LKBEngine_SOURCE\lkbTexture.h"

namespace lkb {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"FirstCityBG", L"..\\Resources\\img\\map\\City2\\Bright\\City2.png");
		Resources::Load<graphics::Texture>(L"Soldier1", L"..\\Resources\\img\\Character\\Soldier_1\\Soldier_1.png");

		//right animation 리로드
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

		//left animation 업로드
		Resources::Load<graphics::Texture>(L"walk_left", L"..\\Resources\\img\\Character\\Soldier_1\\Walk_left.png");
		Resources::Load<graphics::Texture>(L"attack_left", L"..\\Resources\\img\\Character\\Soldier_1\\Attack_left.png");
		Resources::Load<graphics::Texture>(L"dead_left", L"..\\Resources\\img\\Character\\Soldier_1\\Dead_left.png");
		Resources::Load<graphics::Texture>(L"grenade_left", L"..\\Resources\\img\\Character\\Soldier_1\\Grenade_left.png");
		Resources::Load<graphics::Texture>(L"hurt_left", L"..\\Resources\\img\\Character\\Soldier_1\\Hurt_left.png");
		Resources::Load<graphics::Texture>(L"idle_left", L"..\\Resources\\img\\Character\\Soldier_1\\Idle_left.png");
		Resources::Load<graphics::Texture>(L"reload_left", L"..\\Resources\\img\\Character\\Soldier_1\\Recharge_left.png");
		Resources::Load<graphics::Texture>(L"run_left", L"..\\Resources\\img\\Character\\Soldier_1\\Run_left.png");
		Resources::Load<graphics::Texture>(L"shoot_left", L"..\\Resources\\img\\Character\\Soldier_1\\Shot_1_left.png");
	}
}

// 카메라

// 크기 조정하는거

// 스크립트