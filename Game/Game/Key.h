#pragma once
#include"KeyConst.h"

class Key {
public:
	//初期化
	static void Initialize();
	//更新
	static void Update();
	//押されているか
	static bool State(int key);
	//押されたか
	static bool Trigger(int key);
	//離れたか
	static bool Release(int key);
	//終了処理
	static void Finalize();

private:
	static int cur_state_;
	static int prev_state_;
};