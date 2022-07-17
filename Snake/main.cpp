#include "raylib.h"
#include "functions.h"
#include <iostream>
#include "snake.h"
#include "apple.h"
#include "string"
int main()
{
    const int screenWidth = 600;
    const int screenHeight = 640;
    InitWindow(screenWidth, screenHeight, "Snake");
    Snake snake(BLUE); 
    Apple apple;
    unsigned char brightness = 255;
    bool plusBrightness;
    bool gameOver = false;
    int score = 0;
    int highScore = 0;
    while(!WindowShouldClose()) {
        
        if (!gameOver) {
            SetTargetFPS(7);
            snake.isAppleEaten(&apple,&score);
            snake.move();
            BeginDrawing();
                DrawText(TextFormat("score : %i", score), 20, 2, 40, WHITE);
                DrawText(TextFormat("high score : %i", highScore), 290, 2, 40, WHITE);
                ClearBackground(BLACK);
                drawGrid();
                snake.draw();
                apple.draw();
            EndDrawing();
        }
        else {
            SetTargetFPS(144);
            BeginDrawing();
                ClearBackground(BLACK);
                DrawText("GAME OVER", 115, 100, 60, WHITE);
                DrawText("Press space to start over", 100, 350, 30, { 255, 255, 255, brightness });
            EndDrawing();
            if (IsKeyPressed(KEY_SPACE)) {
                if (score > highScore) {
                    highScore = score;
                }
                resetGame(&snake, &gameOver, &apple,&score);
            }
            if (brightness == 0) {
                plusBrightness = true;
            }else if (brightness == 255) { 
                plusBrightness = false; 
            }
            if (plusBrightness) { 
                brightness+=1;
            } else { 
                brightness-=1; 
            }
        } 
        gameOver = isGameOver(snake);
    }
    CloseWindow();
}

