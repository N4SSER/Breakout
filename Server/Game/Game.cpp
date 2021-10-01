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

void Game::Set_Deep(bool state)
{
    deepState=state;
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
            timesLosed++;
            WidthofPaddle-=10;
            }
        }
    if(score>pB)
    {
        balls.push_back(ball_);
        pB+=200;
    }
    if(timesLosed>5){
        finished = true;
    }
}

Game::Game() {

    balls.push_back(ball_);
    pB = 100;std::cout<<score<<std::endl;

}

Game* Game::getInstance() {
    if (gameI == nullptr)
    {
        gameI = new Game();
    }

    return gameI;
}
