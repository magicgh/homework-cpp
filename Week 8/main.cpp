#include <iostream>
#include "school.h"
#include "bird.h"
using namespace std;
int main() {
    // Task 1
    Person("Alan", "Male", "North Kehua Rd.", 20, "13333333333", 20000).show();
    cout<<endl;
    Teacher("Bell", "Male", "Chuanda Rd.", "Prof.", 21, "14444444444", 30000).show();
    cout<<endl;
    Cadre("Cinderella", "Female", "South Remin Rd.", "Director", 22, "15555555555", 40000).show();
    cout<<endl;
    TeacherCadre derrick("Derrick", "Male", "Yulin Rd.", "Assistant", "Chairman", 23, "16666666666", 5000);
    derrick.Person::show();
    cout<<endl;
    derrick.Teacher::show();
    cout<<endl;
    derrick.Cadre::show();
    cout<<endl;
    // Task 2
    Bird temp;
    temp.area();
    temp.run();
    IShape* temp1 = &temp;
    temp1->area();
    IAction &temp2= temp;
    temp2.run();
    return 0;
}