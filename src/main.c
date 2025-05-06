#include <stdio.h>
#include "acllib.h"
#include "view.h"
#include "model.h"

void KeyboardListener(int k, int event);
void TimerEventListener(int timerID);

int Setup()
{
    initWindow("bird go go go!", 100, 20, WINDOW_WIDTH, WINDOW_HEIGHT);
    initConsole();
    initGame();
    initView();

    registerKeyboardEvent(KeyboardListener);
    registerTimerEvent(TimerEventListener);
    startTimer(0, 10);

    return 0;
}

void KeyboardListener(int k, int event)
{
    if (k == KEY_FLY && event == KEY_DOWN) {
        moveBird_People();
        refreshWindow();
    }
}

void TimerEventListener(int timerID)
{
    static int i = 0;
    if (timerID == 0) {
        if (i < DELAY_BEGIN) {
            i++;
        }
        else if (g_StopGame == 1) {
            i++;
            if (i == DELAY_BEGIN) {
                showMsg("defeat!!!", 700, 400, BLACK, TIMES_NEW_ROMAN, 36);
            }
            else if (i == DELAY_BEGIN + DELAY_END) {
                exit(0);
            }
        }
        else {
            moveBarrier();
            moveBird_Gravity();
            refreshWindow();
            isBirdCollision();
        }
    }
}