#include "lkbLayer.h"

namespace lkb {
	Layer::Layer()
		: mGameObjects{}
	{

	}
	Layer::~Layer()
	{

	}
	void Layer::Initialize()
	{
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr)
				continue;
			gameobj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr)
				continue;
			gameobj->Update();
		}

	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr)
				continue;
			gameobj->LateUpdate();
		}
	}
	void Layer::Render(HDC mHdc)
	{
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr)
				continue;
			gameobj->Render(mHdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject != nullptr)
			mGameObjects.push_back(gameObject);
	}
}