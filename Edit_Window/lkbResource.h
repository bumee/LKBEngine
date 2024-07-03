#pragma once
#include "lkbEntity.h"

namespace lkb {
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource(); // 자식의 소멸자에 virtual 넣어야 자식의 메모리가 삭제되어 leak 이 안발생함

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 : 실제 메모리에 할당이 불가능해지는 문법
		// HRESULT는 bool과 같다.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		std::wstring mPath;
		enums::eResourceType mType;
	};
}

// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드,, 3스테이지 클리어 시 재시작 하면 3스테이지부터 시작

// 저장 게임 플레이데이터 HDD, 클라우드 저장을 해둔다.
// 이런 것들도 리소스이다.

