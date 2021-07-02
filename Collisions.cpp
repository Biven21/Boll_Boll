

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
    double x,  y, rBall;
    double vx, vy;

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

        if (CollisionIn (Ball1, Ball2))
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

        txSleep (200);
        }
    }
//-----------------------------------------------------------------------------

bool CollisionIn (Ball Ball1, Ball Ball2)
    {
    return ((Collision (Ball1, Ball2)) <= (Ball1.rBall + Ball2.rBall))? true : false;
    }

//-----------------------------------------------------------------------------
double Collision (Ball Ball1, Ball Ball2)
    {
    double rBB = sqrt ((Ball1.x - Ball2.x) * (Ball1.x - Ball2.x) + (Ball1.y - Ball2.y) * (Ball1.y - Ball2.y));
    printf ("расстояние между шарами Collision () rBB = %lg       \n", rBB);

    return rBB;
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

void AnswerCollision (struct Ball* Ball1, struct Ball* Ball2, double dt)
    {
    //float rBB = Colision (Ball1, Ball2);
    float rBB = sqrt (((*Ball1).x - (*Ball2).x) * ((*Ball1).x - (*Ball2).x) +
                      ((*Ball1).y - (*Ball2).y) * ((*Ball1).y - (*Ball2).y));
    if (rBB == 0) rBB = 0.01;
    float cos = (*Ball1).x / rBB;
    float sin = (*Ball1).y / rBB;

    float Vn1 = - (*Ball1).vx * sin + (*Ball1).vy * cos;
    float Vn2 = - (*Ball2).vx * sin + (*Ball2).vy * cos;
    float Vt1 =   (*Ball1).vx * cos + (*Ball2).vy * sin;
    float Vt2 =   (*Ball2).vx * cos + (*Ball2).vy * sin;

    float dop = Vn1;
          Vn1 = Vn2;
          Vn2 = dop;

    (*Ball1).vx = Vt1 * cos - Vn1 * sin;
    (*Ball2).vx = Vt2 * cos - Vn2 * sin;
    (*Ball1).vy = Vt1 * sin + Vn1 * cos;
    (*Ball2).vy = Vt2 * sin + Vn2 * cos;


      //printf ("OLDkoord X = %lg \n", oldx1);
      //printf ("koord X = %lg \n", (*Ball2).x);
    }

