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

int main() {

    // vector<int> dp;
    int dp[1002] = {};

    for (int i = 0; i < 1002; ++i) {
        dp[i] = (99999);
    }

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;

    for (int i = 1; i < 1000; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (int j = 2; i * j <= 1000; ++j) {
            dp[i * j] = min(dp[i * j], dp[i] + j);
        }

    }

    for (int i = 1; i <= 1000; ++i) {
        cout << i << " " << dp[i] << endl;
    }
    // cout << dp[200] << endl;

    return 0;
}
