#ifndef _GODS_H_

#define _GODS_H_

#include <raylib.h>
#include <stdlib.h>

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

void drawlogo(Texture2D *basic_screen_texture);
void switchscreen(GameScreen *currentscreen, int *frames_counter);
void switchdrawing(GameScreen *currentscreen, Texture2D *basic_screen_texture, Font *font1, Texture2D *texture_axe_player);

#endif