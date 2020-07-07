#pragma once

class Line {
public:
	Line(float judgeLinePosY);
	~Line();
	void Intialize();
	void Draw();
	void ChangeCloreText(bool change);

private:
	void LineDraw();
	void TextDraw();

private:
	float judgeLine_pos_y_;
	int initial_left_pos_x{ 160 };
	int interval{ 150 };

	int line_color;
	int white;
	int red;

};