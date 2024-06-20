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

    // track rivalries and who
    set<pair<int, int> > heap;

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

    // cout << "begun\n";

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (auto& z: rivalries[i]) {
            if (z > -1) cnt++;
        }

        heap.insert(make_pair(-cnt, i));
    }

    int ans = 0;
    while (heap.size() > 0) {
        ans++;
        // cout << "ans is " << ans << "\n";
        unordered_set<int> seen;
        // for (auto& h : heap) {
        //     cout << " " << h.first << " " << h.second << "\n";
        // }
        while (heap.size() > 0) {
            // cout << heap.size() << "\n";
            auto t = *heap.begin();
            heap.erase(heap.begin());

            // cout << "t is " << t.second << "\n";

            // If seen ignore it and continue
            if (seen.find(t.second) != seen.end()) {
                continue;
            }

            // Allocate this
            a[t.second] = ans;

            int jc = -1;
            int cc = -1;

            for (int j = 0; j < 3; ++j) {
                // cout << "r[i] = " << rivalries[t.second][j] << "\n";
                int nbhr = rivalries[t.second][j];
                if (nbhr == -1 || seen.find(nbhr) != seen.end() || a[nbhr] > 0) continue;
                int cn = 0;

                // Pick the best nbhr
                for (int blah = 2; blah >= 0; --blah) {
                    if (rivalries[nbhr][blah] != -1) cn++;
                }
                if (cn > jc) {
                    jc = cn;
                    cc = nbhr;
                }
            }
            
            // cout << "cc is " << cc << "\n";

            // No best rivalry found
            if (cc == -1) {
                continue;
            }

            // Else pick this and the best rivalry = cc, e.g. t.second = 0
            int cnt = 0;
            for (auto &nbhr : rivalries[cc]) {
                if (nbhr == -1) continue;
                cnt++;
                for (int j = 0; j < 3; ++j) {
                    if (rivalries[nbhr][j] == t.second || rivalries[nbhr][j] == cc) {
                        rivalries[nbhr][j] = -1;
                    }
                }
                if (nbhr != cc && nbhr != t.second) seen.insert(nbhr);
            }
            
            for (auto &nbhr : rivalries[t.second]) {
                if (nbhr == -1) continue;
                for (int j = 0; j < 3; ++j) {
                    if (rivalries[nbhr][j] == t.second || rivalries[nbhr][j] == cc) {
                        rivalries[nbhr][j] = -1;
                    }
                }
                if (nbhr != cc && nbhr != t.second) seen.insert(nbhr);
            }

            assert(a[cc] == 0);
            a[cc] = ans;
            // cout << "Found " << cnt << "\n";

            assert(heap.find(make_pair(-cnt, cc)) != heap.end());
            // if (heap.find(make_pair(-cnt,cc)) == heap.end()) continue;
            heap.erase(heap.find(make_pair(-cnt, cc)));
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) continue;
            int cnt = 0;
            for (auto& z: rivalries[i]) {
                if (z > -1) cnt++;
            }

            heap.insert(make_pair(-cnt, i));
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