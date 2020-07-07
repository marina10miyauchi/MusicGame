#pragma once

class Score {
public:
	Score(int score = 0);
	void Initialize(int score = 0);
	void Add(int score);
	void Draw()const;
	int Get()const;
private:

private:
	int score_;
};