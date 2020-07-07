#pragma once
#include"KeyConst.h"

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

private:
	static int cur_state_;
	static int prev_state_;
};