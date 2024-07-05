#pragma once
#include "lkbTexture.h"
#include "lkbResource.h"

namespace lkb {
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero) 
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{	

			}
			
		};
		Animation();
		~Animation();
		 
		HRESULT Load(const std::wstring& path);

		void Update();

		void Render(HDC hdc);

		// HRESULT는 bool과 같다.

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SEtAnimator(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}

