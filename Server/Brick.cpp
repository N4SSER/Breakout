//
// Created by Nasser on 31/8/21.
//

#include <iostream>
#include "Brick.h"
#include "Painter.h"
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"
int timesHit;
int score;
Brick::Brick(int col, int row,int type):
        col_(col),
        row_(row),
        countDownTimer_(-1){
        this->type = type;
        setType(type);
    }

void Brick::draw(Painter &p) const
{
    if (countDownTimer_ == -1)
    {
        p.setColor(static_cast<Painter::Color>(row_ /2));
        p.bar(col_ * WIDTH + 3, row_ * HEIGHT + 3,
              (col_ + 1) * WIDTH - 1, (row_ + 1) * HEIGHT - 1);
    }
    else if (countDownTimer_ != 0)
    {
        p.setColor
                (static_cast<Painter::Color>
                 (countDownTimer_ / 10));
        p.bar(col_ * WIDTH + 1, row_ * HEIGHT + 1,
              (col_ + 1) * WIDTH - 1, (row_ + 1) * HEIGHT - 1);
    }
}

Force Brick::tick(const Ball &ball)
{
    if (countDownTimer_ == 0)
        return {0, 0};
    if (countDownTimer_ > 0)
        --countDownTimer_;

    Force result(0, 0);
    float f1 = (ball.y() - row_ * HEIGHT) * WIDTH -
               (ball.x() - col_ * WIDTH) * HEIGHT;
    float f2 = (ball.y() - row_ * HEIGHT - HEIGHT) * WIDTH +
               (ball.x() - col_ * WIDTH) * HEIGHT;
    bool d = f1 < 0;
    bool u = f2 < 0;

    if (d && u) // top
    {
        if (row_ * HEIGHT - ball.y() - 1 < 0 ){
            timesHit+=1;
            result += Force(0, row_ * HEIGHT - ball.y() - 1);}
    }
    else if (d && !u) // right
    {
        if (col_ * WIDTH + WIDTH - ball.x() + 1 > 0){
            timesHit+=1;
            result += Force(col_ * WIDTH + WIDTH - ball.x() + 1,0); //El bug tiene que ver con esto?
        }
    }
    else if (!d && u) // left
    {
        if (col_ * WIDTH - ball.x() - 1 < 0){
            timesHit+=1;
            result += Force(0, col_ * WIDTH - ball.x() - 1);
        }
    }
    else
    {
        if (row_ * HEIGHT + HEIGHT - ball.y() + 1 > 0){
            timesHit+=1;
            result += Force(0, row_ * HEIGHT + HEIGHT - ball.y() + 1);

        }

    }
    return result;
}

void Brick::destroy()
{
        if (countDownTimer_ == -1){
            if(timesHit>hits){
                checkDestroyed();
            }
        }


}

void Brick::setType(int t) {
    switch (t) {
        case 0:
            this->points = 10; //Comunes
            this->hits = 0;
            break;
        case 1:
            this->points = 15; //Dobles
            this->hits = 2;
            break;
        case 2:
            this->points = 20; //Triples
            this->hits = 3;
            break;
        case 3:
            this->points=30; //Internos
            this->hits =1;
            break;
        case 4:
            this->points=0; //Profundos
            break;
        case 5:
            this->points=0; //Sopresas
            this->hits=0;
            break;

    }
}

void Brick::checkDestroyed() {
    Game* game = Game::getInstance();
    if(type<3){
        destroyed = true;
        countDownTimer_ = Painter::BLACK * 10;
        timesHit=0;
        destroyed = false;
        score=score+points;
        std::cout<<score<<std::endl;
    }
    else if(type ==3){
        if(game->ball_.getDeepLvl() > 2){
            destroyed = true;
            countDownTimer_ = Painter::BLACK * 10;
            timesHit=0;
            destroyed =  false;
            score= score+points;
            std::cout<<score<<std::endl;
            std::cout<<"Es un bloque interno" <<std::endl;

        }
    }
    else if(type==5){
        int typeofSup = rand() % 4;
        if(typeofSup==0){
            // Aumentar el tamaño de la barra de jugador
            destroyed = true;
            countDownTimer_ = Painter::BLACK * 10;
            timesHit=0;
            destroyed = false;
            score=score+points;
            WidthofPaddle+=30;
            std::cout<<score<<std::endl;
            std::cout<<"Surprise1"<<std::endl;
        }
        else if(typeofSup==1){
            // Disminuir el tamaño de la barra de jugador.
            destroyed = true;
            countDownTimer_ = Painter::BLACK * 10;
            timesHit=0;
            destroyed = false;
            score=score+points;
            WidthofPaddle-=30;
            std::cout<<score<<std::endl;
            std::cout<<"Surprise2"<<std::endl;
        }
        else if(typeofSup==2){
            //Disminuir la velocidad de la bola
            destroyed = true;
            countDownTimer_ = Painter::BLACK * 10;
            timesHit=0;
            destroyed = false;
            score=score+points;
            ball_speed_x= 20;
            ball_speed_y= -20;
            std::cout<<score<<std::endl;
            std::cout<<"Surprise3"<<std::endl;
        }
        else{
            //Aumentar la velocidad de la bola
            destroyed = true;
            countDownTimer_ = Painter::BLACK * 10;
            timesHit=0;
            destroyed = false;
            score=score+points;
            ball_speed_x= 100;
            ball_speed_y= -100;
            std::cout<<score<<std::endl;
            std::cout<<"Surprise4"<<std::endl;
        }
    }
    else{
        game->ball_.increaseDeep();
    }
}

