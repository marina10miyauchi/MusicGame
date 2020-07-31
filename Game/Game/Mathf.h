#pragma once

#ifndef MATH_F_H_
#define MATH_F_H_


struct Mathf
{
	static float Sign(float f);

	static float Min(float a, float b);

	static float Max(float a, float b);

	static float Clamp(float value, float min, float max);

	static float Clamp01(float value);

	static float Lerp(float a, float b, float t);

	static float MoveToward(float current, float target, float maxDelta);

public:

	static float PI;
	static float DegToRad;
	static float RadToDeg;
};

#endif // !MATH_F_H_
