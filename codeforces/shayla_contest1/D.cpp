
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

const int MAX_N = 500 + 10;
ll arr[MAX_N][MAX_N];
ll pref[MAX_N][MAX_N];

void solve(signed ___) {
    ll n,m,k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        FOR(j, 1, m + 1) {
            cin >> arr[i][j];
        }
    }

    ll snow = 0;
    ll nosnow = 0;

    unordered_set<ll> choices;

    FOR(i, 1, n + 1) {
        string s;
        cin >> s;
        
        FOR(j, 1, m + 1) {
            if (s[j - 1] == '0') {
                nosnow += arr[i][j];
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] - 1;
            } else {
                snow += arr[i][j];
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + 1;
            }
            if (i >= k and j >= k) {
                choices.insert(abs(pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k]));
            }
        }
    }

    ll diff = abs(nosnow - snow);
 
    unordered_set<ll> s = choices;
    unordered_set<ll> ans;
    int M = *max_element(s.begin(), s.end());
     
    // Iterate over the range [1, M]
    for(int i = 1; i <= M; i++) 
    {
        int g = 0;
 
        // Check if i can be the GCD of
        // any subsequence
        for(int j = i; j < M + 1; j += i) 
        {
            if (s.find(j) != s.end()) {
                if (!g) g = j;
                
                g = gcd(g, j);
            }
        }
        if (g == i)
            ans.insert(i);
    }
 
    for (auto& l : ans) {
        if (l == 0) continue;
        // cout << "l = " << l << endl;
        diff %= l;
    }
 

    cout << (diff ? "NO" : "YES") << endl;


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