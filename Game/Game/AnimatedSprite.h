#pragma once

#include<unordered_map>
#include<vector>
#include"Vector2.h"

class AnimatedSprite {
public:
	//コンストラクタ
	AnimatedSprite() = default;
	//デストラクタ
	~AnimatedSprite();
	//画像ファイル読み込み
	void Load(const std::string& fileName);
	//画像ファイル読み込み
	void Load(const std::string& fileName, int row, int column);
	//描画（画像全体）
	void Draw(const Vector2& position)const;
	//描画（）
	void Draw(const Vector2& position, int x, int y, int w, int h)const;
	//描画（）
	void Draw(int no, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;
	//描画（）
	void Draw(int animation, int time, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;
	//アニメーション追加
	void AddAnimation(int animation, int start, int end, float time);
	//キーフレームを追加
	void AddKeyFrame(int animation, float time, int graph_no);
	//キーフレームを追加
	void AddKeyFrame(int animation, float time, int x, int y, int w, int h);
	//アニメーション終了時間を取得
	float AnimationEndTime(int animation)const;
	//消去
	void Clear();
	//コピー禁止
	AnimatedSprite(const AnimatedSprite& other) = delete;
	AnimatedSprite& operator=(const AnimatedSprite& other) = delete;
private:
	//分割画像
	using DivGraphs = std::vector<int>;
	//キーフレーム
	using KeyFrame = std::pair<float, int >;
	//キーフレーム配列
	using KeyFrames = std::vector<KeyFrame>;
	//アニメーション配列
	using Animations = std::unordered_map<int, KeyFrames>;

private:
	//キーフレーム検索
	const KeyFrame& FindKeyFrame(int animation, float time)const;

private:
	//元画像
	int graph_{ -1 };
	//分割画像
	DivGraphs div_graphs_;
	//アニメーションデータ
	Animations animations_;

};