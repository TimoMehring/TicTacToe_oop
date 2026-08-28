#include "playground.h"

void Playground::LoadGraphics(){
    playgroundTexture = LoadTexture("assets/playground.png");

    redPlayerMarkTexture = LoadTexture("assets/playerredmark.png");
    bluePlayerMarkTexture = LoadTexture("assets/playerbluemark.png");
}

void Playground::UnloadGraphics(){
    UnloadTexture(playgroundTexture);

    UnloadTexture(redPlayerMarkTexture);
    UnloadTexture(bluePlayerMarkTexture);
}

void Playground::Draw(){
    DrawTextureEx(playgroundTexture, {340.0f, 100.0f}, 0.0f, 10.0f, WHITE);
}