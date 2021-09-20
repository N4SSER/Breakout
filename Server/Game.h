//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_GAME_H
#define BREAKOUTLITE_GAME_H


#include "Painter.h"
#include "Ball.h"
#include "Wall.h"
#include "Paddle.h"
#include "Brick.h"

class Game {
public:
    void draw(Painter &) const;
    void setX(int x);
    void tick();
    static Game* getInstance();
    int level{};
    Ball ball_;
    Ball ball_1;
    Ball ball_2; //Esta bola esta demas
private:
    Game();
    inline static Game* gameI;
    Wall wall_;
    Paddle paddle;
};


#endif //BREAKOUTLITE_GAME_H
