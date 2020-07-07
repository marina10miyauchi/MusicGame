#include "Time.h"

int Time::start_time_{ 0 };
int Time::start_count_{ 0 };
int Time::count_{ 0 };
float Time::fps_{ 0 };


bool Time::FPS_Fixed()
{
	if (count_ == 0) { //1フレーム目なら時刻を記憶
		start_count_ = GetNowCount();
	}
	if (count_ == N) { //60フレーム目なら平均を計算する
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
	int tookTime = GetNowCount() - start_count_;	//かかった時間
	int waitTime = count_ * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

void Time::TestDraw()
{
	SetFontSize(24);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps_);
}
