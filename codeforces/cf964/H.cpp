
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

    int l = 1, r = 1000;
    for (int i = 0; i < 7; ++i) {
        
        int a = l + (r - l) / 3;
        int b = l + 2 * (r - l) / 3;
        if (b == a) {
            b++;
        }
        cout << "? " << a << " " << b << endl;
        cout.flush();

        ll qa;
        cin >> qa;
        if (qa == -1) {
            cout << "WA" << endl;
            return;
        }

        if ((b - 1 == a) and qa == a * (b + 1)) {
            cout << "! " << b << endl;
            return;
        } else if (i == 6 and b - 1 == a and qa == (a + 1) * (b + 1)) {
            cout << "! " << b - 1 << endl;
            return;
        } else if (i == 6 and b - 1 == a and qa == (a) * (b)) {
            cout << "! " << b + 1 << endl;
            return;
        } else if (qa == a * (b + 1)) {
            // cout << "! " << b << endl;
            l = a;
            r = b + 1;
        } else if (qa == a * b) {
            l = b;
        } else if (qa == (a + 1) * (b + 1)) {
            r = a;
        }
    }

    
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