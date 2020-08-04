#include "Line.h"
#include"ColorConst.h"
#include"Text.h"
#include<DxLib.h>


unsigned int Line::current_color_[LANE_NUM];

Line::Line()
{
	for (int i = 0; i < LANE_NUM; i++)
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
	DrawLine(0, JUDGE_LINE_Y, WINDOW_WIDTH, JUDGE_LINE_Y, ColorConst::White);
	//ƒŒ[ƒ“ƒ‰ƒCƒ“
	DrawLine(LEFT_EDGE_X + LANE_BETWEEN * Lane::Z, 0, LEFT_EDGE_X + LANE_BETWEEN * Lane::Z, JUDGE_LINE_Y, ColorConst::White);
	DrawLine(LEFT_EDGE_X + LANE_BETWEEN * Lane::X, 0, LEFT_EDGE_X + LANE_BETWEEN * Lane::X, JUDGE_LINE_Y, ColorConst::White);
	DrawLine(LEFT_EDGE_X + LANE_BETWEEN * Lane::C, 0, LEFT_EDGE_X + LANE_BETWEEN * Lane::C, JUDGE_LINE_Y, ColorConst::White);
	DrawLine(LEFT_EDGE_X + LANE_BETWEEN * Lane::V, 0, LEFT_EDGE_X + LANE_BETWEEN * Lane::V, JUDGE_LINE_Y, ColorConst::White);
	DrawLine(LEFT_EDGE_X + LANE_BETWEEN * Lane::Edge, 0, LEFT_EDGE_X + LANE_BETWEEN * Lane::Edge, JUDGE_LINE_Y, ColorConst::White);
}

void Line::TextDraw()
{
	DrawFormatStringF(LEFT_EDGE_X + LANE_BETWEEN * 0.5f, JUDGE_LINE_Y + underLange_, current_color_[Lane::Z], "Z");
	DrawFormatStringF(LEFT_EDGE_X + LANE_BETWEEN * 1.5f, JUDGE_LINE_Y + underLange_, current_color_[Lane::X], "X");
	DrawFormatStringF(LEFT_EDGE_X + LANE_BETWEEN * 2.5f, JUDGE_LINE_Y + underLange_, current_color_[Lane::C], "C");
	DrawFormatStringF(LEFT_EDGE_X + LANE_BETWEEN * 3.5f, JUDGE_LINE_Y + underLange_, current_color_[Lane::V], "V");
}
