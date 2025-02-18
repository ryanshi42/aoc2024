
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

const ll MAX_N = 2e5 + 10;
// ll dist1[MAX_N][2];
// ll dist2[MAX_N][2];

typedef tuple<ll, ll, ll> pll;

void solve(signed ___) {
    ll ans = -1;

    ll n, m, h;
    cin >> n >> m >> h;

    vector<int> horses(n + 1);

    vector<vector<pair<ll, ll>>> edges(n + 1);
    
    F0R(i, h) {
        int o; cin >> o; horses[o] = 1;
        // cerr << "horse = " << o << endl;
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    // Create a vector to store distances and initialize all distances as INF
    // THIS WAS THE PROBLEM!!!!
    // for (int i = 0; i < n + 1; i++) {
    //     dist1[i][0] = INF;
    //     dist1[i][1] = INF;
    //     dist2[i][0] = INF;
    //     dist2[i][1] = INF;
    // }
    vector<vector<long long>> dist1(n + 1,vector<long long>(2,1e18));

    // need to write seen array, or use a set
    // need to change the bool to 1
    vector<vector<bool>> seen1(n + 1,vector<bool>(2,false));
    vector<vector<bool>> seen2(n + 1,vector<bool>(2,false));

    vector<vector<long long>> dist2(n + 1,vector<long long>(2,1e18));
    // vector<ll> dist1h(n + 1 , INF);
    // vector<ll> dist2(n + 1, INF);
    // vector<ll> dist2h(n + 1, INF);

    // Insert source into priority queue and initialize its distance as 0
    pq.push(make_tuple(0, 1, 0));
    dist1[1][0] = 0;

    // Process the priority queue
    while (!pq.empty()) {
        // Get the vertex with the minimum distance
            // cerr << "helpme= " << get<1>(pq.top()) << endl;

        // getting rid of this & helps...
        auto [d, u, h] = pq.top();
        ll hh = h;
        pq.pop();

        if (seen1[u][h]) continue;
        seen1[u][h] = true;

        // cerr << "asdfa" << u << endl;

        if (horses[u]) {
            hh = 1;
            // cerr << "asdjhflaskdjhf" << endl;
        }

        // Iterate through all adjacent vertices of the current vertex
        for (auto& neighbor : edges[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;
            
            ll old = dist1[u][h];

            // If a shorter path to v is found
            ll dd = weight / (hh ? 2 : 1);
            if (dist1[v][hh] > old + dd) {
                // Update distance and push new distance to the priority queue
            // cerr << "neighbour = " << v << endl;
                dist1[v][hh] = old + dd;
                pq.push({dist1[v][hh], v, hh});
                continue;
            // cerr << "neighbour = " << get<1>(pq.top()) << endl;
            }
        }
    }

     // Insert source into priority queue and initialize its distance as 0
    pq.push(make_tuple(0, n, 0));
    dist2[n][0] = 0;

    // Process the priority queue
    while (!pq.empty()) {
        // Get the vertex with the minimum distance
        auto [d, u, h] = pq.top();
        ll hh = h;
        pq.pop();

        if (seen2[u][h]) continue;
        seen2[u][h] = true;

        if (horses[u]) {
            hh = 1;
        }

        // Iterate through all adjacent vertices of the current vertex
        for (auto& neighbor : edges[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;
            
            ll old = dist2[u][h];

            // If a shorter path to v is found
            ll dd = weight / (hh ? 2 : 1);
            if (dist2[v][hh] > old + dd) {
                // Update distance and push new distance to the priority queue
            // cerr << "neighbour = " << v << endl;
                dist2[v][hh] = old + dd;
                pq.push({dist2[v][hh], v, hh});
                continue;
            // cerr << "neighbour = " << get<1>(pq.top()) << endl;
            }
        }
    }

    ans = INF;

    for (int i = 1; i <= n; ++i) {
        // if (dist1[i][0] != INF and dist2[i][0] != INF) {
            ans = min(ans, max(min(dist1[i][0], dist1[i][1]), min(dist2[i][0], dist2[i][1])));
            // cerr << "abcd = " << dist1[i][0] << " " << dist1[i][1] << " " << dist2[i][0] << " " << dist2[i][1] << endl;
        // }
    }

    // cerr << "ans ";
    cout << (ans == INF ? -1 : ans) << endl;

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