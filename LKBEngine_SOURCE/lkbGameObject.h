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
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

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
		void initializeTransform();
	private:
		//GameObject의 좌표
		/*float mX;
		float mY;*/
		std::vector<Component*> mComponents;
	};
}

