//
// Created by Nasser on 31/8/21.
//
#include <cstdlib>
#include <iostream>
#include "Wall.h"
#include "Ball.h"
Wall::Wall()
{
    //int nHit=2;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < COLS_COUNT; ++col) {
            int type = rand() % 6;
            bricks_.push_back(Brick(col, row,type));
        }
    }
}

void Wall::draw(Painter &p) const
{
    for(auto& brick : bricks_){
        brick.draw(p);
    }

}

Force Wall::tick(const Ball &ball)
{
    Force result(0, 0);
    if (1 - ball.x() > 0)
        result += Force(1 - ball.x(), 0);
    if (WIDTH - ball.x() -1 < 0)
        result += Force(WIDTH - ball.x() -1, 0);
    if (1 - ball.y() > 0)
        result += Force(0, 1 - ball.y());

    for (auto& brick : bricks_)
    {
        Force f = brick . tick(ball);
        result += f;
        if (f.x != 0 || f.y != 0)
            brick.timesHit++;
            brick . destroy();
            if(brick.destroyed){
                points +=brick.points;
                getpts();
            }
    }

    return result;
}

int Wall::getpts() const {
    std::cout<<points<<std::endl;
    return points;
}

