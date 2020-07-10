#include "Game.h"
#include<DxLib.h>
#include"Sound.h"
#include"Key.h"
#include"Mouse.h"

#include"Time.h"


Game::Game(int width, int height, bool full_screen, std::string name) :
	window_width{ width }, window_height{ height }, is_full_screen{ full_screen }, window_name{ name }
{

	SetMainWindowText(window_name.c_str());
	//�E�B���h�E�T�C�Y�̐ݒ�
	SetWindowSize(window_width, window_height);
	//�t���X�N���[�����[�h���̉𑜓x��ݒ�
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
	//�O���t�B�b�N���[�h�̐ݒ�
	SetGraphMode(window_width, window_height, 32);
	//�E�B���h�E���[�h��
	ChangeWindowMode(is_full_screen ? FALSE : TRUE);
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	//DX���C�u����������
	DxLib_Init();
}

Game::~Game()
{
	DxLib_End();
}

int Game::Run()
{
	//����������
	Sound::Initialize();
	Key::Initialize();
	Mouse::Initialize();
	Start();
	nextTime_ = GetNowCount();
	while (ProcessMessage() == 0 && Is_Running())
	{

		//FPS�̌Œ�i�Q�[�������ɓ����ƂȂ���43�����o�Ȃ��Ȃ�c�j
		Time::FPS_Fixed();
		Key::Update();
		Mouse::Update();
		//�X�V
		Update(1.0f);
		//��ʃN���A
		ClearDrawScreen();
		//�`��
		Draw();
		//Key::DebugDraw();
		//Mouse::DebugDraw();
		//Time::TestDraw();
		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();


		Time::Wait();

	}
	End();
	//�I������
	Sound::Finalize();
	Key::Finalize();
	Mouse::Initialize();
	return 0;
}

void Game::Start()
{
}

void Game::Update(float)
{
}

void Game::Draw()
{
}

void Game::End()
{
}

bool Game::Is_Running() const
{
	return CheckHitKey(KEY_INPUT_ESCAPE) == 0;
}
