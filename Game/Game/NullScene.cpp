#include "NullScene.h"
#include"Scene.h"

void NullScene::Start(){}

void NullScene::Update(float delta_time){}

void NullScene::Draw() const{}

bool NullScene::Is_End() const
{
	return false;
}

Scene NullScene::Next() const
{
	return Scene::None;
}

void NullScene::End(){}
