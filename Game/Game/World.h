#pragma once
#include"IWorld.h"
#include"ActorGroupManager.h"
#include"ActorPtr.h"
#include<functional>

class World :public IWorld {
public:
	using EventMessageListener = std::function<void(EventMessage, void*)>;

public:
	World();
	void Initialize();
	void Update(float _deltaTime);
	void Draw() const;
	void HandleMessage(EventMessage _message, void* _param);
	void AddEventMessageListener(EventMessageListener _listener);
	void Clear();

	virtual void AddActor(ActorGroup _group, const ActorPtr & _actor) override;
	virtual ActorPtr FindActor(ActorGroup _group, const std::string& _name) const override;
	virtual unsigned int CountActor(ActorGroup _group) const override;
	virtual void SendMessage(EventMessage _message, void * _param = nullptr) override;


	World(const World& other) = delete;
	World& operator=(const World& other) = delete;
private:
	EventMessageListener listener_{ [](EventMessage,void*) {} };
	ActorGroupManager actors_;

};