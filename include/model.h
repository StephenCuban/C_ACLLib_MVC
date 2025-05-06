#ifndef __MODEL_H
#define __MODEL_H

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define BG_DEFALUT_XPOS 0
#define BG_DEFALUT_YPOS 0
#define BIRD_DEFAULT_XPOS 400
#define BIRD_DEFALUT_YPOS 375

#define BARRIER_WIDTH 100
#define BARRIER_GAP 200
#define BIRD_WIDTH 80
#define BIRD_HEIGHT 50

#define BIRD_JUMP 50
#define DELAY_BEGIN 300
#define DELAY_END 300
#define KEY_FLY 38

typedef struct barrier
{
    int left;
    int top1;
    int right;
    int buttom1;
    int top2;
    int buttom2;
} Barrier;

typedef struct bird
{
    int xpos;
    int ypos;
} Bird;

extern Barrier g_barriers;
extern Bird g_bird;
extern int g_StopGame;

void initGame();
void moveBarrier();
void moveBird_People();
void moveBird_Gravity();
void isBirdCollision();

#endif