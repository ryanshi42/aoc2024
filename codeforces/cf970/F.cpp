
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
ll arr[MAX_N];
 
ll pow(ll x, ll n, ll m) { // (x ^ n) % m
    if (n == 0) return 1;
    ll a = pow(x, n/2, m);
    a = mod(a * a, m);
    if (n%2 == 1) a = mod(a * x, m);
    return a;
}
 
ll modinv(ll x, ll m) {return pow(x, m-2, m);}
 
ll fact[MAX_N], invfact[MAX_N];
void computeFact(ll n) {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = mod(i * fact[i-1]);
        invfact[i] = modinv(fact[i], MOD);
    }
}
 
ll comb(ll n, ll r) {
    return mod(fact[n] * mod(invfact[r] * invfact[n-r]));
}
 

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// int calc(vector<ll>& v, ll mid) {
//     int ans = 0;
//     for (auto& n : v) {
//         ans += distance(v.begin(), upper_bound(v.begin(), v.end(), ((ll) mid / n)));
//     }
//     return ans;
// }

void solve(signed ___) {
    ll n;
    cin >> n;

    vector<ll> v;
    ll big = 0;
    for (int i = 0; i < n; ++i) {
        ll vv; cin >> vv; v.pb(vv);
        // big = mod(big + vv);
        big += vv;
    }

    sort(v.begin(), v.end());

    // ll l = 1, r = 1e18;
    // while (l < r) {
    //     ll mid = (r + l + 1) / 2;
    //     cout << "mid = " << mid << ", c = " << calc(v, mid) << ", " << calc(v, mid + 1) << endl;
    //     if (calc(v, mid) < calc(v, mid + 1)) {
    //         r = mid - 1;
    //     } else {
    //         l = mid;
    //     }
    // }


    // ll P = 0, sum = v[0];
    // for (int i = 1; i < n; ++i) {
    //     P = mod(P + mod(v[i] * sum));
    //     sum = mod(sum + v[i]);
    // }
    ll P = 0;
    for (int i = 0; i < n; ++i) {
        big = mod(big - mod(v[i] + MOD));
        if (big < 0) big += MOD;
        P = mod(P + mod(v[i] * big));
    }
    ll Q = mod(n * (n - 1) / 2);

    // cerr << "P = " << P << ", Q = " << Q << endl;
    
    cout << mod(mod(P) * modinv(Q, MOD)) << endl;

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