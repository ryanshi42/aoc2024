
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

// const int MAX_N = 2e5 + 10;
// ll l[MAX_N];
// ll r[MAX_N];

void solve(signed ___) {
    ll ans = 0;

    ll n, d, k;
    cin >> n >> d >> k;

    vector<vector<int>> starts(n + 1, vector<int>{});
    vector<vector<int>> ends(n + 1, vector<int>{});
    unordered_set<int> w;

    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;

        starts[l].pb(i);
        ends[r].pb(i);

        if (1 <= l and l <= d) {
            w.insert(i);
        }
    }

    int mum = w.size();
    int mw = d;
    int bro = w.size();
    int bw = d;


    for (int day = d + 1; day <= n; ++day) {
        for (auto& end : ends[day - d]) {
            w.erase(end);
        }
        for (auto& start : starts[day]) {
            w.insert(start);
        }

        if (w.size() < mum) {
            mum = w.size();
            mw = day;
        }
        if (w.size() > bro) {
            bro = w.size();
            bw = day;
        }
    }

    // cerr << "ans" << endl;
    cout << bw - d + 1 << " " << mw - d + 1 << endl;

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