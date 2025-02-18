#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

typedef pair<ll, ll> pll;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 1 3 5 
    // 
    ll n, m, k;
    cin >> n >> m >> k;

    vector<pll> votes(n + 1);
    vector<ll> ans(n + 1);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x; votes[i] = make_pair(x, i); s += x;
    }
    sort(votes.begin(), votes.end());

    ll 

    for (int i = 0; i < m; ++i) {
        
    }

    ll rem = k - s;
    for (auto& [v, i] : votes) {
        
    }


    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}