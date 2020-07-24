#include "PlayScene.h"
#include"Scene.h"
#include"Sound.h"
#include"SoundID.h"
#include"ColorConst.h"
#include"Text.h"

#include<list>
#include<DxLib.h>

void PlayScene::Start()
{
	notes_manager_ = new NotesManager("text/Amethyst_8bit_.txt");
	notes_test_ = new NotesTest("text/test.txt");

	line_ = new Line(judgeLine_pos_y);

	//‰¹‚ÌÄ¶
	Sound::LoadSE(SoundId::Music_1, "Sound/Amethyst_8bit_20190620.wav");
	Sound::LoadSE(SoundId::Click, "Sound/cursor2.wav");
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
			Sound::PlaySE(SoundId::Music_1);
			one_ = true;
		}
	}
	//notes_manager_->Update(judgeLine_pos_y, current_time);
	notes_test_->Update(judgeLine_pos_y, current_time);

	is_end_ = notes_test_->IsNotesEnd();

}

void PlayScene::Draw() const
{
	////ƒeƒXƒg•`‰æ
	//notes_manager_->Draw();
	notes_test_->Draw();
	line_->Draw();
	Text::DrawStringText(Vec2Pos{ 0,0 }, std::to_string(current_time), ColorConst::Red);
}

bool PlayScene::Is_End() const
{
	return is_end_;
}

Scene PlayScene::Next() const
{
	Sound::StopBGM();
	return Scene::Result;
}

void PlayScene::End() {}
