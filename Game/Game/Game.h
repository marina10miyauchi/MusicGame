#pragma once
#pragma comment(linker,"/entry:mainCRTStartup") 

#include<string>

class Game {
public:
	Game() = default;
	//�R���X�g���N�^
	//width = ��ʉ����@height = ��ʏc���@full_screen = �t���X�N���[�����[�h�ɂ��邩 name = �E�B���h�E��
	Game(int width, int height, bool full_screen,std::string name="GameWin");
	~Game();
	//���s
	int Run();

	Game(const Game& other) = delete;
	Game& operator= (const Game& other) = delete;

private:
	//�J�n����
	virtual void Start();
	//�X�V
	virtual void Update(float);
	//�`��
	virtual void Draw();
	//�I��
	virtual void End();
	//���s����
	virtual bool Is_Running()const;

private:
	int window_width{ 640 };
	int window_height{ 480 };
	bool is_full_screen{ false };
	std::string window_name{ "GameWin" };

private:
	double nextTime_{ 0 };
};