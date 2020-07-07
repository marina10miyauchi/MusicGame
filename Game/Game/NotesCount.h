#pragma once

#include<Windows.h>
#include<DxLib.h>

class NotesCount {
public:
	NotesCount();
	~NotesCount();
	void NotesUpdate();

	int *CurrentTime();

	void TestDraw();


private:
	int startTime_{0};
	int count_{-1};
	float fps_{0};


	LONGLONG start_time_;
	LONGLONG now_time_;

	int currentTime;

};