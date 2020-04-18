//
// Created by magicgh on 4/18/2020.
//
#include "school.h"
#include <cstdio>

void Person::show() {
    printf("%s:\n\tAge: %d\n\tGender: %s\n\tAddress: %s\n\tPhone Number: %s\n\tSalary: %d\n",name.c_str(), age, gender.c_str(), addr.c_str(), number.c_str(), salary);
}

void Teacher::show(){
    Person::show();
    printf("\tTitle: %s\n",title.c_str());
}

void Cadre::show(){
    Person::show();
    printf("\tPosition: %s\n",position.c_str());
}