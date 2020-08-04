#pragma once
#include"GameData.h"

enum Lane {
	Z,
	X,
	C,
	V,
	
	Edge	//右端
};

class Line {
public:
	//Line() = default;
	Line();
	~Line();
	void Draw();
	void ChangeCore(int lane, bool change);


private:
	void LineDraw();
	void TextDraw();

private:
	
	int underLange_{ 50 };//ラインから文字表示場所までの長さ

	static unsigned int current_color_[LANE_NUM];
};