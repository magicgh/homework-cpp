//
// Created by magicgh on 4/3/2020.
//
#pragma once
#ifndef WEEK_6_TEACHER_H
#define WEEK_6_TEACHER_H

#endif //WEEK_6_TEACHER_H

#include "person.h"
using namespace std;
class Teacher: public Person{
    private:
        string tid;
        int salary;
    public:
        Teacher(string name,string gender,int age,string tid,int salary):Person(name,gender,age),tid(tid),salary(salary){};
        inline string getTid()const {return tid;}
        inline int getSalary()const {return salary;}
        void print(){
            Person::print();
            printf("\tTeacher ID: %s\n\tSalary: %d\n",tid.c_str(),salary);
        }
};