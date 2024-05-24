#include <stdio.h>
#include "raylib.h"
#include "plug.h"

int main(void){
    InitWindow(800, 450, "Panim2");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(400, 225, 50, RED);
        DrawCircle(400, 325, 50, RED);
        EndDrawing();
    }
    return 0;
}
