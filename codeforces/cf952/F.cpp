
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

int a[MAX_N];
int b[MAX_N];

void solve(signed ___) {
    ll h, n;
    cin >> h >> n;

    priority_queue<tuple<ll, ll, ll>> pq;
    F0R(i, n) {
        cin >> a[i];
    }
    F0R(i, n) {
        cin >> b[i];
    }
    F0R(i, n) {
        pq.push(make_tuple(0, a[i], b[i]));
    }

    ll ans = 0;

    while (h > 0) {
        ll time, curr, gain;
        // What does tie do in CPP?
        tie(time, curr, gain) = pq.top();
        pq.pop();
        // cout << time << " " << curr << endl;
        time = -time;
        ans = max(time + 1, ans);
        h -= curr;
        time += gain;
        pq.push(make_tuple(-time, curr, gain));
    }

    cout  << ans << endl;
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