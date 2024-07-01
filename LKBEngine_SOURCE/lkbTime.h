#pragma once
#include "Commoninclude.h"
namespace lkb {
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static float getDeltaTime() { return DeltaTime; }

	private:
		static LARGE_INTEGER CPUFrequency; // long long int임 ((8바이트)
		static LARGE_INTEGER PrevFrequency; // long long int임 ((8바이트)
		static LARGE_INTEGER CurrentFrequency; // long long int임 ((8바이트)
		static float DeltaTime;
	};
}

