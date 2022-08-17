#pragma once
#include "raylib.h"

class Dragon
{

public:
    Dragon(void);  // Constructor
    ~Dragon(void); // Destructor

    void setLives(int lifeCount);
    int getLives(void);

    void setDragonPos(Vector2 vec);
    Vector2 getDragonPos(void);

    Texture2D getDragonImage(void);
    Rectangle getDragonRect(void);
    Vector2 getDragonCenter(void);

    void MoveDragon(void);
    void UpdateSprite(float currentFrame);

private:
    int lives;

    Texture2D dragonImg;
    Vector2 dragonPos;
    Rectangle dragonRect;
};