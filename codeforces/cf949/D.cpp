
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

// #include <array>

// auto temp = std::array<char, 100>{};

int ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    int n = 1e6 + 10;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }   
        }
    }

    vector<int> primes = {1};

    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) primes.push_back(p);
    }

    // cout << primes.size() << endl;

    int g[n + 10000]; 

    g[0] = 1;
    g[1] = 1;
    g[2] = 2;
    g[3] = 2;
    g[4] = 3;
    g[5] = 3;
    g[6] = 1;
    
    int place = 3;
    int i = 7;
    while (i < n) {
        g[i++] = primes[place];
        g[i++] = primes[place];
        g[i++] = 2;
        place++;

        g[i++] = primes[place];
        g[i++] = primes[place];
        int z = place - 2;
        while (i < n and z > 0) {
            g[i++] = primes[place - 1];
            g[i++] = primes[z--];
            g[i++] = primes[place];
            if (primes[z] == 2) {
                g[i++] = 1;
                break;
            }
            g[i++] = primes[z--];
        }
        place++;
    }

        // 3 mults, 2 ints
        // 1 1 2 2
        // 6 mults, 3 ints
        // 1 1 2 2 3 3 1 
        // 10 mults, 4 ints
        // each multiples by itself 4 times
        // 1 1 2 2 3 3 1 5 5 2
        // next
        // 15 mults, 5 ints
        // 1 1 2 2 3 3 1 5 5 2 7 7 5 3 7 1
        // 21 mults, 6 ints
        // 1 1 2 2 3 3 1 
        // 5 5 2 
        // 7 7 5 3 7 1 
        // 11 11 2 
        // 13 13 11 7 13 5 11 3 13 1
        // 17 17 2
        // 19 19 17 13 19 11 17 7 19 5 17 3 19 1
        // 23 23 2
        // 25 25 23 19 25 17 23 13 25 11 23 7 25 5 23 3 25 1
        // 29 29 2
        // 31 31 29 25 31 23 29 19 31 17 29 13 31 11 29 7 31 5 29 3 31 1
        // 37 37 2


    while (t--) {
        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            cout << g[i] << " ";
        }
        cout << '\n';

        // cout << ans << "\n";

    } 

}