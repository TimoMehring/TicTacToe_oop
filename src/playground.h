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
    Texture2D borderAnimationTexture;
    int currentBorderFrame = 0;
    float borderAnimationTimer = 0.0f;
    float frameWidth = borderAnimationTexture.width / 9.0f;
    float frameHeight = borderAnimationTexture.height;

    Texture2D reloadTexture;
    Texture2D playerRedTexture;
    Texture2D playerBlueTexture;

    Texture2D redPlayerMarkTexture;
    Texture2D bluePlayerMarkTexture;

    Texture2D clearWinningTexture;
    Texture2D redPlayerWinsTexture;
    Texture2D bluePlayerWinsTexture;

    ZoneState zones [3][3];
    Rectangle fields [3][3];


    public:
    void LoadGraphics();
    void UnloadGraphics();

    void InitFields();
    bool UpdatePlayground(ZoneState currentZoneState);
    void Draw();
    void DrawWinningPlayerTextures(ZoneState winner);

    bool CheckWin(ZoneState currentZoneState);

    void UpdateBorderAnimation();
    void DrawBorderAnimation();

    void Reset();
    

};
