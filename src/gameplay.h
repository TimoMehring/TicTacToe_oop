#pragma once
#include "raylib.h"
#include "playground.h"

enum class GameState{
    ChooseStartingPlayer,
    PlayerRedTurn,
    PlayerBlueTurn,
    PlayerRedWins,
    PlayerBlueWins
};

class Game {
    private:
    Playground playground;
    GameState currentState = GameState::ChooseStartingPlayer;

    public:
    void ChooseStartingPlayer();
    void Update();
};