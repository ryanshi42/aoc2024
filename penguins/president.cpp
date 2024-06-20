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
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <unordered_set>


using namespace std;

bool skelly[1010][1010];

// Hash function  
struct hashFunction 
{ 
    size_t operator()(const pair<int ,  
                        int> &x) const
    { 
        return x.first ^ x.second; 
    } 
}; 

int main() {

    int m, n, k;

    cin >> n >> m >> k;

    // cout << "IMPOSSIBLE" << endl;
    // return 0;

    if (k > n * m - 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    } else if (n == 1) {
        if (k == m - 1) {
            cout << "POSSIBLE" << '\n';
            for (int i = 1; i < m; ++i) {
                cout << "1 " << i << " 1 " << i + 1 << '\n';
            }
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
        return 0;
    } else if (m == 1) {
        if (k == n - 1) {
            cout << "POSSIBLE" << '\n';
            for (int i = 1; i < n; ++i) {
                cout << i << " 1 " << i + 1 << " 1" << '\n';
            }
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
        return 0;
    }

    int x = n;
    bool hoz = false;
    int y = m;

    if (x % 2 == 1) {
        x -= 1; 
        hoz = true;
    } else if (y % 2 == 1) {
        y -= 1;
    }

    int base = x + y - 1;

    if (k < base) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    } else {
        cout << "POSSIBLE" << '\n'; 
    }

    // unordered_set<pair<int, int>, hashFunction> skelly;

    
    if (hoz) {
        // cout << "HOZ" << '\n';
        // Can finally start printing
        // go one by one

        int h = (n + 1) / 2;
        if (n % 2 == 0) {
            base--;
        }

        // cout << n << " " << m << " " << h << '\n';

        for (int i = 1; i < h; ++i) {
            skelly[i][1] = true;
            // skelly.insert(make_pair(i, 1));
            skelly[i + 1][1] = true;
            // skelly.insert(make_pair(i + 1, 1));
            cout << i << " 1 " << i + 1 << " 1" << '\n';
        }

        for (int i = 1; i < m; ++i) {
            skelly[h][i] = true;
            skelly[h][i + 1] = true;
            cout << h << " " << i << " " << h << " " << i + 1 << " " << '\n';
        }

        for (int i = h; i < n; ++i) {
            skelly[i][m] = true;
            skelly[i + 1][m] = true;
            // skelly.insert(make_pair(i, m));
            // skelly.insert(make_pair(i + 1, m));
            cout << i << " " << m << " " << i + 1 << " " << m << " " << '\n';
        }

        int cr = 1;
        int cc = 1;
        for (int i = base; i < k; ++i) {
            int nr = cr;
            int nc = cc;
            if (cr == h) {
                base = i;
                break;
            }
            if (cr % 2 == 1) {
                if (cc == m) {
                    nc = cc;
                    nr = cr + 1;
                } else {
                    nc = cc + 1;
                    nr = cr;
                }
            } else {
                if (cc == 2) {
                    nc = cc;
                    nr = cr + 1;
                } else {
                    nc = cc - 1;
                    nr = cr;
                }
            }
            if (skelly[nr][nc]) {
                base = i;
                break;
            }
            cout << cr << " " << cc << " " << nr << " " << nc << " " << '\n';
            skelly[cr][cc] = true;
            skelly[nr][nc] = true;
            cr = nr;
            cc = nc;
            base++;
        }

        cc = m;
        cr = n;

        for (int i = base; i < k; ++i) {
            int nr = cr;
            int nc = cc;
            if (cr == h) {
                break;
            }
            if (cr % 2 == n % 2) {
                if (cc == 1) {
                    nc = cc;
                    nr = cr - 1;
                } else {
                    nc = cc - 1;
                    nr = cr;
                }
            } else {
                if (cc == m - 1) {
                    nc = cc;
                    nr = cr - 1;
                } else {
                    nc = cc + 1;
                    nr = cr;
                }
            }
            if (skelly[nr][nc]) {
                base = i;
                break;
            }
            cout << cr << " " << cc << " " << nr << " " << nc << " " << '\n';
            skelly[cr][cc] = true;
            skelly[nr][nc] = true;
            cr = nr;
            cc = nc;
        }

        // for (auto& p: skelly) {
        //     cout << p.first << " " << p.second << '\n';
        // }

        // Fill in non skelly steps
        for (int i = 1; i <= m; ++i) {
            int j = 0;
            while (h + j + 1 <= n) {
                // cout << i << " " << h + j + 1 << '\n';

                if (!skelly[h + j + 1][i]) {
                    cout << h + j << " " << i << " " << h + j + 1 << " " << i << " " << '\n';
                } else {
                    break;
                }
                j++;
            }
            j = 0;
            while (h - j - 1 > 0) {
                if (!skelly[h - j - 1][i]) {
                    cout << h - j << " " << i << " " << h - j - 1 << " " << i << " " << '\n';
                } else {
                    break;
                }
                j++;
            }
        }
    } else {
        // Can finally start printing
        // go one by one

        // cout << "VERT" << '\n';

        int h = (m + 1) / 2;
        if (m % 2 == 0) {
            base--;
        }

        // cout << n << " " << m << " " << h << '\n';

        for (int i = 1; i < h; ++i) {
            skelly[1][i] = true;
            skelly[1][i + 1] = true;
            cout << "1 " << i << " 1 " << i + 1 << '\n';
        }

        for (int i = 1; i < n; ++i) {
            skelly[i][h] = true;
            skelly[i + 1][h] = true;
            cout << i << " " << h << " " << i + 1 << " " << h << " " << '\n';
        }

        for (int i = h; i < m; ++i) {
            skelly[n][i] = true;
            skelly[n][i + 1] = true;
            cout << n << " " << i << " " << n << " " << i + 1 << " " << '\n';
        }

        int cr = 1;
        int cc = 1;
        for (int i = base; i < k; ++i) {
            // cout << "bob";
            int nr = cr;
            int nc = cc;
            if (cc == h) {
                // cout << i << "\n";
                base = i;
                break;
            }
            if (cc % 2 == 1) {
                if (cr == n) {
                    nr = cr;
                    nc = cc + 1;
                } else {
                    nr = cr + 1;
                    nc = cc;
                }
            } else {
                if (cr == 2) {
                    nr = cr;
                    nc = cc + 1;
                } else {
                    nr = cr - 1;
                    nc = cc;
                }
            }
            if (skelly[nr][nc]) {
                // cout << i << "\n";
                base = i;
                break;
            }
            cout << cr << " " << cc << " " << nr << " " << nc << " " << '\n';
            skelly[cr][cc] = true;
            skelly[nr][nc] = true;
            // skelly.insert(make_pair(cr, cc));
            // skelly.insert(make_pair(nr, nc));
            cr = nr;
            cc = nc;
            base++;
        }

        cc = m;
        cr = n;

        for (int i = base; i < k; ++i) {
            int nr = cr;
            int nc = cc;
            if (cc == h) {
                break;
            }
            if (cc % 2 == m % 2) {
                if (cr == 1) {
                    nr = cr;
                    nc = cc - 1;
                } else {
                    nr = cr - 1;
                    nc = cc;
                }
            } else {
                if (cr == n - 1) {
                    nr = cr;
                    nc = cc - 1;
                } else {
                    nr = cr + 1;
                    nc = cc;
                }
            }
            // cout << "pp " << nr << " " << nc << " " << base << "\n";
            if (skelly[nr][nc]) {
                base = i;
                break;
            }
            cout << cr << " " << cc << " " << nr << " " << nc << " " << '\n';
            // skelly.insert(make_pair(cr, cc));
            // skelly.insert(make_pair(nr, nc));
            skelly[cr][cc] = true;
            skelly[nr][nc] = true;
            cr = nr;
            cc = nc;
        }

        // for (auto& p: skelly) {
        //     cout << p.first << " " << p.second << '\n';
        // }

        // cout << "nonskelly" << "\n";

        // Fill in non skelly steps
        for (int i = 1; i <= n; ++i) {
            int j = 0;
            while (h + j + 1 <= m) {
                // cout << i << " " << h + j + 1 << '\n';

                if (!skelly[i][h + j + 1]) {
                    cout << i << " " << h + j << " " << i << " " << h + j + 1 << " " << '\n';
                } else {
                    break;
                }
                j++;
            }
            j = 0;
            while (h - j - 1 > 0) {
                if (!skelly[i][h - j - 1]) {
                    cout << i << " " << h - j << " " << i << " " << h - j - 1 << " " << '\n';
                } else {
                    break;
                }
                j++;
            }
        }
    }



    return 0;
}