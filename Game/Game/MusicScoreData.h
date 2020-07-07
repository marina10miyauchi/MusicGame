#pragma once
#include<string>
#include<vector>


//譜面データ管理
class MusicScoreDate {
public:
	//fileName = 譜面データの書かれている.txtファイル名
	MusicScoreDate(std::string fileName);
	~MusicScoreDate();
	//譜面データの読み込み
	void Load();




private:
	//譜面データファイルの名前
	std::string file_name_;
	
	std::vector<int> notes_count_;
	std::vector<std::vector<float>> perfect_timing_;

};