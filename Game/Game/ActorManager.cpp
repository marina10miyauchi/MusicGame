#include "ActorManager.h"

void ActorManager::Add(const ActorPtr & _actor)
{
	actors_.push_back(_actor);
}

void ActorManager::Update(float _deltaTime)
{
	for (const auto& actor : actors_)
	{
		actor->Updata(_deltaTime);
	}
}

void ActorManager::Draw() const
{
	for (const auto& actor : actors_)
	{
		actor->Draw();
	}
}

void ActorManager::Remove()
{
	actors_.remove_if([](const ActorPtr& actor) {return actor->IsDead(); });
}

ActorPtr ActorManager::FindActor(const std::string & _name) const
{
	for (const auto& actor : actors_) {
		if (actor->Name() == _name)
			return actor;
	}
	return ActorPtr();
}

unsigned int ActorManager::Count() const
{
	return actors_.size();
}

void ActorManager::HandleMessage(EventMessage _message, void * _param)
{
	for (const auto& actor : actors_) {
		actor->HandleMessage(_message, _param);
	}
}

void ActorManager::Clear()
{
	actors_.clear();
}
