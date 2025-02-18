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

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

struct chash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const ll INF = 1e18;

#define f first
#define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

void solve(signed ___) {
    ll N, W; cin >> N >> W;
    vector<ll> memo(W + 1, 0);

    vector<ll> val(N + 1, 0);
    vector<ll> wt(N + 1, 0);
    vector<ll> ww(N + 1, 1);

    for (ll i = 0; i < N; ++i) {
        ll n, w; cin >> w >> n;
        val[i] = n; wt[i] = w;
        val[i]--;
        // cerr << val[i] << endl;
    }

    // Fill memo[] using the recursive formula
    // This is W * N as well but different from knapsack
    for (ll i = 0; i <= W; i++) {
        for (ll j = 0; j < N; j++) {
            if (wt[j] <= i) {
                if (memo[i - wt[j]] + val[j] > memo[i]) {
                    memo[i] = max(memo[i], memo[i - wt[j]] + val[j]);
                    ww[j] += 2;
                    // cout << ww[j] << endl;
                    // cout << val[j] << endl;
                    val[j] -= ww[j];
                }
            }
        }
        // cout << memo[i] << endl;
    }

    ll ans = 0;

    for (int i = 0; i <= W; ++i) {
        ans = max(ans, memo[i]);
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve(69420);
    }
}