#include <iostream>
#include "fraction.h"

using namespace fraction;

template<typename T>
T max_element(const T *a, const unsigned int n) {
    T Max = a[0];
    for (int i = 1; i < n; i++)
        Max = max(Max, a[i]);
    return Max;
}

int main() {
    CFraction a[] = {"-3/9", "27/3", "-98/44", "-21/8", "1024/113", "-25/150", "255/3125", "91/8", "102/274",
                     "5023/1471"};
    cout << max_element(a, sizeof(a) / sizeof(CFraction));
    return 0;
}
