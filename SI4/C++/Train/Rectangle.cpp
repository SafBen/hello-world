//
// Created by safwane on 28/09/2020.
//

#include "Rectangle.h"

void Rectangle::resize(int l, int w) {
    this->length=l;
    this->width=w;
}

int Rectangle::getLength() {
    return this->length;
}

//Rectangle::Rectangle():s1(),s2(),s3(),s4() {
//    this->length=0;
//}

int Rectangle::getWidth() {
    return this->width;
}

Rectangle::Rectangle(int x) :s1(10),s2(4),s3(10),s4(4)  {
    this->length=x;
}

Segment Rectangle::getSegment() {
    return s1;
}
