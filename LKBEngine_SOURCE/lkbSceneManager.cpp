#include "lkbSceneManager.h"

namespace lkb {

	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{

	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LaterUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC mHdc)
	{
		mActiveScene->Render(mHdc);
	}
}
