#include "ResultScene.h"
#include"Text.h"
#include"Key.h"
#include"KeyConst.h"
#include"Scene.h"
#include"ColorConst.h"

unsigned int ResultScene::color_[(int)ResultButton::Max_Button];


void ResultScene::Start()
{
	select_button_num = 0;
}

void ResultScene::Update(float delta_time)
{
	for (int i = 0; i < (int)ResultButton::Max_Button; i++)
	{
		if (select_button_num == i)
			color_[i] = ColorConst::Red;
		else
			color_[i] = ColorConst::White;
	}
	if (Key::Trigger(keyConst::Space)) {
		switch (select_button_num)
		{
		case (int)ResultButton::End:		nextScene = Scene::End;		 break;
		case (int)ResultButton::ReStart:	nextScene = Scene::Play;	 break;
		case (int)ResultButton::Select:		nextScene = Scene::Title;	 break;
		default:break;
		}
		is_end_ = true;
	}
	if (Key::Trigger(keyConst::Down)) {
		select_button_num++;
		if (select_button_num >= (int)ResultButton::Max_Button)
			select_button_num = (int)ResultButton::End;
	}
	if (Key::Trigger(keyConst::Up)) {
		select_button_num--;
		if (select_button_num <= -1)
			select_button_num = (int)ResultButton::Select;
	}
}

void ResultScene::Draw() const
{
	Text::DrawStringText({ 0,0 }, std::to_string(score_->Get()));

	Text::DrawStringText({ 400, 0 }, "GameEnd", color_[(int)ResultButton::End]);
	Text::DrawStringText({ 400,30 }, "ReStart", color_[(int)ResultButton::ReStart]);
	Text::DrawStringText({ 400,60 }, "Select",  color_[(int)ResultButton::Select]);

}

bool ResultScene::Is_End() const
{
	return is_end_;
}

Scene ResultScene::Next() const
{
	return nextScene;
}

void ResultScene::End()
{
}
