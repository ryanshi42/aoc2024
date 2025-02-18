
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
int flag[MAX_N];

int solve(signed ___, int n, vector<int> arr, int m, vector<pair<int, int>> pairs) {
    for (auto& [x, y] : pairs) {
        flag[x] += 1;
        flag[y + 1] -= 1;
    }

    int curr = 0;
    vector<int> ugly;

    unordered_map<int, int> cnt;

    for (int i = 0; i < n; ++i) {
        curr += flag[i];
        
        if (curr == 0) {
            ugly.pb(arr[i]);
        } else {
            cnt[arr[i]] += curr;
        }
    }

    sort(ugly.begin(), ugly.end());

    vector<pair<int, int>> items;
    for (auto& [k, v] : cnt) {
        items.emplace_back(k, v);
    }

    sort(items.begin(), items.end());

    int j = 0, ans = 0, less_than = 0;
    for (auto& ugly_num : ugly)
    {
        while (j < items.size() and items[j].first <= ugly_num) {
            less_than += items[j].second;
            j++;
        }
        ans += less_than;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr;
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.pb(x);
        }

        int m; cin >> m;

        for (int i = 0; i < m; ++i) {
            int x; int y; cin >> x >> y;
            pairs.emplace_back(x, y);
        }
        cout << solve(6942, n, arr, m, pairs) << endl;
    }
}