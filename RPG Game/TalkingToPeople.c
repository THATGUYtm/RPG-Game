#include "Dialog.c"

bool IsTalking = false;
char* Text;
float Character = 0;
bool ShouldDrawTextBox = false;
int TextDir = 0;
int DialogNum = 0;
float TextBoxPos[2];
bool MoveChar = false;

void NewTextBox(int Person, int DialogNumtemp, bool mc){
    MoveChar = mc;
    TextDir = 1;
    Text = Dialog[DialogNumtemp];
    DialogNum = DialogNumtemp;
    ShouldDrawTextBox = true;
    IsTalking = true;
    TextBoxPos[0] = 0;
    TextBoxPos[1] = GetScreenHeight();
    if(MoveChar){Character = GetScreenWidth();}
    switch (Person){
        case 0:
            TextBoxCharacter = LoadTexture("Assets/HdCuteAnimeGirl.png");
            break;
    }
}

void DrawTextBox(){
    float DeltaTime = GetFrameTime()*100;
    if(ShouldDrawTextBox){
        DrawTextureEx(TextBoxCharacter, (Vector2){Character, -GetScreenHeight()/20}, 0, GetScreenHeight()*0.000694, WHITE);
        DrawRectangle(TextBoxPos[0]+10, TextBoxPos[1], GetScreenWidth()-20, GetScreenHeight()-TextBoxPos[1], BLACK);
        DrawRectangle(TextBoxPos[0]+10 + 10, TextBoxPos[1] + 10, GetScreenWidth()-40, GetScreenHeight()-20-TextBoxPos[1], WHITE);
        DrawText(Text, TextBoxPos[0]+10 + 20, TextBoxPos[1] + 20, GetScreenHeight()/20, BLACK);
        if(TextDir == 1){
            TextBoxPos[1]-=10*DeltaTime;
            if(MoveChar == true){Character-=20*DeltaTime;}
            if(TextBoxPos[1] < GetScreenHeight()/1.3){
                TextDir = 0;
            }
        }else if(TextDir == 2){
            TextBoxPos[1]+=10*DeltaTime;
            Character+=20*DeltaTime;
            if(TextBoxPos[1] > GetScreenHeight()){
                ShouldDrawTextBox = false;
                IsTalking = false;
            }
        }else if(TextDir == 3){
            TextBoxPos[1]+=10*DeltaTime;
            if(TextBoxPos[1] > GetScreenHeight()){
                MoveChar = false;
                TextDir = 1;
                Text = Dialog[DialogNum];
                TextBoxPos[0] = 0;
                TextBoxPos[1] = GetScreenHeight();
            }
        }else{
            if(IsKeyPressed(KEY_SPACE)){
                DialogNum++;
                switch(DialogNum){
                    case 2:
                        TextDir = 2;
                        break;
                    default:
                        TextDir = 3;
                        break;
                }
            }
        }
    }
}