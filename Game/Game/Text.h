#pragma once
#include<string>
#include<DxLib.h>

struct Vec2Pos
{
	int x;
	int y;
};


class Text {
public:
	//サイズ、フォントの一斉設定
	static void InitializeTextSetting(int size, std::string fontName, unsigned int color);

	static void DrawStringText(Vec2Pos pos, std::string text);
	static void DrawStringText(Vec2Pos pos, std::string text, int size);
	static void DrawStringText(Vec2Pos pos, std::string text, unsigned int color);
	static void DrawStringText(Vec2Pos pos, std::string text, int size, unsigned int color);
	static void DrawStringText( Vec2Pos pos, std::string text, int size, unsigned int color, std::string fontName);

private:
	static int size_;
	static const char* fontName_;
	static unsigned int color_;
};