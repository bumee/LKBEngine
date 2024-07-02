#include "lkbScene.h"
namespace lkb 
{
	Scene::Scene()
		:mGameObjects{}
	{

	}

	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		//범위 기반 for 문
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		//범위 기반 for 문
		for (GameObject* gameObj : mGameObjects) {
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC mHdc)
	{
		//범위 기반 for 문
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Render(mHdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}
