//
// Created by n4ssser on 31/8/21.
//
#include "Force.h"
#include "Painter.h"
#ifndef BREAKOUTLITE_BALL_H
#define BREAKOUTLITE_BALL_H

extern int ball_speed_x;
extern int ball_speed_y;
class Ball {
public:
    constexpr static const float DT = 0.0005;
    Ball();
    void setDeepLvl(int lvl);
    int getDeepLvl() const;
    void increaseDeep();
    void draw(Painter &) const;
    [[nodiscard]] float x() const { return x_; }
    [[nodiscard]] float y() const { return y_; }
    void tick(Force);
private:
    int lvl;
    float x_;
    float y_;
    float vx_;
    float vy_;
};


#endif //BREAKOUTLITE_BALL_H
