#pragma once
#include "..\\LKBEngine_SOURCE\lkbScene.h"
namespace lkb {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override ; 
		void Render(HDC mHdc) override;

		void OnEnter() override; // 씬에 입장할 때 불러주는 함수
		void OnExit() override;// 씬에서 퇴장할 때 불러주는 함수

	private:
		class Player* bg;
		class Player* p1;
	};
}

