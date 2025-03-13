#include <stdio.h>
#include "raylib.h"

int main(void) {
    // Initialize Raylib
    InitWindow(800, 600, "Simple Raylib Window");
    SetTargetFPS(60); // Set FPS to 60

    // Main game loop
    while (!WindowShouldClose()) {
        // Begin drawing
        BeginDrawing();
        ClearBackground(RAYWHITE); // Set background color to white

        // Draw text in the center of the screen
        DrawText("Hello, Raylib!", 350, 275, 20, DARKGRAY);

        // End drawing
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
