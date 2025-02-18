
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

const int MAX_N = 2e5 + 10;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

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

char ch[MAX_N];
int bh[MAX_N];

void solve(signed ___) {
    int n;
    cin >> n;
    vector<int> how(n + 2, -1);
    how[0] = 0;
    string s; 
    cin >> s;

    for (int i = 1; i <= n; i++) {
        ch[i] = s[i - 1];
        if (ch[i] == 'a' or ch[i] == 'e') {
            bh[i] = 1;
        } else {
            bh[i] = 0;
        }
        // cout << bh[i] << endl;
    }
        
    for (int i = 1; i <= n; i++) {
        if (i >= 2) {
            if (bh[i] and !bh[i - 1] and how[i - 2] >= 0) {
                how[i] = i - 2;
            }
        }
        if (i >= 3) {
            if (!bh[i] and bh[i - 1] and !bh[i - 2] and how[i - 3] >= 0) {
                how[i] = i - 3;
            }
        }
        // cout << i << " " << how[i] << endl;
    }

    vector<int> chain; 
    int j = n;
    while (j > 0) {
        int next = how[j];
        chain.push_back(next);
        j = next;
    }
    chain.pop_back();

    reverse(chain.begin(), chain.end());
    // for (int i = 0; i < chain.size(); i++) {
    //     cout << chain[i] << " ";
    // }

    chain.pb(n + 5);

    string ans = "";
    int curr = 0;

    for (int i = 1; i <= n; i++) {
        cout << ch[i];
        if (i == chain[curr]) {
            cout << ".";
            curr++;
        }
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve(69420);
    }
}