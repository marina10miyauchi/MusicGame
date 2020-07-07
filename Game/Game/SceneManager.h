#pragma once

#include"IScenePtr.h"
#include<unordered_map>

enum class Scene;

class SceneManager {
public:

	SceneManager();
	//������
	void Initialize();
	//�X�V
	void Update(float delta_time);
	//�`��
	void Draw()const;
	//�I��
	void End();
	//�V�[���̒ǉ�
	void Add(Scene name, const IScenePtr& scene);
	//�V�[���ύX
	void Change(Scene name);
	//�R�s�[�֎~
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator=(const SceneManager& other) = delete;

private:
	//�V�[���ۑ���
	std::unordered_map<Scene, IScenePtr> scenes_;
	//���݂̃V�[��
	IScenePtr current_scene;
};