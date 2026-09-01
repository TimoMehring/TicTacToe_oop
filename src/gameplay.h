#pragma once
#include "raylib.h"
#include "playground.h"

enum class GameState{
    Playing,
    PlayerRedWins,
    PlayerBlueWins,
    Draw
};

class Game {
    private:
    Playground playground;
    GameState currentState = GameState::Playing;
    ZoneState currentPlayer = ZoneState::PlayerRed;

    float restartTextTimer = 0.0f;
    bool showRestartText = true;

    public:
    void LoadGraphics();
    void UnloadGraphics();

    void Init();

    void Update();
    void Draw();

    void SwitchPlayer();
    void ResetGame();
};