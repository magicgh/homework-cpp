//
// Created by magicgh on 4/3/2020.
//
#pragma once
#ifndef WEEK_6_PERSON_H
#define WEEK_6_PERSON_H

#endif //WEEK_6_PERSON_H

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class Person{
    private:
        string name,gender;
        int age;
    public:
        Person(string name,string gender,int age):name(name),gender(gender),age(age){};
        inline string getName()const {return name;}
        inline string getGender()const {return gender;}
        inline int getAge()const {return age;}
        void print(){
            printf("[%s]\n\tGender: %s\n\tAge: %d\n",name.c_str(),gender.c_str(),age);
        }
};