

#include "TXLib.h"
#include <math.h>

void Move_Ball ();
void DrawBall (struct Ball);
void MoveBall (struct Ball* Ball, double dt);
double Collision (struct Ball Ball1, struct Ball Ball2);
bool CollisionIn (struct Ball Ball1, struct Ball Ball2);
void AnswerCollision (struct Ball* Ball1, struct Ball* Ball2, double dt);

//-----------------------------------------------------------------------------

struct Ball
    {
    int x,  y, rBall;
    int vx, vy;

    double ax, ay;

    COLORREF color;
    COLORREF fillcolor;
    };

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (900, 600);

    Move_Ball ();

    return 0;
    }

//-----------------------------------------------------------------------------

void Move_Ball ()
    {
    struct Ball Ball1 = {100, 130, 30, 5, 2, 0, 0, TX_LIGHTGREEN,     TX_GREEN};
    struct Ball Ball2 = {120, 150, 30, 3, 1, 0, 1, RGB (12, 15, 128), RGB (122, 0, 128)};

    double dt = 1;

    //int rBB = sqrt ((x - x1) * (x - x1) + (y - y1) * (y - y1));

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        DrawBall (Ball1);
        DrawBall (Ball2);
        txSetFillColor (TX_BLACK);

        MoveBall (&Ball1, dt);
        MoveBall (&Ball2, dt);

        if (CollisionIn (struct Ball Ball1, struct Ball Ball2))
            {
            AnswerCollision(&Ball1, &Ball2, dt);
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
    return ((Collision (struct Ball Ball1, struct Ball Ball2)) <= (Ball1.rBall + Ball2.rBall))? true : false;
    }

//-----------------------------------------------------------------------------

void DrawBall (struct Ball Ball)
     {
     txSetColor (Ball.color, 2);
     txSetFillColor (Ball.fillcolor);

     txCircle (Ball.x, Ball.y, Ball.rBall);
     }

//-----------------------------------------------------------------------------

void MoveBall (struct Ball* Ball, double dt)
    {
    (*Ball).vx += (*Ball).ax * dt;
    (*Ball).vy += (*Ball).ay * dt;

    (*Ball).x += (*Ball).vx * dt;
    (*Ball).y += (*Ball).vy * dt;

    if ((*Ball).x > 900 - (*Ball).rBall) {(*Ball).vx = -(*Ball).vx; (*Ball).x = 900 - (*Ball).rBall;}

    if ((*Ball).y > 600 - (*Ball).rBall) {(*Ball).vy = -(*Ball).vy; (*Ball).y = 600 - (*Ball).rBall;}

    if ((*Ball).x < 0 + (*Ball).rBall)   {(*Ball).vx = -(*Ball).vx; (*Ball).x = 0 + (*Ball).rBall;}

    if ((*Ball).y < 0 + (*Ball).rBall)   {(*Ball).vy = -(*Ball).vy; (*Ball).y = 0 + (*Ball).rBall;}

     }

//-----------------------------------------------------------------------------

double Collision (struct Ball Ball1, struct Ball Ball2)
    {
    double rBB = sqrt ((Ball1.x - Ball2.x) * (Ball1.x - Ball2.x) + (Ball1.y - Ball2.y) * (Ball1.y - Ball2.y));
    //printf ("���������� ����� ������ Collision () rBB = %lg       \n", rBB);

    return rBB;
    }

//-----------------------------------------------------------------------------
void AnswerCollision (struct Ball* Ball1, struct Ball* Ball2, double dt)
      {
    (*Ball1).vx += (*Ball1).ax * dt;
    (*Ball1).vy += (*Ball1).ay * dt;

    (*Ball1).x += -(*Ball1).vx * dt;
    (*Ball1).y += -(*Ball1).vy * dt;

    (*Ball2).vx += (*Ball2).ax * dt;
    (*Ball2).vy += (*Ball2).ay * dt;

    (*Ball2).x += -(*Ball2).vx * dt;
    (*Ball2).y += -(*Ball2).vy * dt;
      }

//D:\school\���\�����������\Boll_Boll\Boll_Boll\Collisions.cpp|28|error: expected primary-expression before 'struct'|
