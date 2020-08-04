#pragma once
#include"IScene.h"



class SelectScene:public IScene
{
public:
	SelectScene() = default;
	// IScene ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;



private:
	bool is_end_{ false };

};