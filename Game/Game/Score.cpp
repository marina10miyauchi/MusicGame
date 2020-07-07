#include "Score.h"
#include<algorithm>



Score::Score(int score) :score_{ score } {}

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
	
}

int Score::Get() const
{
	return score_;
}
