#include "Notes.h"
#include<DxLib.h>
#include"Graphics2D.h"
#include"Assets.h"
#include"GameData.h"


bool Notes::notes_end_{ false };

Notes::~Notes() {}

void Notes::Initialize(NotesDate notes)
{
	//notes.hasNotes = true;
	notes.state = NotesState::None;
	notes.x = LEFT_EDGE_X + NOTE_WIDTH / 2 + LANE_BETWEEN * notes.lane;
	notes_end_ = false;
}

void Notes::UpDate(float judgeLinePosY, float currentTime, NotesDate& notes)
{
	if (notes.state == NotesState::None) {
		notes.y = WINDOW_HIGHT * (float)(currentTime - notes.timing) / 2 + judgeLinePosY;

		if (WINDOW_HIGHT + NOTE_HEIGHT < notes.y
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
		Graphics2D::DrawSprite(TextureID::Notes_ID, Vector2(notes.x, notes.y), Vector2(0.2f, 0.2f));
}

bool Notes::NotesEnd()
{
	return notes_end_;
}

