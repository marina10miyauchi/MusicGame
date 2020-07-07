#pragma once
#include"IScene.h"

class TitleScene :public IScene {
public:
	TitleScene() = default;
	// IScene ����Čp������܂���
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;

private:
	bool is_end_{ false };

};
