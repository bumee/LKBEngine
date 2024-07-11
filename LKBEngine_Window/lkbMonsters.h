#pragma once
#include "lkbGameObject.h"

namespace lkb {
	class Monsters : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

