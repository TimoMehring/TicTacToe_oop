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
    playground.LoadAssets();
}

void Game::UnloadGraphics(){
    playground.UnloadAssets();
}

void Game::Init(){
    playground.InitFields();
}

void Game::Update(){
    if(currentState == GameState::Playing){
        playground.UpdatePlayerTurnAnimation();
        playground.UpdateBorderAnimation();
        if(playground.UpdatePlayground(currentPlayer)){
            if(playground.CheckWin(currentPlayer)){
                if(currentPlayer == ZoneState::PlayerRed){
                    currentState = GameState::PlayerRedWins;
                }
                else{
                    currentState = GameState::PlayerBlueWins;
                }
            }
            else if(playground.CheckDraw()){
                currentState = GameState::Draw;
            }
            else{
            SwitchPlayer();
            }
        }
    }
    else if(currentState == GameState::PlayerRedWins || currentState == GameState::PlayerBlueWins || currentState == GameState::Draw){

        playground.UpdateWinningPlayerTextures();

        if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            ResetGame();
        }
    }
}

void Game::Draw(){
    playground.Draw();
    playground.DrawBorderAnimation();

    if(currentState == GameState::Playing){
        playground.DrawPlayerTurnAnimation(currentPlayer);
    }

    if(currentState ==GameState::PlayerRedWins){
            playground.DrawWinningPlayerTextures(ZoneState::PlayerRed);
    }
    else if(currentState == GameState::PlayerBlueWins){
            playground.DrawWinningPlayerTextures(ZoneState::PlayerBlue);
        
    }
    else if(currentState == GameState::Draw){
        playground.DrawMatchResultDraw();
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

void Game::ResetGame(){
    currentState = GameState::Playing;
    currentPlayer = ZoneState::PlayerRed;


    playground.Reset();
}