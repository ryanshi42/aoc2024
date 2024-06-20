
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


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef long long ll;

int ch[MAX_N];

int main() {
    cin.tie(0);


    ll n;
    cin >> n;

    ll ans = 0;

    // do heap and then remove if not ascending order
    priority_queue<int> pq;

    for (int i = 0; i < n; ++i) cin >> ch[i];

    // NEED TO CHECK THE DOCUMENTATION OF PQ
    
    for (int i = 0; i < n; ++i) {
        if (ch[i] == 0) {
            while (!pq.empty()) {
                pq.pop();
                ans += 1;
            }
            continue;
        }

        // Non-zero
        if (pq.empty()) {
            pq.push(ch[i]);
        } else {
            while (!pq.empty() && pq.top() > ch[i]) {
                pq.pop();
                ans += 1;
            }
            if ((!pq.empty() && pq.top() != ch[i]) || pq.empty()) {
                pq.push(ch[i]);
            }
        }
    }

    cout << ans + pq.size() << '\n';

}