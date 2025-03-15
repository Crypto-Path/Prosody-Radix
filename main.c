#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "clay/renderers/raylib/clay_renderer_raylib.c"

const uint32_t FONT_ID_BODY_16 = 0;

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main(void) {
	uint64_t clayRequireMemory = Clay_MinMemorySize();
	Clay_Arena clayMemory = (Clay_Arena) { .memory = malloc(clayRequireMemory), .capacity = clayRequireMemory };
	Clay_Raylib_Initialize(800, 600, "Prosody Clay", FLAG_WINDOW_RESIZABLE);
	Clay_Initialize(clayMemory, (Clay_Dimensions) { .width = GetScreenWidth(), .height = GetScreenHeight() }, (Clay_ErrorHandler) { HandleClayErrors });
	
	Font fonts[1];
	fonts[FONT_ID_BODY_16] = LoadFontEx("resources/Roboto-Regular.ttf", 48, 0, 400);
	SetTextureFilter(fonts[FONT_ID_BODY_16].texture, TEXTURE_FILTER_BILINEAR);
    Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

	while (!WindowShouldClose()) {
        Clay_SetLayoutDimensions((Clay_Dimensions) {
            .width = GetScreenWidth(),
            .height = GetScreenHeight() / 2
        });
        
		Clay_BeginLayout();
		
		CLAY({ .id = CLAY_ID("body"),
			.layout = {
				.layoutDirection = CLAY_LEFT_TO_RIGHT,
				.sizing = {
					.width = CLAY_SIZING_GROW(0),
					.height = CLAY_SIZING_GROW(0) 
				}
			},
			.backgroundColor = {95, 90, 105, 255}
		} ) {
			CLAY({ .id = CLAY_ID(" chartDataContainer"),
				.layout = {
					.sizing = {
						.width = CLAY_SIZING_GROW(0),
						.height = CLAY_SIZING_GROW(0)
					}
				}
			}) {
				// Chart Info & stuff
			}
			CLAY({ .id = CLAY_ID("chartListContainer"),
				.layout = {
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
					.sizing = {
						.width = CLAY_SIZING_FIXED(240),
						.height = CLAY_SIZING_GROW(0)
					}
				},
				.backgroundColor = {185, 180, 195, 200},
            	.cornerRadius = CLAY_CORNER_RADIUS(8)
			}) {
				CLAY_TEXT(CLAY_STRING("Hello World"), CLAY_TEXT_CONFIG({
                    .fontId = FONT_ID_BODY_16,
					.fontSize = 24,
					.textColor = {255, 255, 255, 255} 
				}));
			}
		}
		
		Clay_RenderCommandArray renderCommands = Clay_EndLayout();
		
		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands, fonts);
		EndDrawing();
	}

	Clay_Raylib_Close();
	return 0;
}
