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

    // Border Animation
    int currentBorderFrame = 0;
    float borderAnimationTimer = 0.0f;
    float frameWidth = borderAnimationTexture.width / 9.0f;
    float frameHeight = borderAnimationTexture.height;

    // Player Turn Animation
    int currentPlayerTurnFrame = 0;
    float turnAnimationTimer = 0.0f;

    Texture2D reloadTexture;
    Texture2D playerRedTexture;
    Texture2D playerBlueTexture;

    Texture2D redPlayerMarkTexture;
    Texture2D bluePlayerMarkTexture;

    Texture2D clearWinningTexture;
    Texture2D redPlayerWinsTexture;
    Texture2D bluePlayerWinsTexture;

    // Spritesheets
    Texture2D borderAnimationTexture;
    Texture2D playerBlueTurnTexture;
    Texture2D playerBlueTurnReverseTexture;
    Texture2D playerRedTurnTexture;
    Texture2D playerRedTurnReverseTexture;

    ZoneState zones [3][3];
    Rectangle fields [3][3];

    Sound markSound;
    Sound winSound;


    public:
    void LoadAssets();
    void UnloadAssets();

    void InitFields();
    bool UpdatePlayground(ZoneState currentZoneState);
    void Draw();
    void DrawWinningPlayerTextures(ZoneState winner);

    bool CheckWin(ZoneState currentZoneState);
    bool CheckDraw();

    void UpdateBorderAnimation();
    void DrawBorderAnimation();

    void UpdatePlayerTurnAnimation();
    void DrawPlayerTurnAnimation(ZoneState currentZoneState);

    void Reset();
    

};
