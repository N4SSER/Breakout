//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_BRICK_H
#define BREAKOUTLITE_BRICK_H
#include "Painter.h"
#include "Force.h"
#include "Ball.h"

class Brick {
public:
    enum { WIDTH = 25,
        HEIGHT = 20 };
    Brick(int col, int row, int type,int hits,int point,bool deep);
    void draw(Painter &) const;
    void destroy();
    Force tick(const Ball &);
private:
    int hits;
    int poinTs;
    int type;
    int points;
    float col_;
    float row_;
    int countDownTimer_;
};


#endif //BREAKOUTLITE_BRICK_H
