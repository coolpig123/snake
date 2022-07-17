#include "functions.h"
#include "raylib.h"
#include "Snake.h"
#include <vector>
void drawGrid() {
	bool color = false;
	for (int i = 0; i < 600; i += 40) {
		for (int j = 40; j < 640; j += 40) {
			if (color) {
				DrawRectangle(i, j, 40, 40, {20,50,10,255});
				color = false;
			}
			else {
				DrawRectangle(i, j, 40, 40, DARKGREEN);
				color = true;
			}
		}
	}
}
bool isGameOver(Snake snake) {
	if (snake.body[0].first < 0 || snake.body[0].first > 560 ||
		snake.body[0].second < 40 || snake.body[0].second > 600) {
		return true;
	}
	for (int i = 0; i < snake.body.size(); i++) {
		for (int j = 0; j < snake.body.size(); j++) {
			if (snake.body[i].first == snake.body[j].first &&
				snake.body[i].second == snake.body[j].second && i != j) {
				return true;
			}
		}
	}
	return false;
}
void resetGame(Snake* snake, bool* gameOver, Apple* apple,int* score) {
	*gameOver = false;
	(*snake).body.clear();
	(*snake).body.push_back({ 0, 40 });
	(*snake).right = true;
	(*snake).left = false;
	(*snake).up = false;
	(*snake).down = false;
	(*apple).position = {float(GetRandomValue(0,14)) * 40,float(GetRandomValue(1,15)) * 40};
	(*score) = 0;
}
void generateApplePos(Apple* apple,std::vector<std::pair<int,int>> body) {
	bool equalPos = false;
	do {
		equalPos = false;
		apple->position = { float(GetRandomValue(0,14)) * 40,float(GetRandomValue(1,15)) * 40 };
		for (int i = 0; i < body.size(); i++) {
			if (body[i].first == apple->position.x &&
				body[i].second == apple->position.y) {
				equalPos = true;
				break;
			}
		}
	} while (equalPos);
}