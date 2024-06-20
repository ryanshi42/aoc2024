
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

    int n, k;
    cin >> n >> k;

    int l = 1;
    int r = k;

    string s;
    cin >> s;

    for (auto& c : s) {
        if (c == '+') {
            l = min(l + 1, k);
            r = min(r + 1, k);
        } else if (c == '-') {
            l = max(l - 1, 1);
            r = max(r - 1, 1);
        }
    }

    cout << r - l + 1 << endl; 

}