#pragma once

#include<string>
#include"Vector2.h"

class IWorld;
enum class EventMessage;

class Actor {
public:
	Actor() = default;
	virtual ~Actor() {}
	virtual void Updata(float _deltaTime);
	virtual void Draw()const;
	virtual void HandleMessage(EventMessage _message, void* _param = nullptr);

	void Die();
	bool IsDead()const;
	const std::string& Name()const;

	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;

protected:
	IWorld* world_{ nullptr };
	std::string name_{};
	Vector2 position_{ 0.0f,0.0f };
	bool dead_{ false };


};