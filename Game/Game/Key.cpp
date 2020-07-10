#include "Key.h"
#include"ColorConst.h"

int Key::cur_state_{ 0 };
int Key::prev_state_{ 0 };
std::list<int> Key::keys_;
int Key::key_num{ 0 };

int  test = 0;
void Key::Initialize()
{
	cur_state_ = 0;
	prev_state_ = 0;
	SetKeyList();
}

void Key::Update()
{
	prev_state_ = cur_state_;
	cur_state_ = KeyUpdate();
	/*cur_state_ = GetJoypadInputState();*/

	if (Trigger(keyConst::Space))
		int t = 0;
}

bool Key::State(int key)
{
	return (cur_state_ == key) != 0;
	//return(cur_state_&key) != 0;
	//return(cur_key_&key_[key]) != 0;
}

bool Key::Trigger(int key)
{
	//test = (cur_state_ == key) && (cur_state_ != prev_state_);
	return (cur_state_ == key) && (key != prev_state_) != 0;
	//return (cur_state_&~prev_state_&key) != 0;
}

bool Key::Release(int key)
{
	return ((cur_state_ != key) && (prev_state_ == key)) != 0;
	//return (~cur_state_&prev_state_&key) != 0;
	//return (~cur_key_&prev_key_&key_[key]) != 0;
}

void Key::Finalize()
{
	Initialize();
}

void Key::DebugDraw()
{
	DrawFormatString(0, 0, ColorConst::White, "cur_state_: %o", cur_state_);
	DrawFormatString(0, 20, ColorConst::White, "prev_state_: %o", prev_state_);
	DrawFormatString(0, 40, ColorConst::White, "test: %o", test);
}

int Key::KeyUpdate()
{
	key_num = 0;
	for (int key : keys_)
	{
		auto test = CheckHitKey(key);
		if (test != 0) {
			key_num = key;
		}
	}
	return key_num;
}


void Key::SetKeyList()
{
	int keys[15] = {
		keyConst::Z,
		keyConst::X,
		keyConst::C,
		keyConst::V,
		keyConst::W,
		keyConst::A,
		keyConst::S,
		keyConst::D,
		keyConst::Left,
		keyConst::Right,
		keyConst::Up,
		keyConst::Down,
		keyConst::Esc,
		keyConst::Space,
		keyConst::Enter
	};
	for (int key : keys) {
		keys_.push_back(key);
	}
}

