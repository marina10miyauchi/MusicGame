#include "Graphics2D.h"
#include<DxLib.h>

std::unordered_map<int, int>Graphics2D::spritemap_;
int Graphics2D::screenSize_x;
int Graphics2D::screenSize_y;

void Graphics2D::Initialize()
{
	spritemap_.clear();
	GetWindowSize(&screenSize_x, &screenSize_y);
}

void Graphics2D::LoadSprite(int id, const std::string & fileName)
{
	spritemap_[id] = LoadGraph(fileName.c_str());
}

void Graphics2D::DrawSprite(int id, const Vector2 & pos)
{
	DrawGraphF(pos.x, pos.y, spritemap_[id], TRUE);
}

void Graphics2D::DrawSprite(int id, const Vector2 & pos, const Vector2 & scale)
{
	int sprite_x, sprite_y = 0;
	GetGraphSize(spritemap_[id], &sprite_x, &sprite_y);
	float scalingPos_x = pos.x + (sprite_x * scale.x);
	float scalingPos_y = pos.y + (sprite_y * scale.y);

	DrawExtendGraph(pos.x, pos.y, scalingPos_x, scalingPos_y, spritemap_[id], TRUE);

}

void Graphics2D::ScreenSizeDrawSprite(int id)
{
	int sprite_x, sprite_y = 0;
	GetGraphSize(spritemap_[id], &sprite_x, &sprite_y);
	DrawExtendGraph(0, 0, screenSize_x, screenSize_y, spritemap_[id], TRUE);

}

void Graphics2D::DrawSprite(int id, const Vector2 & pos, int x, int y, int w, int h)
{

	DrawRectGraphF(pos.x, pos.y, x, y, w, h, spritemap_[id], TRUE, FALSE);

}

void Graphics2D::DeleteSprite(int id)
{
	spritemap_.erase(id);
}

void Graphics2D::ClearColor(float r, float g, float b)
{
	SetBackgroundColor(int(r*255.0f), int(g*255.0f), int(b*255.0f));
}

void Graphics2D::Finalize()
{
	Initialize();
}