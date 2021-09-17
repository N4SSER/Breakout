//
// Created by Nasser on 31/8/21.
//

#include <iostream>
#include "Game.h"
#include "Brick.h"
#include "Paddle.h"
void Game::draw(Painter &p) const
{
    wall_.draw(p);
    //for(auto& ball : balls_level)...
    ball_.draw(p);
    paddle.draw(p);
}


void Game::setX(int x)
{
    paddle.setX(x);
}
void Game::tick()
{
    Force f = wall_.tick(ball_);
    f += paddle.tick(ball_);
    ball_.tick(f);
    if (ball_.y() > Wall::HEIGHT){
        ball_ = Ball();
        ball_.setDeepLvl(0);
        std::cout<<"Oops!"<<std::endl;
        WidthofPaddle-=10;
    }
}

Game::Game() {

}

Game* Game::getInstance() {
    if (gameI == nullptr)
    {
        gameI = new Game();
    }

    return gameI;
}
