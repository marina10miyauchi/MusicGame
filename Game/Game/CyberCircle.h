#pragma once
#include"Vector2.h"

class CyberCircle {
public:
	CyberCircle(int textureNum, const Vector2& pos, const Vector2& scale, float speed);
	void Update(float deltaTime);
	void Draw();

private:
	//�|�W�V�����𒆉��Ƃ������̍���̈ʒu
	Vector2 CenterPos();
private:
	int texture_Num_;
	Vector2 pos_;
	Vector2 scale_;
	float speed_;

	float angle_{ 0 };
};