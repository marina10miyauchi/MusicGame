#pragma once

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include<cmath>
#include<string>

struct  Vector2
{
	float x{ 0.0f };	//�x�N�g����X����
	float y{ 0.0f };	//�x�N�g����Y����
	//�R���X�g���N�^
	Vector2(float x, float y);

	static Vector2 zero();
	static Vector2 one();
	static Vector2 up();
	static Vector2 down();
	static Vector2 left();
	static Vector2 right();

	std::string ToString()const;

	//���ς��v�Z
	static float Dot(const Vector2& lhs, const Vector2& rhs);
	//����
	float Magnitube()const;
	//2��̒��������߂�
	float SqrMagnitude()const;
	//���K���@magnitube��1�Ƃ����x�N�g��
	Vector2 Normalized();

	//0 or 1���擾���� x or y ��Ԃ��@0 = x  1 = y
	float operator[](int index)const;
	float& operator[](int index);

	//
	bool Equals(const Vector2& other)const;
	//���K��
	void Normalize();
	//
	void Set(float nx, float ny);

	//�p�x�@2�̃x�N�g���̂Ȃ��p��Ԃ�
	static float Angle(const Vector2& from, const Vector2& to);
	//
	static Vector2 ClampMagnitube(const Vector2& vector, float max_lange);
	//a b �Ԃ̋�����Ԃ�
	static float Distance(const Vector2& a, const Vector2& b);
	
	//2�̃x�N�g�� a b �̐��`���
	static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
	//2�̃x�N�g�� a b �̐��`���
	static Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t);
	//2�̃x�N�g���Ŋe�����̈�ԑ傫�Ȓl���g�p���ăx�N�g�����쐬
	static Vector2 Max(const Vector2& lhs, const Vector2& rhs);
	//2�̃x�N�g���̊e�����̈�ԏ������l���g�p���ăx�N�g���𐶐�
	static Vector2 Min(const Vector2& lhs, const Vector2& rhs);
	//target�Ɍ����Ă����ǂ�
	static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float max_distance_delta);
	//
	static Vector2 Perpendicular(Vector2 inDirection);
	//�x�N�g���̔��˂��擾
	static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);
	//��̃x�N�g���̊e��������Z����
	static Vector2 Scale(const Vector2& a, const Vector2& b);
	//
	static float SignedAngle(const Vector2& from, const Vector2& to);
	//target�Ɍ����Ď��Ԍo�߂ƂƂ��ɏ��X�Ƀx�N�g����ω�
	Vector2 SmoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity, float smooth_time, float max_speed, float delta_time);
	
public:
	static float kEpsilon;
	static float kEpsilonNormalSqrt;

};

//�P�����Z�q 
Vector2 operator -(const Vector2& v);
//������Z�q
Vector2 operator += (Vector2& lhs, const Vector2& rhs);
Vector2 operator -= (Vector2& lhs, const Vector2& rhs);
Vector2 operator *= (Vector2& lhs, float rhs);
Vector2 operator /= (Vector2& lhs, float rhs);

//��K���Z�q
Vector2 operator+ (const Vector2& lhs, const Vector2& rhs);
Vector2 operator - (const Vector2& lhs, const Vector2& rhs);
Vector2 operator * (const Vector2& lhs, float rhs);
Vector2 operator * (const Vector2& lhs, const Vector2& rhs);
Vector2 operator / (const Vector2& lhs, float rhs);

bool operator == (const Vector2& lhs, const Vector2& rhs);
bool operator != (const Vector2& lhs, const Vector2& rhs);



#endif // !VECTOR2_H_
