#pragma once

class JudgeNotes {
public:
	JudgeNotes();
	~JudgeNotes();

	//�m�[�c�̔���
	void Judge();

private:
	void SetKey();
	bool GoodJudge();
	bool PerfectJudge();

private:
	int* key;

};