//
// Created by magicgh on 4/10/2020.
//

#ifndef WEEK_7_ALPHABET_H
#define WEEK_7_ALPHABET_H

#endif //WEEK_7_ALPHABET_H

#include <iostream>
using namespace std
;
class A{
    private:
        int a,b;
    public:
        A(int a, int b):a(a),b(b){};
        inline void setA(int x){a=x;}
        inline void setB(int x){b=x;}
        inline void printA(){cout<<a<<endl;}
        inline void printB(){cout<<b<<endl;}
};

class C: virtual public A{
    private:
        int d;
    public:
        C(int a,int b,int d):A(a,b),d(d){};
        inline void setD(int x){d=x;};
        inline void printD(){cout<<d<<endl;}
};

class E: virtual public A{
    private:
        int f;
    public:
        E(int a,int b,int f):A(a,b),f(f){};
        inline void setF(int x){f=x;};
        inline void printF(){cout<<f<<endl;}
};

class G: public C, public E{
    public:
        G(int a,int b,int d,int f):C(a,b,d),E(a,b,f),A(a,b){};
};