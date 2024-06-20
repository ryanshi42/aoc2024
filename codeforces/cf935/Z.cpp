
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

    int n, m;
    cin >> n >> m;

    vector<int> v;

    long long curr = 1;
    while (curr < 1e9) {
        v.push_back(curr);
        curr *= 3;
    }

    if (n == m) {
        cout << "Particle wins." << endl;
        return 0;
    } else if (n == 0) {
        cout << "Particle wins." << endl;
        return 0; 
    } else if (m == 0) {
        cout << "Triangle wins." << endl;
        return 0;
    }
    
    bool found = false;
    for (auto x : v) {
        if (x == m) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Triangle wins." << endl;
        return 0;
    }

    int l = 1;
    int r = 2;
    int y = 3;

    found = false;
    while (y <= m) {
        if (l * (m / y) < n && n < r * (m / y)) {
            found = true;
            break;
        }
        if (l * (m / y) == n || r * (m / y) == n) {
            break;
        }
        
        if (n < l * (m / y)) {
            l *= 3;
            l -= 2;
            r = l + 1;
        } else {
            r *= 3;
            r += 2;
            l = r - 1;
        }

        y *= 3;
        // cout << l << " / " << y << "\n";
        // cout << r << " / " << y << "\n";



    }

    if (found) {
        cout << "Triangle wins." << endl;
        return 0; 
    } else {
        cout << "Particle wins." << endl;
        return 0; 
    }
    
}