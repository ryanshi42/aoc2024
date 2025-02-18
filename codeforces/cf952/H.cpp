
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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<int> v;
    v.pb(x);
    v.pb(y);
    v.pb(z);
    sort(v.begin(), v.end());

    x = v[0];
    y = v[1];
    z = v[2];

    ll ans = 0;

    for (ll a = 1; a <= k; ++a) {
        if (k % a != 0) {
            continue;
        }
        for (ll b = 1; a * b <= k; ++b) {
            if (k % b != 0) {
                continue;
            }

            ll c = k / (a * b);
            v.clear();
            v.pb(a);
            v.pb(b);
            v.pb(c);
            sort(v.begin(), v.end());

            ll aa = v[0];
            ll bb = v[1];
            ll cc = v[2];

            ans = max(ans, (x + 1 - aa) * (y + 1 - bb) * (z + 1 - cc));
        }
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