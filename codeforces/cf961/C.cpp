
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

ll ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        ll ans = 0;
        ll n;
        cin >> n;

        bool can = true;
        ll prev = 1;

        for (int i = 0; i < n; i++) {
            cin >> ch[i];
            if (i > 0) {

                // if (ch[i] < ch[i - 1]) {
                    if (ch[i] == 1 && ch[i - 1] != 1) {
                        can = false;
                        continue;
                    } else if (ch[i] == 1 and ch[i - 1] == 1) {
                        prev = 1;
                        continue;
                    }
                    long double x = log(ch[i - 1]) / log(ch[i]);
                    int curr = 2;
                    for (int j = 1; j < prev; ++j) {
                        curr *= curr;
                    }
                    if (curr < x) {
                        prev = 1;
                        continue;
                    }
                    
                    long double curr = 2;
                    int a = 1;
                    while (curr < x) {
                        a++;
                        curr *= curr;
                        cout << "curr = " << curr << endl;
                    }
                    int y = a;
                        
                    cout << " x=" << x << " a=" << a << " y=" << y << endl;
            
                    prev = pow(2, y);
                    ans += y;
                // }
            }
        }
        if (!can) {
            ans = -1;
        }
        cout << "ans=" << ans << endl;


    } 

}