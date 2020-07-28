#pragma once
#include<DxLib.h>
#include<string>
#include<list>
#include"Notes.h"
#include"KeyConst.h"

#include"Line.h"
#include"Score.h"


//enum TimingJudge {
//	Prefect,
//	Good,
//	Miss,
//};

//ノーツ全体の管理クラス
class NotesManager {
public:
	NotesManager(std::string fileName);
	~NotesManager();

	void Initialize();
	void Update(float judgeLinePosY, float currentTime);
	//ノーツの判定
	void JudgeNotes(float currentTime);
	//ボタンを押されたかの判定

	void Draw();

	//bool IsNotesEnd();

private:
	void NotesPushAct(int lane, int num);
	//譜面データ取得
	void MusicScoreLoad();


private:
	//譜面データのファイル名
	std::string file_name_;

	int max_notes_{ 1000 };
	int notes_count_[4];
	float prefect_timing_{ 0.05f };
	float good_timing_{ 0.1f };

	float click_timing_[4] = { 0,0,0,0 };


	NotesDate notes_data_[4][1000];

	Notes* _notes_;
	Line* line_;
	Score* score_;
	std::list<Notes> notes_;

	//
	int seHandle;

};