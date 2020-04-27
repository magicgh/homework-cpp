//
// Created by magicgh on 4/27/2020.
//

#ifndef WEEK_9_MYSTACK_H
#define WEEK_9_MYSTACK_H

#endif //WEEK_9_MYSTACK_H

#include <iostream>
using namespace std;

template <typename T> class Stack{
    private:
        T* _stack;
        unsigned int _cap, _top;
    public:
        Stack(unsigned int cap){
            _cap= cap;
            _stack= new T[_cap];
            _top= -1;
        }

        ~Stack(){
            delete [] _stack;
            _stack= NULL;
        }

        inline bool empty() const {
            return _top==-1 ? 1:0;
        }

        inline int size() const {
            return _top+1;
        }

        inline unsigned capacity() const{
            return _cap;
        }

        T top() const{
            try {
                if (empty())throw "Stack is empty.";
                else return _stack[_top];
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        inline void clear(){
            _top= -1;
        }

        void push(const T &ele){
            try {
                if (_top == _cap-1) throw "Stack is full.";
                else _stack[++_top]= ele;
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        void pop(){
            try{
                if(empty()) throw "Stack is empty.";
                else _top--;
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }
};