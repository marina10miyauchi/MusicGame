#include "GameMain.h"
#include"Scene.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include"ResultScene.h"
#include"SelectScene.h"
#include<list>
#include<DxLib.h>


void GameMain::Start()
{
	////ÉVÅ[ÉìÇÃí«â¡////

	scene_manager.Add(Scene::Title, new_Scene<TitleScene>());
	scene_manager.Add(Scene::Select, new_Scene<SelectScene>());
	scene_manager.Add(Scene::Play, new_Scene<PlayScene>());
	scene_manager.Add(Scene::Result, new_Scene<ResultScene>());
	scene_manager.Change(Scene::Title);

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
