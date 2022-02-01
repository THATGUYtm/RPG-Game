float Player[5];
float CameraPos[] = {0.0f, MapScale*0.5, MapScale*0.9};
float CameraFov = 60.0f;
Camera camera = { 0 };

void CameraInt(){
    camera.position = (Vector3){ CameraPos[0] += Player[0], CameraPos[1], CameraPos[2] += Player[1]};// x, y, z
    camera.target = (Vector3){ Player[0], 16.0f, Player[1] };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    SetCameraMode(camera, CAMERA_FREE);
}

void CameraUpdate(){
    camera.position = (Vector3){ CameraPos[0], CameraPos[1], CameraPos[2] };
    camera.target = (Vector3){ Player[0], MapScale*0.2f, Player[1] };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = CameraFov;
}