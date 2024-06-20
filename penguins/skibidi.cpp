
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
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <deque>


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef long long ll;

int ch[MAX_N];

int main() {
    // Initial 
    cin.tie(0); 

    ll ans = 0;

    for (int i = 1; i < 607; ++i) {
        for (int j = 1; j < 607; ++j) {
            ll num = 7;
            while (num <= 607) {
                if (num == 607) {
                    ans += 1;
                    break;
                }
                num = i * num + j;
            }
        }
    }

    cout << ans << endl;


}