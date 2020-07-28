#include "World.h"
#include"ActorGroup.h"

World::World()
{
	Initialize();
}

void World::Initialize()
{
	Clear();
	actors_.Add(ActorGroup::Notes);
	actors_.Add(ActorGroup::Effect);
}

void World::Update(float _deltaTime)
{
	actors_.Updata(_deltaTime);
	actors_.Remove();
}

void World::Draw() const
{
	actors_.Draw();
}

void World::HandleMessage(EventMessage _message, void * _param)
{
	listener_(_message, _param);
	actors_.HandleMessage(_message, _param);
}

void World::AddEventMessageListener(EventMessageListener _listener)
{
	listener_ = _listener;
}

void World::Clear()
{
	actors_.Clear();
	listener_ = [](EventMessage, void*) {};
}

void World::AddActor(ActorGroup _group, const ActorPtr & _actor)
{
	actors_.Add(_group, _actor);
}

ActorPtr World::FindActor(ActorGroup _group, const std::string& _name) const
{
	return actors_.Fine(_group, _name);
}

unsigned int World::CountActor(ActorGroup _group) const
{
	return actors_.Count(_group);
}

void World::SendMessage(EventMessage _message, void * _param )
{
	HandleMessage(_message, _param);
}
