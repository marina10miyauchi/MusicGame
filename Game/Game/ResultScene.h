#pragma once
#include"IScene.h"
#include"NotesCount.h"
#include"NotesManager.h"
#include"Line.h"

#include"NotesTest.h"

enum ResultButton {
	End,
	ReStart,
	Select,
};

class  ResultScene :public IScene
{
public:
	ResultScene() = default;
	// IScene ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };

	int select_button_num;
};