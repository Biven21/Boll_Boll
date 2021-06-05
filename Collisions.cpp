
#include "TXLib.h"

void Move_Ball ();
void DrawBall (int x, int y, int rBall, COLORREF color, COLORREF fillcolor);
void MoveBall (int* x, int* y, int* vx, int* vy, int rBall, int ax, int ay, int dt);

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball ()
    {
    int rBall = 30;
    int x  = 100, y  = 130,
        vx =   5, vy =   2;
    int ax =   0, ay =   0;

    int dt = 1;

    int x1  = 120, y1  = 150, rBall1 = 30,
        vx1 = 3,   vy1 = 1;
    int ax1 = 0,   ay1 = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        DrawBall (x,  y,  rBall, TX_LIGHTGREEN, TX_GREEN);
        DrawBall (x1, y1, rBall1, RGB (12, 15, 128), RGB (122, 0, 128));
        txSetFillColor (TX_BLACK);

        MoveBall (&x,  &y,  &vx,  &vy,  rBall,  ax,  ay,  dt);
        MoveBall (&x1, &y1, &vx1, &vy1, rBall1, ax1, ay1, dt);

        if (txGetAsyncKeyState (VK_RIGHT)) vx --;
        if (txGetAsyncKeyState (VK_LEFT))  vx ++;
        if (txGetAsyncKeyState (VK_UP))    vy --;
        if (txGetAsyncKeyState (VK_DOWN))  vy ++;

        if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;

        if (txGetAsyncKeyState (VK_F1))
            {
            txSetColor (TX_LIGHTGREEN, 2);
            txSetFillColor (TX_GREEN);
            }
        if (txGetAsyncKeyState (VK_F2))
            {
            txSetColor (TX_LIGHTBLUE, 2);
            txSetFillColor (TX_BLUE);
            }

        txSleep (10);
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int rBall, COLORREF color, COLORREF fillcolor)
     {
     txSetColor (color, 2);
     txSetFillColor (fillcolor);

     txCircle (x, y, rBall);
     }

//-----------------------------------------------------------------------------

void MoveBall (int* x, int* y, int* vx, int* vy, int rBall, int ax, int ay, int dt)
    {
    *vx += ax * dt;
    *vy += ay * dt;

    (*x) += (*vx) * dt;
    (*y) += (*vy) * dt;

    if (*x > 900 - rBall) {*vx = -(*vx); (*x) = 900 - rBall;}

    if (*y > 600 - rBall) {*vy = -(*vy);  *y  = 600 - rBall;}

    if (*x < 0 + rBall)   {*vx = -(*vx); (*x) = 0 + rBall;}

    if (*y < 0 + rBall)   {*vy = -(*vy);  *y  = 0 + rBall;}

    }
