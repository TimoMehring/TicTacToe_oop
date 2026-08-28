#include "raylib.h"
#include "playground.h"
int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "TicTacToe");

    SetTargetFPS(60); 
    
    Playground playground;
    playground.LoadGraphics();
    playground.InitFields();

    while (!WindowShouldClose())    
    {
        playground.UpdatePlayground();

        BeginDrawing();
        
        ClearBackground(LIGHTGRAY);

        playground.Draw();


        EndDrawing();
        
    }
    playground.UnloadGraphics();

    CloseWindow();        

    return 0;
}