#include "SelectScene.h"
#include"Graphics2D.h"
#include"Assets.h"
#include"Text.h"
#include"Key.h"
#include"KeyConst.h"

std::unordered_map<int, Scene> SelectScene::selectScene_;

void SelectScene::Start()
{
	is_end_ = false;
	selectFramw_->Initialize();
}

void SelectScene::Update(float delta_time)
{
	selectFramw_->Updata();
	if (Key::Trigger(keyConst::Space)) {
		is_end_ = true;
	}
}

void SelectScene::Draw() const
{
	//ボタン表示　
	selectFramw_->Draw();
}

bool SelectScene::Is_End() const
{
	return is_end_;
}

Scene SelectScene::Next() const
{
	return Scene::Play;
}

void SelectScene::End()
{
}

void SelectScene::Init()
{
	
}
