

#include "TXLib.h"

void Move_Ball ();
void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillcolor);

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball ()
    {
    int x  = 100, y  = 100,
        vx =  15, vy =   2;

    int dt = 1;

    int x1  = 120, y1  = 150,
        vx1 = 10,  vy1 = 4;
    int ax1 = 0,   ay1 = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        DrawBall (x,  y,  10, TX_LIGHTGREEN, TX_GREEN);
        DrawBall (x1, y1, 15, RGB (x1, y1, 128), RGB (x1/2, y1/2, 128));

        x += -vx * dt;
        y +=  vy * dt;

        vx1 += ax1 * dt;
        vy1 += ay1 * dt;

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x > 900)
           {
           vx = -vx;
           x = 900;
           }

        if (x1 > 900) {vx1 = -vx1; x1 = 900;}

        if (y > 600)
           {
            vy = -vy;
            y = 600;
           }

        if (y1 > 600) {vy1 = -vy1; y1 = 600;}

        if (x < 0)
           {
            vx = -vx;
            x = 0;
           }

        if (x1 < 0) {vx1 = - vx1; x1 = 0;}

        if (y < 0)
           {
            vy = -vy;
            y = 0;
           }

        if (y1 < 0) {vy1 = - vy1; y1 = 0;}

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

        txSleep (20);
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillcolor)
     {
     txSetColor (color, 2);
     txSetFillColor (fillcolor);

     txCircle (x,  y, r);
     }
