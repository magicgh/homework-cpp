#include <iostream>
#include "date.h"
int main() {
    //test 1
    Date a("2012-11-11");
    cout<<a++<<' '<<a<<' '<<++a<<' '<<a<<endl<<endl;

    //test 2
    Date b;
    for(int i=1;i<=365;i++){
        b+=1;
        cout<<b<<endl;
    }
    cout<<endl;

    //test 3
    cout<<"1900.2.29"<<endl;//Invalid Date
    Date(1900,2,29);
    return 0;
}
