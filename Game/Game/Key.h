#pragma once
#include"KeyConst.h"
#include<list>
#include<map>

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

struct Test {
	int keynum;
	bool isPush = false;
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
	static void KeyUpdata();
	static void SetKeyList();

private:
	static std::list<int> keys_;

	static std::map<int, bool> cur_keys_;
	static std::map<int, bool>pre_keys_;

};