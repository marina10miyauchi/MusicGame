#pragma once
#include<string>
#include"ActorPtr.h"

enum class ActorGroup;
enum class EventMessage;

class IWorld {
public:
	virtual ~IWorld() {}
	virtual void AddActor(ActorGroup _group, const ActorPtr& _actor) = 0;
	virtual ActorPtr FindActor(ActorGroup _group, const std::string& _name) const = 0;
	virtual unsigned int CountActor(ActorGroup _group)const = 0;
	virtual void SendMessage(EventMessage _message, void* _param = nullptr) = 0;
};