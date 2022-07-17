#include "Apple.h"
#include "raylib.h"
Apple::Apple() {
	this->position = { float(GetRandomValue(0,14)) * 40,float(GetRandomValue(1,15)) * 40 };
}
void Apple::draw() {
	DrawRectangleV(this->position, { 40,40 }, this->color);
}