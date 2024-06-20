
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
#include <unordered_set>
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
        int n;
        cin >> n;
        string r; 
        cin >> r;
        unordered_set<char> s;
        for (int i = 0; i < n; i++) {
            s.insert(r[i]);
        }

        vector<char> v;
        for (auto& c: s) {
            v.push_back(c);
        }
        sort(v.begin(), v.end());

        unordered_map<char, int> m;
        for (int i = 0; i < v.size(); i++) {
            m[v[i]] = i;
        }

        int l = v.size();
        string x;
        for (auto& c : r) {
            x += v[l - 1 - m[c]];
        }

        cout << x << "\n";

    } 

}