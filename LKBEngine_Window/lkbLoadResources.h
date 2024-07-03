#pragma once
#include "..\\LKBEngine_SOURCE\lkbResources.h"

#include "..\\LKBEngine_SOURCE\lkbTexture.h"

namespace lkb {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\hass-guest\\source\\repos\\LKBEngine\\LKBEngine_SOURCE\\CloudOcean.png");
	}
}