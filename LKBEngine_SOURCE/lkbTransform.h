#pragma once
#include "lkbEntity.h"
#include "lkbComponent.h"

namespace lkb {

	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		float getRotation() { return mRotation; }
		Vector2 getScale() { return mScale; }
		void setRotation(float rotate) { mRotation = rotate; }
		void setScale(Vector2 scale) { mScale = scale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}

