#pragma once
#include"Game.h"
#include"SceneManager.h"
#include"Time.h"
#include"NotesCount.h"
#include"NotesManager.h"


#define WIN_W 800 // ウインドウの横幅
#define WIN_H 600 // ウインドウの縦幅
#define LANE_NUM 4 // レーンの数
#define NOTE_NUM 1000 // ノーツの最大数
#define NOTE_WIDTH 72 // ノーツの幅
#define NOTE_HEIGHT 20 // ノーツの高さ
#define JUDGE_Y 500 // 判定ラインのY座標


class GameMain :public Game {
public:
	GameMain() :Game(1000, 750, false) {}
private:
	//開始
	virtual void Start() override;
	//更新
	virtual void Update(float delta_time)override;
	//描画
	virtual void Draw()override;
	//終了
	virtual void End()override;

private:

private:
	SceneManager scene_manager;
	NotesManager* notes_manager_;

	//test
	float current_time{0};
		//ノーツの流れるレーン数
	int lane_num{ 4 };
	//1レーン当たりの同時生成可能ノーツ数
	int notes_num{ 40 };
	//ノーツの落下スピード

	int* key;

	float judgeLine_pos_y{ 600.0f };
	int offset_s{ 3 };

	bool one_{ false };
	int soundHandl;

};