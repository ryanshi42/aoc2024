
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

const int MAX_N = 2e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const ll INF = 1e18;

#define f first
#define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        ll ans = 0;
        ll n, m;
        cin >> n >> m;
        unordered_map<ll, int> cnt;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            cnt[a]++;
        }
        for (auto& b : cnt) {
            ll a = b.first;
            for (int j = 0; j <= cnt[a]; j++) {
                if (j * a > m) break;
                if (a > 1) ans = max(ans, j * a + ((a - 1) * min((m - j * a) / (a - 1), (ll) cnt[a - 1])));
                ans = max(ans, j * a + ((a + 1) * min((m - j * a) / (a + 1), (ll) cnt[a + 1])));
            }
        }

        cout << ans << endl;



    } 

}