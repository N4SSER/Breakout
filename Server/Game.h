//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_GAME_H
#define BREAKOUTLITE_GAME_H

#include <list>
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
private:
    std:: list<Ball> balls;
    Game();
    int pB;
    inline static Game* gameI;
    Wall wall_;
    Paddle paddle;
};


#endif //BREAKOUTLITE_GAME_H
