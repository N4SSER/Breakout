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
    if(score>100)
    {
        ball_1.draw(p);
    }
    if(score>400)
    {
        ball_2.draw(p);
    }
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
    if(score>100)
    {
        Force f = wall_.tick(ball_1);
        f += paddle.tick(ball_1);
        ball_1.tick(f);
        if (ball_1.y() > Wall::HEIGHT){
            ball_1 = Ball();
            ball_1.setDeepLvl(0);
            std::cout<<"Es la bola 2 "<<std::endl;
            WidthofPaddle-=10;
        }
    }
    if(score>400)
    {
        Force f = wall_.tick(ball_2);
        f += paddle.tick(ball_2);
        ball_2.tick(f);
        if (ball_2.y() > Wall::HEIGHT){
            ball_2 = Ball();
            ball_2.setDeepLvl(0);
            std::cout<<"Es la bola 3 extra "<<std::endl;
            WidthofPaddle-=10;
        }
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
