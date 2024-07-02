#pragma once
#include "lkbScene.h"

namespace lkb {
	class SceneManager
	{
	public:

		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name) {

			if(mActiveScene!=nullptr)
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

		static void Initialize();

		static void Update();
		static void LateUpdate();

		static void Render(HDC mHdc);

	/*private:*/
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

