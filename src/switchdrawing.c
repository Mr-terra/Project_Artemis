#include "gods.h"
#include "structure_game.h"
#include <raylib.h>
#include <stdlib.h>

void switchdrawing(GameScreen *currentscreen, struct structure_game *game)
{
    BeginDrawing();
    ClearBackground(BLACK);

    const char GameTitle[50] = "GODS";

    Vector2 fontPosition1 = {SCREEN_WIDTH / 2 - 200 - MeasureTextEx(game->font1, GameTitle, (float)game->font1.baseSize, -3).x / 2,
                             SCREEN_HEIGHT / 2 -150 - game->font1.baseSize / 2.0f - 80.0f};

    switch (*currentscreen)
    {
    case INTRO:
    {
        drawlogo(&game->texture_axe_player);
    }
    break;

    case LOGO:
    {
        drawlogo(&game->basic_screen_texture);
    }
    break;

    case TITLE:
    {
        drawlogo(&game->basic_screen_texture);
        DrawTextEx(game->font1, GameTitle, fontPosition1, 180, 1, WHITE);
    }
    break;

    case GAMEPLAY:
    {
        // DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);
        // DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
        // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
        game_window(game);
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
