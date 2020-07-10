#pragma once
#include"KeyConst.h"
#include<list>

static const int KEYS[15] = {
	keyConst::Z,
	keyConst::X,
	keyConst::C,
	keyConst::V,

	keyConst::W,
	keyConst::A,
	keyConst::S,
	keyConst::D,

	keyConst::Esc,
	keyConst::Space,
	keyConst::Enter,

	keyConst::Right,
	keyConst::Left,
	keyConst::Up,
	keyConst::Down,

};

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

	static void DebugDraw();
private:
	static int KeyUpdate();
	static void SetKeyList();

private:
	static int cur_state_;
	static int prev_state_;

	static int key_num;

	static std::list<int> keys_;

};