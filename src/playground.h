#pragma once
#include "raylib.h"

enum class ZoneState { 
    Empty,
    PlayerRed,
    PlayerBlue
};

class Playground {
    private:
    Texture2D playgroundTexture;
    Texture2D redPlayerMarkTexture;
    Texture2D bluePlayerMarkTexture;

    public:
    void LoadGraphics();
    void UnloadGraphics();
    void Draw();
    

};
