#include "Key.h"

int Key::cur_state_{ 0 };
int Key::prev_state_{ 0 };

void Key::Initialize()
{
	cur_state_ = 0;
	prev_state_ = 0;
}

void Key::Update()
{
	prev_state_ = cur_state_;
	cur_state_ = CheckHitKeyAll(DX_CHECKINPUT_KEY);
}

bool Key::State(int key)
{
	return(cur_state_&key) != 0;
}

bool Key::Trigger(int key)
{
	return (cur_state_&~prev_state_&key) != 0;
}

bool Key::Release(int key)
{
	return (~cur_state_&prev_state_&key) != 0;
}

void Key::Finalize()
{
	Initialize();
}
