#include "Notes.h"
#include<DxLib.h>

#define WIN_W 800 // �E�C���h�E�̉���
#define WIN_H 600 // �E�C���h�E�̏c��
#define LANE_NUM 4 // ���[���̐�
#define NOTE_NUM 1000 // �m�[�c�̍ő吔
#define NOTE_WIDTH 72 // �m�[�c�̕�
#define NOTE_HEIGHT 20 // �m�[�c�̍���
#define JUDGE_Y 500 // ���胉�C����Y���W

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
	//�m�[�c�������
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
	//if (notes.hasNotes) {
	//	DrawBoxAA(notes.x, notes.y - NOTE_HEIGHT / 2,
	//		notes.x + NOTE_WIDTH, notes.y + NOTE_HEIGHT / 2, GetColor(0, 255, 0), TRUE);
	//}
	if (notes.state == NotesState::None)
		DrawBoxAA(notes.x, notes.y - NOTE_HEIGHT / 2,
			notes.x + NOTE_WIDTH, notes.y + NOTE_HEIGHT / 2, GetColor(0, 255, 0), TRUE);
}

bool Notes::NotesEnd()
{
	return notes_end_;
}

