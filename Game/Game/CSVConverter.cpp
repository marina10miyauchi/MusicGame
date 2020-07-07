#include "CSVConverter.h"
#include<fstream>
#include<sstream>
#include<stdexcept>

CSVConverter::CSVConverter(const std::string fileName):
	file_name_{fileName}
{
	Load();
}

void CSVConverter::Load()
{
	std::ifstream file(file_name_);
	//�t�@�C�����ǂݍ��߂Ȃ�������
	if (!file)throw std::runtime_error("CSV�t�@�C�����I�[�v���ł��܂���ł���");
	std::string line;
	int line_count = 0;
	int rane_count = 1;


	//��s�ǂݍ���
	while (std::getline(file, line))
	{
		if (!one_) {
			std::istringstream streng_stream_i(line);
			std::string value;
			int count = 0;
			//�J���}��؂�œǂݍ���
			while (std::getline(streng_stream_i, value, ','))
			{
				switch (count)
				{
				case 0:output_file_name_ = value; break;
				case 1:bpm_ = atoi(value.c_str());
				default:
					break;
				}
				count++;
			}
			one_ = true;
			continue;
		}

		int rane_count = 1;

		std::istringstream streng_stream_i(line);
		std::string value;
		//�J���}��؂�œǂݍ���
		while (std::getline(streng_stream_i, value, ','))
		{
			//�b���̌v�Z�@�K��
			if (atoi(value.c_str()) > 0) {
				time_ = 60 * line_count / bpm_ * atoi(value.c_str());
				//�ǂݍ��񂾏��i�����珇�j�Ƀ��[�����Ƃ̔z��Ɋi�[���Ă���
				switch (rane_count)
				{
				case 1: rane_1.push_back(time_); break;
				case 2: rane_2.push_back(time_); break;
				case 3: rane_3.push_back(time_); break;
				case 4: rane_4.push_back(time_); break;
				default:break;
				}
			}
			rane_count++;
		}
		line_count++;
	}

	std::ofstream output("output/" + output_file_name_ + ".txt");

	Output(output, rane_1);
	Output(output, rane_2);
	Output(output, rane_3);
	Output(output, rane_4);

	output.close();

}

void CSVConverter::Output(std::ofstream & outputFile, std::list<float> rane)
{
	int count = 0;

	for (float c : rane)
	{
		count++;
		outputFile << c;
		if (count == (int)rane.size())
			outputFile << "\n";
		else
			outputFile << ",";
	}
}

