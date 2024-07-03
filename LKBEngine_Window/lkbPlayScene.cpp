#include "lkbPlayScene.h"
#include "lkbGameObject.h"
#include "lkbPlayer.h"
#include "lkbTransform.h"
#include "lkbSpriteRenderer.h"
#include "lkbInput.h"
#include "lkbTitleScene.h"
#include "lkbSceneManager.h"
#include "lkbObject.h"
#include "lkbTexture.h"
#include "lkbResources.h"

namespace lkb {
	PlayScene::PlayScene()
		: bg(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//게임 오브젝트 만들기 전에 리소드들을 전부 로드해주면 좋다!

		bg = Object::Instantinate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		graphics::Texture* tx = Resources::Find<graphics::Texture>(L"BG");

		sr->SetTexture(tx);

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"Title Scene");
		}
	}
	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(mHdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}
}
