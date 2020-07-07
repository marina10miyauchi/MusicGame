#include "TitleScene.h"
#include"Scene.h"
#include"Key.h"
#include"KeyConst.h"
#include<DxLib.h>

void TitleScene::Start()
{
	is_end_ = false;
}

void TitleScene::Update(float delta_time)
{
	if (Key::Trigger(keyConst::Space))
		is_end_ = true;
}

void TitleScene::Draw() const
{
	DrawFormatString(450, 350, GetColor(255, 255, 255), "ƒ^ƒCƒgƒ‹‰æ–Ê");
	DrawFormatString(420, 500, GetColor(255, 255, 255), "Push SpasebButton");
}

bool TitleScene::Is_End() const
{
	return is_end_;
}

Scene TitleScene::Next() const
{
	return Scene::Play;
}

void TitleScene::End() {}
