#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "clay/renderers/raylib/clay_renderer_raylib.c"

int main(void) {
	Clay_Raylib_Initialize(800, 600, "Prosody", FLAG_WINDOW_RESIZABLE);

	uint64_t clayRequireMemory = Clay_MinMemorySize();
	Clay_Arena clayMemory = (Clay_Arena) {
		.memory = malloc(clayRequireMemory),
		.capacity = clayRequireMemory
	};
	Clay_Initialize(clayMemory, (Clay_Dimensions) {
		.width = GetScreenWidth(),
		.height = GetScreenHeighr()
	});
	
	while (!WindowShouldClose()) {
		Clay_BeginLayout();
		
		CLAY(
			CLAY_RECTANGLE({
				.color = { 89, 85, 96, 255 }
			}),
			CLAY_LAYOUT({
				.sizing = {
					.width = CLAY_SIZING_GROW(),
					.height = CLAY_SIZING_GROW()
				}
			})
		) {
			
		}
		
		Clay_RenderCommandArray renderCommands = Clay_EndLayout();
		
		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands);
		EndDrawing();
	}

	return 0;
}
