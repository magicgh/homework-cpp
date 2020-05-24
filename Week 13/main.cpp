#include <iostream>
using namespace std;
template<typename T>
struct Node{
    T val;
    Node *next;
    Node(T val):val(val),next(nullptr){};
    Node():val(0),next(nullptr){};
};
template<typename T>
class List{
    private:
        Node<T> *head;
        int len;
    public:
        List():head(nullptr),len(0){};
        ~List(){
            for(Node<T> *ptr=head;ptr!= nullptr;){
                Node<T> *tmp=ptr;
                ptr=ptr->next;
                delete tmp;
            }
        }
        void insert(int pos,T value){
            try{
                len++;
                if(pos<1||pos>len)throw "out of range";
                else{
                    Node<T>*ptr=head;
                    for(int i=1;i<pos-1;i++,ptr=ptr->next);
                    Node<T>*tmp=new Node(value);
                    if(pos==1)head=tmp,ptr=head;
                    if(ptr->next!= nullptr)tmp->next=ptr->next;
                    if(pos>1)ptr->next=tmp;
                }
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        void remove(int pos){
            try{
                if(pos<1||pos>len)throw "out of range";
                else{
                    Node<T>*ptr=head;
                    for(int i=1;i<pos-1;i++,ptr=ptr->next);
                    if(pos==1){
                        head=ptr->next;
                        cout<<ptr->val<<endl;
                        delete ptr;
                    }
                    else{
                        Node<T>*tmp=ptr->next;
                        if(pos==len)ptr->next= nullptr;
                        else if(pos>1)ptr->next=ptr->next->next;
                        delete tmp;
                    }
                }
                len--;
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        T find(int pos){
            try{
                if(pos<1||pos>len)throw "out of range";
                else{
                    Node<T>*ptr=head;
                    for(int i=1;i<pos;i++,ptr=ptr->next);
                    return ptr->val;
                }
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        void modify(int pos,T value){
            try{
                if(pos<1||pos>len)throw "out of range";
                else{
                    Node<T>*ptr=head;
                    for(int i=1;i<pos;i++,ptr=ptr->next);
                    ptr->val=value;
                }
            }
            catch (const char *msg) {
                cerr << msg << endl;
                exit(-1);
            }
        }

        void print(){
            for(Node<T> *ptr=head; ptr!= nullptr;ptr=ptr->next)
                cout<<ptr->val<<' ';
        }
};
int main() {
    List<int>a;
    for(int i=1;i<=10;i++)a.insert(i,i*2);
    a.print();//2 4 6 8 10 12 14 16 18 20
    cout<<endl;
    for(int i=1;i<=5;i++)a.remove(i);
    a.print();//4 8 12 16 20
    cout<<endl;
    cout<<a.find(3)<<endl;//12
    a.modify(5,21);
    a.print();//4 8 12 16 20
    cout<<endl;//4 8 12 16 21
    return 0;
}
