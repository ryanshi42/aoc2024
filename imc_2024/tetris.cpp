#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int table[256];
int n;
string x;

string chars = "IOTJSZL";

const int INF = 1e9;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> x;
    int res = 0;

    for (auto c : x) {
        table[c]++;

        int highest = 0;
        int lowest = INF;
        for (auto d : chars) {
            highest = max(highest, table[d]);
            lowest = min(lowest, table[d]);
        }
        int dif = highest - lowest;
        if (dif == 0) {
            res = max(res, 1);
        } else if (dif <= lowest) {
            if (lowest % dif == 0) {
                res = max(res, dif);
            } else {
                while (lowest % res + dif > res) {
                    res += 1;
                } 
            }
        } else {
            res = max(highest, res);
        }
    }

    cout << res * 7 << '\n';
}