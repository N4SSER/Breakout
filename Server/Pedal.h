//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_PEDAL_H
#define BREAKOUTLITE_PEDAL_H


#include "Painter.h"
#include "Force.h"
#include "Ball.h"

class Pedal {
public:
    enum { WIDTH = 60 };
    Pedal();
    void draw(Painter &) const;
    Force tick(const Ball &) const;
    void setX(int x);
private:
    int x_;
};


#endif //BREAKOUTLITE_PEDAL_H
