#pragma once
#include "..\\LKBEngine_SOURCE\lkbSceneManager.h"
#include "lkbPlayScene.h"
#include "lkbTitleScene.h"

namespace lkb {
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"Title Scene");
		SceneManager::CreateScene<PlayScene>(L"Play Scene");

		SceneManager::LoadScene(L"Play Scene");
	}
}