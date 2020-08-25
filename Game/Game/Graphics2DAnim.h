#pragma once

#include"Vector2.h"
#include"AnimatedSprite.h"
#include<string>
#include<unordered_map>

class Graphics2DAnim {
public:
	static void Initialize();
	static void LoadSprite(int id, const std::string& fileName, int row, int colum);

	static void DrawSprite(int id, const Vector2& pos, int x, int y, int w, int h);
	static void DrawSprite(int id, int divNo, const Vector2& pos, const Vector2& center, const Vector2& scale, float rotate = 0.0f);
	static void DrawSprite(int id, int anim, float time, const Vector2& pos, const Vector2& center, const Vector2& scale, float rotate = 0.0f);

	static void AddSpriteAnim(int id, int anim, int start, int end, float time);
	static void AddSpriteKeyFrame(int id, int anim, float time, int divNo);
	static void AddSpriteKeyFrame(int id, int anim, float time, int x, int y, int w, int h);

	static void DeleteSprite(int id);
	static void GetSpriteAnimEndTime(int id, int anim);
	static void Finalize();

private:
	static std::unordered_map<int, AnimatedSprite>sprite_anim_map_;
};