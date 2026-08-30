#include "gameplay.h"

/* void Game::ChooseStartingPlayer(){
    int randomPlayer = GetRandomValue(0, 1);

     if (randomPlayer == 0){
        currentState = GameState::PlayerRedTurn;
     }
     else{
        currentState = GameState::PlayerBlueWins;
     }
} */



void Game::LoadGraphics(){
    playground.LoadGraphics();
}

void Game::UnloadGraphics(){
    playground.UnloadGraphics();
}

void Game::Init(){
    playground.InitFields();
}

void Game::Update(){
    if(currentState == GameState::Playing){
        if(playground.UpdatePlayground(currentPlayer)){
            SwitchPlayer();
        }
    }
}

void Game::Draw(){
    playground.Draw();
}

void Game::SwitchPlayer(){
    if(currentPlayer == ZoneState::PlayerRed){
        currentPlayer = ZoneState::PlayerBlue;
    }
    else{
        currentPlayer = ZoneState::PlayerRed;
    }
}