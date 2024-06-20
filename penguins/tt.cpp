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
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <array>

using namespace std;

int a[100010];

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> v = {-1, -1, -1};
    // n thingies of length 3
    vector<vector<int> > rivalries(n, v);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int y = 0;
        while (rivalries[a][y] != -1) y++;
        rivalries[a][y] = b;
        y = 0;
        while (rivalries[b][y] != -1) y++;
        rivalries[b][y] = a;
        // cout << "a: " << a << " b: " << b << " y: " << y << "\n";
        // cout << rivalries[a][0] << "\n";
        // cout << rivalries[b][0] << "\n";
    }

    int ans = 1;

    unordered_set<int> ga;
    ga.insert(0);
    a[0] = 1;

    for (int i = 1; i < n; ++i) {
        // check for each nbhr would adding this elem invalidate it
        // check also if it has more than 2 neighbours
        // cout << " i: " << i << "\n";
        int c1 = 0;
        for (int j = 0; j < 3; ++j) {
            int nn = rivalries[i][j];
            if (nn == -1) continue;

            int c2 = 0;

            // does it have more than 2 neighbours in ga already?
            // also, is the nbhr in ga and does it have another nbhr in ga?
            if (ga.find(rivalries[i][j]) != ga.end()) {
                // cout << rivalries[i][j] << "\n";
                for (int l = 0; l < 3; ++l) {
                    // does the nbhr nbhr have a neighbour in ga already?
                    if (ga.find(rivalries[nn][l]) != ga.end()) {
                        // cout << nn << " " << rivalries[nn][l] << "\n";
                        c2++;
                    }
                }

                if (c2 >= 1) c1 = 69;

                c1++;
            }

        }
        // cout << c1 << " " << "\n";
        if (c1 > 1) {
            ans = 2;
            a[i] = 2;
        } else {
            a[i] = 1;
            ga.insert(i);
        }
    }
    if (ans >= 3) assert(false);

    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}