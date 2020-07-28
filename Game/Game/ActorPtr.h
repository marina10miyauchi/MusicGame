#pragma once
#include<memory>

class Actor;
using ActorPtr = std::shared_ptr<Actor>;

template<class T, class... Args>
inline ActorPtr new_Actor(Args&&... args) {
	return std::make_shared<T>(args...);
}