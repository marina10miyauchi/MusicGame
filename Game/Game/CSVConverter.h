#pragma once

#include<string>
#include<list>

//csv→txtの譜面に変更

struct Data
{
	int lane_;
	float time_;
};

class CSVConverter {
public:
	CSVConverter() = default;
	CSVConverter(const std::string fileName);
	//読み込み
	void Load();
	//書き出し
	void Output(std::ofstream &outputFile, std::list<float> rane);

private:

	//ファイル名
	std::string file_name_;
	std::string output_file_name_;

	//時間
	double time_{ 0 };
	//テンポ
	float bpm_{ 120 };
	//一度のみの処理
	bool one_;

	//テスト
	using Rane = std::list<float>;
	//テスト　レーンごとにまとめる
	Rane rane_1;
	Rane rane_2;
	Rane rane_3;
	Rane rane_4;

	std::list<Data> note_data_;
};