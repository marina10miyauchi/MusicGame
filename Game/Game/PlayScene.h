#pragma once
#include"IScene.h"
#include"NotesCount.h"
#include"NotesManager.h"
#include"Line.h"

class  PlayScene :public IScene
{
public:
	PlayScene() = default;
	// IScene を介して継承されました
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };

	NotesManager* notes_manager_;
	Line* line_;

	//test
	LONGLONG start_count{ 0 };

	float current_time{ 0 };
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