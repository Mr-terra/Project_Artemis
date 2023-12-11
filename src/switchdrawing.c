#include <stdlib.h>
#include "gods.h"
#include <raylib.h>

void switchdrawing(GameScreen *currentscreen, Texture2D *basic_screen_texture, Font *font1, Texture2D *texture_axe_player)
{
    BeginDrawing();
    ClearBackground(BLACK);

    const char GameTitle[50] = "Gods";

    Vector2 fontPosition1 = {SCREEN_WIDTH / 2 -120 - MeasureTextEx(*font1, GameTitle, (float)font1->baseSize, -3).x / 2,
                             SCREEN_HEIGHT / 2 +50 - font1->baseSize / 2.0f - 80.0f};

    switch (*currentscreen)
    {
    case INTRO:
    {
        drawlogo(texture_axe_player);
    }
    break;

    case LOGO:
    {
        drawlogo(basic_screen_texture);
    }
    break;

    case TITLE:
    {
        // Vector2 pos = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        drawlogo(basic_screen_texture);
        DrawTextEx(*font1, GameTitle, fontPosition1, 125, -18, WHITE);
        // DrawTextEx(font1, "yolo", pos, 20, 12, WHITE);
        //  DrawText("yolo",640,360,20,WHITE);
    }
    break;

    case GAMEPLAY:
    {
        // DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);
        // DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
        // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
        game();
    }
    break;

    case ENDING:
    {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
        DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
    }
    break;

    default:
        break;
    }
    EndDrawing();
}
