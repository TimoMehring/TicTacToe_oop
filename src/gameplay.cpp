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
            if(playground.CheckWin(currentPlayer)){
                if(currentPlayer == ZoneState::PlayerRed){
                    currentState = GameState::PlayerRedWins;
                }
                else{
                    currentState = GameState::PlayerBlueWins;
                }
            }
            else{
            SwitchPlayer();
            }
        }
    }
}

void Game::Draw(){
    playground.Draw();

    // temoporary, create later DrawWinner method
    if(currentState ==GameState::PlayerRedWins){
        DrawText("Player Red wins!", 430, 650, 40, RED);
    }
    else if(currentState == GameState::PlayerBlueWins){
        DrawText("Player Blue wins!", 430, 650, 40, BLUE);
    }
}

void Game::SwitchPlayer(){
    if(currentPlayer == ZoneState::PlayerRed){
        currentPlayer = ZoneState::PlayerBlue;
    }
    else{
        currentPlayer = ZoneState::PlayerRed;
    }
}