#pragma once
#include<DxLib.h>

#include<Windows.h>

class Time {
public:
	Time() = default;
	//FPS�̉񐔌Œ�
	static bool FPS_Fixed();
	//�ҋ@���
	static void Wait();
	//FPS�e�X�g�`��
	static void TestDraw();


private:
	static int start_time_;
	static int start_count_;      //����J�n����
	static int count_;          //�J�E���^
	static float fps_;          //fps
	static const int N{ 60 };	//���ς����T���v����
	static const int FPS{ 60 };	//�ݒ肵��FPS
};