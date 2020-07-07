#include "Notes.h"
#include<DxLib.h>

#define WIN_W 800 // ウインドウの横幅
#define WIN_H 600 // ウインドウの縦幅
#define LANE_NUM 4 // レーンの数
#define NOTE_NUM 1000 // ノーツの最大数
#define NOTE_WIDTH 72 // ノーツの幅
#define NOTE_HEIGHT 20 // ノーツの高さ
#define JUDGE_Y 500 // 判定ラインのY座標

Notes::~Notes()
{
}

void Notes::UpDate(float judgeLinePosY,float currentTime,NotesDate& notes)
{
	//ノーツがあれば
	if (notes.frag) {
		notes.y = 750 * (float)(currentTime-notes.timing) / 2 + judgeLinePosY;
		
		if (750 + 20 < notes.y
			&& 0.3 < currentTime -notes.timing)
			notes.frag = false;
	}
}


void Notes::Draw(NotesDate& notes)
{
	if (notes.frag) {
		DrawBoxAA(notes.x, notes.y - NOTE_HEIGHT / 2,
			notes.x + NOTE_WIDTH, notes.y + NOTE_HEIGHT / 2, GetColor(0, 255, 0), TRUE);
	}
}

void Notes::Initialize(NotesDate notes, int lane)
{
	notes.frag = true;
	notes.x = 200.f + 150.f * lane;
}

///test

void Notes::Each(std::function<void(bool)>  action)
{
	for (int i = 0; i < lane_num; i++)
	{
		for (int j = 0; j < notes_num; j++)
		{
			action(notes_date[i][j].frag);
		}
	}
}

void Notes::KeySet()
{
	key = new int[4]{
	KEY_INPUT_Z,
	KEY_INPUT_X,
	KEY_INPUT_C,
	KEY_INPUT_V
	};
}

