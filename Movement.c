bool IsMKeyDown(int key ){
    switch (key){
        case 1:
            if(IsKeyDown(KEY_W) ||
               IsKeyDown(KEY_UP) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) < -0.5){
                   return true;
               }
            break;
        case 3:
            if(IsKeyDown(KEY_S) ||
               IsKeyDown(KEY_DOWN) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) > 0.5){
                   return true;
               }
            break;
        case 0:
            if(IsKeyDown(KEY_A) ||
               IsKeyDown(KEY_LEFT) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) < -0.5){
                   return true;
               }
            break;
        case 2:
            if(IsKeyDown(KEY_D) ||
               IsKeyDown(KEY_RIGHT) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) > 0.5){
                   return true;
               }
            break;
    }
    return false;
}
/*
0, LEFT
1, UP
2, RIGHT
3, DOWN
*/

bool IsMKeyPressed(int key ){
    switch (key){
        case 1:
            if(IsKeyDown(KEY_W) ||
               IsKeyDown(KEY_UP) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) < -0.5){
                   return true;
               }
            break;
        case 3:
            if(IsKeyDown(KEY_S) ||
               IsKeyDown(KEY_DOWN) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) > 0.5){
                   return true;
               }
            break;
        case 0:
            if(IsKeyDown(KEY_A) ||
               IsKeyDown(KEY_LEFT) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) < -0.5){
                   return true;
               }
            break;
        case 2:
            if(IsKeyDown(KEY_D) ||
               IsKeyDown(KEY_RIGHT) ||
               IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ||
               GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) > 0.5){
                   return true;
               }
            break;
        case 4:
            if(IsKeyPressed(KEY_SPACE) ||
               IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                   return true;
               }
            break;
        case 5:
            if(IsKeyPressed(KEY_E) ||
               IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)){
                   return true;
               }
            break;
    }
    return false;
}
/*
0, Left
1, Up
2, Right
3, Down
4, SPACE
5, E
*/