
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
    ll n, x;
    cin >> n >> x;

    ll ans = 0;

    // for (int a = 1; a <= x; a++) {
    //     for (int b = 1; b <= min(a, x - a); b++) {
    //         for (int c = 1; c <= min(a, min(b, x - a - b)); c++) {
    //             if (a * b + b * c + a * c <= n) {
    //                 // 221
    //                 // 322
    //                 if (a != b and b != c and a != c) {
    //                     ans += 1;
    //                 } else if (a == b and b == c) {
    //                     ans += 1;
    //                 } else if (a == b) {
    //                     ans += 3;
    //                 } else if (b == c) {
    //                     ans += 3;
    //                 }
    //             }
    //         }
    //     }
    // }

    for (ll a = 1; a <= x; a++) {
        for (ll b = 1; b <= x; b++) {

        // cout << a << " " << b << endl;
        while (a + b + 1 > x) {
            break;
        }
        // b--;

        if (a * b + (a + b) > n) {
            break;
        }


        ll l = 1;
        ll r = x - a - b;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            ll c = mid;
            if (a * b + b * c + a * c <= n and a + b + c <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans += b * l;
        // for (ll c = 1; c <= x; c++) {
        //     if () {
        //         ans += c;
        //     } else {
        //         break;
        //     }
        // }
        // cout << a * b + (a + b) * (x - b - a) << endl;
        // if (a * b + (a + b) * (x - b - a) <= n) {
        //     ans += x - a - b;
        // }

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