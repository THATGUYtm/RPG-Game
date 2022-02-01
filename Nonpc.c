bool OnTask = false;
float NPCQords[] = {3.5*MapScale, 4.9f*MapScale};
int TargetDestination[] = {0,0};

Texture2D NPCCharacterSpriteSheet;

Rectangle NPCCharacterAnimationRectangle = { 5.0f, 96.0f, 18.0f, 32.0f};

int ind[MapHeight][MapWidth] = {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

int* Path[21][2];

void intai(){

}

void RenderNPC(){
    DrawBillboardRec(camera, NPCCharacterSpriteSheet, NPCCharacterAnimationRectangle, (Vector3){ NPCQords[0], MapScale*0.18f, NPCQords[1] }, (Vector2){MapScale*0.1, MapScale*0.1}, WHITE);

}

void Nonpc(){
    int TEMPx;
    int TEMPy;
    if(OnTask == false){
        while(OnTask == false){
            TEMPx = GetRandomValue(0, MapWidth);
            TEMPy = GetRandomValue(0, MapHeight);
            switch (OverWorldMap[TEMPx][TEMPy]){
                case 1:
                case 6:
                case 7:
                case 8:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                    TargetDestination[0] = TEMPx;
                    TargetDestination[1] = TEMPy;
                    OnTask = true;
                    break;
            }
        }
    }
}