#pragma once
#include"IScene.h"
#include"NotesCount.h"
#include"NotesManager.h"
#include"Line.h"

#include"JudgeEffect.h"
#include"NotesTest.h"

class  PlayScene :public IScene
{
public:
	//PlayScene() = default;
	PlayScene() = default;
	// IScene ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };

	NotesManager* notes_manager_;
	NotesTest* notes_test_;
	Line* line_;
	JudgeEffect* judge_effect_[4];

	//test
	LONGLONG start_count{ 0 };

	float current_time{ 0 };

	int offset_s{ 3 };

	bool one_{ false };
	int soundHandl;

};