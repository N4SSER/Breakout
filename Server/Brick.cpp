//
// Created by n4ssser on 31/8/21.
//

#include "Brick.h"
#include "Painter.h"
#include "Ball.h"
int timesHit;
Brick::Brick(int col, int row,int type,int hits,int point, bool deep):
        col_(col),
        row_(row),
        countDownTimer_(-1){
    this->hits=hits;
    poinTs = point;
    this->type = type;
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
            result += Force(col_ * WIDTH + WIDTH - ball.x() + 1,0);
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
            countDownTimer_ = Painter::BLACK * 10;
            points+=poinTs;
            timesHit=0;
            }
        }


}

