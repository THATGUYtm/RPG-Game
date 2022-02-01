#define MapScale 10
#include "raylib.h"

Texture2D TextBoxCharacter;

bool Debug = false;

#include "Map.c"
#include "Camera.c"
#include "TalkingToPeople.c"
#include "Nonpc.c"
#include "Player.c"
#include "Render.c"

int main() {
    intai();
    const int screenWidth = 1200;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "RPG Game");
    SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
    ToggleFullscreen();
    HideCursor();

    CameraInt();

    IntTextures();

    while (!WindowShouldClose())
    {
        Nonpc();

        PlayerMovement();
        
        RenderScene();

        CameraUpdate();

    }

    UnloadTextures();

    CloseWindow();

    return 0;
}