#include <raylib.h>
#include "gods.h"
#include "structure_game.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gods");

    //Loading assets
    Image basic_screen = LoadImage("assets/img/godsIntrofixed.png");
    Texture2D basic_screen_texture = LoadTextureFromImage(basic_screen);
    UnloadImage(basic_screen);

    Image axe_player = LoadImage("assets/img/Axe_player.png");
    Texture2D texture_axe_player = LoadTextureFromImage(axe_player);
    UnloadImage(axe_player);

    Image walking_player_right = LoadImage("assets/img/walk_player.png");
    Texture2D texture_walking_player_right = LoadTextureFromImage(walking_player_right);
    UnloadImage(walking_player_right);

    //Loading font
    Font font1 = LoadFont("assets/img/Gods_font.png");

    //Seting screen
    GameScreen currentscreen = GAMEPLAY;

    //player information
    bool is_going_right = true;
    bool is_going_left = false;

    //frames stuff related
        //player frames stuff
            int player_frame = 0;
            int player_nmb_walking_frame = 10;
        //frames games calculation
            int framesCounter = 0;
            int framesSpeed = 8;
            int currentFrame = 0;
            float frametime = GetFrameTime();

            // loading the structure
            struct structure_game game = {
                .basic_screen_texture = basic_screen_texture,
                .font1 = font1,
                .frames_counter = 0,
                .player = {400, 280, 40, 40},
                .texture_axe_player = texture_axe_player,
                .texture_walking_player_right = texture_walking_player_right,
                .player_frame = player_frame,
                .player_nmb_walking_frame = player_nmb_walking_frame,
                .framesCounter = framesCounter,
                .framesSpeed = framesSpeed,
                .currentFrame = currentFrame,
                .frametime = frametime,
                .is_going_right = is_going_right,
                .is_going_left = is_going_left};

            SetTargetFPS(60);

            while (!WindowShouldClose())
            {
                switchscreen(&currentscreen, &game);

                switchdrawing(&currentscreen, &game);
    }
    UnloadFont(font1);
    CloseWindow();

    return 0;
}
