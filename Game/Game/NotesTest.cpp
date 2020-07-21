#include "NotesTest.h"
#include<fstream>
#include<sstream>
#include"Key.h"
#include"KeyConst.h"
#include"Sound.h"
#include"SoundID.h"

NotesTest::NotesTest(std::string fileName) :
	file_name_{ fileName }
{
	MusicScoreLoad();
	Initialize();
	score_ = new Score();
	score_->Initialize();
}

NotesTest::~NotesTest() {}

void NotesTest::Initialize()
{
	for (int i = 0; i < notes_data_.size(); i++)
	{
		notes_data_[i].hasNotes = true;
		notes_data_[i].x = 200.0f + 150.0f * (notes_data_[i].lane - 1);
	}
}

void NotesTest::Update(float judgeLinePosY, float currentTime)
{
	for (int i = 0; i < notes_data_.size(); i++)
	{
		_notes_->UpDate(judgeLinePosY, currentTime, notes_data_[i]);
	}
	JudgeNotes(currentTime);
}

void NotesTest::JudgeNotes(float currentTime)
{
	for (int x = 0; x < Lane::Max; x++)
	{
		if (Key::Trigger(KEYS_[x])) {
			Sound::PlaySE(SoundId::Click);
			for (int i = 0; i < notes_data_.size(); i++)
			{
				if (notes_data_[i].hasNotes && (notes_data_[i].lane - 1) == x)
				{
					if (Judge(notes_data_[i], prefect_timing_, currentTime))
						NotesPushAct(notes_data_[i], 50);
					else if (Judge(notes_data_[i], good_timing_, currentTime))
						NotesPushAct(notes_data_[i], 10);
				}
			}
		}
		line_->ChangeCore(x, Key::State(KEYS_[x]));
	}
}

void NotesTest::Draw()
{
	for (int i = 0; i < notes_data_.size(); i++)
	{
		_notes_->Draw(notes_data_[i]);
	}

	//for (auto notes_ : notes_data_) {
	//	_notes_->Draw(notes_);
	//}
	score_->Draw();
}

void NotesTest::NotesPushAct(NotesDate notes_, int addScore)
{
	notes_.hasNotes = false;
	score_->Add(addScore);
}

void NotesTest::MusicScoreLoad()
{
	std::ifstream file(file_name_);
	if (!file)
		throw std::runtime_error("開けませんでした。");
	int note = 0;

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream streng_stream_i(line);
		std::string value;

		int count = 0;
		NotesDate notes_;
		//カンマ区切りで読み込む
		while (std::getline(streng_stream_i, value, ','))
		{
			switch (count)
			{
			case 0: notes_.lane = atof(value.c_str()); break;
			case 1: notes_.timing = atof(value.c_str()); break;
			default:break;
			}
			count++;
		}
		notes_.num = note;
		notes_data_.push_back(notes_);
		note++;
	}

}

bool NotesTest::Judge(NotesDate notes_, float judge_timing, float current_time_)
{
	float notes_timing = notes_.timing;
	if (-judge_timing < current_time_ - notes_timing
		&& current_time_ - notes_timing < judge_timing)
		return true;
	return false;
}
