
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

int ch[MAX_N];

int main() {
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > vs(n + 7);
    vector<unordered_map<char, pair<int, int> > > edges(n + 7);

    for (int i = 0; i < n; i++) {
        vector<int> b(2);
        cin >> b[0] >> b[1];
        vs[i] = b;
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (vs[a][0] == vs[b][0] && vs[a][1] < vs[b][1]) {
            edges[a]['E'] = make_pair(b, c);
            edges[b]['W'] = make_pair(a, c);
        }
        if (vs[a][0] == vs[b][0] && vs[a][1] > vs[b][1]) {
            edges[a]['W'] = make_pair(b, c);
            edges[b]['E'] = make_pair(a, c);
        }
        if (vs[a][0] > vs[b][0] && vs[a][1] == vs[b][1]) {
            edges[a]['S'] = make_pair(b, c);
            edges[b]['N'] = make_pair(a, c);
        }
        if (vs[a][0] < vs[b][0] && vs[a][1] == vs[b][1]) {
            edges[a]['N'] = make_pair(b, c);
            edges[b]['S'] = make_pair(a, c);
        }
    }

    int start;
    cin >> start;
    char dir;
    cin >> dir;

    string superb = "NESWNESW";

    while (true) {
        int val = edges[start][dir].second; 
        int next = edges[start][dir].first;
        char oppdir = 'N';
        if (dir == 'E') oppdir = 'W';
        if (dir == 'N') oppdir = 'S';
        if (dir == 'W') oppdir = 'E';

        // Guaranteed to be over 0
        edges[start][dir] = make_pair(next, val - 1);
        edges[next][oppdir] = make_pair(start, val - 1);
        
        start = next;
        // Decide next direction to take
        char lm = '.';
        bool found = false;
        for (auto c: superb) {
            if (c == oppdir) {
                if (!found) found = true;
                else continue;
            }

            if (edges[start][c].second > 0) {
                dir = c;
                break;
            }
        }


    }
    cout << vs[start][0] << " " << vs[start][1] << '\n';

}