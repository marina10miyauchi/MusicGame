#pragma once

#include"IScenePtr.h"
#include<unordered_map>

enum class Scene;

class SceneManager {
public:

	SceneManager();
	//初期化
	void Initialize();
	//更新
	void Update(float delta_time);
	//描画
	void Draw()const;
	//終了
	void End();
	//シーンの追加
	void Add(Scene name, const IScenePtr& scene);
	//シーン変更
	void Change(Scene name);
	//コピー禁止
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator=(const SceneManager& other) = delete;

private:
	//シーン保存先
	std::unordered_map<Scene, IScenePtr> scenes_;
	//現在のシーン
	IScenePtr current_scene;
};