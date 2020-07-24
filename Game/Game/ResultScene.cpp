#include "ResultScene.h"
#include"Text.h"

void ResultScene::Start()
{
}

void ResultScene::Update(float delta_time)
{
	
}

void ResultScene::Draw() const
{
	Text::DrawStringText({ 0,0 }, "Result");
}

bool ResultScene::Is_End() const
{
	return is_end_;
}

Scene ResultScene::Next() const
{
	return Scene();
}

void ResultScene::End()
{
}
