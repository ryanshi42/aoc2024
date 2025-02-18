
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

void solve(signed ___, unordered_set<int> q) {
    int n;
    cin >> n;

    if (n == 1 or n == 0) {
        cout << "YES" << endl;
        return;
    }

    for (auto &c : q) {
        if (c <= n and n % c == 0 and q.find(n / c) != q.end()) {
            cout << "YES" << endl;
            return; 
        }
    }

    cout << "NO" << endl;
        return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    unordered_set<int> q = {1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
    int old = 0;

    while (q.size() != old) {
        old = q.size();
        // cout << old << endl;
        unordered_set<int> v;

        for (ll s : q) {
            for (ll t : q) {
                ll u = s * t;
                if (u > 1e6)
                    continue;

                v.insert(u);
            }
        }

        q = v;
    }
    q.insert(100000);
    vector<int> v  = {10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111 };
    for (auto& z : v) {
        q.insert(z);
    }

    while (t--) {
        solve(69420, q);
    }
}