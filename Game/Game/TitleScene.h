#pragma once
#include"IScene.h"
#include"CyberCircle.h"

class TitleScene :public IScene {
public:
	TitleScene() = default;
	// IScene ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };
	float rotate_{ 0 };

	CyberCircle* circle_;
	CyberCircle* circle_2;
	CyberCircle* circle_3;

};
