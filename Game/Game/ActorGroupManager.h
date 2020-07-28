#pragma once

#include"ActorManager.h"
#include<map>

enum class ActorGroup;

class ActorGroupManager {
public:
	ActorGroupManager() = default;
	void Add(ActorGroup _group);
	void Add(ActorGroup _group, const ActorPtr& _actor);
	void Updata(float _deltaTime);
	void Draw()const;
	void Draw(ActorGroup _group)const;
	void Clear();
	ActorPtr Fine(ActorGroup _group, const std::string& _name)const;
	unsigned int Count(ActorGroup _group)const;
	void Remove();
	void HandleMessage(EventMessage _message, void* _param);

private:
	using ActorGroupMap = std::map<ActorGroup, ActorManager>;
	ActorGroupMap actorGroupMap_;
};