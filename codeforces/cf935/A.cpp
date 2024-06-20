
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

int ch[MAX_N];

int main() {
    cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (b % 3 == 1 && (c == 1 || c == 0)) {
            cout << "-1\n";
        } else if (b % 3 == 2 && (c == 0)) {
            cout << "-1\n";
        }
        else {
            int x = b % 3;
            if (x != 0) {
                x = 3 - x;
            }
            int y = c - x;
            if (y % 3 != 0) {
                y += 3;
            }
            cout << ((long long) a + (b + x) / 3 + y / 3) << "\n";
        }

    }

}