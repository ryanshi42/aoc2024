
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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

const int MAX_N = 2e2 + 10;
ll arr[MAX_N][MAX_N];

void solve(signed ___) {
    
    int n, mg, mh;
    cin >> n >> mg;

    // cout << n << " help " << mg << endl;

    unordered_set<ii, pair_hash> sg;

    for (int i = 0; i < mg; ++i) {
        int u, v; cin >> u >> v;

        // cerr << u << " help " << v << endl;
        sg.insert(make_pair(u, v));
    }

    unordered_set<ii, pair_hash> sh;

    cin >> mh;
    
    for (int i = 0; i < mh; ++i) {
        int u, v; cin >> u >> v;
        // cerr << u << " help " << v << endl;
        sh.insert(make_pair(u, v));
    }

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // cerr << i << " abc " << j << endl;
            ll a; cin >> a;
            arr[n - i][j] = a;
        }
    }

    ll ans = 0;

    for (auto& p : sg) {
        // cerr << "hasdfa" << endl;
        if (!sh.contains(p)) {
            cerr << p.first << "asdf" << p.second<< endl;
            ans += arr[p.first][p.second];
            sh.insert(p);
        }
    }
    for (auto& p : sh) {
        // cerr <<"asdhflkadsjh" << endl;
        if (!sg.contains(p)) {
            ans += arr[p.first][p.second];
            sg.insert(p);
        }
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