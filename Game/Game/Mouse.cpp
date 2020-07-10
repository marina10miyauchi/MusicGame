#include "Mouse.h"
#include<DxLib.h>
#include"ColorConst.h"

const int Mouse::Left{ MOUSE_INPUT_LEFT };
const int Mouse::Right{ MOUSE_INPUT_RIGHT };
const int Mouse::Middle{ MOUSE_INPUT_MIDDLE };

int Mouse::current_state_{ 0 };
int Mouse::precios_state_{ 0 };

int test_;

void Mouse::Initialize()
{
	current_state_ = 0;
	precios_state_ = 0;
}

void Mouse::Update()
{
	precios_state_ = current_state_;
	current_state_ = GetMouseInput();

	if (Trigger(Mouse::Left))
		int t = 0;
}

bool Mouse::State(int button)
{
	return (current_state_&button) != 0;
}

bool Mouse::Trigger(int button)
{
	test_ = (current_state_&~precios_state_&button);
	//return (current_state_&~precios_state_&button) != 0;
	return test_ != 0;
}

bool Mouse::Release(int button)
{
	return (~current_state_&precios_state_&button) != 0;
}

void Mouse::Finalize()
{
	Initialize();
}

void Mouse::DebugDraw()
{
	DrawFormatString(0, 60, ColorConst::White, "cur_state_: %o", current_state_);
	DrawFormatString(0, 80, ColorConst::White, "prev_state_: %o", precios_state_);
	DrawFormatString(0, 100, ColorConst::White, "test: %o", test_);

}
