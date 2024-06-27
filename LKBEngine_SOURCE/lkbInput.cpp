#include "lkbInput.h"

namespace lkb {

	std::vector<Input::Key> Input::mKeys = {};

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

	}
}
