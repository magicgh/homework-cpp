#include <iostream>
#include <typeinfo>
#include "window.h"
#include "alphabet.h"
int main() {
    Window i1(1,2,3);
    cout<< typeid(i1).name()<<" i1"<<endl;
    i1.setLength(2);
    cout<<"Length="; i1.printLength();
    i1.setWidth(3);
    cout<<"Width="; i1.printWidth();
    i1.setCost(4);
    cout<<"Cost="; i1.printCost();
    cout<<endl;

    G i3(1,2,3,4);
    cout<< typeid(i3).name()<<" i3"<<endl;
    i3.setA(-1);
    cout<<"A="; i3.printA();
    i3.setB(-2);
    cout<<"B="; i3.printB();
    i3.setD(-3);
    cout<<"D="; i3.printD();
    i3.setF(-4);
    cout<<"F="; i3.printF();
    return 0;
}
