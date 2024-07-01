#include "lkbPlayScene.h"
#include "lkbGameObject.h"

namespace lkb {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		GameObject* objc = new GameObject();
		AddGameObjects(objc);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}
}
