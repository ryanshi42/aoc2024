
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
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;

const int MAX_N = 1e5 + 10;
typedef long long ll;

int ch[MAX_N];

vector<int> getFinalPrice(int n, vector<int> price, int q, vector<vector<int>> queries) {

    int prefix = 0; 

    vector<int> ans(n, 0);

    // Deal with all the Type 1 queries first
    for (int i = q - 1; i >= 0; --i) {
        prefix = (queries[i][0] == 2 and queries[i][1] > prefix) ? queries[i][1] : prefix;

        if (queries[i][0] == 1 and ans[queries[i][1] - 1] == 0) {
            ans[queries[i][1] - 1] = max(queries[i][2], prefix);
        }
    }

    // Deal with all the Type 2 queries next
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            ans[i] = max(price[i], prefix);
        }
    }

    return ans;
}

int main() {
    // Initial 
    cin.tie(0); 

    // Input
    int n = 3;
    vector<int> price = {7, 5, 4};

    int q = 3;
    vector<vector<int>> queries = {{2, 6, 6}, {1, 2, 9}, {2, 8, 8}};

    vector<int> ans = getFinalPrice(n, price, q, queries);

    for (auto& a: ans) {
        cout << a << '\n';
    }

    return 0;

}