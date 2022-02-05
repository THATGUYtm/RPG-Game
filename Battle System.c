#include "BattleText.c"

Camera2D dcamera = { 0 };

float Banim = -700.0f;
bool Banimating = false;

float P1H = 0.0f;
float P2H = 0.0f;

int BDN = 0;

void IntBattle(){
    if(GameState == 1){Transition = 1;}
    else{
        Alpha = -GetScreenHeight();
        Transition = 1;
    }
}

void IntDCamera(){
    dcamera.target = (Vector2){ 0, 0 };
    dcamera.offset = (Vector2){ 0, 0 };
    dcamera.rotation = 0.0f;
    dcamera.zoom = 1.0f;
}

void DrawBattleText(){
    DrawText(BattleDialog[BDN], GetScreenWidth()*0.02, GetScreenHeight()*0.75-Banim, GetScreenHeight()/20, BLACK);
}

void BattleUpdate(){
    if(IsKeyPressed(KEY_SPACE)){
        BDN++;
        switch(BDN){
            case 3:
                IntBattle();
                break;
        }
    }
}

void RenderBattle(){
    if(Banimating == true){
        Banim+=GetFrameTime()*1200;
        P1H+=GetFrameTime()*1.7;
        P2H+=GetFrameTime()*1.7;
        if(Banim > 1){
            Banim = 1;
            Banimating = false;
        }
        if(P1H > 1){
            P1H = 1;
            P2H = 1;
        }
    }
        BeginMode2D(dcamera);

            ClearBackground((Color){224, 225, 219, 255});

            //Right most circle
            DrawEllipse(GetScreenWidth()*0.75-Banim, GetScreenHeight()*0.4, GetScreenWidth()/4, GetScreenHeight()*0.1, (Color){196, 200, 174, 255});
            DrawEllipse(GetScreenWidth()*0.75-Banim, GetScreenHeight()*0.4, GetScreenWidth()/4.5, GetScreenHeight()*0.075, (Color){176, 175, 144, 255});  
            
            //Left most circle
            DrawEllipse(GetScreenWidth()*0.25+Banim, GetScreenHeight()*0.7, GetScreenWidth()/4, GetScreenHeight()*0.1, (Color){196, 200, 174, 255});
            DrawEllipse(GetScreenWidth()*0.25+Banim, GetScreenHeight()*0.7, GetScreenWidth()/4.5, GetScreenHeight()*0.075, (Color){176, 175, 144, 255});  

            //P1
            DrawTextureEx(ToadMan, (Vector2){0+Banim, GetScreenHeight()*0.2}, 0, GetScreenHeight()*0.0002, WHITE);

            //Battle Panel
            DrawRectangle(0, GetScreenHeight()*0.7-Banim, GetScreenWidth(), GetScreenHeight()*0.3, (Color){53, 67, 86, 255});
            DrawRectangleRounded((Rectangle){0, GetScreenHeight()*0.73-Banim, GetScreenWidth(), GetScreenHeight()*0.24}, 0.25f, 0, (Color){205, 82, 49, 255});
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.01, GetScreenHeight()*0.74-Banim, GetScreenWidth()-(GetScreenWidth()*0.02), GetScreenHeight()*0.22}, 0.25f, 0, (Color){87, 144, 151, 255});
        
            //P2
            DrawTextureEx(TextBoxCharacter, (Vector2){GetScreenWidth()*0.7-Banim, 0}, 0, GetScreenHeight()*0.0002, WHITE);

            //P2 Health Bar
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.04+Banim, GetScreenHeight()*0.04, GetScreenWidth()*0.35, GetScreenHeight()*0.15}, 0.25f, 0, (Color){32, 31, 37, 255});
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.045+Banim, GetScreenHeight()*0.045, GetScreenWidth()*0.34, GetScreenHeight()*0.14}, 0.25f, 0, (Color){240, 239, 210, 255});
            DrawText("Cute Anime Girl", GetScreenWidth()*0.05+Banim, GetScreenHeight()*0.05, GetScreenHeight()/30, BLACK);
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.055+Banim, GetScreenHeight()*0.14, GetScreenWidth()*0.32, GetScreenHeight()*0.03}, 0.25f, 0, (Color){66, 64, 68, 255});
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.1+Banim, GetScreenHeight()*0.145, GetScreenWidth()*0.27*P1H, GetScreenHeight()*0.02}, 0.25f, 0, (Color){106, 220, 165, 255});
            DrawText("HP", GetScreenWidth()*0.065+Banim, GetScreenHeight()*0.14, GetScreenHeight()/30, BLACK);

            //P1 Health Bar
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.6-Banim, GetScreenHeight()*0.52, GetScreenWidth()*0.35, GetScreenHeight()*0.15}, 0.25f, 0, (Color){32, 31, 37, 255});
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.605-Banim, GetScreenHeight()*0.525, GetScreenWidth()*0.34, GetScreenHeight()*0.14}, 0.25f, 0, (Color){240, 239, 210, 255});
            DrawText("Toad (Cracked at Fortnite)", GetScreenWidth()*0.61-Banim, GetScreenHeight()*0.53, GetScreenHeight()/30, BLACK);
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.615-Banim, GetScreenHeight()*0.625, GetScreenWidth()*0.32, GetScreenHeight()*0.03}, 0.25f, 0, (Color){66, 64, 68, 255});
            DrawRectangleRounded((Rectangle){GetScreenWidth()*0.66-Banim, GetScreenHeight()*0.63, GetScreenWidth()*0.27*P1H, GetScreenHeight()*0.02}, 0.25f, 0, (Color){106, 220, 165, 255});
            DrawText("HP", GetScreenWidth()*0.625-Banim, GetScreenHeight()*0.625, GetScreenHeight()/30, BLACK);

            DrawBattleText();

        EndMode2D();
}