#pragma once

#include"Vector2.h"
#include<string>
#include<unordered_map>

class Graphics2D {
public:
	static void Initialize();
	static void LoadSprite(int id, const std::string& fileName);
	static void DrawSprite(int id, const Vector2& pos);
	static void DrawSprite(int id, const Vector2& pos, const Vector2& scale);
	static void ScreenSizeDrawSprite(int id);
	static void DrawSprite(int id, const Vector2& pos, int x, int y, int w, int h);

	static void DeleteSprite(int id);
	static void ClearColor(float r, float g, float b);
	static void Finalize();

private:

private:
	static std::unordered_map<int, int> spritemap_;
	static int screenSize_x;
	static int screenSize_y;
};