
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

typedef long long ll;

int ch[MAX_N];

int main() {
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll a[99999];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll as = 0;
        ll mas = n;
        for (int i = 1; i < n - 1; i += 2) {
            as += a[i];
            mas = min(mas, a[i]);
        }

        ll bs = 0;
        ll mbs = n;
        for (int i = 2; i < n - 1; i += 2) {
            bs += a[i];
            mbs = min(mbs, a[i]);
        }

        int c = n;
        ll ans[99999];
        if (as > bs or (as == bs and mas > mbs)) {
            vector<pair<int, int>> xy;
            for (int i = 1; i < n - 1; i += 2) {
                xy.push_back(make_pair(a[i], i));
            }
            sort(xy.begin(), xy.end());
            for (int j = 0; j < xy.size(); j++) {
                ans[xy[j].second] = c;
                c--;
            }
            xy.clear();

            for (int i = 0; i < n; i ++) {
                if (i % 2 == 1 and i != n - 1) continue;
                xy.push_back(make_pair(a[i], i));
            } 
            sort(xy.begin(), xy.end());
            for (int j = 0; j < xy.size(); j++) {
                ans[xy[j].second] = c;
                c--;
            }

        } else {

            vector<pair<int, int>> xy;
            for (int i = 2; i < n - 1; i += 2) {
                xy.push_back(make_pair(a[i], i));
            }
            sort(xy.begin(), xy.end());
            for (int j = 0; j < xy.size(); j++) {
                ans[xy[j].second] = c;
                c--;
            }
            xy.clear();

            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0 and i != 0) continue;
                xy.push_back(make_pair(a[i], i));
            } 
            sort(xy.begin(), xy.end());
            for (int j = 0; j < xy.size(); j++) {
                ans[xy[j].second] = c;
                c--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    } 

}