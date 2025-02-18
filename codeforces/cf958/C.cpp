
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

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> w;
        for (int i = 0; i < 64; ++i) {

            ll z = (1ULL << i);
            if (z & n) {
                if (n == z) {
                    break;
                }
                w.pb(n & ~z);
                // cout << "debug" << i << " " << z << " " << n << endl;
            }
        }

        reverse(w.begin(), w.end());
        w.pb(n);
        cout << w.size() << "\n";

        for (ll x : w) {
            cout << x << " ";
        }
        cout << "\n";

    } 

}