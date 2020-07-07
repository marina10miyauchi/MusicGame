#include "SceneManager.h"
#include"NullScene.h"

SceneManager::SceneManager()
	:current_scene(new_Scene<NullScene>()){}

void SceneManager::Initialize()
{
	End();
	scenes_.clear();
}

void SceneManager::Update(float delta_time)
{
	current_scene->Update(delta_time);
	if (current_scene->Is_End()) {
		Change(current_scene->Next());
	}
}

void SceneManager::Draw() const
{
	current_scene->Draw();
}

void SceneManager::End()
{
	current_scene->End();
	current_scene = new_Scene<NullScene>();
}

void SceneManager::Add(Scene name, const IScenePtr & scene)
{
	scenes_[name] = scene;
}

void SceneManager::Change(Scene name)
{
	End();
	current_scene = scenes_[name];
	current_scene->Start();
}
