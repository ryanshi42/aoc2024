
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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        // sort(a, a + 3);
        ll ans = 0;
        if ((a[0] + a[1] + a[2]) % 2 != 0) {
            cout << -1 << "\n";
            continue;
        }
        
        if (a[0] + a[1] == a[2]) {
            cout << a[2] << "\n";
            continue;
        } else if (a[0] + a[1] < a[2]) {
            cout << a[0] + a[1] << "\n";
            continue;
        } 
        ans += a[1] - a[0];
        a[1] -= ans;
        a[2] -= ans;
        while (a[0] + a[1] > a[2] and a[0] > 0 and a[1] > 0) {
            a[0]--;
            a[1]--;
            ans++;
        }
        
        if (a[0] + a[1] == a[2]) {
            ans += a[2];
        } else if (a[0] + a[1] < a[2]) {
            ans += a[0] + a[1];
        } 


        cout << ans << "\n";

    } 

}