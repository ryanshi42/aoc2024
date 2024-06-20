
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
        int n, m;
        cin >> n >> m;

        int a[n + 5];
        int b[n + 5];

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b[i] = x;
        }


        long long ans = 21474836470;
        long long pfx[m + 5];

        pfx[m] = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            pfx[i] = pfx[i + 1] + b[i];
        }
        for (int i = 0; i < m; i++) {
            ans = min(ans, a[i] + pfx[i + 1]);
        }
        for (int i = m; i < n; i++) {
            ans += min(a[i], b[i]);
        }

        cout << ans << "\n";

    } 

}