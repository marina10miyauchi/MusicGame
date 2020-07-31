//#pragma once
//
//#include<unordered_map>
//#include<vector>
//#include"Vector2.h"
//
//class AnimatedSprite {
//public:
//	AnimatedSprite() = default;
//	~AnimatedSprite();
//	void Load(const std::string& _fileName);
//	void Load(const std::string& _fileName, int _row, int _column);
//
//	void Draw(const Vector2& pos)const;
//	void Draw(const Vector2& pos, int x, int y, int w, int h)const;
//	void Draw(int num, const Vector2& pos, const Vector2& center, const Vector2& scale, float rotation)const;
//	void Draw(int anim,float time, const Vector2& pos, const Vector2& center, const Vector2& scale, float rotation)const;
//
//	void AddAnimation(int anim, int start, int end, float time);
//	void AddKeyFrame(int anim, float time, int x, int y, int w, int h);
//	void AddKeyFrame(int anim, float time, int graphNum);
//	float AnimationEndTime(int anim)const;
//
//	void Clear();
//
//
//
//	AnimatedSprite(const AnimatedSprite& other) = delete;
//	AnimatedSprite& operator=(const AnimatedSprite& other) = delete;
////private:
////	const KeyFrame& FindKetFrame(int animation, float timer)const;
//
//private:
//	//’è‹`
//	using GivGraphs = std::vector<float, int>;
//	using KeyFrame = std::pair<float, int>;
//	using KeyFrames = std::vector<int, KeyFrame>;
//	using Animations = std::unordered_map<int, KeyFrames>;
//
//private:
//	const KeyFrame& findKeyFrame_(int animation, float time)const;
//private:
//	int graph_{ -1 };
//	GivGraphs divGraphs_;
//	Animations animations_;
//};