#pragma once
#include "..\\LKBEngine_SOURCE\lkbResources.h"

#include "..\\LKBEngine_SOURCE\lkbTexture.h"

namespace lkb {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"FirstCityBG", L"..\\Resources\\img\\map\\City2\\Bright\\City2.png");
		Resources::Load<graphics::Texture>(L"Soldier1", L"..\\Resources\\img\\Character\\Soldier_1\\Soldier_1.png");
	}
}

// 카메라

// 크기 조정하는거

// 스크립트