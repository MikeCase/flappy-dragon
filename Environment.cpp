#include "raylib.h"
#include <iostream>
#include <string.h>
#include "Environment.h"
#include "Pipe.h"

/**
 * @brief Construct a new Environment:: Environment object
 *
 */
Environment::Environment()
{
    // Initialize Environment. //

    // Load texture for background
    this->BGTexture = LoadTexture("resources/bg.png");

    this->screen = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
}

/**
 * @brief Destroy the Environment:: Environment object
 *
 */
Environment::~Environment()
{
    // UnloadTexture();
    this->pipes.clear();
    UnloadTexture(this->BGTexture);
}

/**
 * @brief Generate a pipe and add it to the stack.
 *
 * @return Pipe
 */
void Environment::GeneratePipe()
{
    Pipe pipe = {0};

    // Define the top pipe height and the bottom pipe height.
    pipe.top = {(float)GetRandomValue(0, (GetScreenHeight() / 2))};
    pipe.bottom = {(float)GetRandomValue((GetScreenHeight() / 2), GetScreenHeight())};

    // std::cout << pipe.bottom-pipe.top << std::endl;

    // Help maintain the gap
    if ((pipe.bottom - pipe.top) < 300)
    {
        pipe.bottom += 250;
    }
    if ((pipe.bottom - pipe.top) > 300)
    {
        pipe.bottom -= 250;
    }

    // Build the top rectangle.
    pipe.topRect = {
        .x = (float)GetScreenWidth() + 20,
        .y = 0.0f,
        .width = (float)pipe.width,
        .height = (float)pipe.top,
    };

    // Build the bottom rectangle.
    pipe.bottomRect = {
        .x = (float)GetScreenWidth() + 20,
        .y = (pipe.bottom),
        .width = (float)pipe.width,
        .height = (float)GetScreenHeight(),
    };

    // Load the image texture.
    pipe.Image = LoadTexture("resources/pipe.png");

    pipe.ImageRect = { 0, 0, (float)pipe.Image.width, (float)pipe.Image.height };

    // Put it on the stack.
    this->pipes.push_back(pipe);
}

/**
 * @brief Move the pipes across the environment(Screen).
 *
 */
void Environment::MovePipes(void)
{

    for (std::size_t i = 0; i < this->pipes.size(); ++i)
    {
        // Not entirely sure if it's needed, or if raylib cleans up when it closes..
        // but just incase, unload the texture for the pipe if it's off screen,
        // then reset the pipe struct to { 0 }, then erase it from the pipes vector.
        if (this->pipes[i].topRect.x < 0.0f - 75.0f)
        {
            UnloadTexture(this->pipes[i].Image);
            this->pipes[i] = {0};
            this->pipes.erase(this->pipes.begin() + i);
        }
        this->pipes[i].topRect.x -= 2.0f;
        this->pipes[i].bottomRect.x -= 2.0f;
        // std::cout << "Top Rectangle: " << this->pipes[i].top << ": " << i << std::endl;
        // std::cout << "Bottom Rectangle: " << this->pipes[i].bottom << ": " << i << std::endl;
    }
}

/**
 * @brief Return the background rectangle.
 *
 * @return Rectangle
 */
Rectangle Environment::getScreen()
{
    return this->screen;
}

/**
 * @brief Return the background texture.
 *
 * @return Texture2D
 */
Texture2D Environment::getBGTexture()
{
    return this->BGTexture;
}