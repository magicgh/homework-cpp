//
// Created by magicgh on 4/18/2020.
//

#ifndef WEEK_8_BIRD_H
#define WEEK_8_BIRD_H

#endif //WEEK_8_BIRD_H

#include <iostream>
#include <string>
using namespace std;

class IShape{
    public:
        IShape() = default;
        virtual ~IShape(){}
        virtual void area() = 0;
};

class IAction{
    public:
        IAction() = default;
        virtual ~IAction(){}
        virtual void run() = 0;
};

class Bird: public IShape, public IAction{
    public:
        Bird() = default;
        virtual ~Bird(){}
        void area(){
            cout<<"我用了接口IShape"<<endl;
        }
        void run(){
            cout<<"我用了接口IAction"<<endl;
        }
};