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
			gameObj->LaterUpdate();
		}
	}
	void Scene::Render(HDC mHdc)
	{
		//범위 기반 for 문
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Render(mHdc);
		}
	}
	void Scene::AddGameObjects(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}
