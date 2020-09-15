#include "PlayScene.h"
#include"Scene.h"
#include"Sound.h"
#include"ColorConst.h"
#include"Assets.h"
#include"Text.h"
#include"GameData.h"
#include"MusicScore.h"

#include"Assets.h"

#include<list>
#include<DxLib.h>
#include"Graphics2D.h"

int test;

void PlayScene::Start()
{
	is_end_ = false;
	////test = MusicDataID::Music_01;
	notes_test_ = new NotesTest(MusicScore::GetMusicData());

	line_ = new Line();
	Vector2 effectPos(LEFT_EDGE_X + LANE_BETWEEN * 0.5f, JUDGE_LINE_Y);
	for (int i = 0; i < 4; i++)
	{
		effectPos.x += i;
		judge_effect_[i] = new JudgeEffect(effectPos);
	}


	start_count = GetNowHiPerformanceCount();

}

void PlayScene::Update(float delta_time)
{
	LONGLONG now_count = GetNowHiPerformanceCount();
	//•b’PˆÊ‚É•ÏŠ·
	current_time = (now_count - start_count) / 1000000.0;
	current_time -= offset_s;

	if (current_time >= 0) {
		if (!one_) {
			Sound::PlaySE(MusicDataID::Music_01);
			one_ = true;
		}
	}
	notes_test_->Update(JUDGE_LINE_Y, current_time);

	is_end_ = notes_test_->IsNotesEnd();
	for (auto* effect : judge_effect_) {
		effect->Update(delta_time);
	}

}

void PlayScene::Draw() const
{
	//SetDrawBlendMode(DX_BLENDMODE_INVSRC, 256);
	//Graphics2D::ScreenSizeDrawSprite(TextureID::TitleBackGround);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	
	//Graphics2D::ClearColor(0, 0.3f, 0.3f);
	////ƒeƒXƒg•`‰æ
	notes_test_->Draw();
	line_->Draw();
	Text::DrawStringText(Vec2Pos{ 0,0 }, std::to_string(current_time), ColorConst::Red);

	for (int i = 0; i < 4; i++)
	{
		judge_effect_[i]->Draw();
	}
	//for (auto* effect : judge_effect_) {
	//	effect->Draw();
	//}
}

bool PlayScene::Is_End() const
{
	return is_end_;
}

Scene PlayScene::Next() const
{
	return Scene::Result;
}

void PlayScene::End() {}
