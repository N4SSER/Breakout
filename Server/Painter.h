//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_PAINTER_H
#define BREAKOUTLITE_PAINTER_H


class Painter {
public:
    enum Color { YELLOW, GREEN, ORANGE, RED, WHITE, BLACK };
    static void bar(float x1,  float y1, float x2, float y2);
    static void ball(float x, float y);
    static void setColor(Color);
};


#endif //BREAKOUTLITE_PAINTER_H
