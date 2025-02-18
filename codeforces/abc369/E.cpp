
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

const int MAX_N = 4e2 + 5;
ll dist[MAX_N][MAX_N];

void solve(signed ___) {
    ll n, m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll>> bridges;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        bridges.emplace_back(u, v, t);
        dist[u][v] = min(dist[u][v], t);
        dist[v][u] = min(dist[v][u], t);
    }

    ll V = n;
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    ll q; cin >> q;

    for (int i = 0; i < q; ++i) {
        ll k; cin >> k;
        vector<ll> bb; 
        for (int j = 0; j < k; ++j) {
            ll b; cin >> b;
            // b--;
            bb.pb(b);
        }

        ll ans = INF;

        do
        {
            // p stores possible bidirectionality
            vector<vector<ll>> p;
            p.pb({bb[0]});
            p.pb({-bb[0]});
            for (int lmao = 1; lmao < k; ++lmao) {
                vector<vector<ll>> np = p;
                p.clear();
                for (auto& v : np) {
                    vector<ll> tmp = v;
                    tmp.pb(bb[lmao]);
                    p.pb(tmp);
                    tmp = v;
                    tmp.pb(-bb[lmao]);
                    p.pb(tmp);
                }
            }

            // check all permutations
            for (auto& v : p) {
                int old = 0;
                ll tt = 0;
                for (auto& val : v) {
                    if (val < 0) {
                        val *= -1;
                        auto [u, v, t] = bridges[--val];
                        tt += dist[old][v] + t;
                        old = u;
                    } else {
                        auto [u, v, t] = bridges[--val];
                        tt += dist[old][u] + t;
                        old = v;
                    }
                }
                tt += dist[old][n - 1];
                ans = min(ans, tt);
            }
        }
        while (std::next_permutation(bb.begin(), bb.end()));

        cout << ans << endl;
    }

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