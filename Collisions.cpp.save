

#include "TXLib.h"
#include <math.h>

void Move_Ball (struct Ball Ball1, struct Ball Ball2, double dt);
void DrawBall (struct Ball *bol);
void MoveBall (struct Ball *bol, double dt);
double Collision (struct Ball Ball1, struct Ball Ball2);
bool CollisionIn (struct Ball Ball1, struct Ball Ball2);
void AnswerCollision (struct Ball Ball1 *bol1, struct Ball Ball2 *bol2, double dt);

//-----------------------------------------------------------------------------

struct Ball
    {
    int x,  y, rBall;
    int vx, vy;

    double ax, ay;

    COLORREF color;
    COLORREF fillcolor;
    };
struct Ball *bol;

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball (struct Ball Ball1, struct Ball Ball2, double dt);

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball (struct Ball Ball1, struct Ball Ball2, double dt)
    {
    struct Ball Ball1 *bol1 = {100, 130, 30, 5, 2, 0, 0, TX_LIGHTGREEN,     TX_GREEN};
    struct Ball Ball2 *bol2 = {120, 150, 30, 3, 1, 0, 1, RGB (12, 15, 128), RGB (122, 0, 128)};

    double dt = 1;

    //int rBB = sqrt ((x - x1) * (x - x1) + (y - y1) * (y - y1));

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        DrawBall (&Ball1);
        DrawBall (&Ball2);
        txSetFillColor (TX_BLACK);

        MoveBall (&Ball1, dt);
        MoveBall (&Ball2, dt);

        if (CollisionIn (struct Ball Ball1, struct Ball Ball2))
            {
            AnswerCollision(Ball1, Ball2, dt);
            }

        if (txGetAsyncKeyState (VK_RIGHT)) Ball1.vx --;
        if (txGetAsyncKeyState (VK_LEFT))  Ball1.vx ++;
        if (txGetAsyncKeyState (VK_UP))    Ball1.vy --;
        if (txGetAsyncKeyState (VK_DOWN))  Ball1.vy ++;

        if (txGetAsyncKeyState (VK_SPACE)) Ball1.vx = Ball1.vy = 0;

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
bool CollisionIn (struct Ball Ball1, struct Ball Ball2)
    {
    return (Collision (Ball1.x, Ball2.x, Ball1.y, Ball2.y) <= (Ball1.rBall + Ball2.rBall))? true : false;
    }

//-----------------------------------------------------------------------------

void DrawBall (struct Ball)
     {
     txSetColor (color, 2);
     txSetFillColor (fillcolor);

     txCircle (Ball.x, Ball.y, Ball.rBall);
     }

//-----------------------------------------------------------------------------

void MoveBall (struct Ball *bol, double dt)
    {
    bol -> vx += bol -> ax * dt;
    bol -> vy += bol -> ay * dt;

    bol -> x += bol -> vx * dt;
    bol -> y += b0l -> vy * dt;

    if (bol -> x > 900 - bol -> rBall) {bol -> vx = -bol -> vx; bol -> x = 900 - bol -> rBall;}

    if (bol -> y > 600 - bol -> rBall) {bol -> vy = -bol -> vy; bol -> y = 600 - bol -> rBall;}

    if (bol -> x < 0 + bol -> rBall)   {bol -> vx = -bol -> vx; bol -> x = 0 + bol -> rBall;}

    if (bol -> y < 0 + bol -> rBall)   {bol -> vy = -bol -> vy; bol -> y  = 0 + bol-> rBall;}

     }

//-----------------------------------------------------------------------------

double Collision (struct Ball Ball1, struct Ball Ball2)
    {
    double rBB = sqrt ((x - x1) * (x - x1) + (y - y1) * (y - y1));
    //printf ("расстояние между шарами Collision () rBB = %lg       \n", rBB);

    return rBB;
    }

//-----------------------------------------------------------------------------
void AnswerCollision (struct Ball Ball1 *bol1, struct Ball Ball2 *bol2, double dt)
      {
    bol1 -> vx += bol1 -> ax * dt;
    bol1 -> vy += bol1 -> ay * dt;

    bol1 -> x += -bol1 -> bol1 -> vx * dt;
    bol1 -> y += -bol1 -> bol1 -> vy * dt;

    bol2 -> vx += bol2 -> ax * dt;
    bol2 -> vy += bol2 -> ay * dt;

    bol2 -> x1 += -bol2 -> vx1 * dt;
    bol2 -> y1 += -bol2 -> vy1 * dt;
      }

//D:\school\КПК\Репозиторий\Boll_Boll\Boll_Boll\Collisions.cpp|28|error: expected primary-expression before 'struct'|
