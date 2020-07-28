#pragma once

class Score {
public:
	Score() = default;
	void Initialize(int score = 0);
	void Add(int score);
	void Draw()const;
	int Get()const;
private:

private:
	static int score_;
};