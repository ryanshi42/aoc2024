
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
#include <chrono>
#include <cstdint>

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

struct pair_hash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

const ll INF = 1e18;

#define f first
#define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'


const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

const int MAX_N = 2e5 + 10;
ll arr[MAX_N];
ll pref[MAX_N];
ll ad[MAX_N];
ll bd[MAX_N];
ll cd[MAX_N];

void bfs(int s, int round, unordered_map<int, vector<int>> &edges) {

    queue<ii> q = {};
    q.push({s, 0});
    unordered_set<int> seen;

    while (!q.empty()) {
        auto [curr, dist] = q.front();
        q.pop();

        if (seen.contains(curr)) continue;
        seen.insert(curr);

        if (round == 0) {
            ad[curr] = dist;
        } else if (round == 1) {
            bd[curr] = dist;
        } else {
            cd[curr] = dist;
        }

        for (auto& nbhr: edges[curr]) {
            q.push({nbhr, 1 + dist});
        }
    }
}

void solve(signed ___) {

    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    F0R(i, m) {
        cin >> arr[i];
    }
    sort(arr, arr + m);

    unordered_map<int, vector<int>> edges = {};
    F0R(i, n) {
        edges[i] = vector<int>();
    }

    F0R(i, m) {
        int x, y; cin >> x >> y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    bfs(a, 0, edges);
    bfs(b, 1, edges);
    bfs(c, 2, edges);

    pref[0] = 0;
    for (int i = 1; i <= m; ++i) {
        pref[i] = arr[i - 1] + pref[i - 1];
    }

    ll ans = INF;

    for (int i = 1; i <= n; ++i) {
        ll d = (cd[i] + ad[i] + bd[i] > m) ? INF : pref[cd[i] + ad[i] + bd[i]] + pref[bd[i]];
        // cerr << i << " makes " << d << ", " << ad[i] << " " << bd[i] << " " << cd[i] << endl;

        ans = min(ans, d);
    }

    // cerr << "ans = ";
    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve(69420);
    }
}