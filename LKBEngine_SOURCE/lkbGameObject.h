#pragma once
#include "Commoninclude.h"

namespace lkb {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void Render(HDC hdc);
		void LateUpdate();

		void setPosition(float x, float y);
		float getPositionX();
		float getPositionY();

	private:
		//GameObject의 좌표
		float mX;
		float mY;
	};
}

