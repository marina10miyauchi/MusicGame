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
	//‰Šú‰»
	static void Initialize();
	//XV
	static void Update();
	//‰Ÿ‚³‚ê‚Ä‚¢‚é‚©
	static bool State(int key);
	//‰Ÿ‚³‚ê‚½‚©
	static bool Trigger(int key);
	//—£‚ê‚½‚©
	static bool Release(int key);
	//I—¹ˆ—
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