#include "SelectScene.h"
#include"Scene.h"

void SelectScene::Start()
{
}

void SelectScene::Update(float delta_time)
{
}

void SelectScene::Draw() const
{
}

bool SelectScene::Is_End() const
{
	return is_end_;
}

Scene SelectScene::Next() const
{
	return Scene::Select;
}

void SelectScene::End()
{
}
