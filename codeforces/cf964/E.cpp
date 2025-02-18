
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

const int MAX_N = 2e5 + 10;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

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
    int l, r;
    cin >> l >> r;

    vector<pair<int, int>> w;

    for (int i = 0; i <= 14; ++i) {
        w.pb(make_pair(pow(3, i), i + 1));
    }

    ll ans = 0;
    ll lmao = l;
    while (lmao > 0) {
        lmao = floor(lmao / 3);
        ans += 2;
    }

    l++;

    // 1, 1
    // 3, 2
    // 9, 3

    // cout <<"absdf" << ans << endl;

    for (int i = 1; i < w.size(); ++i) {
        auto x = w[i - 1];
        auto y = w[i];

        // if (l <= x.first and x.first <= r) {
        //     ans += x.second;
        // }

        // cout << x.first << " " << x.second << " " << y.first << " " << y.second << " " <<  (min(y.first - 1, r) - max(x.first, l) + 1) * x.second << endl;
        ans += (max(0, min(y.first - 1, r) - max(x.first, l) + 1)) * x.second;
    }


    cout << ans << endl;
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