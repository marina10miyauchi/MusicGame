#include "Graphics2DAnim.h"

std::unordered_map<int, AnimatedSprite> Graphics2DAnim::sprite_anim_map_;


void Graphics2DAnim::Initialize()
{
	sprite_anim_map_.clear();
}

void Graphics2DAnim::LoadSprite(int id, const std::string & fileName, int row, int colum)
{
	sprite_anim_map_[id].Load(fileName, row, colum);
}

void Graphics2DAnim::DrawSprite(int id, const Vector2 & pos, int x, int y, int w, int h)
{
	sprite_anim_map_[id].Draw(pos, x, y, w, h);
}

void Graphics2DAnim::DrawSprite(int id, int divNo, const Vector2 & pos, const Vector2 & center, const Vector2 & scale, float rotate)
{
	sprite_anim_map_[id].Draw(divNo, pos, center, scale, rotate);
}

void Graphics2DAnim::DrawSprite(int id, int anim, float time, const Vector2 & pos, const Vector2 & center, const Vector2 & scale, float rotate)
{
	sprite_anim_map_[id].Draw(anim, time, pos, center, scale, rotate);
}

void Graphics2DAnim::AddSpriteAnim(int id, int anim, int start, int end, float time)
{
	sprite_anim_map_[id].AddAnimation(anim, start, end, time);
}

void Graphics2DAnim::AddSpriteKeyFrame(int id, int anim, float time, int divNo)
{
	sprite_anim_map_[id].AddKeyFrame(anim, time, divNo);
}

void Graphics2DAnim::AddSpriteKeyFrame(int id, int anim, float time, int x, int y, int w, int h)
{
	sprite_anim_map_[id].AddKeyFrame(anim, time, x, y, w, h);
}

void Graphics2DAnim::DeleteSprite(int id)
{
	sprite_anim_map_[id].Clear();
}

void Graphics2DAnim::GetSpriteAnimEndTime(int id, int anim)
{
	sprite_anim_map_[id].AnimationEndTime(anim);
}

void Graphics2DAnim::Finalize()
{
	Initialize();
}
