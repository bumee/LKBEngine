#include "lkbPlayScene.h"
#include "lkbGameObject.h"
#include "lkbPlayer.h"
#include "lkbTransform.h"
#include "lkbSpriteRenderer.h"

namespace lkb {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Player* p1 = new Player();
		Transform* tr = p1->AddComponent<Transform>();
		tr->SetPos(800, 450);

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= p1->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(p1);
		
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
