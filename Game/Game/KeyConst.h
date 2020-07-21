#pragma once
#include<DxLib.h>

class keyConst {
public:

	static const int Esc{ KEY_INPUT_ESCAPE };
	static const int Space{ KEY_INPUT_SPACE };
	static const int Enter{ KEY_INPUT_RETURN };

	static const int Z{ KEY_INPUT_Z };
	static const int X{ KEY_INPUT_X };
	static const int C{ KEY_INPUT_C };
	static const int V{ KEY_INPUT_V };

	static const int W{ KEY_INPUT_W };
	static const int A{ KEY_INPUT_A };
	static const int S{ KEY_INPUT_S };
	static const int D{ KEY_INPUT_D };

	static const int Left{ KEY_INPUT_LEFT };
	static const int Right{ KEY_INPUT_RIGHT };
	static const int Up{ KEY_INPUT_UP };
	static const int Down{ KEY_INPUT_DOWN };
};

//îªíËÉ{É^ÉìÅ@
static const int KEYS_[4] = {
	keyConst::Z,
	keyConst::X,
	keyConst::C,
	keyConst::V,
};
