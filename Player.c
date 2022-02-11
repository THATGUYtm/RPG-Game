#define TalkingRadius 1.1

/*
0 = X
1 = Y
2 = Movement Speed
3 = Animation Timer
4 = Direction
*/
float Player[] = {6 *MapScale, 6*MapScale, MapScale*0.02, 0.0f, 3.0f};
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

bool CantWalkThrough(float x, float y){
    int cx, cy;
    if(TileSet == 0){
        cx = (int)x/MapScale;
        cy = (int)y/MapScale;
    }else{
        cx = (int)x/(MapScale/2);
        cy = (int)y/(MapScale/2);
    }
    if(x < 0 || x > (OverWorldMapWidth)*MapScale || y < 0 || y > (OverWorldMapHeight)*MapScale)
        return true;
    if(TileSet == 0){
        switch(BigOverWorldMap[cy * OverWorldMapWidth + cx]){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 25:
                return false;
                break;
        }
    }else if(TileSet == 1){
        switch(BigOverWorldMap[cx * OverWorldMapWidth + cy]){
            case 13:
                return false;
                break;
        }
        if(cx >= 28){
            SwitchMap(0);
            Player[0] = 4 * MapScale + (MapScale/2);
            Player[1] = 6 * MapScale;
            CameraPos[0] = Player[0];
            CameraPos[2] = MapScale*0.9 + Player[1];
        }
    }
    return true;
}

