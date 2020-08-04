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

};