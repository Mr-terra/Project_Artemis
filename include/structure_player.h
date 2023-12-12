#ifndef _STRUCTURE_PLAYER_H_
#define _STRUCTURE_PLAYER_H_

#include <raylib.h>
#include <stdlib.h>

struct structure_player
{
    //texture
    Texture2D texture_walking_player_right;
    Texture2D texture_walking_player_left;

    // player
    Rectangle player;
    bool is_going_left;
    bool is_going_right;

    // Frames stuff related
    int player_frame;
    int player_nmb_walking_frame;
};

#endif