#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve() {
    int K, N;
    cin >> K >> N;
    vector<int> v;
    vector<int> copy;

    int output = 0;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        v.push_back(e);
        copy.push_back(e);
    }

    sort(copy.begin(), copy.end());

    int ptr = 0;
    for (auto p : v) {
        if (p == copy[ptr]) {
            ptr++;
        }
    }

    output = v.size() - ptr;

    cout << K << ' ' << output << '\n';
}

int main() {
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        solve();
    }
}