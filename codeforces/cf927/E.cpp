

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;
        string s;
        cin >> s;
        long long curr = 0;
        long long ans = 0;
        for (char c : s) {
            curr *= 10;
            curr += c - '0';
            ans += curr;
        }
        cout << ans << endl;
    }
    return 0;
}