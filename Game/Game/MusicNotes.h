#pragma once
#include"Actor.h"
#include<string>
#include"NotesData.h"


class MusicNotes :public Actor {
	//
	MusicNotes(IWorld& _world, NotesState _state, Vector2 _position, float _timing, int lane);

	virtual void Updata(float _deltaTime)override;


private:
	NotesState state_;
	float timing_;

};