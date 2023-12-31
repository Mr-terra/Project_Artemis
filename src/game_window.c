#include <raylib.h>
#include "gods.h"
#include "structure_game.h"
#include "structure_player.h"

void game_window(struct structure_game *game, struct structure_player *player_related)
{

    Camera2D camera = {0};
    camera.target = (Vector2){player_related->player.x + 20.0f, player_related->player.y + 20.0f};
    camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    camera.zoom = 1.0f;

    Rectangle frameRec = {0.0f, 0.0f, (float)player_related->player.width / 6, (float)player_related->player.height};

    // Animation process
    game->framesCounter++;
    game->frametime += GetFrameTime();

    if (game->framesCounter >= (60 / game->framesSpeed))
    {
        game->framesCounter = 0;
        game->currentFrame++;

        if (game->currentFrame > 5)
            game->currentFrame = 0;

        frameRec.x = (float)game->currentFrame * (float)player_related->player.width / 6;
    }

    // Control frames speed
    if (IsKeyPressed(KEY_RIGHT))
        game->framesSpeed++;
    else if (IsKeyPressed(KEY_LEFT))
        game->framesSpeed--;

    if (game->framesSpeed > MAX_FRAME_SPEED)
        game->framesSpeed = MAX_FRAME_SPEED;
    else if (game->framesSpeed < MIN_FRAME_SPEED)
        game->framesSpeed = MIN_FRAME_SPEED;

    // update player movement

    // Player movement
    if (IsKeyDown(KEY_RIGHT))
    {
        player_related->player.x += 2;
        player_related->is_going_right = true;

        if (player_related->is_going_left == true)
        {
            if (game->frametime >= 0.2)
            {
                player_related->player_frame = 0;
            }
            player_related->player_frame = 0;

            player_related->is_going_left = false;
        }

        if (game->frametime >= 0.2)
        {
            player_related->player_frame++;
            game->frametime = 0;
        }

        if (player_related->player_frame >= player_related->player_nmb_walking_frame)
        {
            player_related->player_frame = 2;
        }

    }
    else if (IsKeyDown(KEY_LEFT))
    {
        player_related->player.x -= 2;
        player_related->is_going_left = true;

        if (player_related->is_going_right == true)
        {
            if (game->frametime >= 0.2)
            {
                player_related->player_frame = 0;
            }
            player_related->player_frame = 0;

            player_related->is_going_right = false;
        }

        if (game->frametime >= 0.2)
        {
            player_related->player_frame++;
            game->frametime = 0;
        }

        if (player_related->player_frame >= player_related->player_nmb_walking_frame)
        {
            player_related->player_frame = 2;
        }
    }

    // Camera target follows player
    camera.target = (Vector2){player_related->player.x + 20, player_related->player.y + 20};

    // Drawing stuff
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
    DrawRectangle(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, 200, 200, PINK);

        Rectangle rectangle_player_destination = (Rectangle){player_related->player.x, player_related->player.y, FRAME_SIZE_WIDTH, FRAME_SIZE_HEIGHT};

        Rectangle rectangle_player_source;

        if (player_related->is_going_right == true)
        {
            rectangle_player_source = (Rectangle){FRAME_SIZE_WIDTH * player_related->player_frame, 0, FRAME_SIZE_WIDTH, FRAME_SIZE_HEIGHT};
            DrawTexturePro(player_related->texture_walking_player_right, rectangle_player_source, rectangle_player_destination, (Vector2){0, 0}, 0, WHITE);
        }

        if (player_related->is_going_left == true)
        {
            rectangle_player_source = (Rectangle){FRAME_SIZE_WIDTH * player_related->player_frame, 0, FRAME_SIZE_WIDTH, FRAME_SIZE_HEIGHT};
            DrawTexturePro(player_related->texture_walking_player_left, rectangle_player_source, rectangle_player_destination, (Vector2){0, 0}, 0, WHITE);
        }

    EndMode2D();

    DrawText("SCREEN AREA", 640, 10, 20, RED);

    DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 250, 113, BLUE);

    DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
}