#pragma once

#include"Actor.h"
#include"ActorPtr.h"
#include<list>

class ActorManager {
public:
	ActorManager() = default;
	void Add(const ActorPtr& _actor);
	void Update(float _deltaTime);
	void Draw()const;
	void Remove();
	ActorPtr FindActor(const std::string& _name)const;
	unsigned int Count()const;
	void HandleMessage(EventMessage _message, void* _param);
	void Clear();

	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator=(const ActorManager& other) = delete;

private:
	using ActorList = std::list<ActorPtr>;
	ActorList actors_;
};