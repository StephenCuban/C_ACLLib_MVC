#include "acllib.h"
#include <stdio.h>
ACL_Image *bg, *bird;

int Setup()
{
    initWindow("bird", 100, 20, 1000, 800);
    initConsole();
    bg = (ACL_Image*)malloc(sizeof(ACL_Image));
    bird = (ACL_Image*)malloc(sizeof(ACL_Image));

    const char* bgname = "../images/background.jpg";
    const char* birdname = "../images/bird.jpg";
    loadImage(bgname, bg);
    loadImage(birdname, bird);
    beginPaint();
    putImage(bg, 0, 0);
    putImage(bird, 450, 260);
    setBrushColor(GREEN);
    // setBrushStyle(BRUSH_STYLE_HORIZONTAL);
    rectangle(200, 200, 500, 500);
    endPaint();
    return 0;
}
