#define MapScale 10
#include "raylib.h"
#include "raymath.h"

Texture2D TextBoxCharacter;
Model Map;

int GameState = 0;
float Banim;
bool Banimating;

bool Debug = false;

void IntBattle();

int Transition = 0;
float Alpha;

#include "Movement.c"
#include "Map.c"
#include "OverworldMap.c"
#include "Camera.c"
#include "TalkingToPeople.c"
#include "Nonpc.c"
#include "Player.c"
#include "Render.c"
#include "Battle System.c"

void DrawTransition(){
    switch(Transition){
        case 1:
            BeginMode2D(dcamera);
                Alpha+=GetFrameTime()*4000;
                DrawRectangle(0, Alpha, GetScreenWidth(), GetScreenHeight(), BLACK);
            EndMode2D();
            if(Alpha > 0){
                Transition = 2;
            }
            break;
        case 2:
            BeginMode2D(dcamera);
                Alpha+=GetFrameTime()*4000;
                DrawRectangle(0, Alpha, GetScreenWidth(), GetScreenHeight(), BLACK);
            EndMode2D();
            if(GameState == 1){GameState = 0;}
            else{
                GameState = 1;
                Banimating = true;
                Banim = -700;
                P1H = 0.0f;
                P2H = 0.0f;
                BDN = 0;
            }
            Transition = 3;
            break;
        case 3:
            BeginMode2D(dcamera);
                Alpha+=GetFrameTime()*2200;
                DrawRectangle(0, Alpha, GetScreenWidth(), GetScreenHeight(), BLACK);
            EndMode2D();
            if(Alpha > GetScreenHeight()*2){
                Transition = 0;
                Alpha = 0-GetScreenHeight();
            }
            break;
    }
}

int main() {
    intai();
    const int screenWidth = 1200;
    const int screenHeight = 720;
    IntDCamera();
    InitAudioDevice();
    Music music = LoadMusicStream("Assets/MainTheme.mp3");
    PlayMusicStream(music);

    SetConfigFlags(FLAG_MSAA_4X_HINT || FLAG_VSYNC_HINT); 

    InitWindow(screenWidth, screenHeight, "RPG Game");
    SetWindowSize(GetMonitorWidth(GetCurrentMonitor()*2), GetMonitorHeight(GetCurrentMonitor()*2));
    ToggleFullscreen();
    HideCursor();

    CameraInt();

    IntTextures();

    target = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    while (!WindowShouldClose())
    { 
        UpdateMusicStream(music);
        
        switch (GameState){
            case 0:
                Nonpc();

                PlayerMovement();
                
                RenderScene();

                CameraUpdate();
                break;
            case 1:
                BeginDrawing();
                    BattleUpdate();
                    RenderBattle();
                break;
        }
        DrawTransition();
        EndDrawing();
    }

    UnloadTextures();

    CloseWindow();

    return 0;
}