#pragma once
#include<DxLib.h>
#include<string>
#include<list>
#include<vector>
#include"Notes.h"
#include"KeyConst.h"

#include"Line.h"
#include"Score.h"
#include"JudgeEffect.h"



class NotesTest {
public:
	NotesTest(std::string fileName);
	~NotesTest();

	void Initialize();
	void Update(float judgeLinePosY, float currentTime);
	//�m�[�c�̔���
	void JudgeNotes(float currentTime);
	//�{�^���������ꂽ���̔���

	void Draw();

	bool IsNotesEnd();

private:
	void NotesPushAct(NotesDate& notes_, int addScore);
	//���ʃf�[�^�擾
	void MusicScoreLoad();
	bool Judge(NotesDate notes_, float judge_timing, float current_time_);
	void Conbo(NotesDate);
	void Effect(int line);

private:
	//���ʃf�[�^�̃t�@�C����
	std::string file_name_;
	//NotesDate notes_datas_[1000];
	std::vector<NotesDate> notes_data_;

	Notes* _notes_;
	Line* line_;
	Score* score_;
	//std::list<Notes> notes_;

	float prefect_timing_{ 0.05f };
	float good_timing_{ 0.1f };

	int prefect_point{ 50 };
	int good_point{ 10 };

	float judge_{ false };
};