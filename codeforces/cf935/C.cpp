
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
        ll a;
        cin >> a;
        double n = a;
        string s;
        cin >> s;

        unordered_map<ll, ll> mp; 
        mp[0] = 0;
        mp[1] = 0;
        for (auto c: s) {
            if (c == '0') {
                mp[0]++;
            } else {
                mp[1]++;
            }
        }

        unordered_map<ll, ll> seen; 
        seen[0] = 0;
        seen[1] = 0;

        double poss = -99;
        double i = 0;
        for (i = 0; i < a; i++) {
            if (seen[0] >= seen[1] && mp[1] >= mp[0]) {
                // cout << abs(n / 2 - poss); 
                if (abs(n / 2 - i) < abs(n / 2 - poss)) {
                    poss = i;
                }
            }
            char c = s[i];
            if (c == '0') {
                seen[0]++;
                mp[0]--;
            } else {
                seen[1]++;
                mp[1]--;
            }
        }

        if (seen[0] >= seen[1] && mp[1] >= mp[0]) {
            // cout << abs(n / 2 - poss); 
            if (abs(n / 2 - i) < abs(n / 2 - poss)) {
                poss = i;
            }
        }


        cout << poss << "\n";

    } 

}