#pragma once
#include"Game.h"
#include"SceneManager.h"
#include"Time.h"
#include"NotesCount.h"
#include"NotesManager.h"


#define WIN_W 800 // �E�C���h�E�̉���
#define WIN_H 600 // �E�C���h�E�̏c��
#define LANE_NUM 4 // ���[���̐�
#define NOTE_NUM 1000 // �m�[�c�̍ő吔
#define NOTE_WIDTH 72 // �m�[�c�̕�
#define NOTE_HEIGHT 20 // �m�[�c�̍���
#define JUDGE_Y 500 // ���胉�C����Y���W


class GameMain :public Game {
public:
	GameMain() :Game(1000, 750, false) {}
private:
	//�J�n
	virtual void Start() override;
	//�X�V
	virtual void Update(float delta_time)override;
	//�`��
	virtual void Draw()override;
	//�I��
	virtual void End()override;

private:

private:
	SceneManager scene_manager;
	NotesManager* notes_manager_;

	//test
	float current_time{0};
		//�m�[�c�̗���郌�[����
	int lane_num{ 4 };
	//1���[��������̓��������\�m�[�c��
	int notes_num{ 40 };
	//�m�[�c�̗����X�s�[�h

	int* key;

	float judgeLine_pos_y{ 600.0f };
	int offset_s{ 3 };

	bool one_{ false };
	int soundHandl;

};