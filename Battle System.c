#include "BattleText.c"

Camera2D dcamera = { 0 };

float Banim = -700.0f;
float Aanim = -700.0f;
bool Banimating = false;
bool Aanimating = false;

float P1H = 0.0f;
float P2H = 0.0f;

int BDN = 0;

bool BattleOptions = false;

int CursorPos[] = {0, 1};

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
    if(BattleOptions == false){
        DrawText(BattleDialog[BDN], GetScreenWidth()*0.02, GetScreenHeight()*0.75-Banim, GetScreenHeight()/20, BLACK);
    }else{
        if(Aanimating == true){
            Aanim+=GetFrameTime()*4000;
            if(Aanim > 1){
                Aanim = 1;
                Aanimating = false;
            }
        }
        DrawRectangleRounded((Rectangle){GetScreenWidth()*0.5-Aanim, GetScreenHeight()*0.73, GetScreenWidth()*0.5, GetScreenHeight()*0.24}, 0.25f, 0, (Color){132, 136, 164, 255});
        DrawRectangleRounded((Rectangle){GetScreenWidth()*0.51-Aanim, GetScreenHeight()*0.74, GetScreenWidth()*0.5-(GetScreenWidth()*0.02), GetScreenHeight()*0.22}, 0.25f, 0, (Color){255, 255, 255, 255});
        DrawText(BattleDialog[BDN], GetScreenWidth()*0.02, GetScreenHeight()*0.75, GetScreenHeight()/20, BLACK);
        DrawText("ATTACK", GetScreenWidth()*0.55-Aanim, GetScreenHeight()*0.77, GetScreenHeight()/15, BLACK);
        DrawText("DEFEND", GetScreenWidth()*0.78-Aanim, GetScreenHeight()*0.77, GetScreenHeight()/15, BLACK);
        DrawText("ITEM", GetScreenWidth()*0.55-Aanim, GetScreenHeight()*0.87, GetScreenHeight()/15, BLACK);
        DrawText("RUN", GetScreenWidth()*0.78-Aanim, GetScreenHeight()*0.87, GetScreenHeight()/15, BLACK);
        DrawRectangleLinesEx((Rectangle){GetScreenWidth()*0.54 + (CursorPos[0]*GetScreenWidth()*0.23)-Aanim, GetScreenHeight()*0.755 + (CursorPos[1]*GetScreenHeight()*0.1), GetScreenWidth()*0.19, GetScreenHeight()*0.09}, GetScreenHeight()/150, BLACK); 
    }
}

void BattleUpdate(){
    if(IsMKeyPressed(0) && CursorPos[0] != 0){CursorPos[0]--;}
    if(IsMKeyPressed(1) && CursorPos[1] != 0){CursorPos[1]--;}
    if(IsMKeyPressed(2) && CursorPos[0] != 1){CursorPos[0]++;}
    if(IsMKeyPressed(3) && CursorPos[1] != 1){CursorPos[1]++;}
    if(IsMKeyPressed(4) && BattleOptions == false){
        BDN++;
        switch(BDN){
            case 3:
                BattleOptions = true;
                Aanimating = true;
                //IntBattle();
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