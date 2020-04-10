//
// Created by magicgh on 4/10/2020.
//

#ifndef WEEK_7_COMPONENT_BASE_H
#define WEEK_7_COMPONENT_BASE_H

#endif //WEEK_7_COMPONENT_BASE_H

#include <iostream>
using namespace std;

class ComponentBase {
    protected:
        int length,width;
    public:
        ComponentBase(int length, int width):length(length),width(width){};
        virtual void setLength(int x)=0;
        virtual void setWidth(int x)=0;
        virtual void printLength()=0;
        virtual void printWidth()=0;
};