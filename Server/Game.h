//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_GAME_H
#define BREAKOUTLITE_GAME_H


#include "Painter.h"
#include "Ball.h"
#include "Wall.h"
#include "Pedal.h"

class Game {
public:
    void draw(Painter &) const;
    void setX(int x);
    void tick();
    static Game* getInstance();
private:
    Game();
    inline static Game* gameI;
    Ball ball_;
    Wall wall_;
    Pedal pedal_;
};


#endif //BREAKOUTLITE_GAME_H
