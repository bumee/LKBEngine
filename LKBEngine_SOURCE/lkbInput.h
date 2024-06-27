#pragma once
#include "Commoninclude.h"

namespace lkb {
	enum class eKeyState 
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode 
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};
	class Input
	{
	public:
		struct Key {
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code);
		static bool GetKeyUp(eKeyCode code);
		static bool GetKey(eKeyCode code);

	private:
		static std::vector<Key> mKeys;
	};
}

