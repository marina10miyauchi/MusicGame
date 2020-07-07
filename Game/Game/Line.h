#pragma once

enum Lane {
	Z,
	X,
	C,
	V,
	Max
};

class Line {
public:
	Line(float judgeLinePosY);
	~Line();
	void Draw();
	void ChangeCore(int lane, bool change);


private:
	void LineDraw();
	void TextDraw();

private:
	float judgeLine_pos_y_;
	int initial_left_pos_x{ 160 };
	int interval{ 150 };

	unsigned int current_color_[(int)Lane::Max];
};