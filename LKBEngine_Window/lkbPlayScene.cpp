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
#include "lkbPlayerScript.h"
#include "lkbCamera.h"
#include "lkbRenderer.h"

namespace lkb {
	PlayScene::PlayScene()
		: bg(nullptr)
		, p1(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()

	{

		//메인 카메라
		GameObject* camera = Object::Instantinate<GameObject>(enums::eLayerType::None, Vector2(968.0f, 560.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();

		//게임 오브젝트 만들기 전에 리소드들을 전부 로드해주면 좋다!

		bg = Object::Instantinate<Player>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		

		graphics::Texture* tx = Resources::Find<graphics::Texture>(L"FirstCityBG");

		sr->SetTexture(tx);

		p1 = Object::Instantinate<Player>
			(enums::eLayerType::Player);
		SpriteRenderer* srforp1 = p1->AddComponent<SpriteRenderer>();
		p1->AddComponent<PlayerScript>();

		graphics::Texture* txforp1 = Resources::Find<graphics::Texture>(L"Soldier1");

		srforp1->SetTexture(txforp1);
		srforp1->SetSize(Vector2(5.0f, 5.0f));

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(mHdc, 0, 0, str, 10);
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
