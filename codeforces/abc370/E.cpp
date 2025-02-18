#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(h), col(w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    auto erase = [&](int x, int y) {
        assert(x >= 0 && x < h && y >= 0 && y < w);
        assert(row[x].count(y) && col[y].count(x));
        row[x].erase(y);
        col[y].erase(x);
    };

    for(int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if(row[r].count(c)) {
            erase(r, c);
            continue;
        }
        auto r_it = row[r].lower_bound(c);
        if(r_it != row[r].end()) {
            assert(*r_it != c);
            erase(r, *r_it);
        }
        // Reload since previous pointer might have been invalidated.
        r_it = row[r].lower_bound(c);
        if(r_it != row[r].begin()) {
            assert(*prev(r_it) != c);
            erase(r, *prev(r_it));
        }
        auto c_it = col[c].lower_bound(r);
        if(c_it != col[c].end()) {
            assert(*c_it != r);
            erase(*c_it, c);
        }
        // Reload since previous pointer might have been invalidated.
        c_it = col[c].lower_bound(r);
        if(c_it != col[c].begin()) {
            assert(*prev(c_it) != r);
            erase(*prev(c_it), c);
        }
    }

    int ans = 0;
    for(auto x : row) {
        ans += x.size();
    }
    cout << ans << "\n";
    return 0;
}