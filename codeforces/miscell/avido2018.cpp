
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

const int MAX_N = 2e3 + 10;
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

const ll MOD = 998244353;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

void solve(signed ___) {
    ll ans = 0;

    ll a[2][MAX_N] = {{0}};

    ll n, m, k;
    cin >> n >> m >> k;

    // a[k][n] = how many ways to paint up to n bricks with k remaining colours
    F0R(i, n + 1) {
        a[0][i] = m;
    }
    FOR(i, 1, k + 1) {
        FOR(j, 1, n + 1) {
            a[1][j] = mod(a[1][j - 1] + (a[0][j - 1] * (m - 1)));
        }
        F0R(j, n + 1) {
            a[0][j] = a[1][j];
        }
    }

    cout << mod(a[0][n - 1]) << endl;


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve(69420);
    }
}