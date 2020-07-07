#pragma once

#include"IScene.h"
class NullScene :public IScene {
public:
	//�J�n����
	virtual void Start()override;
	//�X�V
	virtual void Update(float delta_time)override;
	//�`��
	virtual void Draw()const override;
	//�I����
	virtual bool Is_End()const override;
	//���̃V�[����
	virtual Scene Next()const override;
	//�I��
	virtual void End()override;
};