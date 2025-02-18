
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

const int MAX_N = 16;

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

string who[MAX_N];
string gen[MAX_N];

void solve(signed ___) {
    int n;
    cin >> n;

    int g = 1;
    int w = 1;
    unordered_map<string, int> gm;
    unordered_map<string, int> wm;

    unordered_map<int, unordered_set<int>> ge;
    unordered_map<int, unordered_set<int>> we;
    
    int lp = 0;

    unordered_map<int, int> dupes;


    for (int i = 0; i < n; i++) {
        cin >> gen[i] >> who[i];
        if (!gm[gen[i]]) {
            gm[gen[i]] = g++;
        }
        if (!wm[who[i]]) {
            wm[who[i]] = w++;
        }
        int x = gm[gen[i]];
        int y = wm[who[i]];

        // cout << "xy = " << x << " " << y << endl;

        ge[x].insert(x * 100 + y);
        we[y].insert(x * 100 + y);

        dupes[x * 100 + y]++;
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    


    for (int i = 0; i < n; i++) {
        int x = gm[gen[i]];
        int y = wm[who[i]];
        
        // BFS to find longest path starting from index i
        queue<pair<int, vector<int>>> q;
        // unordered_set<int> visited;
        q.push({x * 100 + y, vector<int>{x * 100 + y}});

        while (!q.empty()) {
            pair<int, vector<int>> elem = q.front();
            int u = elem.first;
            vector<int> path = elem.second;
            // cout << "path ";
            // for (int x : path) {
            //     cout << x << " ";
            // }
            // cout << u << endl;
            q.pop();
            int g = u / 100;
            int w = u % 100;

            int sp = 0;
            for (auto& asdf: path) {
                sp += dupes[asdf];
            }
            lp = max(lp, sp);

            for (int j : ge[g]) {
                // int x = j / 100;
                // int y = j % 100;
                if ((find(path.begin(), path.end(), j) == path.end()) and j != 0) {
                    vector<int> new_path = path;
                    // cout << j << endl;
                    new_path.push_back(j);
                    q.push({j, new_path});
                    // visited.insert(j);
                }
            }
            for (int j : we[w]) {
                // int x = j / 100;
                // int y = j % 100;
                if ((find(path.begin(), path.end(), j) == path.end()) and j != 0) {
                    vector<int> new_path = path;
                    // WHY DOES THIS NOT STUPID PASS BY REFERENCE
                    new_path.push_back(j);
                    q.push({j, new_path});
                    // visited.insert(j);
                }
            }
        }
    }

    cout << n - lp << endl;


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