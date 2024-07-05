#include "lkbTitleScene.h"
#include "lkbInput.h"
#include "lkbPlayScene.h"
#include "lkbSceneManager.h"

namespace lkb {

	TitleScene::TitleScene()
	{

	}

	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"Play Scene");
		}
	}

	void TitleScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
		/*wchar_t str[50] = L"Title Scene";
		TextOut(mHdc, 0, 0, str, 11);*/
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
