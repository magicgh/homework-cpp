#include <iostream>
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
int main() {
    Person("Amy","Female",21).print();
    Student("Bill","Male",15,"EECS-20200403","20200101").print();
    Teacher("Cindy","Female",32,"T20200404",15000).print();
    Admin dell("Dell","Male",29,"ADMIN-20200405",20000,vector<string>{"20200101","20200102","20200103","20200104","20200105"});
    cout<<endl;


    dell.print(),cout<<endl<<endl;
    cout<<dell.countClasses()<<endl;//expect 5
    cout<<dell.getFirstClass()<<endl;//expect 20200101
    dell.addClassToBack("20200106");
    dell.printClasses(),cout<<endl;//expect 20200101 20200102 20200103 20200104 20200105 20200106
    cout<<dell.getClass(3)<<endl;//expect 20200104
    dell.deleteClass(2);
    dell.printClasses(),cout<<endl;//expect 20200101 20200102 20200104 20200105 20200106
    dell.insertClass(0,"20190101");
    dell.printClasses(),cout<<endl;//expect 20190101 20200101 20200102 20200104 20200105 20200106
    return 0;
}
