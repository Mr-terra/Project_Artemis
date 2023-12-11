#include <raylib.h>
#include "gods.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gods");

    Image basic_screen = LoadImage("assets/img/godsIntrofixed.png");
    Texture2D basic_screen_texture = LoadTextureFromImage(basic_screen);
    UnloadImage(basic_screen);
    Image axe_player = LoadImage("assets/img/Axe_player.png");
    Texture2D texture_axe_player = LoadTextureFromImage(axe_player);
    UnloadImage(axe_player);
    Font font1 = LoadFont("assets/img/Gods_font.png");
    GameScreen currentscreen = INTRO;

    int frames_counter = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switchscreen(&currentscreen, &frames_counter);

        switchdrawing(&currentscreen, &basic_screen_texture, &font1, &texture_axe_player);
    }
    UnloadFont(font1);
    CloseWindow();

    return 0;
}
