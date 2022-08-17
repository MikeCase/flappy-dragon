#pragma once

#include "raylib.h"

/**
 * @brief This struct defines an individual pipe.
 *
 */
typedef struct
{
    float top;
    float bottom;
    float width = 75.0f;
    Rectangle bottomRect;
    Rectangle topRect;
    Texture2D Image;
    Rectangle ImageRect;

} Pipe;
