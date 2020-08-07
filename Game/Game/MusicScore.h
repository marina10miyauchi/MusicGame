#pragma once
#include<string>
#include<unordered_map>

class MusicScore {
public:
	static void Iniitialize();
	static void LoadMusicScore(int id,const std::string& fileName);
	static std::string GetMusicData(int id);
	static std::string GetMusicData();
	static void SetMusicScore(int id);

private:
	static std::unordered_map<int, std::string> music_score_;
	static int current_musicscore_id;
};