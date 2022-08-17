#include "raylib.h"
#include "raymath.h"
#include "Dragon.h"
#include "Environment.h"
#include "Pipe.h"
#include <iostream>

int main()
{
    // Initialize the window, screen, Dragon etc..
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Flappy Dragons");
    Environment env;
    Dragon dragon; // Initialize the dragon

    // Initialize frame counter/speed/etc for the sprite animation.
    int currentFrame = 0;
    int currentPFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;
    int pipeGenerator;

    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())
    {
        // Update everything..

        // Check for collisions.
        // for (std::size_t i = 0; i < env.pipes.size(); ++i)
        // {
        //     if (CheckCollisionRecs(env.pipes[i].bottomRect, dragon.getDragonRect()) ||
        //         CheckCollisionRecs(env.pipes[i].topRect, dragon.getDragonRect()))
        //     {
        //         std::cout << "Collision" << std::endl;
        //     }
        // }

        framesCounter++;
        pipeGenerator++;

        if (pipeGenerator >= (1000 / framesSpeed))
        {
            pipeGenerator = 0;
            env.GeneratePipe();
        }

        if (framesCounter >= (60 / framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;
            if (currentFrame > 4)
                currentFrame = 0;
            dragon.UpdateSprite((float)currentFrame);
        }

        // Update dragon position. If position is greater than screen width, place
        //  dragon on the left side of the screen beyond the view.
        dragon.MoveDragon();

        // Update location of pipes. Move them to the left.
        env.MovePipes();

        // Draw the screen
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexturePro(env.getBGTexture(), env.getScreen(), env.getScreen(), Vector2Zero(), 0, WHITE);

        // Show the available lives.
        DrawText(TextFormat("Dragon Lives: %d", dragon.getLives()), 100, 50, 20, WHITE);

        // I believe I'll need this for the dragons rotation on rise and fall.
        // DrawTexturePro(dragon.getDragonImage(), dragon.getDragonRect(), dragon.getDragonRect(), dragon.getDragonCenter(), 0.0f, WHITE);

        DrawTextureRec(dragon.getDragonImage(), dragon.getDragonRect(), dragon.getDragonPos(), WHITE);

        for (std::size_t i = 0; i < env.pipes.size(); ++i)
        {
            if (CheckCollisionRecs(env.pipes[i].bottomRect, dragon.getDragonRect()) ||
                CheckCollisionRecs(env.pipes[i].topRect, dragon.getDragonRect()))
            {
                std::cout << "Collision" << std::endl;
            }
            // DrawRectangle(env.pipes[i].topRect.x, env.pipes[i].topRect.y, env.pipes[i].topRect.width, env.pipes[i].topRect.height, DARKBLUE);
            // DrawRectangle(env.pipes[i].bottomRect.x, env.pipes[i].bottomRect.y, env.pipes[i].bottomRect.width, env.pipes[i].bottomRect.height, DARKBLUE);
            // Top Pipe
            DrawTexturePro(
                /* Texture 2d */ env.pipes[i].Image,
                /* SrcRect */ env.pipes[i].ImageRect,
                /* DestRect */ env.pipes[i].topRect,
                /* Vector2 position */ { env.pipes[i].topRect.width, env.pipes[i].topRect.height },
                /* Rotation */ 180.0f,
                /* Tint */ WHITE
            );

            // Bottom Pipe
            DrawTexturePro(
                /* Texture 2d */ env.pipes[i].Image,
                /* SrcRect */ env.pipes[i].ImageRect,
                /* DestRect */ env.pipes[i].bottomRect,
                /* Origin (Vector2D) */ { 0, 0 },
                /* Rotation */ 0.0f,
                /* Tint */ WHITE
            );
        }
        EndDrawing();
    }

    CloseWindow();
    std::cout << "Window closed" << std::endl;
    return 0;
}