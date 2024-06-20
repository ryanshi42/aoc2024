
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
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

    // int n = 1e5;
    // bool prime[n + 1];
    // memset(prime, true, sizeof(prime));

    // for (int p = 2; p * p <= n; p++) {
    //     // If prime[p] is not changed, then it is a prime
    //     if (prime[p] == true) {
    //         // Update all multiples of p greater than or
    //         // equal to the square of it numbers which are
    //         // multiple of p and are less than p^2 are
    //         // already been marked.
    //         for (int i = p * p; i <= n; i += p) {
    //             prime[i] = false;
    //         }   
    //     }
    // }

    vector<int> twos;

    int i = 1;
    while (i < 1e9) {
        twos.push_back(i);
        i *= 2;
    }

    ll t;
    cin >> t;
    

    while (t--) {
        int l, r;
        cin >> l >> r;

        ll ans = 0;
        
        for (int i = twos.size(); i >= 0; i--) {
            if (twos[i] >= l && twos[i] <= r) {
                ans = i;
                break;
            }
        }

        cout << ans << "\n";

    } 

}