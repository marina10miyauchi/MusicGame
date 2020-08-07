#include "TitleScene.h"
#include"Scene.h"
#include"Key.h"
#include"KeyConst.h"
#include<DxLib.h>
#include"Text.h"
#include"ColorConst.h"
#include"Graphics2D.h"
#include"Assets.h"
#include"Sound.h"
#include"MusicScore.h"


void TitleScene::Start()
{
	is_end_ = false;

	//テクスチャ
	Graphics2D::LoadSprite(TextureID::TitleBackGround, "Assets/Texture/background.png");
	Graphics2D::LoadSprite(TextureID::Notes_ID, "Assets/Texture/Notes.png");
	Graphics2D::LoadSprite(TextureID::Button_Select, "Assets/Texture/button_on.png");
	Graphics2D::LoadSprite(TextureID::Button_NoSelect, "Assets/Texture/button_off.png");
	Graphics2D::LoadSprite(TextureID::JacketPhoto_, "Assets/Texture/button_off.png");

	//音
	Sound::LoadSE(MusicDataID::Music_01, "Assets/Sound/Amethyst_8bit_20190620.wav");
	Sound::LoadSE(SoundId::Click, "Assets/Sound/cursor2.wav");

	//譜面データ
	MusicScore::LoadMusicScore(MusicDataID::Music_01, "Assets/text/test.txt");
	MusicScore::LoadMusicScore(MusicDataID::Music_02, "Assets/text/test.txt");
	MusicScore::LoadMusicScore(MusicDataID::Music_03, "Assets/text/test.txt");
	MusicScore::LoadMusicScore(MusicDataID::Music_04, "Assets/text/test.txt");
	MusicScore::LoadMusicScore(MusicDataID::Music_05, "Assets/text/test.txt");
	MusicScore::LoadMusicScore(MusicDataID::Music_06, "Assets/text/test.txt");

}

void TitleScene::Update(float delta_time)
{
	if (Key::Trigger(keyConst::Space)) {
		Sound::PlaySE(SoundId::Click);
		is_end_ = true;
	}
}


void TitleScene::Draw() const
{
	Graphics2D::ScreenSizeDrawSprite(TextureID::TitleBackGround);

	Text::DrawStringText(Vec2Pos{ 450,350 }, "タイトル画面", ColorConst::Red);
	Text::DrawStringText(Vec2Pos{ 420,500 }, "Push SpasebButton");
}

bool TitleScene::Is_End() const
{
	return is_end_;
}

Scene TitleScene::Next() const
{
	return Scene::Select;
}

void TitleScene::End() {}
