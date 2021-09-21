//
// Created by n4ssser on 31/8/21.
//
#include <vector>
#include "Brick.h"
#include "Ball.h"
#include "Force.h"
#include "Painter.h"

#ifndef BREAKOUTLITE_WALL_H
#define BREAKOUTLITE_WALL_H


class Wall {
    public:
    enum { ROWS_COUNT = 16,
        COLS_COUNT = 8 * 3 };
    enum { WIDTH = ROWS_COUNT * Brick::WIDTH,
        HEIGHT = COLS_COUNT * Brick::HEIGHT };
    Wall();
    void draw(Painter &) const;
    Force tick(const Ball &);
    int points;
public:
    int getpts() const; //No actualiza bien los puntos ??
    typedef std::vector<Brick> Bricks;
    Bricks bricks_;
};


#endif //BREAKOUTLITE_WALL_H
