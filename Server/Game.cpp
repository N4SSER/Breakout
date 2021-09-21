//
// Created by Nasser on 31/8/21.
//

#include <iostream>
#include "Game.h"
#include "Brick.h"
#include "Paddle.h"
void Game::draw(Painter &p) const
{
    for(auto& ball:balls ){
        ball.draw(p);
    }
    wall_.draw(p);
    paddle.draw(p);
}


void Game::setX(int x)
{
    paddle.setX(x);
}
void Game::tick()
{
    for(auto& ball:balls ){
        Force f = wall_.tick(ball);
        f += paddle.tick(ball);
        ball.tick(f);
        if (ball.y() > Wall::HEIGHT){
            ball = Ball();
            ball.setDeepLvl(0);
            std::cout<<"Oops!"<<std::endl;
            WidthofPaddle-=10;
            }
        }
    if(score>pB)
    {
        balls.push_back(ball_);
        pB+=200;
    }
}

Game::Game() {

    balls.push_back(ball_);
    pB = 100;

}

Game* Game::getInstance() {
    if (gameI == nullptr)
    {
        gameI = new Game();
    }

    return gameI;
}
