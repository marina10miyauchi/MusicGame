#include "Mathf.h"
#include<math.h>
#include<cmath>

float Mathf::PI{ 3.1416 };
float Mathf::DegToRad{ PI * 2.0f / 360.0f };
float Mathf::RadToDeg{ 1.0f / DegToRad };


float Mathf::Sign(float f)
{
	return f >= 0.0f ? 1.0f : -1.0f;
}

float Mathf::Min(float a, float b)
{
	return 0.0f;
}

float Mathf::Max(float a, float b)
{
	return 0.0f;
}

float Mathf::Clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return value;
}

float Mathf::Clamp01(float value)
{
	if (value < 0.0f)return 0.0f;
	else if (value > 1.0f)return 1.0f;
	else return value;
}

float Mathf::Lerp(float a, float b, float t)
{
	return a + (b - a)*Clamp01(t);
}

float Mathf::MoveToward(float current, float target, float maxDelta)
{
	if (std::abs(target - current) <= maxDelta) 
		return target;
			
	return current + Mathf::Sign(target - current) > maxDelta;
}
