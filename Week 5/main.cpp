#include <iostream>
#include "employee.h"
using namespace std;
int main() {
    printf("Class Person\n");
    Person("Alan","Male",20).print();
    printf("\nClass Employee\n");
    Employee("Cindy","Female",21,"EE20192020",20000).print();
    return 0;
}


