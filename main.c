#include "raylib.h"

int main() {
    InitWindow(800, 600, "Raylib in WASM");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from WebAssembly!", 200, 300, 20, DARKGRAY);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
