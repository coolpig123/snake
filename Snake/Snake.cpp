#include "Snake.h"
#include "raylib.h"
#include <vector>
#include <time.h>
#include "functions.h"
Snake::Snake(Color color) {
	this->body.push_back({ 0, 40 });
	this->color = color;
}
void Snake::draw() {
	for (int i = 0; i < body.size(); i++) {
		DrawRectangle(body[i].first, body[i].second, 40, 40, this->color);
	}
}
void Snake::move() {
	if (IsKeyPressed(KEY_LEFT) && right == false) {
		up = false;
		down = false;
		left = true;
	}
	else if (IsKeyPressed(KEY_RIGHT) && left == false) {
		up = false;
		down = false;
		right = true;
	}
	else if (IsKeyPressed(KEY_UP) && down == false) {
		right = false;
		left = false;
		up = true;
	}
	else if (IsKeyPressed(KEY_DOWN) && up == false) {
		right = false;
		left = false;
		down = true;
	}
	if (down) {
		body.insert(body.begin(), { body[0].first, body[0].second + 40 });
		body.erase(body.begin() + body.size() - 1);
	}
	else if (up) {
		body.insert(body.begin(), { body[0].first, body[0].second - 40 });
		body.erase(body.begin() + body.size() - 1);
	}
	else if (right) {
		body.insert(body.begin(), { body[0].first + 40 , body[0].second });
		if (body.size() > 1)
			body.erase(body.begin() + body.size() - 1);
	}
	else if (left) {
		body.insert(body.begin(), { body[0].first - 40 , body[0].second });
		body.erase(body.begin() + body.size() - 1);
	}
	
}
void Snake::isAppleEaten(Apple* apple,int* score) {
	if (this->body[0].first ==  (*apple).position.x &&
		this->body[0].second == (*apple).position.y) {
		body.push_back(body[0]);
		generateApplePos(apple, body);
		(*score)++;
	}
}