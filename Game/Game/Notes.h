#pragma once
#include<functional>

struct NotesDate
{
	//
	bool frag;
	//pos_x
	float x;
	//pos_y
	float y;
	//ノーツの判定ライン到達カウント
	float timing;
};

//降ってくるノーツの管理クラス（単体）
class Notes {
public:
	Notes() = default;
	~Notes();
	//ノーツ初期化
	void Initialize(NotesDate notes, int lane);

	//ノーツの更新
	void UpDate(float judgeLinePosY,float currentTime,NotesDate& notes );
	//ノーツの描画
	void Draw(NotesDate& notes);

private:
	void Each(std::function<void(bool)> action);
	void KeySet();

private:
	NotesDate notes_date[4][40];
	//ノーツの流れるレーン数
	int lane_num{ 4 };
	//1レーン当たりの同時生成可能ノーツ数
	int notes_num{ 40 };
	//ノーツの落下スピード
	float notes_speed{ 3.0f };

	int bpm_{ 120 };

	//
	int* key;

	float judgeline_y{ 600.0f };
};