
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

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> gcds = {};
        vector<ll> repl = {};
        for (int i = 0; i < n - 1; ++i) {
            gcds.push_back(gcd(a[i], a[i + 1]));
        }

        for (int i = 0; i < n - 2; ++i) {
            repl.push_back(gcd(a[i], a[i + 2]));
        }
        repl.push_back(0);

        bool y = true;
        ll past = -1;
        vector<int> left = {};
        vector<int> right = {};
        for (auto& g: gcds) {

            // Is it increasing before and including this index
            if (g < past) {
                y = false;
            }
            past = g;
            left.push_back(y);
            right.push_back(true);
        }

        past = 1e9 + 10;
        y = true;
        for (int i = n - 2; i >= 0; --i) {
            // cout << past << " " << gcds[i] << endl;
            if (gcds[i] > past) {
                y = false;
            } 
            past = gcds[i];
            right[i] = y;
        }

        // cout << "<<<" << endl;
        // for (int i = 0; i < n - 1; ++i) {
        //     cout << left[i] << " ";
        //     cout << right[i] << " ";
        //     cout << gcds[i] << " ";
        //     cout << repl[i] << endl;
        // }

        bool p = false;
        for (int i = 0; i < n - 2; ++i) {
            if (i == 0) {
                if (right[i + 2] and gcds[i + 2] >= repl[i]) p = true;
            } else if (i == n - 3) {
                if (left[i - 1] and gcds[i - 1] <= repl[i]) p = true; 
            } else if (left[i - 1] and right[i + 2] and gcds[i + 2] >= repl[i] and repl[i] >= gcds[i - 1]) {
                p = true;
            }

            if (p) break;
        }

        if (right[1] or left[n - 3]) p = true;

        if (p) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    } 

}