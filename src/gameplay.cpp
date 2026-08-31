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
        ClearBackground(LIGHTGRAY);
        playground.DrawWinningPlayerTextures(ZoneState::PlayerRed);
        DrawText("Wins", 625, 300, 80, WHITE);
    }
    else if(currentState == GameState::PlayerBlueWins){
        playground.DrawWinningPlayerTextures(ZoneState::PlayerBlue);
        DrawText("Wins", 625, 300, 80, WHITE);
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