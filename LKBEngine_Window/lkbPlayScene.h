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
	};
}

