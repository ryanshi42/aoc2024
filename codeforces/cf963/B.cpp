
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

ll ch[MAX_N];

void solve(signed ___) {
    int n;
    cin >> n;

    ll best_odd = 0;
    priority_queue<ll> evens;

    F0R(i, n) {
        ll x;
        cin >> x;
        
        if (x % 2 == 0) { 
            evens.push(-x);
        }
        else { 
            best_odd = max(best_odd, x);
        }
    
    }

    ll ans = 0;

    if (best_odd == 0 or evens.size() == 0) {
        cout << ans << endl;
        return;
    }

    // There are some odds and evens
    while (evens.size() > 0) {
        ll y = -evens.top();
        ans++;
        cout << "BO = " << best_odd << endl;
        if (y < best_odd) {
            evens.pop();
            best_odd += y;
        } else {
            best_odd += y;
        }

    }


    cout << "ans =" << ans << endl;
    // at least 1 odd means we have to turn the entire array into odds



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