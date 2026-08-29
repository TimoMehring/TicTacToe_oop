#include "gameplay.h"

void Game::ChooseStartingPlayer(){
    int randomPlayer = GetRandomValue(0, 1);

     if (randomPlayer == 0){
        currentState = GameState::PlayerRedTurn;
     }
     else{
        currentState = GameState::PlayerBlueWins;
     }
}

void Game::Update(){
    switch(currentState){
        case GameState::ChooseStartingPlayer:
            ChooseStartingPlayer();
            break;

        case GameState::PlayerRedTurn:
            break;

        case GameState::PlayerBlueTurn:
            break;

        case GameState::PlayerRedWins:
            break;

        case GameState::PlayerBlueWins:
            break;
        
    }
}