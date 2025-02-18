
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

int aa[MAX_N];
int bb[MAX_N];

pair<ll, ll> bs(ll x, ll n) {

    ll ans = 0;
    ll ops = 0;

    for (int i = 0; i < n; i++) {
        ll y = ceil((a[i] - x) / b[i]);
        ans += y * a[i] - b[i] * ((y * (y - 1)) / 2);
        ops += y;
    }

    return make_pair(ans, ops);
    
}

void solve(signed ___) {
    ll n, k;
    cin >> n >> k;

    F0R(i, n) {
        cin >> aa[i];
    }

    F0R(i, n) {
        cin >> bb[i];
    }
    
    ll ans = 0;

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (bs(mid, n).second <= k) {
            ans = max(ans, bs(mid, n).first);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return return ans;
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