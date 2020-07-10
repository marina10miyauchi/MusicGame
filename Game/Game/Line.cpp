#include "Line.h"
#include"ColorConst.h"
#include"Text.h"
#include<DxLib.h>


unsigned int Line::current_color_[Lane::Max];

Line::Line(float judgeLinePosY) :
	judgeLine_pos_y_{ judgeLinePosY }
{
	for (int i = 0; i < Lane::Max; i++)
	{
		current_color_[i] = ColorConst::White;
	}
}

Line::~Line()
{}

void Line::Draw()
{
	LineDraw();
	TextDraw();
}

void Line::ChangeCore(int lane, bool change)
{
	current_color_[lane] = ColorConst::White;
	if (change)
		current_color_[lane] = ColorConst::Red;
}

void Line::LineDraw()
{
	//”»’èƒ‰ƒCƒ“
	DrawLine(0, judgeLine_pos_y_, 1000, judgeLine_pos_y_, GetColor(255, 255, 255));
	//ƒŒ[ƒ“ƒ‰ƒCƒ“
	DrawLine(initial_left_pos_x + interval * 0, 0, initial_left_pos_x + interval * 0, 600, ColorConst::White);
	DrawLine(initial_left_pos_x + interval * 1, 0, initial_left_pos_x + interval * 1, 600, ColorConst::White);
	DrawLine(initial_left_pos_x + interval * 2, 0, initial_left_pos_x + interval * 2, 600, ColorConst::White);
	DrawLine(initial_left_pos_x + interval * 3, 0, initial_left_pos_x + interval * 3, 600, ColorConst::White);
	DrawLine(initial_left_pos_x + interval * 4, 0, initial_left_pos_x + interval * 4, 600, ColorConst::White);
}

void Line::TextDraw()
{
	DrawFormatStringF(initial_left_pos_x + interval * 0.5f, judgeLine_pos_y_ + 50, current_color_[Lane::Z], "Z");
	DrawFormatStringF(initial_left_pos_x + interval * 1.5f, judgeLine_pos_y_ + 50, current_color_[Lane::X], "X");
	DrawFormatStringF(initial_left_pos_x + interval * 2.5f, judgeLine_pos_y_ + 50, current_color_[Lane::C], "C");
	DrawFormatStringF(initial_left_pos_x + interval * 3.5f, judgeLine_pos_y_ + 50, current_color_[Lane::V], "V");
}
