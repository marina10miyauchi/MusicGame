#include "NotesManager.h"
#include<fstream>
#include<sstream>
#include<stdexcept>
#include"Sound.h"
#include"SoundID.h"
#include"Key.h"
#include"Score.h"
#include"Notes.h"
#include"GameData.h"


NotesManager::NotesManager(std::string fileName) :
	file_name_{ fileName }
{
	MusicScoreLoad();
	Initialize();
	score_->Initialize();
}

NotesManager::~NotesManager() {}

void NotesManager::Initialize()
{
	for (int col = 0; col < LANE_NUM; col++) {
		int lane_length = notes_count_[col];
		for (int row = 0; row < lane_length; row++) {
			notes_data_[col][row].hasNotes = true;
			//notes_data_[col][row].state = NotesState::None;
			notes_data_[col][row].x = 200.f + 150.f * col;
		}
	}
}

void NotesManager::Update(float judgeLinePosY, float currentTime)
{
	// ノーツ座標更新
	for (int col = 0; col < LANE_NUM; col++) {
		for (int row = 0; row < max_notes_; row++) {
			_notes_->UpDate(judgeLinePosY, currentTime, notes_data_[col][row]);

		}
	}

	JudgeNotes(currentTime);
	//JudgeTest(currentTime);
}

void NotesManager::JudgeNotes(float currentTime)
{
	// レーンに対応するキーが押されていて、かつ判定範囲内であればノーツを削除
	for (int col = 0; col < LANE_NUM; col++) {
		if (Key::Trigger(KEYS_[col])) {
			Sound::PlaySE(SoundId::Click);
			for (int row = 0; row < max_notes_; row++) {
				if (notes_data_[col][row].hasNotes
					&& -good_timing_ < currentTime - notes_data_[col][row].timing
					&& currentTime - notes_data_[col][row].timing < good_timing_) {
					NotesPushAct(col, row);

				}
				//if (notes_data_[col][row].state==NotesState::None
				//	&& -good_timing_ < currentTime - notes_data_[col][row].timing
				//	&& currentTime - notes_data_[col][row].timing < good_timing_) {
				//	NotesPushAct(col, row);

				//}

			}
		}
		line_->ChangeCore(col, Key::State(KEYS_[col]));
	}
}

void NotesManager::Draw()
{
	for (int col = 0; col < LANE_NUM; col++) {
		for (int row = 0; row < max_notes_; row++) {

			_notes_->Draw(notes_data_[col][row]);
		}
	}
	score_->Draw();
}

//bool NotesManager::IsNotesEnd()
//{
//	return _notes_->NotesEnd();
//}

void NotesManager::NotesPushAct(int lane, int num)
{
	notes_data_[lane][num].hasNotes = false;

	//スコア加算
	score_->Add(100);

}


void NotesManager::MusicScoreLoad()
{
	std::ifstream file(file_name_);
	if (!file)
		throw std::runtime_error("開けませんでした。");
	int lane = 0;

	int number_ = 0;
	std::string line;
	while (std::getline(file, line))
	{

		std::istringstream streng_stream_i(line);
		std::string value;

		int note = 0;

		//カンマ区切りで読み込む
		while (std::getline(streng_stream_i, value, ','))
		{
			notes_data_[lane][note].timing = atof(value.c_str());
			notes_data_[lane][note].lane = lane;

			note++;
		}
		notes_count_[lane] = note;
		lane++;
	}
}


