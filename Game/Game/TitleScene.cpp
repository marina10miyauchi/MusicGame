#include "TitleScene.h"
#include"Scene.h"
#include"Key.h"
#include"KeyConst.h"
#include<DxLib.h>
#include"Text.h"
#include"ColorConst.h"
#include"PadConst.h"
#include"Mouse.h"

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

	Text::DrawStringText(Vec2Pos{ 450,350 }, "ƒ^ƒCƒgƒ‹‰æ–Ê", ColorConst::Red);
	Text::DrawStringText(Vec2Pos{ 420,500 }, "Push SpasebButton");
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
