//
// Created by magicgh on 3/27/20.
//

#ifndef WEEK_5_PERSON_H
#define WEEK_5_PERSON_H

#endif //WEEK_5_PERSON_H

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Person{
    private:
        string name,gender;
        int age;
    public:
        Person(string name,string gender,int age):name(name),gender(gender),age(age){};
        string getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }
        string getGender() const{
            return gender;
        }
        void print() const{
            printf("[%s]\n\tGender:%s\n\tAge:%d\n",this->name.c_str(),this->gender.c_str(),this->age);
        }
};