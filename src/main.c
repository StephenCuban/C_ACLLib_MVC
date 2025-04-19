#include "../include/acllib.h"
#include <stdio.h>

int Setup()
{
    initWindow("Test", DEFAULT, DEFAULT, 800, 450);

    initConsole();
    printf("hell0\n");
    beginPaint();
    line(10, 10, 100, 100);
    endPaint();

    return 0;
}