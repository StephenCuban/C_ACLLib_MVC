#include "model.h"
#include "acllib.h"
#include "view.h"

Barrier g_barriers;
Bird g_bird;
int g_StopGame = 0;

static int barier_speed = 5;
static int bird_speed = 3;

void initGame()
{
    g_bird.xpos = BIRD_DEFAULT_XPOS;
    g_bird.ypos = BIRD_DEFALUT_YPOS;

    g_barriers.left = 1000;
    g_barriers.right = g_barriers.left + BARRIER_WIDTH;
    g_barriers.top1 = 0;
    g_barriers.buttom1 = 100;
    g_barriers.top2 = g_barriers.buttom1 + BARRIER_GAP;
    g_barriers.buttom2 = WINDOW_HEIGHT;
}

void moveBarrier()
{
    g_barriers.left -= barier_speed;
    g_barriers.right -= barier_speed;
    if (g_barriers.right <= 0) {
        g_barriers.left = WINDOW_WIDTH;
        g_barriers.right = WINDOW_WIDTH + BARRIER_WIDTH;
        g_barriers.buttom1 = rand() % 500 + 100;
        g_barriers.top2 = g_barriers.buttom1 + BARRIER_GAP;
    }
}

void moveBird_People()
{
    g_bird.ypos -= BIRD_JUMP;
}

void moveBird_Gravity()
{
    if (g_bird.ypos >= WINDOW_HEIGHT) {
        g_bird.ypos = WINDOW_HEIGHT - BIRD_HEIGHT;
        return;
    }
    g_bird.ypos += bird_speed;
}

void isBirdCollision()
{
    if(g_bird.ypos<=0 || g_bird.ypos>= WINDOW_HEIGHT-BIRD_HEIGHT){
        g_StopGame=1;
    }
    else if(g_bird.ypos<g_barriers.buttom1 || g_bird.ypos+BIRD_HEIGHT>g_barriers.top2){
        if(g_bird.xpos>g_barriers.left && g_bird.xpos<g_barriers.right){
            g_StopGame=1;
        }
        else if(g_bird.xpos + BIRD_WIDTH >g_barriers.left && g_bird.xpos+BIRD_WIDTH < g_barriers.right){
            g_StopGame=1;
        }
    }
}