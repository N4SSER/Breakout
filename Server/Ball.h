//
// Created by n4ssser on 31/8/21.
//
#include "Force.h"
#include "Painter.h"
#ifndef BREAKOUTLITE_BALL_H
#define BREAKOUTLITE_BALL_H


class Ball {
public:
    constexpr static const float DT = 0.001;
    Ball();
    void draw(Painter &) const;
    float x() const { return x_; }
    float y() const { return y_; }
    void tick(Force);
private:
    float x_;
    float y_;
    float vx_;
    float vy_;
};


#endif //BREAKOUTLITE_BALL_H
