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
    enum { WIDTH = 20,
        HEIGHT = 8 };
    Brick(int col, int row);
    void draw(Painter &) const;
    void destroy();
    Force tick(const Ball &);
private:
    int points;
    float col_;
    float row_;
    int countDownTimer_;
};


#endif //BREAKOUTLITE_BRICK_H
