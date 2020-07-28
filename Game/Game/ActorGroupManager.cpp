#include "ActorGroupManager.h"

void ActorGroupManager::Add(ActorGroup _group)
{
	actorGroupMap_[_group].Clear();
}

void ActorGroupManager::Add(ActorGroup _group, const ActorPtr & _actor)
{
	actorGroupMap_[_group].Add(_actor);
}

void ActorGroupManager::Updata(float _deltaTime)
{
	for (auto& pair : actorGroupMap_) {
		pair.second.Update(_deltaTime);
	}
}

void ActorGroupManager::Draw() const
{
	for (auto& pair : actorGroupMap_) {
		Draw(pair.first);
	}
}

void ActorGroupManager::Draw(ActorGroup _group) const
{
	actorGroupMap_.at(_group).Draw();
}

void ActorGroupManager::Clear()
{
	actorGroupMap_.clear();
}

ActorPtr ActorGroupManager::Fine(ActorGroup _group, const std::string & _name)const
{
	return actorGroupMap_.at(_group).FindActor(_name);
}

unsigned int ActorGroupManager::Count(ActorGroup _group) const
{
	return actorGroupMap_.at(_group).Count();
}

void ActorGroupManager::Remove()
{
	for (auto& pair : actorGroupMap_) {
		pair.second.Remove();
	}
}

void ActorGroupManager::HandleMessage(EventMessage _message, void * _param)
{
	for (auto& pair : actorGroupMap_) {
		pair.second.HandleMessage(_message, _param);
	}
}
