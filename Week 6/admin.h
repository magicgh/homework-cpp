//
// Created by magicgh on 4/3/2020.
//
#pragma once
#ifndef WEEK_6_ADMIN_H
#define WEEK_6_ADMIN_H

#endif //WEEK_6_ADMIN_H

#include "teacher.h"
#include <vector>

using namespace std;
class Admin: public Teacher{
private:
    vector<string>classes;
public:
    Admin(string name,string gender,int age,string tid,int salary,vector<string> classes):Teacher(name,gender,age,tid,salary),classes(classes){};
    inline vector<string> getClasses()const {return classes;}
    inline string getClass(const int& pos)const {return classes[pos];}
    inline string getFirstClass()const {return classes.front();}
    inline string getLastClass()const {return classes.back();}
    inline void addClassToBack(const string&s) {classes.push_back(s);}
    inline void deleteLastClass() {classes.pop_back();}
    inline void resetClasses() {classes.clear();}
    inline void insertClass(const int &pos,const string &s) {classes.insert(classes.begin()+pos,s);}
    inline void deleteClass(const int &pos) {classes.erase(classes.begin()+pos);}
    inline void printClasses()const {for(auto &it:classes)cout<<it<<" ";}
    inline unsigned int countClasses()const {return classes.size();}
    void print(){
        Teacher::print();
        cout<<"\tClasses: ";
        for(auto &it:classes)cout<<it<<" ";
    }
};