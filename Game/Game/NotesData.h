#pragma once
enum NotesState {
	None,
	Good,
	Prefect,
	Miss
};

struct NotesDate
{
	//
	bool hasNotes;
	//
	NotesState  state;
	//pos_x
	float x;
	//pos_y
	float y;
	//�m�[�c�̔��胉�C�����B�J�E���g
	float timing;
	//�ԍ�
	int num;
	//���[���ԍ�
	int lane;
};