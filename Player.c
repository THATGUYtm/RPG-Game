#define TalkingRadius 1.1

/*
0 = X
1 = Y
2 = Movement Speed
3 = Animation Timer
4 = Direction
*/
float Player[] = {3.5*MapScale, 4.9f*MapScale, MapScale*0.004, 0.0f, 3.0f};
Texture2D CharacterSpriteSheet;
Rectangle CharacterAnimationRectangle = { 5.0f, 96.0f, 18.0f, 32.0f};
int PlayerChunk[2];

bool IsWalking = false;

void PlayerAnimation(){
    if(Player[3] > 1){
        Player[3] = 0;
    }
    switch((int)Player[4]){
        case 0:
            if(Player[3] < 0.125f){CharacterAnimationRectangle = (Rectangle){3.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.25f){CharacterAnimationRectangle = (Rectangle){28.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.375f){CharacterAnimationRectangle = (Rectangle){51.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.5f){CharacterAnimationRectangle = (Rectangle){75.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.625f){CharacterAnimationRectangle = (Rectangle){99.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.75f){CharacterAnimationRectangle = (Rectangle){123.0f, 64.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.875f){CharacterAnimationRectangle = (Rectangle){147.0f, 64.0f, 18.0f, 32.0f};}
            else {CharacterAnimationRectangle = (Rectangle){171.0f, 64.0f, 18.0f, 32.0f};}
            break;
        case 1: 
            if(Player[3] < 0.125f){CharacterAnimationRectangle = (Rectangle){3.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.25f){CharacterAnimationRectangle = (Rectangle){28.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.375f){CharacterAnimationRectangle = (Rectangle){51.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.5f){CharacterAnimationRectangle = (Rectangle){75.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.625f){CharacterAnimationRectangle = (Rectangle){99.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.75f){CharacterAnimationRectangle = (Rectangle){123.0f, 32.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.875f){CharacterAnimationRectangle = (Rectangle){147.0f, 32.0f, 18.0f, 32.0f};}
            else {CharacterAnimationRectangle = (Rectangle){171.0f, 32.0f, 18.0f, 32.0f};}
            break;
        case 2: 
            if(Player[3] < 0.125f){CharacterAnimationRectangle = (Rectangle){3.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.25f){CharacterAnimationRectangle = (Rectangle){28.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.375f){CharacterAnimationRectangle = (Rectangle){51.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.5f){CharacterAnimationRectangle = (Rectangle){75.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.625f){CharacterAnimationRectangle = (Rectangle){99.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.75f){CharacterAnimationRectangle = (Rectangle){123.0f, 96.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.875f){CharacterAnimationRectangle = (Rectangle){147.0f, 96.0f, 18.0f, 32.0f};}
            else {CharacterAnimationRectangle = (Rectangle){171.0f, 96.0f, 18.0f, 32.0f};}
            break;
        case 3:
            if(Player[3] < 0.125f){CharacterAnimationRectangle = (Rectangle){3.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.25f){CharacterAnimationRectangle = (Rectangle){28.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.375f){CharacterAnimationRectangle = (Rectangle){51.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.5f){CharacterAnimationRectangle = (Rectangle){75.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.625f){CharacterAnimationRectangle = (Rectangle){99.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.75f){CharacterAnimationRectangle = (Rectangle){123.0f, 0.0f, 18.0f, 32.0f};}
            else if(Player[3] < 0.875f){CharacterAnimationRectangle = (Rectangle){147.0f, 0.0f, 18.0f, 32.0f};}
            else {CharacterAnimationRectangle = (Rectangle){171.0f, 0.0f, 18.0f, 32.0f};}
            break;
    }
}

bool CantWalkThrough(){
    switch(OverWorldMap[PlayerChunk[1]][PlayerChunk[0]]){
        case 2:
        case 3:
        case 4:
        case 5:
        case 9:
            return true;
            break;
        
        default:
            return false;
            break;
    }
}

void CollisonDetection(int dir){
    float DeltaTime = GetFrameTime()*100;
    PlayerChunk[0] = (int)Player[0]/MapScale;
    PlayerChunk[1] = (int)Player[1]/MapScale;
    switch (dir){
        case 0:
            if(CantWalkThrough()){
                CameraPos[0] += Player[2]*DeltaTime;
                Player[0] += Player[2]*DeltaTime;
            }
            break;
        case 1:
            if(CantWalkThrough()){
                CameraPos[2] += Player[2]*DeltaTime;
                Player[1] += Player[2]*DeltaTime;
            }
            break;
        case 2:
            if(CantWalkThrough()){
                CameraPos[0] -= Player[2]*DeltaTime;
                Player[0] -= Player[2]*DeltaTime;
            }
            break;
        case 3:
            if(CantWalkThrough()){
                CameraPos[2] -= Player[2]*DeltaTime;
                Player[1] -= Player[2]*DeltaTime;
            }
            break;
        case 4:
            if(CantWalkThrough()){
                CameraPos[0] += Player[2]*DeltaTime;
                Player[0] += Player[2]*DeltaTime;
                CameraPos[2] += Player[2]*DeltaTime;
                Player[1] += Player[2]*DeltaTime;
            }
            break;
        case 5:
            if(CantWalkThrough()){
                CameraPos[0] -= Player[2]*DeltaTime;
                Player[0] -= Player[2]*DeltaTime;
                CameraPos[2] += Player[2]*DeltaTime;
                Player[1] += Player[2]*DeltaTime;
            }
            break;
        case 6:
            if(CantWalkThrough()){
                CameraPos[0] -= Player[2]*DeltaTime;
                Player[0] -= Player[2]*DeltaTime;
                CameraPos[2] -= Player[2]*DeltaTime;
                Player[1] -= Player[2]*DeltaTime;
            }
            break;
        case 7:
            if(CantWalkThrough()){
                CameraPos[0] += Player[2]*DeltaTime;
                Player[0] += Player[2]*DeltaTime;
                CameraPos[2] -= Player[2]*DeltaTime;
                Player[1] -= Player[2]*DeltaTime;
            }
            break;
    }
}

void PlayerMovement(){
    float DeltaTime = GetFrameTime()*100;
    Player[3] += GetFrameTime();

    PlayerAnimation();

    if (IsKeyPressed(KEY_SPACE) && IsTalking == false){
        if(Player[0] > NPCQords[0]-TalkingRadius && Player[0] < NPCQords[0]+TalkingRadius
        && Player[1] > NPCQords[1]-TalkingRadius && Player[1] < NPCQords[1]+TalkingRadius){
            NewTextBox(0, 0, true);
        }
    }
    if (IsKeyPressed(KEY_E) && IsTalking == false){
        if(Player[0] > NPCQords[0]-TalkingRadius && Player[0] < NPCQords[0]+TalkingRadius
        && Player[1] > NPCQords[1]-TalkingRadius && Player[1] < NPCQords[1]+TalkingRadius){
            IntBattle();
        }
    }

    int TEMP = 0;
    if(!IsTalking){
        //Diagonal Movement
        if(IsKeyDown(KEY_W) && IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)){
            CameraPos[2] -= Player[2]/1.5*DeltaTime;
            Player[1] -= Player[2]/1.5*DeltaTime;
            CameraPos[0] -= Player[2]/1.5*DeltaTime;
            Player[0] -= Player[2]/1.5*DeltaTime;
            Player[4] = 1;
            TEMP++;
            CollisonDetection(4);
        }
        if(IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)){
            CameraPos[2] += Player[2]/1.5*DeltaTime;
            Player[1] += Player[2]/1.5*DeltaTime;
            CameraPos[0] -= Player[2]/1.5*DeltaTime;
            Player[0] -= Player[2]/1.5*DeltaTime;
            Player[4] = 3;
            TEMP++;
            CollisonDetection(7);
        }
        if(IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && IsKeyDown(KEY_D)){
            CameraPos[2] += Player[2]/1.5*DeltaTime;
            Player[1] += Player[2]/1.5*DeltaTime;
            CameraPos[0] += Player[2]/1.5*DeltaTime;
            Player[0] += Player[2]/1.5*DeltaTime;
            Player[4] = 3;
            TEMP++;
            CollisonDetection(6);
        }
        if(IsKeyDown(KEY_D) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && IsKeyDown(KEY_W)){
            CameraPos[2] -= Player[2]/1.5*DeltaTime;
            Player[1] -= Player[2]/1.5*DeltaTime;
            CameraPos[0] += Player[2]/1.5*DeltaTime;
            Player[0] += Player[2]/1.5*DeltaTime;
            Player[4] = 1;
            TEMP++;
            CollisonDetection(5);
        }

        //Straight Movement
        if(IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)){
            CameraPos[2] -= Player[2]*DeltaTime;
            Player[1] -= Player[2]*DeltaTime;
            Player[4] = 1;
            TEMP++;
            CollisonDetection(1);
        }
        if(IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_D)){
            CameraPos[0] -= Player[2]*DeltaTime;
            Player[0] -= Player[2]*DeltaTime;
            Player[4] = 0;
            TEMP++;
            CollisonDetection(0);
        }
        if(IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_D)){
            CameraPos[2] += Player[2]*DeltaTime;
            Player[1] += Player[2]*DeltaTime;
            Player[4] = 3;
            TEMP++;
            CollisonDetection(3);
        }
        if(IsKeyDown(KEY_D) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)){
            CameraPos[0] += Player[2]*DeltaTime;
            Player[0] += Player[2]*DeltaTime;
            Player[4] = 2;
            TEMP++;
            CollisonDetection(2);
        }
    }

    if(TEMP == 0){
        IsWalking = false;
        Player[3] = 0;
    }else{
        IsWalking = true;
    }
}

void RenderCharacter(){

    PlayerChunk[0] = (int)Player[0]/MapScale;
    PlayerChunk[1] = (int)Player[1]/MapScale;

    if(IsWalking == false){
        switch((int)Player[4]){
            case 3:
                CharacterAnimationRectangle = (Rectangle){3.0f, 0.0f, 18.0f, 32.0f};
                break;
            case 1:
                CharacterAnimationRectangle = (Rectangle){3.0f, 31.0f, 18.0f, 32.0f};
                break;
            case 0:
                CharacterAnimationRectangle = (Rectangle){1.0f, 64.0f, 18.0f, 32.0f};
                break;
            case 2:
                CharacterAnimationRectangle = (Rectangle){5.0f, 96.0f, 18.0f, 32.0f};
                break;
        }
    }else{
        PlayerAnimation();
    }
    DrawBillboardRec(camera, CharacterSpriteSheet, CharacterAnimationRectangle, (Vector3){ Player[0], MapScale*0.18f, Player[1] }, (Vector2){MapScale*0.1, MapScale*0.1}, WHITE);
}