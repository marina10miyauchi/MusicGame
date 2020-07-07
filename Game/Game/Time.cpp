#include "Time.h"

int Time::start_time_{ 0 };
int Time::start_count_{ 0 };
int Time::count_{ 0 };
float Time::fps_{ 0 };


bool Time::FPS_Fixed()
{
	if (count_ == 0) { //1�t���[���ڂȂ玞�����L��
		start_count_ = GetNowCount();
	}
	if (count_ == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		fps_ = 1000.f / ((t - start_count_) / (float)N);
		count_ = 0;
		start_count_ = t;
	}
	count_++;
	return true;
}


void Time::Wait()
{
	int tookTime = GetNowCount() - start_count_;	//������������
	int waitTime = count_ * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

void Time::TestDraw()
{
	SetFontSize(24);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps_);
}
