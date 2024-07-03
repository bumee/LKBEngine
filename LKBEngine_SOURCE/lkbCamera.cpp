#include "lkbCamera.h"
#include "lkbTransform.h"
#include "lkbGameObject.h"

namespace lkb {
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2(1600.0f, 900.0f))
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
	{

	}
	Camera::~Camera()
	{

	}
	void Camera::Initialize()
	{

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
