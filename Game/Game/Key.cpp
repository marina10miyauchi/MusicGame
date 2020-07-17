#include "Key.h"
#include"ColorConst.h"

std::list<int> Key::keys_;
std::map<int, bool> Key::cur_keys_;
std::map<int, bool> Key::pre_keys_;

void Key::Initialize()
{
	SetKeyList();
}

void Key::Update()
{
	pre_keys_ = cur_keys_;
	KeyUpdata();

	if (Trigger(keyConst::Space))
		int t = 0;
}

bool Key::State(int key)
{
	return (cur_keys_[key]) != 0;
}

bool Key::Trigger(int key)
{
	return(cur_keys_[key] && !pre_keys_[key]) != 0;
}

bool Key::Release(int key)
{
	return(!cur_keys_[key] && pre_keys_[key]) != 0;
}

void Key::Finalize()
{
	Initialize();
}

void Key::DebugDraw()
{
}

void Key::KeyUpdata()
{
	for (int key : keys_)
	{
		auto test = CheckHitKey(key);
		cur_keys_[key] = false;
		if (test != 0)
			cur_keys_[key] = true;
	}
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
		cur_keys_[key] = false;
	}
}

