#pragma once
#include "lkbEntity.h"
#include "lkbGameObject.h"
#include "lkbLayer.h"

namespace lkb {
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC mHdc);

		virtual void OnEnter(); // 씬에 입장할 때 불러주는 함수
		virtual void OnExit(); // 씬에서 퇴장할 때 불러주는 함수

		void AddGameObject(GameObject* gameObject, eLayerType type);

	private:
		std::vector<Layer*> mLayers;
	};
}