void PlayerMovement(){
    float DeltaTime = GetFrameTime()*100;
    Player[3] += GetFrameTime();

    PlayerAnimation();

    if (IsMKeyPressed(4) && IsTalking == false){
        if(Player[0] > NPCQords[0]-TalkingRadius && Player[0] < NPCQords[0]+TalkingRadius
        && Player[1] > NPCQords[1]-TalkingRadius && Player[1] < NPCQords[1]+TalkingRadius){
            NewTextBox(0, 0, true);
        }
    }
    if (IsMKeyPressed(5) && IsTalking == false){
        if(Player[0] > NPCQords[0]-TalkingRadius && Player[0] < NPCQords[0]+TalkingRadius
        && Player[1] > NPCQords[1]-TalkingRadius && Player[1] < NPCQords[1]+TalkingRadius){
            IntBattle();
        }
    }

    int TEMP = 0;
    float TEMP2 = Player[2]/1.5*DeltaTime;
    float TEMPS = TEMP2/sqrt(2);
    if(!IsTalking){
        //Diagonal Movement
        if(IsMKeyDown(1) && IsMKeyDown(0) && !IsMKeyDown(3) && !IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0] - TEMP2, Player[1] - TEMP2)){
                CameraPos[0] -= TEMPS;
                Player[0] -= TEMPS;
                CameraPos[2] -= TEMPS;
                Player[1] -= TEMPS;
                Player[4] = 1;
                TEMP++;
            }else{
                if(!CantWalkThrough(Player[0] - TEMP2, Player[1])){
                    CameraPos[0] -= TEMP2;
                    Player[0] -= TEMP2;
                    Player[4] = 0;
                    TEMP++;
                }
                if(!CantWalkThrough(Player[0], Player[1] - TEMP2)){
                    CameraPos[2] -= TEMP2;
                    Player[1] -= TEMP2;
                    Player[4] = 1;
                    TEMP++;
                }
            }
        }
        if(IsMKeyDown(0) && !IsMKeyDown(1) && IsMKeyDown(3) && !IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0] - TEMP2, Player[1] + TEMP2)){
                CameraPos[0] -= TEMPS;
                Player[0] -= TEMPS;
                CameraPos[2] += TEMPS;
                Player[1] += TEMPS;
                Player[4] = 3;
                TEMP++;
            }else{
                if(!CantWalkThrough(Player[0] - TEMP2, Player[1])){
                    CameraPos[0] -= TEMP2;
                    Player[0] -= TEMP2;
                    Player[4] = 0;
                    TEMP++;
                }   
                if(!CantWalkThrough(Player[0], Player[1] + TEMP2)){
                    CameraPos[2] += TEMP2;
                    Player[1] += TEMP2;
                    Player[4] = 3;
                    TEMP++;
                }
            }
        }
        if(IsMKeyDown(3) && !IsMKeyDown(0) && !IsMKeyDown(1) && IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0] + TEMP2, Player[1] + TEMP2)){
                CameraPos[0] += TEMPS;
                Player[0] += TEMPS;
                CameraPos[2] += TEMPS;
                Player[1] += TEMPS;
                Player[4] = 3;
                TEMP++;
            }else{
                if(!CantWalkThrough(Player[0] + TEMP2, Player[1])){
                    CameraPos[0] += TEMP2;
                    Player[0] += TEMP2;
                    Player[4] = 2;
                    TEMP++;
                }
                if(!CantWalkThrough(Player[0], Player[1] + TEMP2)){
                    CameraPos[2] += TEMP2;
                    Player[1] += TEMP2;
                    Player[4] = 3;
                    TEMP++;
                }
            }
        }
        if(IsMKeyDown(2) && !IsMKeyDown(0) && !IsMKeyDown(3) && IsMKeyDown(1)){
            if(!CantWalkThrough(Player[0] + TEMP2, Player[1] - TEMP2)){
                CameraPos[0] += TEMPS;
                Player[0] += TEMPS;
                CameraPos[2] -= TEMPS;
                Player[1] -= TEMPS;
                Player[4] = 1;
                TEMP++;
            }else{
                if(!CantWalkThrough(Player[0] + TEMP2, Player[1])){
                    CameraPos[0] += TEMP2;
                    Player[0] += TEMP2;
                    Player[4] = 2;
                    TEMP++;
                }   
                if(!CantWalkThrough(Player[0], Player[1] - TEMP2)){
                    CameraPos[2] -= TEMP2;
                    Player[1] -= TEMP2;
                    Player[4] = 1;
                    TEMP++;
                }
            }
        }

        //Straight Movement
        if(IsMKeyDown(1) && !IsMKeyDown(0) && !IsMKeyDown(3) && !IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0], Player[1] - TEMP2)){
                CameraPos[2] -= TEMP2;
                Player[1] -= TEMP2;
                Player[4] = 1;
                TEMP++;
            }
        }
        if(IsMKeyDown(0) && !IsMKeyDown(1) && !IsMKeyDown(3) && !IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0] - TEMP2, Player[1])){
                CameraPos[0] -= TEMP2;
                Player[0] -= TEMP2;
                Player[4] = 0;
                TEMP++;
            }
        }
        if(IsMKeyDown(3) && !IsMKeyDown(0) && !IsMKeyDown(1) && !IsMKeyDown(2)){
            if(!CantWalkThrough(Player[0], Player[1] + TEMP2)){
                CameraPos[2] += TEMP2;
                Player[1] += TEMP2;
                Player[4] = 3;
                TEMP++;
            }
        }
        if(IsMKeyDown(2) && !IsMKeyDown(0) && !IsMKeyDown(3) && !IsMKeyDown(1)){
            if(!CantWalkThrough(Player[0] + TEMP2, Player[1])){
                CameraPos[0] += TEMP2;
                Player[0] += TEMP2;
                Player[4] = 2;
                TEMP++;
            }
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

    if(TileSet == 0){
        PlayerChunk[0] = (int)Player[0]/MapScale;
        PlayerChunk[1] = (int)Player[1]/MapScale;
    }else{
        PlayerChunk[0] = (int)Player[0]/(MapScale/2);
        PlayerChunk[1] = (int)Player[1]/(MapScale/2);
    }

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
    DrawBillboardRec(camera, CharacterSpriteSheet, CharacterAnimationRectangle, (Vector3){ Player[0], MapScale*0.1725f, Player[1] }, (Vector2){MapScale*0.1, MapScale*0.1}, WHITE);
}