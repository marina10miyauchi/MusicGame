#include "SelectFrame.h"
#include"Graphics2D.h"
#include"Assets.h"
#include"Key.h"
#include"KeyConst.h"
#include"Text.h"
#include"MusicScore.h"

std::string SelectFrame::music_name_;
int SelectFrame::texture_ID_;
int SelectFrame::hight_score_;


int SelectFrame::select_button_num;
int SelectFrame::button_texture_ID_[6];
int SelectFrame::jacket_phote[6];
std::string  SelectFrame::titles[6];


void SelectFrame::Initialize()
{
	select_button_num = 0;
	for (auto& texture : button_texture_ID_)
	{
		texture = TextureID::Button_NoSelect;
	}
	for (int i = 0; i < 6; i++)
	{
		titles[i] = std::to_string(i) + "MusicData";
		jacket_phote[i] = TextureID::JacketPhoto_;
	}
}

void SelectFrame::Updata()
{
	Select();
	int num = 100 + select_button_num;
	MusicScore::SetMusicScore(num);
}

void SelectFrame::Draw()
{
	Graphics2D::DrawSprite(texture_ID_, Vector2{ 100,100 }, Vector2{ 6,6 });
	//テスト　タイトル　スコア
	Text::DrawStringText(Vec2Pos{ 150,500 }, music_name_, 64);
	Text::DrawStringText(Vec2Pos{ 100,570 }, "HightScore : ");


	ButtonDraw();

}

int SelectFrame::SelectNum()
{
	return select_button_num;
}

void SelectFrame::Select()
{
	if (Key::Trigger(keyConst::Down)) {
		select_button_num++;
		if (select_button_num >= 6)
			select_button_num = 0;
	}
	if (Key::Trigger(keyConst::Up)) {
		select_button_num--;
		if (select_button_num <= -1)
			select_button_num = 5;
	}

	for (int i = 0; i < 6; i++)
	{
		if (select_button_num == i) {
			button_texture_ID_[i] = TextureID::Button_Select;
			texture_ID_ = jacket_phote[i];
			music_name_ = titles[i];
		}
		else {
			button_texture_ID_[i] = TextureID::Button_NoSelect;
		}
	}
}

void SelectFrame::ButtonDraw()
{
	Graphics2D::DrawSprite(button_texture_ID_[0], Vector2{ 600,0 }, Vector2{ 6.25,2 });
	Graphics2D::DrawSprite(button_texture_ID_[1], Vector2{ 600,128 }, Vector2{ 6.25,2 });
	Graphics2D::DrawSprite(button_texture_ID_[2], Vector2{ 600,256 }, Vector2{ 6.25,2 });
	Graphics2D::DrawSprite(button_texture_ID_[3], Vector2{ 600,384 }, Vector2{ 6.25,2 });
	Graphics2D::DrawSprite(button_texture_ID_[4], Vector2{ 600,512 }, Vector2{ 6.25,2 });
	Graphics2D::DrawSprite(button_texture_ID_[5], Vector2{ 600,640 }, Vector2{ 6.25,2 });
}
