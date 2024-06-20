
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
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

int ch[MAX_N];


// Function to get transpose of a matrix
vector<vector<int>> getTranspose(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> transpose(m, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < m; j++) 
    {
        transpose[j][i] = matrix[i][j];
    }
    }
    return transpose;
}

// Function to check for row preservation
bool rowEquality(vector<vector<int>> s,
                vector<vector<int>> f)
{
    vector<set<int>> sets, setf;
    unordered_map<int, int> map;

    // Creating sets from the initial matrix
    for (int i = 0; i < s.size(); i++)
    {

        // Create set for corresponding row
        set<int> sett;

        // Add first element to the set
        sett.insert(s[i][0]);

        // Store the row number in map
        map[s[i][0]] = i;

        // Add remaining elements to the set
        for (int j = 1; j < s[0].size(); j++) 
        {
            sett.insert(s[i][j]);
        }
        sets.push_back(sett);

    }

    // Create sets for final matrix
    // and check with the initial matrix
    int rowIndex = -1;
    for (int i = 0; i < f.size(); i++) 
    {
        rowIndex = -1;
        set<int> sett;

        for (int j = 0; j < f[0].size(); j++)
        {
            sett.insert(f[i][j]);
            if (map.find(f[i][j]) != map.end())
            {
                rowIndex = map[f[i][j]];
            }
        }

        setf.push_back(sett);
        // cout << "i = " << i << endl;
        // cout << sets.size() << endl;
        // cout << setf.size() << endl;
        // cout << s.size() << endl;
        // cout << f.size() << endl;
        // cout << rowIndex << endl;

        // for (auto& b: setf[i]) {
        //     cout << b << endl;
        // }

        // for (auto& b: sets[rowIndex]) {
        //     cout << b << endl;
        // }
        
        if (setf[i] != sets[rowIndex]) 
            return false;
    }

    return true;
}

// 1 2
// 3 4

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;


        vector<vector<int>> startMatrix;

        vector<vector<int>> finalMatrix;

        for (int i = 0; i < n; i++) {
            vector<int> t;
            for (int j = 0; j < m; j++) {
                int x; 
                cin >> x;
                t.push_back(x);
            }
            startMatrix.push_back(t);
        }

        for (int i = 0; i < n; i++) {
            vector<int> t;
            for (int j = 0; j < m; j++) {
                int x; 
                cin >> x;
                t.push_back(x);
            }
            finalMatrix.push_back(t);
        }

        if (n == 1 or m == 1) {
            cout << "YES" << endl;
            continue;
        }
        
        vector<vector<int>> startTranspose = getTranspose(startMatrix);
        vector<vector<int>> finalTranspose = getTranspose(finalMatrix);
        
        if (rowEquality(startMatrix, finalMatrix) &&
            rowEquality(startTranspose, finalTranspose))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } 

}