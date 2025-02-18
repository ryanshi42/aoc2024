
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
    string s;
    cin >> s;

    int n = s.size();

    ll ans = 0;

    unordered_map<int, vector<ll>> w;

    w[0] = {1, 0, 0};

    int l = 0;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '1') {
            l++;
        } else {
            l--;
        }

        if (w.find(l) == w.end()) {
            w[l] = {0, 0, 0};
        }
        w[l][0]++;
        if (w[l][0] > 1) {
            w[l][1] += 1 + w[l][2];
            ans = mod(ans + (w[l][1]) * (n - i));
        }
        w[l][2] = i + 1;

    }


    cout << mod(ans) << endl;

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