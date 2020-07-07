#pragma once

#include<string>
#include<unordered_map>

class Sound {
public:
	static void Initialize();
	static void LoadBGM(int id, const std::string& fileName);
	static void PlayBGM(int id);
	static void StopBGM();
	static void DeleteBGM(int id);

	static void LoadSE(int id, const std::string& fileName);
	static void PlaySE(int id);
	static void DeleteSE(int id);

	static void Finalize();

private:
	static std::unordered_map<int, int> bgm_map_;
	static int current_bgm_;
	static std::unordered_map<int, int> se_map_;
};