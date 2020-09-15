#pragma once
#include"GameData.h"
#include"JudgeEffect.h"

enum Lane {
	Z,
	X,
	C,
	V,
	
	Edge	//�E�[
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
	void JudgeEffectDraw();

private:
	
	int underLange_{ 50 };//���C�����當���\���ꏊ�܂ł̒���

	static unsigned int current_color_[LANE_NUM];
	JudgeEffect* judge_effect[LANE_NUM];

};