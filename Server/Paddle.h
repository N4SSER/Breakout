//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_PEDAL_H
#define BREAKOUTLITE_PEDAL_H


#include "Painter.h"
#include "Force.h"
#include "Ball.h"
extern int WidthofPaddle;
class Paddle {
public:
    enum { WIDTH = 60 };
    //int WidthofPaddle=60; //Aumentar de tamano
    Paddle();
    void draw(Painter &) const;
    Force tick(const Ball &) const;
    void setX(int x);
private:
    int x_;
};


#endif //BREAKOUTLITE_PEDAL_H
