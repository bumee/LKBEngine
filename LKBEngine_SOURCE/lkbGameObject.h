#pragma once
#include "Commoninclude.h"
#include "lkbComponent.h"

namespace lkb {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void LateUpdate();

		/*void setPosition(float x, float y);
		float getPositionX();
		float getPositionY();*/

		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	private:
		//GameObject의 좌표
		/*float mX;
		float mY;*/
		std::vector<Component*> mComponents;
	};
}

