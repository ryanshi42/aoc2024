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

// long long madd(long long a, long long b) { return ((a + b) % m + m) % m; }

// long long msub(long long a, long long b) { return ((a - b) % m + m) % m; }

using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

bool myComparison(vector<int>& a, vector<int>&b)
{
       return a[1]<b[1];
}
const int MAX_N = 1e5 + 10;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<vector<int> > intervals;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> x(2);
        x[0] = a;
        x[1] = b;
        intervals.push_back(x);
    }
    sort(intervals.begin(), intervals.end());
    sort(intervals.begin(), intervals.end(), myComparison);

    int i = 0;
    vector<int> v(k);
    std::fill(v.begin(), v.end(), -1);

    int ans = 0;

    multiset<int> endtime;

    // The issue with multiple classrooms is for example
    // 1 2
    // 3 4 
    // 2 5 
    // Check your algo returns 2 but the multiset correct algorithm is 3
    for (auto x: intervals) {
        // int a = x[0];
        // int b = x[1];

        // if (a > v[i]) {
        //     v[i] = b;
        //     i = (i + 1) % k;
        //     ans += 1;
        // }

        auto it = endtime.lower_bound(-x[0]);

        if (it == endtime.end()) {
            if (endtime.size() < k) {
                endtime.insert(-x[1]-1);
                ans++;
            }

            continue;
        }
        
        // There is an element which is no less. Well, remove it 
        // This is a pointer to a specific element
        endtime.erase(it);
        endtime.insert(-x[1]-1);
        ans++;

    }

    // for (auto c : intervals) {
    //     cout << c[0] << " " << c[1] << "\n";
    // }
    cout << ans << "\n";

}