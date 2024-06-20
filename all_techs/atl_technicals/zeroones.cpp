#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;
int main() { 

    // Parade in Hackerland

    string s;
    int ans = 0;
    cin >> s;

    int waiting = 0;
    int curr_zeroes = 0;

    for (auto c: s) {
        if (c == '0') {
            curr_zeroes++;
            waiting = max(waiting - 1, 0);
        } else {
            if (!curr_zeroes) 
                continue;
            ans = max(ans, curr_zeroes + waiting);
            waiting++;
        }
    }
    cout << ans << endl;
    return 0;

}


