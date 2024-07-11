#include "lkbAnimation.h"
#include "lkbTime.h"
#include "lkbTransform.h"
#include "lkbGameObject.h"
#include "lkbAnimator.h"
#include "lkbRenderer.h"
#include "lkbCamera.h"

namespace lkb {
    Animation::Animation()
        : Resource(enums::eResourceType::Animation)
        , mAnimator(nullptr)
        , mTexture(nullptr)
        , mAnimationSheet{}
        , mIndex(-1)
        , mTime(0.0f)
        , mbComplete(false)
    {
    }

    Animation::~Animation()
    {
    }

    HRESULT Animation::Load(const std::wstring& path)
    {
        return E_NOTIMPL;
    }

    void Animation::Update()
    {
        if (mbComplete)
            return;

        mTime += Time::getDeltaTime();

        if (mAnimationSheet[mIndex].duration < mTime)
        {
            mTime = 0.0f;
            if (mIndex < mAnimationSheet.size() - 1)
                mIndex++;
            else
                mbComplete = true;
        }
    }

    void Animation::Render(HDC hdc)
    {
        // 알파블렌드를 쓸수 있는 조건 : 해당이미지 알파채널이 있어야한다.
        //AlphaBlend(125, );


        if (mTexture == nullptr)
            return;

        GameObject* gameObj = mAnimator->GetOwner();
        Transform* tr = gameObj->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        float rot = tr->getRotation();
        Vector2 scale = tr->getScale();

        if (renderer::mainCamera)
            pos = renderer::mainCamera->CalculatePosition(pos);

        BLENDFUNCTION func = {};
        func.BlendOp = AC_SRC_OVER;
        func.BlendFlags = 0;
        func.AlphaFormat = AC_SRC_ALPHA;
        func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

        Sprite sprite = mAnimationSheet[mIndex];

        graphics::Texture::eTextureType type = mTexture->GetTextureType();
        if (type == graphics::Texture::eTextureType::Bmp) {
            BLENDFUNCTION func = {};
            func.BlendOp = AC_SRC_OVER;
            func.BlendFlags = 0;
            func.AlphaFormat = AC_SRC_ALPHA;
            func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

            HDC imgHdc = mTexture->GetHdc();

            AlphaBlend(hdc, pos.x -(sprite.size.x/2.0f), pos.y - (sprite.size.y/2.0f), sprite.size.x * scale.x, sprite.size.y * scale.y, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);

        }

        else if (type == graphics::Texture::eTextureType::Png) {
            // 내가 원하는 픽셀을 투명화 시킬 때
            Gdiplus::ImageAttributes imgAtt = {};

            // 투명화 시킬 픽셀의 색 범위
            imgAtt.SetColorKey(Gdiplus::Color(225, 225, 225), Gdiplus::Color(255, 255, 255));

            Gdiplus::Graphics gr(hdc);

            gr.TranslateTransform(pos.x, pos.y);
            gr.RotateTransform(rot);
            gr.TranslateTransform(-pos.x, -pos.y);


            gr.DrawImage(mTexture->GetImage(),
                Gdiplus::Rect
                (
                    pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f),
                    sprite.size.x * scale.x, sprite.size.y * scale.y
                )
                , sprite.leftTop.x
                , sprite.leftTop.y
                , sprite.size.x
                , sprite.size.y
                , Gdiplus::Unit::UnitPixel
                , /*&imgAtt*/nullptr
            );
        }

       /*Gdiplus::Graphics graphics(hdc);

       Gdiplus::Rect sourceRect(sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y);

       graphics.DrawImage(mTexture->GetImage(), pos.x, pos.y, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, Gdiplus::Unit::UnitPixel);*/
        
    }

    void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet
        , Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration, bool left)
    {
        mTexture = spriteSheet;
        for (size_t i = 0; i < spriteLegth; i++)
        {
            Sprite sprite = {};
            sprite.leftTop.x = leftTop.x + (size.x * i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;
            if (left) {
                sprite.leftTop.x = size.x * (spriteLegth - i - 1);
            }

            mAnimationSheet.push_back(sprite);
        }
    }

    void Animation::Reset()
    {
        mTime = 0.0f;
        mIndex = 0;
        mbComplete = false;
    }
}
