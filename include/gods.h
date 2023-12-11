#ifndef _GODS_H_

#define _GODS_H_

#include <raylib.h>
#include <stdlib.h>
#include "structure_game.h"

typedef enum Gamescreen
{
    INTRO=0,
    LOGO,
    TITLE,
    GAMEPLAY,
    ENDING
} GameScreen;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 0
#define FRAME_SIZE_WIDTH 62
#define FRAME_SIZE_HEIGHT 100

void drawlogo(Texture2D *basic_screen_texture);
void switchscreen(GameScreen *currentscreen, struct structure_game *game);
void switchdrawing(GameScreen *currentscreen, struct structure_game *game);
void game_window(struct structure_game *game);

#endif