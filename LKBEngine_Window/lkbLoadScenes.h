#pragma once
#include "..\\LKBEngine_SOURCE\lkbSceneManager.h"
#include "lkbPlayScene.h"

namespace lkb {
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}