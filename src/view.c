#include "view.h"
#include "acllib.h"
#include "model.h"

ACL_Image *img_background, *img_bird;

static void showBarriers(Barrier* pBarrier)
{
    setBrushColor(GREEN);
    rectangle(pBarrier->left, pBarrier->top1, pBarrier->right, pBarrier->buttom1);
    rectangle(pBarrier->left, pBarrier->top2, pBarrier->right, pBarrier->buttom2);
}

void initView()
{
    img_background = (ACL_Image*)malloc(sizeof(ACL_Image));
    img_bird = (ACL_Image*)malloc(sizeof(ACL_Image));
    loadImage(BG_FILENAME, img_background);
    loadImage(BIRD_FILENAME, img_bird);
    beginPaint();
    putImage(img_background, BG_DEFALUT_XPOS, BG_DEFALUT_YPOS);
    putImage(img_bird, BIRD_DEFAULT_XPOS, BIRD_DEFALUT_YPOS);
    endPaint();
}

void refreshWindow()
{
    clearDevice();
    beginPaint();
    putImage(img_background, BG_DEFALUT_XPOS, BG_DEFALUT_YPOS);
    putImage(img_bird, g_bird.xpos, g_bird.ypos);
    showBarriers(&g_barriers);
    endPaint();
}

void showMsg(const char* pMsg, int x, int y, ACL_Color msgColor, const char* pFontName, int msgSize)
{
    setTextColor(msgColor);
    setTextSize(msgSize);
    setTextFont(pFontName);
    beginPaint();
    paintText(x, y, pMsg);
    endPaint();
}