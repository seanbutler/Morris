//
// Created by sean on 12/02/2021.
//

#pragma once
#include <math.h>       /* sin */

class XForm {
public:
    XForm()
            : x(0.0), y(0.0)
            , dx(0.0), dy(1.0)
            , w(1.0), h(1.0)
    {
    }

    XForm(const XForm & F)
            : x(F.x), y(F.y)
            , w(F.w), h(F.h)
            , dx(F.dx), dy(F.dy)
    {
    }

    XForm(float X = 0.0f, float Y = 0.0f, float DX = 0.0f, float DY = 1.0f, float W = 0.0f, float H = 0.0f)
            : x(X), y(Y)
            , dx(DX), dy(DY)
            , w(W), h(H)
    {
    }

    void Move(float X, float Y)         { x += X; y+=Y; }

    void SetX(float X)                  { x = X; }
    void SetY(float Y)                  { y = Y; }

    void MoveY(float D)                 { Move(0.0, D); }
    void MoveX(float D)                 { Move(D, 0.0); }

    void Advance(float D = 1.0)         { x += (dx*D); y += (dy*D); }
    void Retreat(float D = 1.0)         { x -= (dx*D); y -= (dy*D); }

    void SetDirection(float X, float Y) { dx = X; dy = Y; }

    void TurnRight(float A=90.0)
    {
        double cosA = cos(A);
        double sinA = sin(A);

        double px = x * cosA - y * sinA;
        double py = x * sinA + y * cosA;

        x = px;
        y = py;
    }

    void TurnLeft(float A = 90.0) {
        TurnRight(A * -1);
    }

public:
    float x, y;
    float dx, dy;
    float w, h;
};
