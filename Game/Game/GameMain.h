#pragma once
#include"Game.h"
#include"SceneManager.h"
#include"Time.h"
#include"NotesCount.h"
#include"NotesManager.h"
#include"GameData.h"


class GameMain :public Game {
public:
	GameMain() :Game(WINDOW_WIDTH, WINDOW_HIGHT, false) {}
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

};