#pragma once
#include<string>
#include"Assets.h"

class SelectFrame {
public:

	SelectFrame() = default;
	void Initialize();
	void Updata();
	void Draw();

	int SelectNum();

private:
	void Select();

	void ButtonDraw();

private:
	static std::string music_name_;	//表示名
	static int texture_ID_;		//表示テクスチャ
	static int hight_score_;		//ハイスコア

	static int select_button_num;

	static int button_texture_ID_[6];
	static int jacket_phote[6];
	static std::string titles[6];

};