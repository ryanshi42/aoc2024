
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

int a[MAX_N];
int b[MAX_N];

int d[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;


    while (t--) {

        unordered_set<int> seen;
        int n, m;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            seen.insert(b[i]);
        }

        cin >> m;

        unordered_map<int, int> g; 

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            d[i] = x;
            if (g.find(x) != g.end()) {
                g[x]++;
            } else {
                g[x] = 1;
            }
        }

        bool p = true;


        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                bool found = false;
                if (g.find(b[i]) != g.end()) {
                    g[b[i]]--;
                    // cout << "blah" << g[b[i]] << endl;
                    if (g[b[i]] >= 0) {
                        found = true;
                    } 
                } 
                if (!found) {
                    p = false;
                    break;
                }
            }
        }


        // Can't cover up
        if (seen.find(d[m - 1]) == seen.end()) {
            p = false;
        }

        if (p) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


        

    } 

}