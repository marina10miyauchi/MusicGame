#include "CyberCircle.h"
#include"Graphics2D.h"
#include"Assets.h"
#include<DxLib.h>

CyberCircle::CyberCircle(int textureNum, const Vector2 & pos, const Vector2 & scale, float speed) :
	texture_Num_(textureNum), pos_(pos), scale_(scale), speed_(speed)
{}

void CyberCircle::Update(float deltaTime)
{
	angle_ += deltaTime * speed_;
}

void CyberCircle::Draw()
{
	//Graphics2D::DrawSprite(texture_Num_, pos_, CenterPos(), scale_, angle_);
	Graphics2D::DrawSprite(texture_Num_, pos_, CenterPos(), scale_, angle_, DX_BLENDMODE_ALPHA,126);

}

Vector2 CyberCircle::CenterPos()
{
	Vector2 textureSize = Graphics2D::TextureSize(texture_Num_);
	Vector2 leftPos(textureSize.x / 2, textureSize.y / 2);
	return leftPos;
}
