#pragma once
#include "lkbComponent.h"

namespace lkb {
	using namespace lkb::math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		/*std::vector<GameObject*> mGameObjects;*/

		Vector2 mDistance; // 카메라의 실제 위치 데이터
		Vector2 mResolution; // 카메라의 해상도
		Vector2 mLookPosition;
		class GameObject* mTarget;
	};
}

