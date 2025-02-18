
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
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// pdb = python debug

const int MAX_N = 1e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const ll INF = 1e18;

#define f first
#define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(i, b) FOR (i, 0, b)
#define endl '\n'

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

    ll t;
    cin >> t;

    while (t--) {
        int n, m, k;
        // cout << "hi";
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s += 'L';
        s = 'L' + s;
        n += 2;

        vector<ll> dp(n + 13, INF);
        // dp[0] = 0;
        // F0R(i, min(m, n + 1)) {
        //     if (s[i] != 'C')
        //         dp[i] = 0;
        // }
        dp[0] = 0;


        FOR(i, 0, n) {
            if (s[i] == 'C') dp[i] = INF;
            if (s[i] == 'W') {
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
                // cout << dp[i + 1] << ' ' << dp[i] << endl;
            } else if (s[i] == 'L') {
                F0R(j, m) {
                    dp[i + j + 1] = min(dp[i + j + 1], dp[i]);
                }

            }
        }



        // F0R(i, n) {
        //     if (s[i] == 'C') {
        //         croc = true;
        //     } else if (s[i] == 'L') {
        //         if (i - llog <= m) {
        //             acc = true;
        //         } else if (!croc && (swim + i - llog - 1) <= k) {
        //             swim += i - llog - 1;
        //         } else {
        //             unr = true;
        //             break;
        //         }
        //         llog = i;
        //         croc = false;
        //     }
        // }

        // int i = n;

        // if (unr) {
        //     acc = false;
        // } else if (i - llog <= m) {
        //     acc = true;
        // } else if (!croc && (swim + i - llog - 1) <= k) {
        //     acc = true;
        // } else {
        //     acc = false;
        // }
        // F0R(i, n) {
        //     cout << dp[i] << " ";
        // } 
        // cout << endl;
        int acc = (dp[n] <= k);

        if (acc) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    } 

}