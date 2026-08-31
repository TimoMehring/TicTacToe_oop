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
    Texture2D reloadTexture;
    Texture2D playerRedTexture;
    Texture2D playerBlueTexture;

    Texture2D redPlayerMarkTexture;
    Texture2D bluePlayerMarkTexture;

    ZoneState zones [3][3];
    Rectangle fields [3][3];


    public:
    void LoadGraphics();
    void UnloadGraphics();

    void InitFields();
    bool UpdatePlayground(ZoneState currentZoneState);
    void Draw();

    bool CheckWin(ZoneState currentZoneState);
    

};
