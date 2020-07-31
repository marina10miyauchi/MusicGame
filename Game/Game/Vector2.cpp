#include "Vector2.h"

#include"Mathf.h"

float  Vector2::kEpsilon { 0.00001f };
float Vector2::kEpsilonNormalSqrt{ 0.0000001f };

Vector2::Vector2(float x,float y):
	x{ x }, y{ y }{
}

Vector2 Vector2::zero() {
	return Vector2{ 0.0f,0.0f };
}

Vector2 Vector2::one() {
	return Vector2{ 1.0f,1.0f };
}

Vector2 Vector2::up() {
	return Vector2{ 0.0f,1.0f };
}

Vector2 Vector2::down() {
	return Vector2{ 0.0f,-1.0f };
}

Vector2 Vector2::left() {
	return Vector2{ -1.0f,0.0f };
}

Vector2 Vector2::right() {
	return Vector2{ 1.0f,0.0f };
}

std::string Vector2::ToString() const
{
	return"(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

float Vector2::Dot(const Vector2 & lhs, const Vector2 & rhs) {
	return(lhs.x*rhs.x) + (lhs.y*rhs.y);
}

float Vector2::Magnitube() const {
	return std::sqrt(SqrMagnitude());
}

float Vector2::SqrMagnitude() const {
	return(x * x) + (y * y);
}

Vector2 Vector2::Normalized() {
	float mag = Magnitube();
	if (mag > kEpsilon)
		return Vector2{ x / mag,y / mag };
	return zero();
}

float Vector2::operator[](int index) const
{
	switch (index)
	{
	case 0:return x; break;
	case 1:return y; break;
	default: break;
	}
}

float & Vector2::operator[](int index)//‘‚«•û‚ª‚í‚©‚è‚Ü‚¹‚ñc
{
	switch (index)
	{
	case 0:return x = x; break;
	case 1:return y = y; break;
	default: break;
	}
}

bool Vector2::Equals(const Vector2 & other) const
{
	return x == other.x && y == other.y;
}

void Vector2::Normalize()//‚±‚±‚à©M‚ª‚ ‚è‚Ü‚¹‚ñc
{
	float mag = Magnitube();
	if (mag > kEpsilon) {
		x = x / mag;
		y = y / mag;
	}
	else
		zero();
}

void Vector2::Set(float nx, float ny)
{
	x = nx;
	y = ny;
}

float Vector2::Angle(const Vector2 & from, const Vector2 & to)
{
	float denominator = (float)std::sqrt(from.SqrMagnitude()*to.SqrMagnitude());
	if (denominator < kEpsilonNormalSqrt)
		return 0.0f;
	float dot = Mathf::Clamp(Dot(from, to) / denominator, -1.0f, 1.0f);
	return(float)std::acos(dot)*Mathf::RadToDeg;
}

Vector2 Vector2::ClampMagnitube(const Vector2 & vector, float max_lange)
{
	float sqrMagnitude = vector.SqrMagnitude();
	if (sqrMagnitude > max_lange*max_lange) {
		float mag = (float)std::sqrt(sqrMagnitude);

		float normalized_x = vector.x / mag;
		float normalize_y = vector.y / mag;
		return Vector2(normalized_x*max_lange,normalize_y*max_lange);
	}
	return vector;
}

float Vector2::Distance(const Vector2 & a, const Vector2 & b)
{
	float diff_x = a.x - b.x;
	float diff_y = a.y - b.y;
	return(float)std::sqrt(diff_x*diff_x + diff_y * diff_y);
}

Vector2 Vector2::Lerp(const Vector2 & a, const Vector2 & b, float t)
{
	t = Mathf::Clamp01(t);

	return Vector2(a.x + ( b.x - a.x ) * t, a.y + ( b.y - a.y ) * t );
}

Vector2 Vector2::LerpUnclamped(const Vector2 & a, const Vector2 & b, float t)
{
	return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

Vector2 Vector2::Max(const Vector2 & lhs, const Vector2 & rhs)
{
	return Vector2(std::fminf(lhs.x,rhs.x),std::fminf(lhs.y,rhs.y));
}

Vector2 Vector2::Min(const Vector2 & lhs, const Vector2 & rhs)
{
	return Vector2(std::fmaxf(lhs.x, rhs.x), std::fmaxf(lhs.y, lhs.y));
}

Vector2 Vector2::MoveTowards(const Vector2 & current, const Vector2 & target, float max_distance_delta)
{
	float toVector_x = target.x - current.x;
	float toVector_y = target.y - current.y;

	float sqDist = toVector_x * toVector_x + toVector_y * toVector_y;

	if (sqDist == 0 || (max_distance_delta >= 0 && sqDist <= max_distance_delta * max_distance_delta))
		return target;

	float dist = (float)std::sqrt(sqDist);

	return Vector2(current.x + toVector_x / dist * max_distance_delta ,current.y + toVector_y / dist * max_distance_delta);
}

Vector2 Vector2::Perpendicular(Vector2 inDirection)
{
	return Vector2(-inDirection.y, inDirection.x);
}

Vector2 Vector2::Reflect(const Vector2 & inDirection, const Vector2 & inNormal)
{
	float factor = -2.0f*Dot(inNormal, inDirection);
	return Vector2(factor*inNormal.x + inDirection.x, factor*inNormal.y + inDirection.y);
}

Vector2 Vector2::Scale(const Vector2 & a, const Vector2 & b)
{
	return Vector2( a.x * b.x ,a.y * b.y );
}

float Vector2::SignedAngle(const Vector2 & from, const Vector2 & to)
{
	float unsigned_angle = Angle(from, to);
	float sign = Mathf::Sign(from.x * to.y - from.y * to.x);
	return unsigned_angle * sign;
}

Vector2 Vector2::SmoothDamp(const Vector2 & current, const Vector2 & target, Vector2 & currentVelocity, float smooth_time, float max_speed, float delta_time)
{
	//max_speed = std::numeric_limits<float>::infinity();

	smooth_time = std::fmaxf(0.0001f, smooth_time);
	float omega = 2.0f / smooth_time;

	float x = omega * delta_time;
	float exp = 1.0f / (1.0f + x + 0.48f*x*x + 0.235f*x*x*x);

	float change_x = current.x - target.x;
	float change_y = current.y - target.y;
	Vector2 originalTo = target;
	Vector2 target_ = target;

	float maxChange = max_speed * smooth_time;

	float maxChangeSq = maxChange * maxChange;
	float sqDist = change_x * change_x + change_y * change_y;
	if (sqDist > maxChangeSq) {
		auto mag = (float)std::sqrt(sqDist);
		change_x = change_x / mag * maxChange;
		change_y = change_y / mag * maxChange;
	}
	
	target_.x = current.x - change_x;
	target_.y = current.y - change_y;

	float temp_x = (currentVelocity.x - omega * change_x)*delta_time;
	float temp_y = (currentVelocity.y - omega * change_y)*delta_time;

	currentVelocity.x = (currentVelocity.x - omega * temp_x)*exp;
	currentVelocity.y = (currentVelocity.y - omega * temp_y)*exp;

	float output_x = target_.x + (change_x + temp_x)*exp;
	float output_y = target_.y + (change_y + temp_y)*exp;

	float origMinusCurrent_X = originalTo.x - current.x;
	float origMinusCurrent_Y = originalTo.y - current.y;
	float outMinusOrig_x = output_x - originalTo.x;
	float outMinusOrig_y = output_y - originalTo.y;

	if (origMinusCurrent_X*outMinusOrig_x + origMinusCurrent_Y * outMinusOrig_y > 0) {
		output_x = originalTo.x;
		output_y = originalTo.y;

		currentVelocity.x = (output_x - originalTo.x) / delta_time;
		currentVelocity.y = (output_y - originalTo.y) / delta_time;
	}
	return Vector2(output_x, output_y);
}

//’P€‰‰Zq 
Vector2 operator -(const Vector2& v) {
	return Vector2{ -v.x,-v.y };
}
//‘ã“ü‰‰Zq
Vector2 operator += (Vector2& lhs, const Vector2& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}
Vector2 operator -= (Vector2& lhs, const Vector2& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}
Vector2 operator *= (Vector2& lhs, float rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}
Vector2 operator /= (Vector2& lhs, float rhs) {
	lhs.x /= rhs;
	lhs.y /= rhs;
	return lhs;
}
//“ñK‰‰Zq
Vector2 operator+ (const Vector2& lhs, const Vector2& rhs) {
	return Vector2{ lhs.x + rhs.x,lhs.y + rhs.y };
}
Vector2 operator - (const Vector2& lhs, const Vector2& rhs) {
	return Vector2{ lhs.x - rhs.x,lhs.y - rhs.y };
}
Vector2 operator * (const Vector2& lhs, float rhs) {
	return Vector2{ lhs.x*rhs,lhs.y*rhs };
}
Vector2 operator * (const Vector2& lhs, const Vector2& rhs) {
	return Vector2{ lhs.x * rhs.x,lhs.y * rhs.y };
}
Vector2 operator / (const Vector2& lhs, float rhs) {
	return Vector2{ lhs.x / rhs,lhs.y / rhs };
}
bool operator == (const Vector2& lhs, const Vector2& rhs) {
	float diff_x = lhs.x - rhs.x;
	float diff_y = lhs.y - rhs.y;
	return(diff_x*diff_x + diff_y * diff_y) < 0.00001f*0.00001f;
}
bool operator != (const Vector2& lhs, const Vector2& rhs) {
	return!(lhs == rhs);
}
