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
#include "lkbMonsters.h"
#include "lkbMonsterScript.h"

namespace lkb {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()

	{
		//게임 오브젝트 만들기 전에 리소드들을 전부 로드해주면 좋다!

		//메인 카메라
		GameObject* camera = Object::Instantinate<GameObject>(enums::eLayerType::None, Vector2(968.0f, 560.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// 맵 텍스처 불러오기
		GameObject* bg = Object::Instantinate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

		graphics::Texture* tx = Resources::Find<graphics::Texture>(L"FirstCityBG");
		bgSr->SetTexture(tx);




		// 플레이어 가져오기
		p1 = Object::Instantinate<Player>
			(enums::eLayerType::Player);
		/*SpriteRenderer* srforp1 = p1->AddComponent<SpriteRenderer>();*/
		p1->AddComponent<PlayerScript>();


		// right 플레이어 애니메이션 가져오기
		graphics::Texture* WalkingAnim = Resources::Find<graphics::Texture>(L"walk");
		graphics::Texture* RunningAnim = Resources::Find<graphics::Texture>(L"run");
		graphics::Texture* ReloadingAnim = Resources::Find<graphics::Texture>(L"reload");
		graphics::Texture* AttackingAnim = Resources::Find<graphics::Texture>(L"attack");
		graphics::Texture* IdleAnim = Resources::Find<graphics::Texture>(L"idle");
		graphics::Texture* DeadAnim = Resources::Find<graphics::Texture>(L"dead");
		graphics::Texture* ExplosionAnim = Resources::Find<graphics::Texture>(L"explosion");
		graphics::Texture* GrenadeAnim = Resources::Find<graphics::Texture>(L"grenade");
		graphics::Texture* HurtAnim = Resources::Find<graphics::Texture>(L"hurt");
		graphics::Texture* ShootingAnim = Resources::Find<graphics::Texture>(L"shoot");

		// left 플레이어 애니메이션 불러오기
		graphics::Texture* WalkingAnim_left = Resources::Find<graphics::Texture>(L"walk_left");
		graphics::Texture* RunningAnim_left = Resources::Find<graphics::Texture>(L"run_left");
		graphics::Texture* ReloadingAnim_left = Resources::Find<graphics::Texture>(L"reload_left");
		graphics::Texture* AttackingAnim_left = Resources::Find<graphics::Texture>(L"attack_left");
		graphics::Texture* IdleAnim_left = Resources::Find<graphics::Texture>(L"idle_left");
		graphics::Texture* DeadAnim_left = Resources::Find<graphics::Texture>(L"dead_left");
		graphics::Texture* GrenadeAnim_left = Resources::Find<graphics::Texture>(L"grenade_left");
		graphics::Texture* HurtAnim_left = Resources::Find<graphics::Texture>(L"hurt_left");
		graphics::Texture* ShootingAnim_left = Resources::Find<graphics::Texture>(L"shoot_left");


		Animator* animator = p1->AddComponent<Animator>();
		animator->CreateAnimation(L"walk", WalkingAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 7, 0.1f);
		animator->CreateAnimation(L"run", RunningAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.1f);
		animator->CreateAnimation(L"reload", ReloadingAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 13, 0.1f);
		animator->CreateAnimation(L"attack", AttackingAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 3, 0.1f);
		animator->CreateAnimation(L"idle", IdleAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 7, 0.1f);
		animator->CreateAnimation(L"dead", DeadAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.15f);
		animator->CreateAnimation(L"explosion", ExplosionAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 9, 0.1f);
		animator->CreateAnimation(L"grenade", GrenadeAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 9, 0.1f);
		animator->CreateAnimation(L"hurt", HurtAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 3, 0.1f);
		animator->CreateAnimation(L"shoot", ShootingAnim, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"walk_left", WalkingAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 7, 0.1f, true);
		animator->CreateAnimation(L"run_left", RunningAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.1f, true);
		animator->CreateAnimation(L"reload_left", ReloadingAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 13, 0.1f, true);
		animator->CreateAnimation(L"attack_left", AttackingAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 3, 0.1f, true);
		animator->CreateAnimation(L"idle_left", IdleAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 7, 0.1f, true);
		animator->CreateAnimation(L"dead_left", DeadAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.15f, true);
		animator->CreateAnimation(L"grenade_left", GrenadeAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 9, 0.1f, true);
		animator->CreateAnimation(L"hurt_left", HurtAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 3, 0.1f, true);
		animator->CreateAnimation(L"shoot_left", ShootingAnim_left, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.1f, true);

		animator->PlayAnimation(L"attack_left", true);

		p1->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));

		// 이미지 사이즈 조절
		p1->GetComponent<Transform>()->setScale(Vector2(2.0f, 2.0f));

		// 각도 조절
		/*p1->GetComponent<Transform>()->setRotation(30.0f);*/


		// Enemy(Monster) 가져오기
		Monsters* monster = Object::Instantinate<Monsters>
			(enums::eLayerType::Enemy);
		monster->AddComponent<MonsterScript>();

		Animator* Monsteranimator = monster->AddComponent<Animator>();


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
