
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
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 2e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];

// wrong idea

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<pair<int,int>> v;

        map<int, int> maxim;

        map<pair<int, int>, int> f; 


        for (int i = 0; i < k; i++) {
            int r, c;
            cin >> r >> c;
            v.push_back(make_pair(r, c));
            if (maxim.find(c) == maxim.end()) {
                maxim[c] = r;
            } else {
                maxim[c] = max(maxim[c], r);
                f[make_pair(r, c)] = i;
            }
        }

        int curr = n;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (maxim.find(i) != maxim.end()) {
                if ((n - maxim[i]) < curr) {
                    curr = n - maxim[i];
                    ch[f[make_pair(maxim[i], i)]] = 1;
                }
            }
            ans += curr;
        }

        cout << ans << "\n";

        for (int i = 0; i < k; i++) {
            cout << ch[i] << " ";
        }
        cout << "\n";

    } 

}