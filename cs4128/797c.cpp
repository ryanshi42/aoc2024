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

    string s;
    cin >> s;
    int n = s.size();

    // Keep track of the largest number seen so far
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ch[i] = s[i];
        } else {
            ch[i] = min(ch[i + 1], (int) s[i]);
        }
    }
    
    string ans;
    string temp;

    // Keep track of the temp. We might add stuff to temp e.g. d, whilst not seeing c, 
    // But then right afterwards we might want to pop d from temp instead of adding more to temp.
    // ADCE -> aced vs adce
    // This is the difference between them.
    for (int i = 0; i < n; i++) {
        while (!temp.empty() && temp.back() <= ch[i]) {
            ans += temp.back();
            temp.pop_back();
        }
        if (s[i] == ch[i]) {
            ans += s[i];
        } else {
            temp += s[i];
        }
    }

    for (int j = temp.size() - 1; j >= 0; j--) {
        ans += temp[j];
    }


    cout << ans << endl;

}