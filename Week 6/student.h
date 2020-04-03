//
// Created by magicgh on 4/3/2020.
//
#pragma once
#ifndef WEEK_6_STUDENT_H
#define WEEK_6_STUDENT_H

#endif //WEEK_6_STUDENT_H

#include "person.h"
using namespace std;
class Student: public Person{
    private:
        string sid,sclass;
    public:
        Student(string name,string gender,int age,string sid,string sclass):Person(name,gender,age),sid(sid),sclass(sclass){};
        inline string getSid()const {return sid;}
        inline string getSclass()const {return sclass;}
        void print(){
            Person::print();
            printf("\tStudent ID: %s\n\tClass: %s\n",sid.c_str(),sclass.c_str());
        }
};