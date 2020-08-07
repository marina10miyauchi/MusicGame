#include "MusicScore.h"

std::unordered_map<int, std::string> MusicScore::music_score_;
int MusicScore::current_musicscore_id;

void MusicScore::Iniitialize()
{
	music_score_.clear();
}

void MusicScore::LoadMusicScore(int id, const std::string & fileName)
{
	music_score_[id] = fileName;
}

std::string MusicScore::GetMusicData(int id)
{
	return music_score_[id];
}

std::string MusicScore::GetMusicData()
{
	return music_score_[current_musicscore_id];
}

void MusicScore::SetMusicScore(int id)
{
	current_musicscore_id = id;
}
