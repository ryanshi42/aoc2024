
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
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> iii;

const ll dx[4] = { -1, 1, 0, 0 };
const ll dy[4] = { 0, 0, -1, 1 };

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
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define ROF(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

const ll MAX_N = 2e5 + 10;
ll arr[MAX_N];
ll pref[MAX_N];

void solve(signed ___) {
    ll n, q;
    cin >> n >> q;

    pref[0] = 0;

    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
        pref[i] = arr[i] + pref[i - 1];
    }

    ll s = pref[n];

    //cerr << "s = " << s << endl;

    // 1 2 3 
    // .     2 3 1
    // .           3 1 2

    for (ll i = 0; i < q; ++i) {

        ll l, r;
        cin >> l >> r;
        l--; r--;

        ll la = l / n, lb = l % n;
        ll ra = r / n, rb = r % n;

        //cerr << la << " " << lb << " " << ra << " " << rb << endl;

        ll ans = 0;

        // middle
        ans += ((ll) max(0LL, ra - la - 1LL)) * s;

        if (la == ra) {
            ll x = ((la + lb) % n + n) % n;
            ll y = ((la + rb) % n + n) % n;

            //cerr << "x = " << x << "y = " << y << endl;

            if (x <= y) {
                ans += pref[y + 1] - pref[x];
            } else {
                ans += (s - pref[x]) + pref[y + 1];
            } 

            // cerr << "ans = ";

            cout << ans << endl;

            continue;
        }
        // left side
        ll x = ((la + lb) % n + n) % n;
        ll y = ((la + n - 1) % n + n) % n;

        //cerr << "x = " << x << "y = " << y << endl;

        if (x <= y) {
            ans += pref[y + 1] - pref[x];
        } else {
            ans += (s - pref[x]) + pref[y + 1];
        }

        //cerr << "a1 = " << ans << endl;

        // right side
        x = ((ra) % n + n) % n;
        y = ((ra + rb) % n + n) % n;
        if (x <= y) {
            ans += pref[y + 1] - pref[x];
        } else {
            ans += (s - pref[x]) + pref[y + 1];
        }


        // cerr << "ans = ";

        cout << ans << endl;

    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve(69420);
    }
}