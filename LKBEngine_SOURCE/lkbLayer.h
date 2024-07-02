#pragma once
#include "lkbEntity.h"
#include "Commoninclude.h"
#include "lkbGameObject.h"

namespace lkb {

	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC mHdc);

		void AddGameObject(GameObject* gameObject);

	private:
		/*eLayerType mType;*/
		std::vector<GameObject*> mGameObjects;
	};
}

