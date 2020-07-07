#pragma once

enum class Scene;

class IScene {
public:
	virtual ~IScene(){}
	//開始
	virtual void Start() = 0;
	//更新
	virtual void Update(float delta_time) = 0;
	//描画
	virtual void Draw()const = 0;
	//終了しているか
	virtual bool Is_End()const = 0;
	//次のシーンを返却
	virtual Scene Next()const = 0;
	//終了
	virtual void End() = 0;
};
