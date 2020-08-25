#pragma once
#include"IScene.h"
#include"SelectFrame.h"
#include<unordered_map>
#include"Scene.h"
#include"CyberCircle.h"


class SelectScene :public IScene
{
public:
	SelectScene() = default;
	// IScene ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Start() override;

	virtual void Update(float delta_time) override;

	virtual void Draw() const override;

	virtual bool Is_End() const override;

	virtual Scene Next() const override;

	virtual void End() override;


private:
	void Init();


private:
	bool is_end_{ false };
	static std::unordered_map<int, Scene> selectScene_;

	SelectFrame* selectFramw_;

	CyberCircle* circle_;
};