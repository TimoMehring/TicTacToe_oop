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
            else{
            SwitchPlayer();
            }
        }
    }
    else if(currentState == GameState::PlayerRedWins || currentState == GameState::PlayerBlueWins){
        if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            ResetGame();
        }
    }
}

void Game::Draw(){
    if(currentState == GameState::Playing){
        playground.Draw();
        playground.DrawBorderAnimation();
    }

    // temoporary, create later DrawWinner method
    if(currentState ==GameState::PlayerRedWins){
        playground.DrawWinningPlayerTextures(ZoneState::PlayerRed);
        DrawText("Wins", 625, 300, 80, WHITE);
        DrawText("Press Enter or Left-Click to Restart Match", 370, 435, 20.0, LIGHTGRAY);
    }
    else if(currentState == GameState::PlayerBlueWins){
        playground.DrawWinningPlayerTextures(ZoneState::PlayerBlue);
        DrawText("Wins", 625, 300, 80, WHITE);
        DrawText("Press Enter or Left-Click to Restart Match", 370, 435, 20.0, LIGHTGRAY);
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