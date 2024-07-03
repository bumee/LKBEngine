#include "lkbSceneManager.h"

namespace lkb {

	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name) {

		if (mActiveScene != nullptr)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter =
			mScene.find(name);

		if (iter == mScene.end()) {
			return nullptr;
		}
		else {
			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}
	}

	void SceneManager::Initialize()
	{

	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC mHdc)
	{
		mActiveScene->Render(mHdc);
	}
}
