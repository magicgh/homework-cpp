//
// Created by magicgh on 4/10/2020.
//

#ifndef WEEK_7_WINDOW_H
#define WEEK_7_WINDOW_H

#endif //WEEK_7_WINDOW_H

#include "component_base.h"
using namespace std;

class Window: virtual public ComponentBase{
    private:
        int cost;
    public:
        Window(int length, int width, int cost):ComponentBase(length,width),cost(cost){};
        void setLength(int x){length=x;}
        void setWidth(int x){width=x;}
        void printLength(){cout<<length<<endl;}
        void printWidth(){cout<<width<<endl;}
        void setCost(int x){cost=x;}
        void printCost(){cout<<cost<<endl;}
};