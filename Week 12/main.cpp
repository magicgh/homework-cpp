#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 10005;
int p[MAXN], ans;

int main() {
    string s;
    bool Flag = 0;
    cin >> s;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s.find_first_of(s[i]) == s.find_last_of(s[i])) {
            cout << "First Character: " << s[i] << endl;
            Flag = 1;
            break;
        }
    }
    if (!Flag)cout << "First Character: None" << endl;
    s.insert(0, "`");
    for (unsigned int i = 0; i < s.length(); i += 2)s.insert(i + 1, "|");
    for (int i = 1, mid = 0, r = 0; i < s.length(); i++) {
        if (i <= r)p[i] = min(p[(mid << 1) - i], r - i + 1);
        while (s[i + p[i]] == s[i - p[i]])p[i]++;
        if (i + p[i] > r)mid = i, r = i + p[i] - 1;
        ans = max(ans, p[i]);

    }
    cout << "Maximum Length: " << ans - 1 << endl;
    return 0;
}
