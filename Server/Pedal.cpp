//
// Created by n4ssser on 31/8/21.
//

#include "Pedal.h"
#include "Wall.h"

Pedal::Pedal(): x_(Wall::WIDTH / 2) {}

void Pedal::draw(Painter &p) const
{
    p.setColor(Painter::GREEN);
    p.bar(x_ - WIDTH / 2, Wall::HEIGHT - 10,
          x_ + WIDTH - WIDTH / 2, Wall::HEIGHT);
}
Force Pedal::tick(const Ball &ball) const
{
    float s = ball.x() - x_ + WIDTH / 2;
    if (s >= 0 && s < WIDTH &&
        Wall::HEIGHT - 11 - ball.y() < 0)
        return {(Wall::HEIGHT - 11 - ball.y()) * (x_ - ball.x()) / WIDTH,
                     Wall::HEIGHT - 11 - ball.y()};
    else
        return {0, 0};
}
void Pedal::setX(int x)
{
    x_ = x;
}
