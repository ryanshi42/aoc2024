
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

    // NECESSARY OBSERVATION: You can't ever end with a number greater than x if x was in your path then you would have found it
    // Basically because l always points to something smaller than x... by property of the algorithm

    // Problem F, just sort, keep a pointer and then iterate, picking more mushrooms as you go in descending order which maximises the minimum
    // Problem G, the idea is to keep an original list + PQ, with SUFFIX MAXES denoting a student has yet to pass, then use priority queue impl to simulate
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int a[n + 5];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l = 1;
        int r = n + 1;

        vector<char> b;

        while (r - l != 1) {
            int mid = (l + r) / 2;
            cout << l << " " << mid << " " << r << endl;
            if (a[mid - 1] <= m) {
                b.push_back('l');
                l = mid;
            } else {
                b.push_back('r');
                r = mid;
            }
        }

        cout << a[l - 1] << endl;
        cout << l - 1 << endl;

        for (auto c: b) {
            cout << c;
        }

    } 
    // Note: ceil(x) = (x + y - 1) / y

}