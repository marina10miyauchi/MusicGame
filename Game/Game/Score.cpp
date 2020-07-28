#include "Score.h"
#include<algorithm>
#include"Text.h"

#undef min
#undef max

int Score::score_{ 0 };


void Score::Initialize(int score)
{
	score_ = score;
}

void Score::Add(int score)
{
	score_ = std::min(score_ + score, 9999999);
}

void Score::Draw() const
{
	Text::DrawStringText(Vec2Pos{ 0,40 }, std::to_string(score_));
}

int Score::Get() const
{
	return score_;
}
