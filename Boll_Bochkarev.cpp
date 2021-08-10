

#include "TXLib.h"

void Move_Ball ();
void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillcolor);
void MoveBall (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt);
void BallControl (int* vx, int* vy);

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball ()
    {
    int x  = 100, y  = 130,
        vx =   5, vy =   2;
    int ax =   0, ay =  -1;

    int dt = 1;

    int x1  = 120, y1  = 150,
        vx1 = 6,   vy1 = 3;
    int ax1 = 0,   ay1 = 0;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        DrawBall (x,  y,  20, color, fillcolor);
        DrawBall (x1, y1, 25, RGB (x1, y1, 128), RGB (x1 /2, y1 /2, 128));

        MoveBall (&x,  &y,  20, &vx,  &vy,  ax,   ay,   dt);
        MoveBall (&x1, &y1, 25, &vx1, &vy1, ax1, ay1, dt);

        BallControl (&vx, &vy);

        txSleep (10);
        }
    }


//-----------------------------------------------------------------------------
void BallControl (int* vx, int* vy)
        {

        if (txGetAsyncKeyState (VK_RIGHT)) (*vx) --;
        if (txGetAsyncKeyState (VK_LEFT))  (*vx) ++;
        if (txGetAsyncKeyState (VK_UP))    (*vy) --;
        if (txGetAsyncKeyState (VK_DOWN))  (*vy) ++;

        if (txGetAsyncKeyState (VK_SPACE)) (*vx) = (*vy) = 0;

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
         }
//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillcolor)
     {
     txSetColor (color, 2);
     txSetFillColor (fillcolor);

     txCircle (x, y, r);
     }

//-----------------------------------------------------------------------------

void MoveBall (int* x, int* y, int r, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx += ax * dt;
    *vy += ay * dt;

    //printf ("MoveBall (): x = %d  vx = %d _________  adr_vx = %p \n", *x, vx, &vx);

    (*x) += (*vx) * dt;
    (*y) += (*vy) * dt;

    //printf ("MoveBall (): x = %d  vx = %d raschet                \n", *x, vx);

    if ((*x) > 900 - r) {*vx = -(*vx); (*x) = (900 - r) - ((*x) - (900 - r));}

    if ((*y) > 600 - r) {*vy = -(*vy); (*y) = (600 - r) - ((*y) - (600 - r));}

    if ((*x) < 0 + r)   {*vx = -(*vx); (*x) = (0 + r) + (0 + r - (*x));}

    if ((*y) < 0 + r)   {*vy = -(*vy); (*y) = (0 + r) + (0 + r - (*y));}

    //printf ("MoveBall (): x = %d  vx = %d (after - ) adr_vx = %p \n\n", *x, vx, &vx);
    }
