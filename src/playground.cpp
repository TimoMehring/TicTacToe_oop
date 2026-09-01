#include "playground.h"

void Playground::LoadAssets(){
    // Textures
    playgroundTexture = LoadTexture("assets/playground.png");
    reloadTexture = LoadTexture("assets/reload.png");

    playerRedTexture = LoadTexture("assets/playerred.png");
    playerBlueTexture = LoadTexture("assets/playerblue.png");

    redPlayerMarkTexture = LoadTexture("assets/playerredmark.png");
    bluePlayerMarkTexture = LoadTexture("assets/playerbluemark.png");

    clearWinningTexture = LoadTexture("assets/clear_winning.png");
    redPlayerWinsTexture = LoadTexture("assets/playerredwins.png");
    bluePlayerWinsTexture  = LoadTexture("assets/playerbluewins.png");

    // Spritesheets
    borderAnimationTexture = LoadTexture("assets/playground_animation.png");
    playerRedTurnTexture = LoadTexture("assets/PlayerRedTurn.png");
    playerRedTurnReverseTexture = LoadTexture("assets/PlayerRedTurnReverse.png");
    playerBlueTurnTexture = LoadTexture("assets/PlayerBlueTurn.png");
    playerBlueTurnReverseTexture = LoadTexture("assets/PlayerBlueTurnReverse.png");

    // Sound & Music Section
    markSound = LoadSound("assets/mark_sound.wav");
    winSound = LoadSound("assets/win_sound.wav");
}

void Playground::UnloadAssets(){
    // Textures
    UnloadTexture(playgroundTexture);
    UnloadTexture(reloadTexture);

    UnloadTexture(playerRedTexture);
    UnloadTexture(playerBlueTexture);

    UnloadTexture(redPlayerMarkTexture);
    UnloadTexture(bluePlayerMarkTexture);

    UnloadTexture(clearWinningTexture);
    UnloadTexture(redPlayerWinsTexture);
    UnloadTexture(bluePlayerWinsTexture);

    // Spritesheets
    UnloadTexture(borderAnimationTexture);
    UnloadTexture(playerRedTurnTexture);
    UnloadTexture(playerBlueTurnReverseTexture);
    UnloadTexture(playerBlueTurnTexture);
    UnloadTexture(playerBlueTurnReverseTexture);


    // Sound & Music
    UnloadSound(markSound);
    UnloadSound(winSound);
}

void Playground::InitFields(){
    const float startX = 340.0f;
    const float startY = 100.0f;

    const float scale = 10.0f;

    const float border = 1.0f * scale;
    const float divider = 1.0f * scale;
    const float fieldSize = 16.0f * scale;

    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            fields[row][col] = {
                startX + border + col * (fieldSize + divider),
                startY + border + row * (fieldSize + divider),
                fieldSize, fieldSize
            };
            zones[row][col] = ZoneState::Empty;
        }
    }
}

bool Playground::UpdatePlayground(ZoneState currentZoneState){
    Vector2 mousePosition = GetMousePosition();

    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(CheckCollisionPointRec(mousePosition, fields[row][col]) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
                if(zones[row][col] == ZoneState::Empty){
                    zones[row][col] = currentZoneState;

                    PlaySound(markSound);
                    return true;
                }
            }
        }
    }
    return false;

}

void Playground::Draw(){
    DrawTextureEx(playgroundTexture, {340.0f, 100.0f}, 0.0f, 10.0f, WHITE);
    //DrawTextureEx(reloadTexture, {550.0f, 650.0f}, 0.0f, 3.0f, WHITE);

    //DrawTextureEx(playerBlueTexture, {50.0f, 200.0f}, 0.0f, 8.0f, WHITE);
    //DrawTextureEx(playerRedTexture, {900.0f, 200.0f}, 0.0f, 8.0f, WHITE);

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (zones[row][col] == ZoneState::PlayerRed){
                DrawTextureEx(redPlayerMarkTexture, {fields[row][col].x +40.0f, fields[row][col].y +40.0f}, 0.0f, 10.0f, WHITE);
            }
            else if(zones[row][col] == ZoneState::PlayerBlue){
                DrawTextureEx(bluePlayerMarkTexture, {fields[row][col].x +40.0f, fields[row][col].y +40.0f}, 0.0f, 10.0f, WHITE);
            }
        }
    }

    
}

