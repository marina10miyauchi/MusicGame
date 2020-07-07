#pragma once
#include<DxLib.h>

#include<Windows.h>

class Time {
public:
	Time() = default;
	//FPSの回数固定
	static bool FPS_Fixed();
	//待機状態
	static void Wait();
	//FPSテスト描画
	static void TestDraw();


private:
	static int start_time_;
	static int start_count_;      //測定開始時刻
	static int count_;          //カウンタ
	static float fps_;          //fps
	static const int N{ 60 };	//平均を取るサンプル数
	static const int FPS{ 60 };	//設定したFPS
};