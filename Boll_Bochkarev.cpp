

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
    int x  = 100,   y  = 100,
        vx =  15,   vy =   2;

    int dt = 1;

    txSetColor (TX_LIGHTGREEN, 2);
    txSetFillColor (TX_GREEN);

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x, y, 10);
        x += vx * dt;
        y += vy * dt;

        if (x > 900)
           {
           vx = -vx;
           x = 900;
           }

        if (y > 600)
           {
            vy = -vy;
            y = 600;
           }

        if (x < 0)
           {
            vx = -vx;
            x = 0;
           }

        if (y < 0)
           {
            vy = -vy;
            y = 0;
           }
        txCircle (x, y, 12);
        x += (-vx / 8) * dt;
        y += (-vy / 2) * dt;

        if (x > 900) {vx = - vx; x = 900;}
        if (y > 600) {vy = - vy; y = 600;}
        if (x < 0)   {vx = - vx; x = 0;}
        if (y < 0)   {vy = - vy; y = 0;}

        txSleep (20);
        }
    }
