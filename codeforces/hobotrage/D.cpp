
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

int bh[MAX_N];
int ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t, u;
    cin >> t >> u;
    ll i = 0;

    ll ans = 0;

    while (t--) { 
        cin >> bh[i] >> ch[i++];
    } 

    priority_queue<int> pq;
    ll past = -1;
    while (u--) {
        ll x;
        cin >> x;

        x--;
        ll mess = 0;
        ll storage = 0;
        for (int i = x; i > past; --i) {
            // cout << "begin loop " << i << endl;
            mess += bh[i];
            if (mess >= storage) {
                mess -= storage;
                storage = 0;
            } else {
                mess = 0;
                storage -= mess;
            }
            // cout << "start m = " << mess << "i = " << i << "ans = " << ans << endl;
            pq.push(ch[i]);
            while (mess > 0 && !pq.empty()) {
                int c = pq.top();
                pq.pop();
                // cout << "m = " << mess << "i = " << i << "c = " << c << endl;
                ans += 1;
                if (c >= mess) {
                    storage = c - mess;
                    mess = 0;
                    break;
                } else {
                    mess -= c;
                }
                // cout << "m = " << mess << "i = " << i << "c = " << c << endl;
            }
                
            if (mess > 0) {
                ans = -1;
                cout << ans << endl;
                exit(0);
            }
        }
        past = x;
    }

    cout << ans << endl;

}