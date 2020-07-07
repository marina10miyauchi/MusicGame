#pragma once
#pragma comment(linker,"/entry:mainCRTStartup") 

#include<string>

class Game {
public:
	Game() = default;
	//コンストラクタ
	//width = 画面横幅　height = 画面縦幅　full_screen = フルスクリーンモードにするか name = ウィンドウ名
	Game(int width, int height, bool full_screen,std::string name="GameWin");
	~Game();
	//実行
	int Run();

	Game(const Game& other) = delete;
	Game& operator= (const Game& other) = delete;

private:
	//開始処理
	virtual void Start();
	//更新
	virtual void Update(float);
	//描画
	virtual void Draw();
	//終了
	virtual void End();
	//実行中か
	virtual bool Is_Running()const;

private:
	int window_width{ 640 };
	int window_height{ 480 };
	bool is_full_screen{ false };
	std::string window_name{ "GameWin" };

private:
	double nextTime_{ 0 };
};