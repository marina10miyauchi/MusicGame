#pragma once
#include<string>
#include<vector>


//���ʃf�[�^�Ǘ�
class MusicScoreDate {
public:
	//fileName = ���ʃf�[�^�̏�����Ă���.txt�t�@�C����
	MusicScoreDate(std::string fileName);
	~MusicScoreDate();
	//���ʃf�[�^�̓ǂݍ���
	void Load();




private:
	//���ʃf�[�^�t�@�C���̖��O
	std::string file_name_;
	
	std::vector<int> notes_count_;
	std::vector<std::vector<float>> perfect_timing_;

};