#pragma once

#include<string>
#include<list>

//csv��txt�̕��ʂɕύX

struct Data
{
	int lane_;
	float time_;
};

class CSVConverter {
public:
	CSVConverter() = default;
	CSVConverter(const std::string fileName);
	//�ǂݍ���
	void Load();
	//�����o��
	void Output(std::ofstream &outputFile, std::list<float> rane);

private:

	//�t�@�C����
	std::string file_name_;
	std::string output_file_name_;

	//����
	double time_{ 0 };
	//�e���|
	float bpm_{ 120 };
	//��x�݂̂̏���
	bool one_;

	//�e�X�g
	using Rane = std::list<float>;
	//�e�X�g�@���[�����Ƃɂ܂Ƃ߂�
	Rane rane_1;
	Rane rane_2;
	Rane rane_3;
	Rane rane_4;

	std::list<Data> note_data_;
};