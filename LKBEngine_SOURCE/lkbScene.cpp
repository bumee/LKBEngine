#include "lkbScene.h"
#include "Commoninclude.h"

namespace lkb 
{
	Scene::Scene()
		: mLayers{}
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		//범위 기반 for 문
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		//범위 기반 for 문
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC mHdc)
	{
		//범위 기반 for 문
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			layer->Render(mHdc);
		}
	}
	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(GameObject* gameObject, enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}
	void Scene::createLayers()
	{
	}
}
