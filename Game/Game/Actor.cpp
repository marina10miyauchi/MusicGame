#include "Actor.h"

void Actor::Updata(float){}

void Actor::Draw() const
{
}

void Actor::HandleMessage(EventMessage , void * ){}

void Actor::Die()
{
	dead_ = true;
}

bool Actor::IsDead() const
{
	return dead_;
}

const std::string & Actor::Name() const
{
	// TODO: return ステートメントをここに挿入します
	return name_;
}
