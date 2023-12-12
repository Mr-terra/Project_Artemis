#include <raylib.h>
#include "gods.h"
#include "structure_game.h"

void switchscreen(GameScreen *currentscreen, struct structure_game *game, struct structure_player *player_related)
{
    switch (*currentscreen)
    {
    case INTRO:
    {
        (game->frames_counter)++;
        if (game->frames_counter > 180)
        {
            game->frames_counter = 0;
            *currentscreen = LOGO;
        }
    }
    break;

    case LOGO:
    {
        (game->frames_counter)++;
        if (game->frames_counter > 180)
        {
            *currentscreen = TITLE;
        }
    }
    break;

    case TITLE:
    {
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            *currentscreen = GAMEPLAY;
        }
    }
    break;

    case GAMEPLAY:
    {
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            *currentscreen = ENDING;
        }
    }
    break;

    case ENDING:
    {
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            *currentscreen = TITLE;
        }
    }
    break;

    default:
        break;
    }

}