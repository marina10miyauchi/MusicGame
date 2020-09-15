#pragma once
#include"IScene.h"
#include"NotesCount.h"
#include"Score.h"
#include"CyberCircle.h"

#include"NotesTest.h"

enum ResultButton {
	End,
	ReStart,
	Select,
	Max_Button
};

class  ResultScene :public IScene
{
public:
	ResultScene() = default;
	// IScene ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };
	CyberCircle* circle_;
	Score* score_;
	Scene nextScene;
	int select_button_num;

	static unsigned int color_[(int)ResultButton::Max_Button];

};