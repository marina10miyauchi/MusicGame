#include "Text.h"
#include<DxLib.h>
#include"ColorConst.h"
static int size_;
static const char* fontName_;
static int color_;

int Text::size_{ 24 };
const char* Text::fontName_{ "PixelMplus10" };
unsigned int Text::color_{ ColorConst::White };

void Text::InitializeTextSetting(int size, std::string fontName, unsigned int color)
{
	size_ = size;
	fontName_ = fontName.c_str();
	color_ = color;
}

void Text::DrawStringText(Vec2Pos pos, std::string text)
{
	ChangeFont(fontName_);
	SetFontSize(size_);
	DrawFormatString(pos.x, pos.y, color_, text.c_str());
}

void Text::DrawStringText(Vec2Pos pos, std::string text, int size)
{
	ChangeFont(fontName_);
	SetFontSize(size);
	DrawFormatString(pos.x, pos.y, color_, text.c_str());
}

void Text::DrawStringText(Vec2Pos pos, std::string text, unsigned int color)
{
	ChangeFont(fontName_);
	SetFontSize(size_);
	DrawFormatString(pos.x, pos.y, color, text.c_str());
}

void Text::DrawStringText(Vec2Pos pos, std::string text, int size, unsigned int color)
{
	ChangeFont(fontName_);
	SetFontSize(size);
	DrawFormatString(pos.x, pos.y, color, text.c_str());
}

void Text::DrawStringText(Vec2Pos pos, std::string text, int size, unsigned int color, std::string fontName)
{
	ChangeFont(fontName.c_str());
	SetFontSize(size);
	DrawFormatString(pos.x, pos.y, color, text.c_str());
}
