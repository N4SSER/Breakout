//
// Created by n4ssser on 31/8/21.
//

#include "Paddle.h"
#include "Wall.h"

Paddle::Paddle(): x_(Wall::WIDTH / 2) {}

void Paddle::draw(Painter &p) const
{
    p.setColor(Painter::WHITE);
    p.bar(x_ - WIDTH / 2, Wall::HEIGHT - 5,
          x_ + WIDTH - WIDTH / 2, Wall::HEIGHT);
}
Force Paddle::tick(const Ball &ball) const
{
    float s = ball.x() - x_ + WIDTH / 2;
    if (s >= 0 && s < WIDTH &&
        Wall::HEIGHT - 1 - ball.y() < 0)
        return {(Wall::HEIGHT - 2 - ball.y()) * (x_ - ball.x()) / WIDTH,
                     Wall::HEIGHT - 2 - ball.y()};
    else
        return {0, 0};
}
void Paddle::setX(int x)
{
    x_ = x;
}