bool Playground::CheckWin(ZoneState currentZoneState){
    // horizontal check
    for(int row = 0; row < 3; row++){
        if(zones[row][0] == currentZoneState && zones[row][1] == currentZoneState && zones[row][2] == currentZoneState){
            PlaySound(winSound);
            return true;
        }
    }
    // vertical check
    for(int col = 0; col < 3; col++){
        if(zones[0][col] == currentZoneState && zones[1][col] == currentZoneState && zones[2][col] == currentZoneState){
            PlaySound(winSound);
            return true;
        }
    }
    // diagonal checks
    if(zones[0][0] == currentZoneState && zones[1][1] == currentZoneState && zones[2][2] == currentZoneState){
        PlaySound(winSound);
        return true;
    }
    else if(zones[2][0] == currentZoneState && zones[1][1] == currentZoneState && zones[0][2] == currentZoneState){
        PlaySound(winSound);
        return true;
    }
    
    return false;
}

bool Playground::CheckDraw(){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(zones[row][col] == ZoneState::Empty){
                return false;
            }
        }
    }
    return true;
}

void Playground::DrawWinningPlayerTextures(ZoneState winner){
    //DrawTextureEx(clearWinningTexture, {0.0f, 0.0f}, 0.0f, 1.0f, WHITE); 
    if(winner == ZoneState::PlayerRed){
        DrawTextureEx(redPlayerWinsTexture, {325.0f, 200.0f}, 0.0f, 5.5f, WHITE);
    }
    else if(winner == ZoneState::PlayerBlue){
        DrawTextureEx(bluePlayerWinsTexture, {325.0f, 200.0f}, 0.0f, 5.5f, WHITE);
    }
}

void Playground::UpdateBorderAnimation(){
    borderAnimationTimer += GetFrameTime();

    if(borderAnimationTimer >= 0.5){
        currentBorderFrame++;

        if(currentBorderFrame >= 9){
            currentBorderFrame = 0;
        }
        borderAnimationTimer = 0.0f;
    }
}

void Playground::DrawBorderAnimation(){
    float frameWidth = borderAnimationTexture.width / 9.0f;
    float frameHeight = borderAnimationTexture.height;

    Rectangle source = {currentBorderFrame * frameWidth, currentBorderFrame * 0.0f, frameWidth, frameHeight};
    Rectangle destination = {320.0f, 80.0f, frameWidth  * 10.0f, frameHeight * 10.0f};

    DrawTexturePro(borderAnimationTexture, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);
}

void Playground::Reset(){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            zones[row][col] = ZoneState::Empty;
        }
    }
}

void Playground::UpdatePlayerTurnAnimation(){
    turnAnimationTimer += GetFrameTime();

    if(turnAnimationTimer >= 0.5){
        currentPlayerTurnFrame++;

        if(currentPlayerTurnFrame >= 2){
            currentPlayerTurnFrame = 0;
        }
        turnAnimationTimer = 0.0f;
    }

}

void Playground::DrawPlayerTurnAnimation(ZoneState currentZoneState){
    float frameWidth = playerBlueTurnTexture.width / 2.0f;
    float frameHeight = playerBlueTurnTexture.height;

    //Rectangle source = {currentBorderFrame * frameWidth, currentBorderFrame * 0.0f, frameWidth, frameHeight};
    Rectangle source2 = {currentPlayerTurnFrame * frameWidth, 0.0f, frameWidth, frameHeight};
    //Rectangle destination = {320.0f, 80.0f, frameWidth  * 10.0f, frameHeight * 10.0f};
    Rectangle destination = {900.0f, 200.0f, frameWidth * 8.0f, frameHeight * 8.0f};
    Rectangle destination2 = {50.0f, 200.0f, frameWidth * 8.0f, frameHeight * 8.0f};

    if(currentZoneState == ZoneState::PlayerRed){
        DrawTexturePro(playerRedTurnTexture, source2, destination, {0.0f,0.0f},0.0f,WHITE);
        //DrawTextureEx(playerBlueTexture, {50.0f, 200.0f}, 0.0f, 8.0f, WHITE);
        DrawTexturePro(playerBlueTurnReverseTexture, source2, destination2, {0.0f,0.0f},0.0f,WHITE);
    }
    else if(currentZoneState == ZoneState::PlayerBlue){
        DrawTexturePro(playerBlueTurnTexture, source2, destination2, {0.0f,0.0f},0.0f,WHITE);
        //DrawTextureEx(playerRedTexture, {900.0f, 200.0f}, 0.0f, 8.0f, WHITE);
        DrawTexturePro(playerRedTurnReverseTexture, source2, destination, {0.0f,0.0f},0.0f,WHITE);
    }
}