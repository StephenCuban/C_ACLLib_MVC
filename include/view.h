#ifndef __VIEW_H
#define __VIEW_H
#include <stdio.h>
#include "acllib.h"
#include "model.h"

#define BG_FILENAME "../images/background.jpg"
#define BIRD_FILENAME "../images/bird.jpg"
#define TIMES_NEW_ROMAN "Times New Roman"

void initView();
void refreshWindow();

void showMsg(const char* pMsg, int x, int y, ACL_Color msgColor, const char* pFontName, int msgSize);

#endif