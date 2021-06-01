

#include "TXLib.h"

void Move_Boll ();

int main()
    {
    txCreateWindow (900, 600);

    Move_Boll ();

    return 0;
    }

void Move_Boll ()
    {
    int x  = 100, y  = 100,
        vx =  15, vy =   2;

    int dt = 1;

    int x1  = 120, y1  = 150,
        vx1 = 10,  vy1 = 4;

    txSetColor (TX_LIGHTGREEN, 2);
    txSetFillColor (TX_GREEN);

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x,  y, 10);
        txCircle (x1, y1, 15);

        x += -vx * dt;
        y +=  vy * dt;

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x > 900)
           {
           vx = -vx;
           x = 900;
           }

        if (x1 > 900) vx1 = -vx1;

        if (y > 600)
           {
            vy = -vy;
            y = 600;
           }

        if (y1 > 600) vy1 = -vy1;

        if (x < 0)
           {
            vx = -vx;
            x = 0;
           }

        if (x1 < 0) vx1 = - vx1;

        if (y < 0)
           {
            vy = -vy;
            y = 0;
           }

        if (y1 < 0) vy1 = - vy1;

        if (txGetAsyncKeyState (VK_RIGHT)) vx ++;
        if (txGetAsyncKeyState (VK_LEFT))  vx --;
        if (txGetAsyncKeyState (VK_UP))    vy ++;
        if (txGetAsyncKeyState (VK_DOWN))  vy --;

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

     while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x + 10, y + 20, 1);
        x += (-vx / 8) * dt;
        y += (-vy / 2) * dt;

        if (x > 900) {vx = - vx; x = 900;}
        if (y > 600) {vy = - vy; y = 600;}
        if (x < 0)   {vx = - vx; x = 0;}
        if (y < 0)   {vy = - vy; y = 0;}
        }
    }
