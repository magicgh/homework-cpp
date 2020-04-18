//
// Created by magicgh on 4/18/2020.
//

#ifndef WEEK_8_SCHOOL_H
#define WEEK_8_SCHOOL_H

#endif //WEEK_8_SCHOOL_H

#include <iostream>
#include <string>
using namespace std;
class Person {
    private:
        string name, gender, addr, number;
        int age, salary;
    public:
        Person(string name, string gender, string addr, int age, string number, int salary):
            name(name), gender(gender), addr(addr), age(age), number(number), salary(salary){};
        ~Person(){};
        void show();
};

class Teacher: virtual public Person{
    private:
        string title;
    public:
        Teacher(string name, string gender, string addr, string title, int age, string number, int salary):
                Person(name, gender, addr, age, number, salary), title(title){};
        ~Teacher(){};
        void show();
};

class Cadre: virtual public Person{
    private:
        string position;
    public:
        Cadre(string name, string gender, string addr, string position, int age, string number, int salary):
            Person(name, gender, addr, age, number, salary), position(position){};
        ~Cadre(){};
        void show();
};

class TeacherCadre: public Teacher, public Cadre{
    public:
        TeacherCadre(string name, string gender, string addr, string title, string position, int age, string number, int salary):
                Teacher(name, gender, addr, title, age, number, salary), Cadre(name, gender, addr, position, age, number, salary), Person(name, gender, addr, age, number, salary){};
        ~TeacherCadre(){};

};