
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

const int MAX_N = 2e5 + 10;
int arr[MAX_N];

void solve(signed ___) {
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> edges;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    vector<bool> visited(n + 10, false);

    visited[0] = true;

    string s; cin >> s;

    int nq = 0;
    for (auto& c : s) {
        if (c == '?') nq++;
    }

    queue<int> q; 
    q.push(0);

    int lz = 0, lo = 0, lu = 0;

    while (q.size()) {
        int curr = q.front();
        q.pop();

        visited[curr] = true;

        bool is_leaf = true;
        for (auto& nbhr : edges[curr]) {
            if (!visited[nbhr]) {
                is_leaf = false;
                q.push(nbhr);
            }
        }

        if (is_leaf) {
            if (s[curr] == '0') lz++;
            if (s[curr] == '1') lo++;
            if (s[curr] == '?') lu++;
        }
    }

    int ans = 0;

    if (s[0] == '?') {
        ans += max(lz, lo);
        if (lz == lo) {
            int left = nq - lu - 1;

            lu++;

            // can force a move first
            if (left % 2 == 1) {
                ans += max(0, (lu) / 2);
            } else {
                ans += max(0, (lu - 1) / 2);
            }
        } else {
            ans += max(0, (lu) / 2);
        }

    } else {
        if (s[0] == '0') {
            ans += lo;
        } else {
            ans += lz;
        }

        ans += max(0, (lu + 1) / 2);
    }

    // cerr << "ans = ";
    cout << ans << endl;

    //           5
    // 1 -- 2 -- 3 -- 4 
    //           6

    // observation: root must start and end at the diff node
    // 
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