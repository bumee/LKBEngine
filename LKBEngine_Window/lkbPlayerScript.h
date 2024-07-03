#pragma once
#include "..\\LKBEngine_SOURCE\lkbScript.h"

namespace lkb {
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}
