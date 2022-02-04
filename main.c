#define MapScale 10
#include "raylib.h"

Texture2D TextBoxCharacter;

int GameState = 0;
float Banim;
bool Banimating;

bool Debug = false;

#include "Map.c"
#include "Camera.c"
#include "TalkingToPeople.c"
#include "Nonpc.c"
#include "Player.c"
#include "Render.c"
#include "Battle System.c"

int main() {
    intai();
    const int screenWidth = 1200;
    const int screenHeight = 720;
    IntDCamera();
    InitAudioDevice();
    Music music = LoadMusicStream("Assets/MainTheme.mp3");
    PlayMusicStream(music);

    InitWindow(screenWidth, screenHeight, "RPG Game");
    SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
    ToggleFullscreen();
    HideCursor();

    CameraInt();

    IntTextures();

    while (!WindowShouldClose())
    { 
        UpdateMusicStream(music);
        if(IsKeyPressed(KEY_B)){
            if(GameState == 1){GameState = 0;}
            else{GameState = 1;Banimating = true;Banim = -700;}
        }
        switch (GameState){
            case 0:
                Nonpc();

                PlayerMovement();
                
                RenderScene();

                CameraUpdate();
                break;
            case 1:
                RenderBattle();
                break;
        }
    }

    UnloadTextures();

    CloseWindow();

    return 0;
}