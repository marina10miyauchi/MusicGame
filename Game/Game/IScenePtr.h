#pragma once

#include<memory>

class IScene;
using IScenePtr = std::shared_ptr<IScene>;

template<class T, class... Args>
inline IScenePtr new_Scene(Args&&... args) {
	return std::make_shared<T>(args...);
}