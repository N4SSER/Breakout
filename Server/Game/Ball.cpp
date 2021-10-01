//
// Created by n4ssser on 31/8/21.
//

#include "Ball.h"
#include "Painter.h"
#include "Wall.h"
int ball_speed_x=80;
int ball_speed_y= -80;
Ball::Ball(): x_(Wall::WIDTH ),
              y_(Wall::HEIGHT - 3),
              vx_(ball_speed_x),
              vy_(ball_speed_y) {}

void Ball::draw(Painter &p) const
{

    p.setColor(Painter::WHITE);
    p.ball(x_, y_);
}
/**
 *
 * Este meteodo calcula la fuerza de rebote de la bola ademas cambia la velocidad de la bola
 * dependiendo de la fuerza con la que choca la bola
 *
 */
void Ball::tick(Force f)
{
    float x = f.x;
    float y = f.y;
    const float LIM = .33;
    if (x > LIM)
        x = LIM;
    if (x < -LIM)
        x = -LIM;
    if (y > LIM)
        y = LIM;
    if (y < -LIM)
        y = -LIM;

    vx_ += 20 * x;
    vy_ += 20 * y;
    x_ += vx_ * DT;
    y_ += vy_ * DT;
}

void Ball::setDeepLvl(int lvl) {
    this->lvl = lvl;
}

int Ball::getDeepLvl() const {
    return lvl;
}

void Ball::increaseDeep() {
    this->lvl+=1;
}
