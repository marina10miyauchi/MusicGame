#include "NotesTest.h"
#include<fstream>
#include<sstream>
#include"Key.h"
#include"KeyConst.h"
#include"Sound.h"
#include"SoundID.h"
#include"GameData.h"

NotesTest::NotesTest(std::string fileName) :
	file_name_{ fileName }
{
	notes_data_.clear();
	MusicScoreLoad();
	Initialize();
	score_->Initialize();
}

NotesTest::~NotesTest() {}

void NotesTest::Initialize()
{
	for (int i = 0; i < notes_data_.size(); i++)
	{
		//notes_data_[i].hasNotes = true;
		notes_data_[i].state = NotesState::None;
		notes_data_[i].x = LEFT_EDGE_X + NOTE_WIDTH / 2 + LANE_BETWEEN * (notes_data_[i].lane - 1);
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
	for (int x = 0; x < LANE_NUM; x++)
	{
		if (Key::Trigger(KEYS_[x])) {
			Sound::PlaySE(SoundId::Click);
			for (int i = 0; i < notes_data_.size(); i++)
			{
				if (notes_data_[i].state == NotesState::None && (notes_data_[i].lane - 1) == x)
				{
					if (Judge(notes_data_[i], prefect_timing_, currentTime)) {
						NotesPushAct(notes_data_[i], prefect_point);
						notes_data_[i].state = NotesState::Good;
						Effect(notes_data_[i].lane);
					}
					else if (Judge(notes_data_[i], good_timing_, currentTime)) {
						NotesPushAct(notes_data_[i], good_point);
						notes_data_[i].state = NotesState::Prefect;
						Effect(notes_data_[i].lane);
					}

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
	score_->Draw();
}

bool NotesTest::IsNotesEnd()
{

	return _notes_->NotesEnd();
}

void NotesTest::NotesPushAct(NotesDate& notes_, int addScore)
{
	//notes_.hasNotes = false;
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

void NotesTest::Effect(int line)
{

}
