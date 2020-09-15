#include "ResultScene.h"
#include"Text.h"
#include"Key.h"
#include"KeyConst.h"
#include"Scene.h"
#include"ColorConst.h"
#include"Assets.h"

unsigned int ResultScene::color_[(int)ResultButton::Max_Button];


void ResultScene::Start()
{
	is_end_ = false;
	select_button_num = 0;
	circle_= new CyberCircle(TextureID::Circle_1, Vector2(100,450), Vector2(0.25f, 0.25f), 1);
}

void ResultScene::Update(float delta_time)
{
	circle_->Update(delta_time);
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
		case (int)ResultButton::Select:		nextScene = Scene::Select;	 break;
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
	Graphics2D::ScreenSizeDrawSprite(TextureID::ResultBackGround);
	Graphics2D::DrawSprite(TextureID::ResultFrame, Vector2(400, 0));
	circle_->Draw();
	Text::DrawStringText({ 500,50 }, "Score",50);
	Text::DrawStringText({ 600,50 }, std::to_string(score_->Get()),60);
	Text::DrawStringText({ 500,100 }, "HighScore", 50);
	Text::DrawStringText({ 600,100 }, std::to_string(score_->Get()), 60);

	Text::DrawStringText({ 500,200 }, "Perfect");
	Text::DrawStringText({ 500,250 }, "Good");
	Text::DrawStringText({ 500,300 }, "Miss");


	Text::DrawStringText({ 600,200 }, "MaxComb", 50);
	Text::DrawStringText({ 520,250 }, "0", 100);


	Text::DrawStringText({ 550,250 }, "GameEnd", color_[(int)ResultButton::End]);
	Text::DrawStringText({ 600,250 }, "ReStart", color_[(int)ResultButton::ReStart]);
	Text::DrawStringText({ 750,250 }, "Select",  color_[(int)ResultButton::Select]);

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
