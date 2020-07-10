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
	//ウィンドウサイズの設定
	SetWindowSize(window_width, window_height);
	//フルスクリーンモード時の解像度を設定
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
	//グラフィックモードの設定
	SetGraphMode(window_width, window_height, 32);
	//ウィンドウモードか
	ChangeWindowMode(is_full_screen ? FALSE : TRUE);
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);
	//DXライブラリ初期化
	DxLib_Init();
}

Game::~Game()
{
	DxLib_End();
}

int Game::Run()
{
	//初期化処理
	Sound::Initialize();
	Key::Initialize();
	Mouse::Initialize();
	Start();
	nextTime_ = GetNowCount();
	while (ProcessMessage() == 0 && Is_Running())
	{

		//FPSの固定（ゲームランに入れるとなぜか43しか出なくなる…）
		Time::FPS_Fixed();
		Key::Update();
		Mouse::Update();
		//更新
		Update(1.0f);
		//画面クリア
		ClearDrawScreen();
		//描画
		Draw();
		//Key::DebugDraw();
		//Mouse::DebugDraw();
		//Time::TestDraw();
		//裏画面の内容を表画面に反映
		ScreenFlip();


		Time::Wait();

	}
	End();
	//終了処理
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
