//
// Created by n4ssser on 31/8/21.
//

#include "Painter.h"
#include <GL/gl.h>
#include <cmath>
void Painter::bar(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();


}

void Painter::ball(float cx, float cy)
{
    float r = 7;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 40; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(40);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);

    }
    glEnd();
}

void Painter::setColor(Color color)
{
    static const struct
    {
        float r, g, b;
    } colors[] =
            {
                    { 1, 1, 0 }, // yellow
                    { 0, 1, 0 }, // green
                    { 1, 0.5, 0 }, // orange
                    { 1, 0, 0 }, // red
                    { 1, 1, 1 }, // yellow
                    { 0, 0, 0 }, // black
            };
    glColor3f(colors[color].r,
              colors[color].g,
              colors[color].b);
}
