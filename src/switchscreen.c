#include <raylib.h>
#include "gods.h"

void switchscreen(GameScreen *currentscreen,int *frames_counter)
{
    switch (*currentscreen)
    {
    case INTRO:
    {
        (*frames_counter)++;
        if (*frames_counter > 180)
        {
            *frames_counter=0;
            *currentscreen = LOGO;
        }
    }
    break;

    case LOGO:
    {
        (*frames_counter)++;
        if (*frames_counter > 180)
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