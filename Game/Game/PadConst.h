#pragma once
#include<DxLib.h>

class PadConst {
public:
	static const int Left{ PAD_INPUT_LEFT };	//←
	static const int Right{ PAD_INPUT_RIGHT };	//→
	static const int Up{ PAD_INPUT_UP };		//↑
	static const int Down{ PAD_INPUT_DOWN };	//↓
	
	static const int A{ PAD_INPUT_1 };			//A_Button
	static const int B{ PAD_INPUT_2 };			//B_Button
	static const int X{ PAD_INPUT_3 };			//X_Button
	static const int Y{ PAD_INPUT_4 };			//Y_Button



	//↓キーボードを使用する際　わかりやすくしたもの　非推奨
	static const int z{ PAD_INPUT_1 };			//Zkey
	static const int x{ PAD_INPUT_2 };			//X
	static const int c{ PAD_INPUT_3 };			//Akey
	static const int a{ PAD_INPUT_4 };			//Skey
	static const int s{ PAD_INPUT_5 };
	static const int d{ PAD_INPUT_6 };
	static const int q{ PAD_INPUT_7 };
	static const int w{ PAD_INPUT_8 };
	static const int esc{ PAD_INPUT_9 };
	static const int space{ PAD_INPUT_10 };
};