
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

const int MAX_N = 3e5 + 10;

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
ll gcs(int curr, int parent, unordered_map<int, vector<int> >& m, unordered_map<int, ll>& mp);

ll gm(int curr, int parent, unordered_map<int, vector<int> >& m, unordered_map<int, ll>& mp, bool b)
{
    cout << "in gm with " << curr << " and " << parent << endl;
    if (mp.find(curr) != mp.end())
        return mp[curr];

    // if (curr < parent) {
    //     return 0;
    // }

    ll ans = 0;

    //  take current node value and call for all grand
    //  children
    ll incl = ch[curr] + gcs(curr, parent, m, mp);
    //  don't take current node value and call for all
    //  children
    ll excl = 0;
    for (auto& child : m[curr]) {
        if (child == parent) {
            continue;
        }
        excl += gm(child, curr, m, mp, false);
    }

    if (incl >= excl) {
        ans = incl;
        // mp[curr] = incl;
        if (b)
            ch[curr] = 0;
    } else {
        ans = excl;
        // mp[curr] = excl;
    }

    return ans;
}


ll gcs(int curr, int parent, unordered_map<int, vector<int> >& m, unordered_map<int, ll>& mp) {
    ll ans = 0;

    for (auto& child : m[curr]) {
        if (child == parent) {
            continue;
        }
        for (auto& gc : m[child]) {
            if (curr == gc) {
                continue;
            }
            ans += gm(gc, child, m, mp, false);
        }
        
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    unordered_map<int, vector<int> > m;

    ll t;
    cin >> t;

    while (t--) {
        ll ans = 0;
        ll total = 0;
        int n;
        cin >> n;
        F0R(i, n) {
            cin >> ch[i + 1];
            total += ch[i + 1];
        }
        F0R(i, n - 1) {
            int x, y;
            cin >> x >> y;
            m[x].pb(y);
            m[y].pb(x);
        }

        ll s = 1;
        while (s > 0) {
            cout << "test" << endl;
            unordered_map<int, ll> mp;
            s = gm(1, -1, m, mp, true);
            cout << s << endl;
            ans += total;
            total -= s;
        }

        cout << ans << "\n";

    } 

}