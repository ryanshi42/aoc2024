
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// pdb = python debug

const int MAX_N = 1e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const ll INF = 1e18;

#define f first
#define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];

void solve(signed ___) {
    int n, m;
    cin >> n >> m;
    string prev = "";
    int pn = 0;
    bool found = false;

    // BUG: putting CRAP on the wrong lines.
    // BUG: using the wrong variable...

    int a = 0;
    int b = 0;
    F0R(i, n + 1) {
        string s;
        if (i != n) {
            cin >> s;
        } else {
            s = "";
            // NOT SUPPORTED
            for (int i = 0; i < m; i++) {
                s += '.';
            }
        }
        if (found) continue;
        int cnt = 0;
        F0R(j, m) {
            if (s[j] == '#') {
                cnt++;
            }
        }
        if (cnt < pn) {
            // cout << "asdjhflaksjhdfklajsfhdsalkh" << endl;
                int tmp = 0;

            F0R(j, m) {
        // cout << cnt << " " << pn << endl;
                if (prev[j] == '#') {
                    tmp++;
                    // cout << "tmp" << tmp << " " << pn << endl;
                    if (tmp * 2 - 1 == pn) {
                        a = i;
                        b = j + 1;
                        found = true;
                    }
                }
            }
        }
        prev = s;
        pn = cnt;
    }
    cout << a << " " << b << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve(69420);
    }
}