
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


    ll n, k;
    cin >> n >> k;

    ll ans = n;

    for (int i = 0; i < k; ++i) {

        ll bsf = -1;

        int a, b, c, d, e;
        
        cin >> a >> b >> c >> d >> e;
        char perms[5] = {'a', 'b', 'c', 'd', 'e'};
        while (next_permutation(perms, perms + 5)) {
            ll num = ans;
            for (auto& x: perms) {
                if (x == 'a') {
                    num += a;
                } else if (x == 'b') {
                    num -= b;
                    if (num < 0) {
                        break;
                    }
                } else if (x == 'c') {
                    num = std::floor(num / c);
                } else if (x == 'd') {
                    num *= d;
                } else if (x == 'e') {
                    if (num <= e) {
                        num = -1;
                        break;
                    } 
                    num += e;
                }
            }
            
            // cout << perms[0] << " " << perms[1] << " " << perms[2] << " " << perms[3] << " " << perms[4] << endl;
            // cout << num << endl;
                // cout << ans << endl;
            bsf = max(bsf, num);
        }
        if (bsf == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans = bsf;
        // cout << ans << endl;

    }
    cout << ans << endl;

}