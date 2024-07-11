#pragma once
#include "..\\LKBEngine_SOURCE\lkbScript.h"

namespace lkb {
	class PlayerScript : public Script
	{
	public:

		enum class eState {
			idle,
			attack,
			dead,
			hurt,
			grenade,
			shoot,
			run,
			reload,
			walk
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}
