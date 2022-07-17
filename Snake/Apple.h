#pragma once
#include "raylib.h"
struct Apple {
	Vector2 position;
	Color color = RED;
	Apple();
	void draw();
};
