#pragma once

enum class Scene;

class IScene {
public:
	virtual ~IScene(){}
	//�J�n
	virtual void Start() = 0;
	//�X�V
	virtual void Update(float delta_time) = 0;
	//�`��
	virtual void Draw()const = 0;
	//�I�����Ă��邩
	virtual bool Is_End()const = 0;
	//���̃V�[����ԋp
	virtual Scene Next()const = 0;
	//�I��
	virtual void End() = 0;
};
