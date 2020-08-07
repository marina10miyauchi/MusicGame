#pragma once
#include<string>

enum MusicData {
	Music_01,
	Music_02,
	Music_03,
	Music_04,
	Music_05,
	Music_06,

	MaxMusicData
};


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

	bool is_select[MusicData::MaxMusicData];
	static int button_texture_ID_[MusicData::MaxMusicData];
	static int jacket_phote[MusicData::MaxMusicData];
	static std::string titles[MusicData::MaxMusicData];

};