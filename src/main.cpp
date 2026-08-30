#include "raylib.h"
#include "playground.h"
#include "gameplay.h"

int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "TicTacToe");

    SetTargetFPS(60); 
    
    Game game;
    game.LoadGraphics();
    game.Init();

    while (!WindowShouldClose())    
    {
        game.Update();

        BeginDrawing();
        
        ClearBackground(LIGHTGRAY);

        game.Draw();


        EndDrawing();
        
    }
    game.UnloadGraphics();

    CloseWindow();        

    return 0;
}