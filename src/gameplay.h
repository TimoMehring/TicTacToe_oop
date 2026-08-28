#pragma once
#include "raylib.h"
#include "playground.h"

enum class GameState{
    Startscreen
};

class Game {
    private:
    GameState currentState = GameState::Startscreen;

    public:
    void Update();
};