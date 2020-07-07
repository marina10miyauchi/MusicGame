#pragma once

class JudgeNotes {
public:
	JudgeNotes();
	~JudgeNotes();

	//ƒm[ƒc‚Ì”»’è
	void Judge();

private:
	void SetKey();
	bool GoodJudge();
	bool PerfectJudge();

private:
	int* key;

};