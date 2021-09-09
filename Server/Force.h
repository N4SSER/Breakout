//
// Created by n4ssser on 31/8/21.
//

#ifndef BREAKOUTLITE_FORCE_H
#define BREAKOUTLITE_FORCE_H

struct Force
{
    Force(float x, float y);
    float x, y;
    const Force &operator+=(Force f);
};



#endif //BREAKOUTLITE_FORCE_H
