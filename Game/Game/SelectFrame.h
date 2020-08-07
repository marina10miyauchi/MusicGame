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
	static std::string music_name_;	//�\����
	static int texture_ID_;		//�\���e�N�X�`��
	static int hight_score_;		//�n�C�X�R�A

	static int select_button_num;

	static int button_texture_ID_[6];
	static int jacket_phote[6];
	static std::string titles[6];

};