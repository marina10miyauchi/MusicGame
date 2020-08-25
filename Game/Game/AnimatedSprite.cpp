#include "AnimatedSprite.h"
#include"MathHelper.h"
#include<cmath>
#include<DxLib.h>

AnimatedSprite::~AnimatedSprite()
{
	Clear();
}

void AnimatedSprite::Load(const std::string & fileName)
{
	Clear();
	graph_ = LoadGraph(fileName.c_str());

}

void AnimatedSprite::Load(const std::string & fileName, int row, int column)
{
	Load(fileName);

	int size_x = 0, size_y = 0;
	GetGraphSize(graph_, &size_x, &size_y);

	int w = size_x / column;
	int h = size_y / row;
	for (int y = 0; y < size_y; y += h)
	{
		for (int x = 0; x < size_x; x += w)
		{
			div_graphs_.push_back(DerivationGraph(x, y, w, h, graph_));
		}
	}

}

void AnimatedSprite::Draw(const Vector2 & position) const
{
	DrawGraphF(position.x, position.y, graph_, TRUE);
}

void AnimatedSprite::Draw(const Vector2 & position, int x, int y, int w, int h) const
{
	DrawRectGraphF(position.x, position.y, x, y, w, h, graph_, TRUE, FALSE);
}

void AnimatedSprite::Draw(int no, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float rotation) const
{
	DrawRotaGraph3F(position.x, position.y, center.x, center.y, scale.x, scale.y, MathHelper::ToRadians(rotation), div_graphs_[no], TRUE);
}

void AnimatedSprite::Draw(int animation, int time, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float rotation) const
{
	Draw(FindKeyFrame(animation, time).second, position, center, scale, rotation);
}

void AnimatedSprite::AddAnimation(int animation, int start, int end, float time)
{
	animations_[animation].clear();
	for (int frame = 0; frame < (end - start); frame++)
	{
		AddKeyFrame(animation, (frame + 1)*time, start + frame);
	}
}

void AnimatedSprite::AddKeyFrame(int animation, float time, int graph_no)
{
	animations_[animation].emplace_back(time, graph_no);
}

void AnimatedSprite::AddKeyFrame(int animation, float time, int x, int y, int w, int h)
{
	div_graphs_.push_back(DerivationGraph(x, y, w, h, graph_));
	AddKeyFrame(animation, time, int(div_graphs_.size()) - 1);
}

float AnimatedSprite::AnimationEndTime(int animation) const
{
	return animations_.at(animation).back().first;
}

void AnimatedSprite::Clear()
{
	if (graph_ = -1) {
		DeleteSharingGraph(graph_);
		graph_ = -1;
		div_graphs_.clear();
	}
	animations_.clear();

}

const AnimatedSprite::KeyFrame & AnimatedSprite::FindKeyFrame(int animation, float timer)const {
	const auto& key_frames = animations_.at(animation);
	timer = fmod(timer, AnimationEndTime(animation) + 1.0f);
	for (const auto& key_frame : key_frames) {
		if (timer <= key_frame.first) {
			return key_frame;
		}
	}
	return key_frames.back();
}