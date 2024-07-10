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
#include "lkbAnimator.h"

namespace lkb {
	PlayScene::PlayScene()
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

		//게임 오브젝트 만들기 전에 리소드들을 전부 로드해주면 좋다!

		// 플레이어 가져오기
		p1 = Object::Instantinate<Player>
			(enums::eLayerType::Player);
		/*SpriteRenderer* srforp1 = p1->AddComponent<SpriteRenderer>();*/
		p1->AddComponent<PlayerScript>();


		// 플레이어 애니메이션 가져오기
		graphics::Texture* WalkingAnim = Resources::Find<graphics::Texture>(L"Walking");
		Animator* animator = p1->AddComponent<Animator>();
		animator->CreateAnimation(L"SoldierFrontMove", WalkingAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 7, 0.1f);

		animator->PlayAnimation(L"SoldierFrontMove", true);

		/*srforp1->SetTexture(WalkingAnim);*/

		// 맵 텍스처 불러오기
		GameObject* bg = Object::Instantinate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

		graphics::Texture* tx = Resources::Find<graphics::Texture>(L"FirstCityBG");
		bgSr->SetTexture(tx);

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init 함수를 호출
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
