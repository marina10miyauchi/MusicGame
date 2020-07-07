#pragma once
#include<DxLib.h>
#include<string>
#include<list>
#include"Notes.h"
#include"KeyConst.h"


//����{�^���@
static const int KEYS[4] = {
	keyConst::Z,
	keyConst::X,
	keyConst::C,
	keyConst::V,
};

//�m�[�c�S�̂̊Ǘ��N���X
class NotesManager {
public:
	NotesManager(std::string fileName);
	~NotesManager();

	void Initialize();
	void Update(float judgeLinePosY,float currentTime);
	//�m�[�c�̔���
	void JudgeNotes(float currentTime);
	//�{�^���������ꂽ���̔���

	void Draw();

private:
	bool PushKey(char key);
	bool CheckKey();
	//���ʃf�[�^�擾
	void MusicScoreLoad();




private:
	//���ʃf�[�^�̃t�@�C����
	std::string file_name_;

	int rane_{ 4 };
	int max_notes_{ 1000 };
	int notes_count_[4];
	float good_judge_{ 0.05f };

	
	NotesDate notes_data_[4][1000];

	Notes* _notes_;
	
	std::list<Notes> notes_;


	//
	int seHandle;

};