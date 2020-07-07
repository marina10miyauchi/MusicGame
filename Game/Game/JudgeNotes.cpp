#include "JudgeNotes.h"
#include<DxLib.h>

JudgeNotes::JudgeNotes()
{
}

JudgeNotes::~JudgeNotes()
{
}

void JudgeNotes::Judge()
{
}

void JudgeNotes::SetKey()
{
	key = new int[4]{
		KEY_INPUT_Z,
		KEY_INPUT_X,
		KEY_INPUT_C,
		KEY_INPUT_V
	};
}

bool JudgeNotes::GoodJudge()
{
	return false;
}

bool JudgeNotes::PerfectJudge()
{
	return false;
}
