#include "Dragon.h"
#include "raylib.h"
#include <algorithm>
#include <iostream>
#include <string>

/**
 * @brief Construct a new Dragon:: Dragon object
 *
 */
Dragon::Dragon(void)
{
    // Initialize the dragon.
    this->dragonPos.x = GetScreenWidth() / 3;
    this->dragonPos.y = GetScreenHeight() / 3;
    this->dragonImg = LoadTexture("resources/dragon/dragon-sheet.png");
    this->dragonRect = {0.0f, 0.0f, (float)this->dragonImg.width / 4, (float)this->dragonImg.height};
    this->lives = 3;
    // std::cout << this->dragonPos.x << std::endl;
}

/**
 * @brief Destroy the Dragon:: Dragon object
 *
 */
Dragon::~Dragon()
{

    UnloadTexture(this->dragonImg);
}

/**
 * @brief Set the life count of the Dragon:: Dragon object.
 *
 * @param lifeCount
 */
void Dragon::setLives(int lifeCount)
{
    this->lives = lifeCount;
}

/**
 * @brief get the lives available of the Dragon:: Dragon object.
 *
 * @return int
 */
int Dragon::getLives(void)
{
    return this->lives;
}

/**
 * @brief Update the sprite animation of the Dragon:: Dragon object
 *
 * @param currentFrame
 */
void Dragon::UpdateSprite(float currentFrame)
{
    this->dragonRect.x = currentFrame * (float)this->dragonImg.width / 4;
}

/**
 * @brief Update the position of the Dragon:: Dragon object.
 *
 */
void Dragon::MoveDragon()
{
    // Constantly falling.
    this->dragonPos.y += 2.0f;

    // Rise up..
    if (IsKeyDown(KEY_SPACE))
    {
        this->dragonPos.y -= 6.0f;
    }
}

/**
 * @brief Get the image of the Dragon:: Dragon object.
 *
 * @return Texture2D
 */
Texture2D Dragon::getDragonImage()
{
    return this->dragonImg;
}

/**
 * @brief Get the rectangle of the Dragon:: Dragon object.
 *
 * @return Rectangle
 */
Rectangle Dragon::getDragonRect()
{
    return this->dragonRect;
}

/**
 * @brief Set the position of the Dragon:: Dragon object.
 *
 * @param vec
 */
void Dragon::setDragonPos(Vector2 vec)
{
    this->dragonPos = vec;
}

/**
 * @brief Get the position of the Dragon:: Dragon object.
 *
 * @return Vector2
 */
Vector2 Dragon::getDragonPos(void)
{
    return this->dragonPos;
}

/**
 * @brief Get the center point for the dragon.
 *
 * @return Vector2
 */
Vector2 Dragon::getDragonCenter(void)
{
    Vector2 dragonCenter = {
        .x = this->dragonRect.height / 2,
        .y = this->dragonRect.width / 2,
    };

    return dragonCenter;
}