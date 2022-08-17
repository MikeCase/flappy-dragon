#pragma once
#include "raylib.h"
#include "Pipe.h"
#include <vector>
using std::vector;

class Environment
{

private:
    Vector2 *Gravity;
    Texture2D BGTexture;
    Rectangle screen;

public:
    vector<Pipe> pipes;

    Environment();
    ~Environment();
    Rectangle getScreen(void);
    Texture2D getBGTexture(void);
    void GeneratePipe();
    void MovePipes(void);
};