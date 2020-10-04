//
// Created by safwane on 28/09/2020.
//

#ifndef TRAIN_RECTANGLE_H
#define TRAIN_RECTANGLE_H

#include "Segment.h"

class Rectangle {

private:
    int length;
    int width;
    Segment s1,s2,s3,s4;

public:
    void resize(int l,int w);
    int getLength();
    int getWidth();
    Segment getSegment();
    Rectangle()=default;
    Rectangle(int x);
};


#endif //TRAIN_RECTANGLE_H
