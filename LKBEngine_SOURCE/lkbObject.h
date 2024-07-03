#pragma once
#include "lkbLayer.h"
#include "lkbGameObject.h"
#include "lkbSceneManager.h"
#include "lkbScene.h"
#include "lkbComponent.h"
#include "lkbTransform.h"

namespace lkb::Object {
	template <typename T>
	static T* Instantinate(lkb::enums::eLayerType type) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::getActiveScene();
		Layer* layer = activeScene->GetLayer(type);

		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantinate(lkb::enums::eLayerType type, math::Vector2 position) {
		T* gameObject = new T();
		Scene* activeScene = SceneManager::getActiveScene();
		Layer* layer = activeScene->GetLayer(type);

		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();

		tr->SetPosition(position);

		return gameObject;
	}
}
