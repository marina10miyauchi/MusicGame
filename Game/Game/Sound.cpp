#include "Sound.h"

#include<DxLib.h>

std::unordered_map<int, int> Sound::bgm_map_;
std::unordered_map<int, int> Sound::se_map_;
int Sound::current_bgm_;

void Sound::Initialize()
{
	StopBGM();
	InitSoundMem();
	bgm_map_.clear();
	se_map_.clear();
	current_bgm_ = -1;
}

void Sound::LoadBGM(int id, const std::string & fileName)
{
	bgm_map_[id] = LoadSoundMem(fileName.c_str(), 1);
}

void Sound::PlayBGM(int id)
{
	StopBGM();
	current_bgm_ = bgm_map_[id];
	PlaySoundMem(current_bgm_, DX_PLAYTYPE_BACK | DX_PLAYTYPE_LOOP);
}

void Sound::StopBGM()
{
	if (current_bgm_ == -1)return;
	StopSoundMem(current_bgm_);
	current_bgm_ = -1;
}

void Sound::DeleteBGM(int id)
{
	DeleteSoundMem(bgm_map_[id]);
	bgm_map_.erase(id);
}

void Sound::LoadSE(int id, const std::string & fileName)
{
	se_map_[id] = LoadSoundMem(fileName.c_str());
}

void Sound::PlaySE(int id)
{
	PlaySoundMem(se_map_[id], DX_PLAYTYPE_BACK);
}

void Sound::DeleteSE(int id)
{
	DeleteSoundMem(se_map_[id]);
	se_map_.erase(id);
}

void Sound::Finalize()
{
	Initialize();
}
