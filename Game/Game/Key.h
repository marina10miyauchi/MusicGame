#pragma once
#include"KeyConst.h"

class Key {
public:
	//������
	static void Initialize();
	//�X�V
	static void Update();
	//������Ă��邩
	static bool State(int key);
	//�����ꂽ��
	static bool Trigger(int key);
	//���ꂽ��
	static bool Release(int key);
	//�I������
	static void Finalize();

private:
	static int cur_state_;
	static int prev_state_;
};