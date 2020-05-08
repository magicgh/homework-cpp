#include <iostream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

template<typename T>
class LinkedList {
private:
    list<T> List;
public:
    inline void push_front(const T &x) {
        List.push_front(x);
    }

    inline void emplace_front(const T &x) {
        List.emplace_front(x);
    }

    inline void reverse_iterate() {
        for_each(List.rbegin(), List.rend(), [](const T &x) { cout << x << ' '; });
        cout << endl;
    }

    inline void clear() {
        List.clear();
    }

    inline void remove(const T &x) {
        List.remove(x);
    }

    inline bool find_in_list(T x) {
        auto it = find(List.begin(), List.end(), x);
        return it != List.end();
    }

    inline void sort() {
        List.sort();
    }

    inline void distinct() {
        map<T, bool> Hash;
        for (auto it = List.begin(); it != List.end();) {
            if (Hash.count(*it))it = List.erase(it);
            else Hash[*it] = 1, ++it;
        }
    }
};

int main() {
    LinkedList<int> linked_List;
    for (int i = 1; i <= 10; i++)linked_List.emplace_front(i);
    for (int i = 10; i >= 1; i--)linked_List.emplace_front(i);
    linked_List.reverse_iterate();
    linked_List.remove(10);
    linked_List.reverse_iterate();
    cout << linked_List.find_in_list(11) << endl;
    cout << linked_List.find_in_list(4) << endl;
    linked_List.sort();
    linked_List.reverse_iterate();
    linked_List.distinct();
    linked_List.reverse_iterate();
    linked_List.clear();
    linked_List.reverse_iterate();
    return 0;
}
