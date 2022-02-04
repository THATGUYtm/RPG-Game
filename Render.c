Texture2D BuildingTexture1;
Texture2D BuildingTexture2;
Texture2D BuildingTexture3;
Texture2D BuildingTexture4;
Texture2D RoadTexture;
Texture2D FloorTexture;
Texture2D ShopTexture;
Texture2D RoofTop;
Texture2D SkyBox;
Texture2D NPCCharacterSpriteSheet;
Texture2D ToadMan;

void IntTextures(){
    //CharacterSpriteSheet = LoadTexture("Assets/Character Sprite Sheet.png");
    CharacterSpriteSheet = LoadTexture("Assets/FrogMan.png");
    NPCCharacterSpriteSheet = LoadTexture("Assets/CuteAnimeGirlCharacterSheet.png");
    BuildingTexture1 = LoadTexture("Assets/BuildingTexture1.png");
    BuildingTexture2 = LoadTexture("Assets/BuildingTexture2.png");
    BuildingTexture3 = LoadTexture("Assets/BuildingTexture3.png");
    BuildingTexture4 = LoadTexture("Assets/BuildingTexture4.png");
    ShopTexture = LoadTexture("Assets/ShopFront.png");
    RoofTop = LoadTexture("Assets/RoofTop.png");
    FloorTexture = LoadTexture("Assets/Floor Texture.png");
    RoadTexture = LoadTexture("Assets/RoadTexture.png");
    SkyBox = LoadTexture("Assets/SkyBox.png");
    TextBoxCharacter = LoadTexture("Assets/HdCuteAnimeGirl.png");
    ToadMan = LoadTexture("Assets/battle_frog.png");
}

void UnloadTextures(){
    UnloadTexture(CharacterSpriteSheet);
    UnloadTexture(BuildingTexture1);
    UnloadTexture(BuildingTexture2);
    UnloadTexture(BuildingTexture3);
    UnloadTexture(BuildingTexture4);
    UnloadTexture(ShopTexture);
    UnloadTexture(RoofTop);
    UnloadTexture(RoadTexture);
    UnloadTexture(FloorTexture);
    UnloadTexture(SkyBox);
    UnloadTexture(TextBoxCharacter);
    UnloadTexture(NPCCharacterSpriteSheet);
    UnloadTexture(ToadMan);
}

void DrawNotRetardedCube(float x, float y, float z, float w, float h, float l, Color c, int Type){
    switch (Type){
        case 0:DrawCube((Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        
        //Road
        case 2:DrawCubeTextureRec(RoadTexture, (Rectangle){0, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 7:DrawCubeTextureRec(RoadTexture, (Rectangle){501, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 8:DrawCubeTextureRec(RoadTexture, (Rectangle){1001, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 9:DrawCubeTextureRec(RoadTexture, (Rectangle){1503, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 12:DrawCubeTextureRec(RoadTexture, (Rectangle){2004, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 13:DrawCubeTextureRec(RoadTexture, (Rectangle){2505, 0, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 14:DrawCubeTextureRec(RoadTexture, (Rectangle){0, 502, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 15:DrawCubeTextureRec(RoadTexture, (Rectangle){501, 502, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 16:DrawCubeTextureRec(RoadTexture, (Rectangle){1003, 502, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 17:DrawCubeTextureRec(RoadTexture, (Rectangle){1505, 502, 500, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 18:DrawCubeTextureRec(RoadTexture, (Rectangle){2010, 504, 499, 500}, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        
        //Floor
        case 3:DrawCubeTexture(FloorTexture, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        
        //Buildings
        case 1:DrawCubeTexture(BuildingTexture1, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 4:DrawCubeTexture(BuildingTexture2, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 5:DrawCubeTexture(BuildingTexture3, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 6:DrawCubeTexture(BuildingTexture4, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 10:DrawCubeTexture(ShopTexture, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        case 11:DrawCubeTexture(RoofTop, (Vector3){x + (w / 2), y + (h / 2), z + (l / 2)}, w, h, l, c);break;
        
    }
}

void RenderMap(){
    for (int i = 0; i < MapHeight; i++){
        for (int j = 0; j < MapWidth; j++){
            //if(j == PlayerChunk[0] && i == PlayerChunk[1]){
                DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, YELLOW, 0);
            //}else{
                switch (OverWorldMap[i][j]){
                    case 1:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 2);break;
                    case 6:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 7);break;
                    case 7:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 8);break;
                    case 8:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 9);break;
                    case 10:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 12);break;
                    case 11:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 13);break;
                    case 12:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 14);break;
                    case 13:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 15);break;
                    case 14:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 16);break;
                    case 15:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 17);break;
                    case 16:DrawNotRetardedCube(j*MapScale, -0.1f, i*MapScale, MapScale, 1.0f, MapScale, WHITE, 18);break;

                    case 2:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), 0.0f, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*1.25, MapScale-(MapScale*0.04), WHITE, 1);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), MapScale*1.25, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.005, MapScale-(MapScale*0.04), WHITE, 11);
                        break;
                    case 3:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), 0.0f, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*1.4, MapScale-(MapScale*0.04), WHITE, 4);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), MapScale*1.4, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.005, MapScale-(MapScale*0.04), WHITE, 11);
                        break;
                    case 4:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), 0.0f, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*1.35, MapScale-(MapScale*0.04), WHITE, 5);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), MapScale*1.35, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.005, MapScale-(MapScale*0.04), WHITE, 11);
                        break;
                    case 5:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), 0.0f, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*1.45, MapScale-(MapScale*0.04), WHITE, 6);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), MapScale*1.45, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.005, MapScale-(MapScale*0.04), WHITE, 11);
                        break;
                    case 9:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), 0.0f, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.4, MapScale-(MapScale*0.04), WHITE, 10);
                        DrawNotRetardedCube(j*MapScale+(MapScale*0.02), MapScale*0.4, i*MapScale+(MapScale*0.02), MapScale-(MapScale*0.04), MapScale*0.005, MapScale-(MapScale*0.04), WHITE, 11);
                        break;
                    
                    default:
                        DrawNotRetardedCube(j*MapScale, 0.0f, i*MapScale, MapScale, 0.9f, MapScale, WHITE, 3);
                        break;
                }
            //}
        }
    }
}

void RenderScene(){
    BeginDrawing();

        ClearBackground(SKYBLUE);

        BeginMode3D(camera);

            //DrawBillboard(camera, SkyBox, (Vector3){ Player[0] + 40.0f, 300.0f, Player[1] -700.0f }, 1500.0f, WHITE);

            RenderMap();

            if (Player[1] < NPCQords[1]){
                RenderCharacter();
                RenderNPC();
            }else{
                RenderNPC();
                RenderCharacter();
            }

        EndMode3D();

        if(Debug == true){
            DrawText(TextFormat("%i, %i", PlayerChunk[0], PlayerChunk[1]), 10, 40, 20, BLACK);
            DrawText(TextFormat("%f, %f", Player[0], Player[1]), 10, 80, 20, BLACK);
            DrawFPS(10, 10);
        }

        DrawTextBox();

    EndDrawing();
}