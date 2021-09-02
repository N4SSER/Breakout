//
// Created by n4ssser on 31/8/21.
//

#include <iostream>
#include "Game.h"
void Game::draw(Painter &p) const
{
    wall_.draw(p);
    //for(auto& ball : balls_level)...
    ball_.draw(p);
    pedal_.draw(p);
}


void Game::setX(int x)
{
    pedal_.setX(x);
}
void Game::tick()
{
    Force f = wall_.tick(ball_);
    f += pedal_.tick(ball_);
    ball_.tick(f);
    if (ball_.y() > Wall::HEIGHT){
        ball_ = Ball();
        std::cout<<"Oops!"<<std::endl;}
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
