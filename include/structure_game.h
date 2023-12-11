#ifndef _STRUCTURE_GAME_H_
#define _STRUCTURE_GAME_H_

#include <raylib.h>
#include <stdlib.h>

struct structure_game
{
    //textures
        Texture2D basic_screen_texture;
        Texture2D texture_axe_player;
        Texture2D texture_walking_player;

        // font
        Font font1;

        // player
        Rectangle player;

    //FPS
        int frames_counter;

        //Frames stuff related
        int player_frame;
        int player_nmb_walking_frame;

        // frames games calculation
        int framesCounter;
        int framesSpeed;
        int currentFrame;
        float frametime;
};




#endif