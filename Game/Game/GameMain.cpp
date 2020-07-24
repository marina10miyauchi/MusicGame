#include "GameMain.h"
#include"Scene.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include"ResultScene.h"
#include<list>
#include<DxLib.h>


LONGLONG start_count{ 0 };
std::list<Notes> note_;

void GameMain::Start()
{
	////シーンの追加
	////
	scene_manager.Add(Scene::Title, new_Scene<TitleScene>());
	scene_manager.Add(Scene::Play, new_Scene<PlayScene>());
	scene_manager.Add(Scene::Result, new_Scene<ResultScene>());
	scene_manager.Change(Scene::Title);

	//カラー設定
}

void GameMain::Update(float delta_time)
{
	scene_manager.Update(delta_time);
}

void GameMain::Draw()
{
	scene_manager.Draw();

}

void GameMain::End()
{
	scene_manager.End();
}
