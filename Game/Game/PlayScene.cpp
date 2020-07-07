#include "PlayScene.h"
#include"Sound.h"
#include"SoundID.h"

#include<list>
#include<DxLib.h>

void PlayScene::Start()
{
	notes_manager_ = new NotesManager("text/Amethyst_8bit_.txt");

	line_ = new Line(judgeLine_pos_y);
	line_->Intialize();

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


	notes_manager_->Update(judgeLine_pos_y, current_time);

	////test


}

void PlayScene::Draw() const
{
	////ƒeƒXƒg•`‰æ
	notes_manager_->Draw();
	line_->Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", current_time);

}

bool PlayScene::Is_End() const
{
	return is_end_;
}

Scene PlayScene::Next() const
{
	return Scene();
}

void PlayScene::End() {}
