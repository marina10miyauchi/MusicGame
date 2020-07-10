#pragma once
struct Vec2
{
	float x;
	float y;
};

class Mouse {
public:
	static const int Left;
	static const int Right;
	static const int Middle;

public:
	static void Initialize();
	static void Update();

	static bool State(int button);
	static bool Trigger(int button);
	static bool Release(int burron);
	static void Finalize();
	static void DebugDraw();
private:
	static int current_state_;
	static int precios_state_;
};