#include "PlayScene.h"
#include"Scene.h"
#include"Sound.h"
#include"ColorConst.h"
#include"Assets.h"
#include"Text.h"
#include"GameData.h"

#include<list>
#include<DxLib.h>

void PlayScene::Start()
{
	is_end_ = false;
	notes_test_ = new NotesTest("Assets/text/test.txt");

	line_ = new Line();

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
	notes_test_->Update(JUDGE_LINE_Y, current_time);

	is_end_ = notes_test_->IsNotesEnd();
}

void PlayScene::Draw() const
{
	////ƒeƒXƒg•`‰æ
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
	return Scene::Result;
}

void PlayScene::End() {}
