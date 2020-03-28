//
// Created by magicgh on 3/27/20.
//

#include "person.h"

#ifndef WEEK_5_EMPLOYEE_H
#define WEEK_5_EMPLOYEE_H

#endif //WEEK_5_EMPLOYEE_H

class Employee: public Person{
    private:
        string workerID;
        int salary;
    public:
        Employee(string name, string gender, int age, string workerID, int salary):Person(name, gender, age),workerID(workerID),salary(salary){};
        string getWorkID() const{
            return workerID;
        }
        int getSalary() const{
            return salary;
        }
        void print() const{
            printf("[%s]\n\tGender:%s\n\tAge:%d\n\tWorker ID:%s\n\tSalary:%d\n\t\n",this->getName().c_str(),this->getGender().c_str(),this->getAge(),this->workerID.c_str(),this->salary);
        }
};


