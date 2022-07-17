#pragma once
#include "Snake.h"
#include "Apple.h"
#include <vector>
void drawGrid();
bool isGameOver(Snake snake);
void resetGame(Snake* snake, bool* gameOver,Apple* apple,int* score);
void generateApplePos(Apple* apple, std::vector<std::pair<int, int>> body);
