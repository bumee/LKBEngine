#include "lkbInput.h"

namespace lkb {

	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void lkb::Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void lkb::Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed == true) {
					mKeys[i].state = eKeyState::Pressed;
				}
				else {
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			// 키가 안눌림
			else {
				// 이전 프레임에 눌려져 있었다. up
				if (mKeys[i].bPressed == true) {
					mKeys[i].state = eKeyState::Up;
				}
				// 이전 프레임에도 안눌려져 있었다. None
				else {
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}

	}
}
