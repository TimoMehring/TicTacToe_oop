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

    ZoneState zones [3][3];
    Rectangle fields [3][3];

    //ZoneState currentPlayer = ZoneState::PlayerRed;

    public:
    void LoadGraphics();
    void UnloadGraphics();

    void InitFields();
    bool UpdatePlayground(ZoneState player);
    void Draw();

    bool CheckWin(ZoneState player);
    

};
