#pragma once
#include<functional>

struct NotesDate
{
	//
	bool hasNotes;
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

//�~���Ă���m�[�c�̊Ǘ��N���X�i�P�́j
class Notes {
public:
	Notes() = default;
	~Notes();
	//�m�[�c������
	void Initialize(NotesDate notes);

	//�m�[�c�̍X�V
	void UpDate(float judgeLinePosY,float currentTime,NotesDate& notes );
	//�m�[�c�̕`��
	void Draw(NotesDate& notes);

private:

private:
	//�m�[�c�̗���郌�[����
	int lane_num{ 4 };
	//1���[��������̓��������\�m�[�c��
	int notes_num{ 40 };
	//�m�[�c�̗����X�s�[�h
	float notes_speed{ 3.0f };

	int bpm_{ 120 };

	//
	int* key;

	float judgeline_y{ 600.0f };
};