
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

typedef long long ll;

char ch[MAX_N];

int main() {
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {

        int n; 
        cin >> n;

        int dir[4] = {0, 0, 0, 0}; 
        int r[4] = {0, 0, 0, 0}; 
        int h[4] = {0, 0, 0, 0}; 

        for (int i = 0; i < n; i++) {
            cin >> ch[i];
            // cout << ch[i] << '\n';
            if (ch[i] == 'N') {
                dir[0]++;
            } else if (ch[i] == 'E') {
                dir[1]++;
            } else if (ch[i] == 'W') {
                dir[2]++;
            } else {
                dir[3]++;
            }
        }
        if (n % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }

        if ((dir[0] + dir[3]) % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        } else if ((dir[1] + dir[2]) % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }
        
        // cout << "DIR ";

        // Give half to r 
        r[0] = dir[0] / 2;
        r[3] = dir[3] / 2;
        h[0] = r[0];
        h[3] = r[3];
        if (dir[0] % 2 == 1) {
            h[0]++;
            h[3]++;
        }

        r[1] = dir[1] / 2;
        r[2] = dir[2] / 2;
        h[1] = r[1];
        h[2] = r[2];
        if (dir[1] % 2 == 1) {
            if (r[0] == 0 and r[1] == 0 and r[2] == 0 and r[3] == 0) {
                r[1]++;
                r[2]++;
            } else {
                h[1]++;
                h[2]++;
            }
        }

        // cout << dir[0] << " " << dir[1] << " " << dir[2] << " " << dir[3] << endl;
        // cout << r[0] << " " << r[1] << " " << r[2] << " " << r[3] << endl;
        // cout << h[0] << " " << h[1] << " " << h[2] << " " << h[3] << endl;

        if (r[0] == 0 and r[1] == 0 and r[2] == 0 and r[3] == 0) {
            cout << "NO" << '\n';
            continue;
        }
        if (h[0] == 0 and h[1] == 0 and h[2] == 0 and h[3] == 0) {
            cout << "NO" << '\n';
            continue;
        }


        // string ans;
        for (int i = 0; i < n; i++) {
            if (ch[i] == 'N') {
                if (r[0]) {
                    r[0]--;
                    // ans += 'R';
                    cout << 'R';
                } else if (h[0]) {
                    h[0]--;
                    // ans += 'H';
                    cout << 'H';
                } else {
                    cout << 'wtf?';

                    assert(false);
                }
            } else if (ch[i] == 'E') {
                if (r[1]) {
                    r[1]--;
                    // ans += 'R';
                    cout << 'R';
                } else if (h[1]) {
                    h[1]--;
                    // ans += 'H';
                    cout << 'H';
                } else {
                    cout << 'wtf?';
                    assert(false);
                }
            } else if (ch[i] == 'W') {
                if (r[2]) {
                    r[2]--;
                    // ans += 'R';
                    cout << 'R';
                } else if (h[2]) {
                    h[2]--;
                    // ans += 'H';
                    cout << 'H';
                } else {
                    cout << 'wtf?';
                    assert(false);
                }
            } else {
                if (r[3]) {
                    r[3]--;
                    // ans += 'R';
                    cout << 'R';
                } else if (h[3]) {
                    h[3]--;
                    // ans += 'H';
                    cout << 'H';
                } else {
                    cout << 'wtf?';
                    assert(false);
                }
            } 
        }

        // cout << "ans ";
        // cout << ans << "\n";
        cout << '\n';

    } 

}