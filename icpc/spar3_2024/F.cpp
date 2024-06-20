


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    string s;
    string t;
    std::cin >> s >> t;
    int x = s.length();
    int wrong = x - n;

    int diffs = 0;

    int ans = 0;
    for (int i = 0; i < x; i++) {
        if (s[i] != t[i]) {
            diffs += 1;
        }
    }
    int same = x - diffs;
    ans = min(same, n);
    int remain = n - ans;
    cout << min(same, n) + diffs - (n - min(same, n)) << endl;
}