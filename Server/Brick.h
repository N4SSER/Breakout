//
// Created by Nasser on 31/8/21.
//

#ifndef BREAKOUTLITE_BRICK_H
#define BREAKOUTLITE_BRICK_H
#include "Painter.h"
#include "Force.h"
#include "Ball.h"
extern int score;
class Brick {
public:
    enum { WIDTH = 25,
        HEIGHT = 20 };
    Brick(int col, int row, int type);
    void draw(Painter &) const;
    void destroy();
    Force tick(const Ball &);
    int points;

    bool destroyed= false;
private:
    int hits;
    int type;
    float col_;
    float row_;
    void setType(int t);
    void checkDestroyed();
    int countDownTimer_;
};


#endif //BREAKOUTLITE_BRICK_H
