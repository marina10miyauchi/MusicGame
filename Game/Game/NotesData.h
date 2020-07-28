#pragma once
enum NotesState {
	None,
	Good,
	Prefect,
	Miss
};

struct NotesDate
{
	//
	bool hasNotes;
	//
	NotesState  state;
	//pos_x
	float x;
	//pos_y
	float y;
	//ノーツの判定ライン到達カウント
	float timing;
	//番号
	int num;
	//レーン番号
	int lane;
};