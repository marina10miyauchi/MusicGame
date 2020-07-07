#include "NotesCount.h"



NotesCount::NotesCount()
{
}

NotesCount::~NotesCount()
{
}

void NotesCount::NotesUpdate()
{
	if (count_ == -1) {
		startTime_ = GetNowHiPerformanceCount();
		count_=0;

	}
	now_time_ = GetNowSysPerformanceCount();
	currentTime = (int)((now_time_ - start_time_) / 10000);
}

int *NotesCount::CurrentTime()
{
	//return this->currentTime;
	return &currentTime;
}

void NotesCount::TestDraw()
{
	SetFontSize(24);
	int test = *CurrentTime();
	DrawFormatString(0, 30, GetColor(255, 255, 255), "%d", test);

}
