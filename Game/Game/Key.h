#pragma once
#include"KeyConst.h"
#include<list>
#include<map>

static const int KEYS[15] = {
	keyConst::Z,
	keyConst::X,
	keyConst::C,
	keyConst::V,

	keyConst::W,
	keyConst::A,
	keyConst::S,
	keyConst::D,

	keyConst::Esc,
	keyConst::Space,
	keyConst::Enter,

	keyConst::Right,
	keyConst::Left,
	keyConst::Up,
	keyConst::Down,

};

struct Test {
	int keynum;
	bool isPush = false;
};

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

	static void DebugDraw();
private:
	static void KeyUpdata();
	static void SetKeyList();

private:
	static std::list<int> keys_;

	static std::map<int, bool> cur_keys_;
	static std::map<int, bool>pre_keys_;

};