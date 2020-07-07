#include "Line.h"
#include<DxLib.h>

Line::Line(float judgeLinePosY):
	judgeLine_pos_y_{ judgeLinePosY }
{}

Line::~Line()
{}

void Line::Intialize()
{
	white = GetColor(255, 255, 255);
	red = GetColor(255, 0, 0);
}

void Line::Draw()
{
	LineDraw();
	TextDraw();
}

void Line::ChangeCloreText(bool change)
{
	if (change)
		line_color = red;
	else line_color = white;
}

void Line::LineDraw()
{
	//îªíËÉâÉCÉì
	DrawLine(0, judgeLine_pos_y_, 1000, judgeLine_pos_y_, GetColor(255, 255, 255));
	//ÉåÅ[ÉìÉâÉCÉì
	DrawLine(initial_left_pos_x + interval * 0, 0, initial_left_pos_x + interval * 0, 600, white);
	DrawLine(initial_left_pos_x + interval * 1, 0, initial_left_pos_x + interval * 1, 600, white);
	DrawLine(initial_left_pos_x + interval * 2, 0, initial_left_pos_x + interval * 2, 600, white);
	DrawLine(initial_left_pos_x + interval * 3, 0, initial_left_pos_x + interval * 3, 600, white);
	DrawLine(initial_left_pos_x + interval * 4, 0, initial_left_pos_x + interval * 4, 600, white);
}

void Line::TextDraw()
{
	DrawFormatStringF(initial_left_pos_x + interval * 0.5f, judgeLine_pos_y_ + 50, line_color, "Z");
	DrawFormatStringF(initial_left_pos_x + interval * 1.5f, judgeLine_pos_y_ + 50, line_color, "X");
	DrawFormatStringF(initial_left_pos_x + interval * 2.5f, judgeLine_pos_y_ + 50, line_color, "C");
	DrawFormatStringF(initial_left_pos_x + interval * 3.5f, judgeLine_pos_y_ + 50, line_color, "V");
}
