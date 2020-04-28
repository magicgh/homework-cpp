#include <iostream>
#include <string>
#include "mystack.h"
int main() {
    Stack<int> s1(10);
    Stack<string> s2(10);
    for(int i=1; i<=10; i++){
        s1.push(i);
        s2.push("str"+to_string(i));
        cout<<s1.top()<<' '<<s2.top()<<endl;
    }
    cout<<"Get the elements in s1\n";
    while(!s1.empty()){
        cout<<s1.top()<<' ';
        s1.pop();
    }
    cout<<"\nGet the elements in s2\n";
    for(int i=s2.size(); i>0; i--){
        cout<<s2.top()<<' ';
        s2.pop();
    }

    return 0;
}
