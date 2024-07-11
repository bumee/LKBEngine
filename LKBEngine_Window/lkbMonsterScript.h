#pragma once
#include "lkbScript.h"

namespace lkb {
	class MonsterScript : public Script
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

		MonsterScript();
		~MonsterScript();

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
		bool lookingRight;
	};
}

