#pragma once

#include"IScene.h"
class NullScene :public IScene {
public:
	//開始処理
	virtual void Start()override;
	//更新
	virtual void Update(float delta_time)override;
	//描画
	virtual void Draw()const override;
	//終了か
	virtual bool Is_End()const override;
	//次のシーンへ
	virtual Scene Next()const override;
	//終了
	virtual void End()override;
};