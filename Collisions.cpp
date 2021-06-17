

#include "TXLib.h"
#include <math.h>

void Move_Ball ();
void DrawBall (int x, int y, int rBall, COLORREF color, COLORREF fillcolor);
void MoveBall (int* x, int* y, int* vx, int* vy, int rBall, int ax, int ay, int dt);
double Collision (int x, int x1, int y, int y1);
bool CollisionIn (int x, int x1, int y, int y1, int rBall, int rBall1);
void AnswerCollision (int* x, int* x1, int* y, int* y1, int* vx, int* vx1, int* vy, int* vy1,
                      int ax, int ay, int dt);

struct Ball
    {
    int x,  y, rBall;
    int vx, vy;

    double ax, ay;

    COLORREF color;
    COLORREF fillcolor;
    };

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball ()
    {
    Ball Ball1 = {100, 130, 30, 5, 2, 0, 0, TX_LIGHTGREEN,     TX_GREEN};
    Ball Ball2 = {120, 150, 30, 3, 1, 0, 1, RGB (12, 15, 128), RGB (122, 0, 128)};

    int dt = 1;

    //int rBB = sqrt ((x - x1) * (x - x1) + (y - y1) * (y - y1));

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        DrawBall (Ball1);
        DrawBall (Ball2);
        txSetFillColor (TX_BLACK);

        MoveBall (&x,  &y,  &vx,  &vy,  rBall,  ax,  ay,  dt);
        MoveBall (&x1, &y1, &vx1, &vy1, rBall1, ax1, ay1, dt);

        if (CollisionIn (x, x1, y, y1, rBall, rBall1))
            {
            AnswerCollision(&x, &x1, &y, &y1, &vx, &vx1, &vy, &vy1, ax, ay, dt);
            }

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
bool CollisionIn (int x, int x1, int y, int y1, int rBall, int rBall1)
    {
    return (Collision (x, x1, y, y1) <= (rBall + rBall1))? true : false;
    }

//-----------------------------------------------------------------------------

void DrawBall (Ball)
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

//-----------------------------------------------------------------------------

double Collision (int x, int x1, int y, int y1)
    {
    double rBB = sqrt ((x - x1) * (x - x1) + (y - y1) * (y - y1));
    //printf ("���������� ����� ������ Collision () rBB = %lg       \n", rBB);

    return rBB;
    }

//-----------------------------------------------------------------------------
void AnswerCollision (int* x, int* x1, int* y, int* y1, int* vx, int* vx1, int* vy, int* vy1,
                      int ax, int ay, int dt)
      {
    *vx += ax * dt;
    *vy += ay * dt;


    (*x) += -(*vx) * dt;
    (*y) += -(*vy) * dt;

    *vx1 += ax * dt;
    *vy1 += ay * dt;

    (*x1) += -(*vx1) * dt;

    (*y1) += -(*vy1) * dt;
      }
