
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


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

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
        ll n, m;
        cin >> n >> m;

        ll ans = n;

        if (m == 0) {
            cout << ans << '\n';
            continue;
        }
    
        ll x = n + m;
        ans = x;

        ll z = n - m;

        if (z < 0) z = 0;

        bool y = false;

        for (int i = 31; i >= 0; i--) {
            if ((((x & (1 << i))) and !((n & (1 << i)))) or (((n & (1 << i))) and !((z & (1 << i))))) {
                y = true;
                // cout << "true " << i << endl;
            }

            if (y) {
                ans |= (1 << i);
                // cout << ans << endl;
            }
        }

        // 1 2 3


        // 

        cout << ans << "\n";

    } 

}