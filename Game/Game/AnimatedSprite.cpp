//#include "AnimatedSprite.h"
//#include<cmath>
//#include<DxLib.h>
//
//AnimatedSprite::~AnimatedSprite()
//{
//	Clear();
//}
//
//void AnimatedSprite::Load(const std::string & _fileName)
//{
//	Clear();
//	graph_ = LoadGraph(_fileName.c_str());
//}
//
//void AnimatedSprite::Load(const std::string & _fileName, int _row, int _column)
//{
//	Load(_fileName);
//
//	int size_x, size_y = 0;
//	GetGraphSize(graph_, &size_x, &size_y);
//	int w = size_x / _column;
//	int h = size_y / _row;
//	for (int y = 0; y < size_y; y += h)
//	{
//		for (int x = 0; x < size_x; x += w)
//		{
//			divGraphs_.push_back(DerivationGraph(x, y, w, h, graph_));
//		}
//	}
//}
//
//void AnimatedSprite::Draw(const Vector2 & pos) const
//{
//	DrawGraphF(pos.x, pos.y, graph_, TRUE);
//}
//
//void AnimatedSprite::Draw(const Vector2 & pos, int x, int y, int w, int h) const
//{
//	DrawRectGraphF(pos.x, pos.y, x, y, w, h, graph_, TRUE, FALSE);
//}
//
//void AnimatedSprite::Draw(int num, const Vector2 & pos, const Vector2 & center, const Vector2 & scale, float rotation) const
//{
//	//DrawRotaGraph3F(pos.x, pos.y, center.x, center.y, scale.x, scale.y, divGraphs_[num], TRUE);
//}
//
//void AnimatedSprite::Draw(int anim , float time, const Vector2 & pos, const Vector2 & center, const Vector2 & scale, float rotation) const
//{
//	//Draw(, pos, center, scale, rotation);
//
//}
//
//void AnimatedSprite::AddAnimation(int anim, int start, int end, float time)
//{
//	animations_[anim].clear();
//	for (int frame = 0; frame < (end - start); frame++)
//	{
//		AddKeyFrame(anim, (frame + 1)*time, start + frame);
//	}
//}
//
//void AnimatedSprite::AddKeyFrame(int anim, float time, int x, int y, int w, int h)
//{
//	divGraphs_.push_back(DerivationGraph(x, y, w, h, graph_));
//	AddKeyFrame(anim, time, int(divGraphs_.size()) - 1);
//}
//
//void AnimatedSprite::AddKeyFrame(int anim, float time, int graphNum)
//{
//	animations_[anim].emplace_back(time, graphNum);
//}
//
//float AnimatedSprite::AnimationEndTime(int anim) const
//{
//	return  animations_.at(anim).back();
//}
//
//void AnimatedSprite::Clear()
//{
//	if (graph_ != -1) {
//		DeleteSharingGraph(graph_);
//		graph_ = -1;
//		divGraphs_.clear();
//	}
//	animations_.clear();
//}
////
////const AnimatedSprite::KeyFrame& AnimatedSprite::findKeyFrame_(int anim, float timer) {
////	const auto& keyframe = animations_.at(anim);
////	timer = fmod(timer, AnimationEndTime(anim) + 1.0f);
////	for (const auto& key:keyframe)
////	{
////		if(timer<=key.first)
////	}
////}