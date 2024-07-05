#include "lkbCamera.h"
#include "lkbTransform.h"
#include "lkbGameObject.h"
#include "LKBApplication.h"

extern lkb::Application application;

namespace lkb {
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
	{

	}
	Camera::~Camera()
	{

	}
	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{

	}
}
