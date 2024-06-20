
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

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const ll INF = 1e18;

// #define f first
// #define s second
#define all(x) x.begin(), x.end() 
#define pb push_back
#define FOR(a, b) for (int i = (a); i < (b); i++)
#define ROF(a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0R(b) FOR (0, b)
#define endl '\n'

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];

vector<int> videoStreaming(int c, int f, int s, vector<int> input) {
    int n = input.size();

    vector<int> ans(n);

    // This keeps track of the first time that the fast line finishes
    priority_queue<int> q;

    F0R(c) {
        q.push(0);
    }

    F0R(n) {
        int p = -q.top();
        int t = input[i];

        // Slow line only
        if (p >= (t + s - 1) / s) {
            ans[i] = (t + s - 1) / s;
            continue;
        }

        q.pop();

        // Use slow line then fast line
        t -= p * s;
        int x = (t + f - 1) / f;
        q.push(- p - x);
        ans[i] = p + x;
    }

    return ans;

}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    vector<int> input = {10, 12, 4, 8, 7, 17, 2, 4, 6, 8, 14};
    int c = 2, f = 5, s = 2;

    vector<int> ans = videoStreaming(c, f, s, input);
    
    F0R(ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;

}