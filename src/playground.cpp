#include "playground.h"

void Playground::LoadGraphics(){
    playgroundTexture = LoadTexture("assets/playground.png");
    playerRedTexture = LoadTexture("assets/playerred.png");
    playerBlueTexture = LoadTexture("assets/playerblue.png");

    redPlayerMarkTexture = LoadTexture("assets/playerredmark.png");
    bluePlayerMarkTexture = LoadTexture("assets/playerbluemark.png");
}

void Playground::UnloadGraphics(){
    UnloadTexture(playgroundTexture);
    UnloadTexture(playerRedTexture);
    UnloadTexture(playerBlueTexture);

    UnloadTexture(redPlayerMarkTexture);
    UnloadTexture(bluePlayerMarkTexture);
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

                    return true;
                }
            }
        }
    }
    return false;

}

void Playground::Draw(){
    DrawTextureEx(playgroundTexture, {340.0f, 100.0f}, 0.0f, 10.0f, WHITE);
    DrawTextureEx(playerBlueTexture, {50.0f, 200.0f}, 0.0f, 8.0f, WHITE);
    DrawTextureEx(playerRedTexture, {900.0f, 200.0f}, 0.0f, 8.0f, WHITE);

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
    for(int row = 0; row < 3; row++){
        if(zones[row][0] == currentZoneState && zones[row][1] == currentZoneState &&zones[row][2] == currentZoneState){
            return true;
        }
    }
    return false;
}