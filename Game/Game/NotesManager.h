#pragma once
#include<DxLib.h>
#include<string>
#include<list>
#include"Notes.h"
#include"KeyConst.h"

#include"Line.h"


//判定ボタン　
static const int KEYS_[Lane::Max] = {
	keyConst::Z,
	keyConst::X,
	keyConst::C,
	keyConst::V,
};

//ノーツ全体の管理クラス
class NotesManager {
public:
	NotesManager(std::string fileName);
	~NotesManager();

	void Initialize();
	void Update(float judgeLinePosY,float currentTime);
	//ノーツの判定
	void JudgeNotes(float currentTime);
	//ボタンを押されたかの判定

	void Draw();

private:
	void PushAction(int lane);
	bool PushKey(char key);
	bool CheckKey();
	//譜面データ取得
	void MusicScoreLoad();




private:
	//譜面データのファイル名
	std::string file_name_;

	int max_notes_{ 1000 };
	int notes_count_[4];
	float good_judge_{ 0.05f };

	
	NotesDate notes_data_[4][1000];

	Notes* _notes_;
	Line* line_;
	std::list<Notes> notes_;

	//
	int seHandle;

};