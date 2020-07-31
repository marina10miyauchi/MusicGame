#pragma once

#ifndef VECTOR2_H_
#define VECTOR2_H_

#include<cmath>
#include<string>

struct  Vector2
{
	float x{ 0.0f };	//ベクトルのX成分
	float y{ 0.0f };	//ベクトルのY成分
	//コンストラクタ
	Vector2(float x, float y);

	static Vector2 zero();
	static Vector2 one();
	static Vector2 up();
	static Vector2 down();
	static Vector2 left();
	static Vector2 right();

	std::string ToString()const;

	//内積を計算
	static float Dot(const Vector2& lhs, const Vector2& rhs);
	//長さ
	float Magnitube()const;
	//2乗の長さを求める
	float SqrMagnitude()const;
	//正規化　magnitubeを1としたベクトル
	Vector2 Normalized();

	//0 or 1を取得して x or y を返す　0 = x  1 = y
	float operator[](int index)const;
	float& operator[](int index);

	//
	bool Equals(const Vector2& other)const;
	//正規化
	void Normalize();
	//
	void Set(float nx, float ny);

	//角度　2つのベクトルのなす角を返す
	static float Angle(const Vector2& from, const Vector2& to);
	//
	static Vector2 ClampMagnitube(const Vector2& vector, float max_lange);
	//a b 間の距離を返す
	static float Distance(const Vector2& a, const Vector2& b);
	
	//2つのベクトル a b の線形補間
	static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
	//2つのベクトル a b の線形補間
	static Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t);
	//2つのベクトルで各成分の一番大きな値を使用してベクトルを作成
	static Vector2 Max(const Vector2& lhs, const Vector2& rhs);
	//2つのベクトルの各成分の一番小さい値を使用してベクトルを生成
	static Vector2 Min(const Vector2& lhs, const Vector2& rhs);
	//targetに向けていいどう
	static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float max_distance_delta);
	//
	static Vector2 Perpendicular(Vector2 inDirection);
	//ベクトルの反射を取得
	static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);
	//二つのベクトルの各成分を乗算する
	static Vector2 Scale(const Vector2& a, const Vector2& b);
	//
	static float SignedAngle(const Vector2& from, const Vector2& to);
	//targetに向けて時間経過とともに徐々にベクトルを変化
	Vector2 SmoothDamp(const Vector2& current, const Vector2& target, Vector2& currentVelocity, float smooth_time, float max_speed, float delta_time);
	
public:
	static float kEpsilon;
	static float kEpsilonNormalSqrt;

};

//単項演算子 
Vector2 operator -(const Vector2& v);
//代入演算子
Vector2 operator += (Vector2& lhs, const Vector2& rhs);
Vector2 operator -= (Vector2& lhs, const Vector2& rhs);
Vector2 operator *= (Vector2& lhs, float rhs);
Vector2 operator /= (Vector2& lhs, float rhs);

//二幸演算子
Vector2 operator+ (const Vector2& lhs, const Vector2& rhs);
Vector2 operator - (const Vector2& lhs, const Vector2& rhs);
Vector2 operator * (const Vector2& lhs, float rhs);
Vector2 operator * (const Vector2& lhs, const Vector2& rhs);
Vector2 operator / (const Vector2& lhs, float rhs);

bool operator == (const Vector2& lhs, const Vector2& rhs);
bool operator != (const Vector2& lhs, const Vector2& rhs);



#endif // !VECTOR2_H_
