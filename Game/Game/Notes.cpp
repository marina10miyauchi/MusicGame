#include "Notes.h"
#include<DxLib.h>
#include"Graphics2D.h"
#include"Assets.h"

#define WIN_W 800 // ウインドウの横幅
#define WIN_H 600 // ウインドウの縦幅
#define LANE_NUM 4 // レーンの数
#define NOTE_NUM 1000 // ノーツの最大数
#define NOTE_WIDTH 72 // ノーツの幅
#define NOTE_HEIGHT 20 // ノーツの高さ
#define JUDGE_Y 500 // 判定ラインのY座標

bool Notes::notes_end_{ false };

Notes::~Notes() {}

void Notes::Initialize(NotesDate notes)
{
	//notes.hasNotes = true;
	notes.state = NotesState::None;
	notes.x = 200.f + 150.f * notes.lane;
	notes_end_ = false;
}

void Notes::UpDate(float judgeLinePosY, float currentTime, NotesDate& notes)
{
	//ノーツがあれば
	//if (notes.hasNotes) {
	//	notes.y = 750 * (float)(currentTime - notes.timing) / 2 + judgeLinePosY;

	//	if (750 + 20 < notes.y
	//		&& 0.3 < currentTime - notes.timing)
	//		if (notes.lane = 9)
	//			notes_end_ = true;
	//	//notes.hasNotes = false;

	//}
	if (notes.state == NotesState::None) {
		notes.y = 750 * (float)(currentTime - notes.timing) / 2 + judgeLinePosY;

		if (750 + 20 < notes.y
			&& 0.3 < currentTime - notes.timing)
			if (notes.lane == 9)
				notes_end_ = true;
			else
				notes.state == NotesState::Miss;
	}
}


void Notes::Draw(NotesDate& notes)
{
	if (notes.state == NotesState::None)
		Graphics2D::DrawSprite(TextureID::Notes, Vector2(notes.x, notes.y), Vector2(0.2f, 0.2f));
}

bool Notes::NotesEnd()
{
	return notes_end_;
}

