#pragma once
#include "raylib.h"
#include "apple.h"
#include <vector>
struct Snake {
	std::vector<std::pair<int, int>> body;
	Color color;
	bool left = false;
	bool right = true;
	bool up = false;
	bool down = false;
	void move();
	void draw();
	void isAppleEaten(Apple* apple,int* score);
	Snake(Color color);
};