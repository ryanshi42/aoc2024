#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const int N = 2000;

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

vector<string> folds;

bool rowCrease[N][N];
bool colCrease[N][N];

bool rowEq(int row, int rows, int cols) {
    for (int i = 1; i < cols; i++)
        if (rowCrease[row][i] != rowCrease[row][0])
            return false;

    return true;
}

bool colEq(int col, int rows, int cols) {
    for (int i = 1; i < rows; i++)
        if (colCrease[i][col] != colCrease[0][col])
            return false;

    return true;
}

bool rowMirrored(int row, int rows, int cols) {
    int r = cols / 2;
    int l = r - 1;

    while (l >= 0 && r < cols) {
        if (colCrease[row][l] == colCrease[row][r]) {
            return false;
        }
        l--;
        r++;
    }

    return true;
}

bool colMirrored(int col, int rows, int cols) {
    int r = rows / 2;
    int l = r - 1;

    while (l >= 0 && r < rows) {
        if (colCrease[l][col] == colCrease[r][col]) {
            return false;
        }

        l--;
        r++;
    }

    return true;
}

/**
 * Possible if
 * - The middle column is all equal:
 *      - Each row mirrors itself across the middle
 *      - Every column outwards from the middle is a mirror of the other
 * - The middle row is all equal
 *      - Each column through the middle mirrors
 *      - Each row outwards from middle mirrors
 * - If good:
 *      - fold on column => recurse on left half
 *      - fold on row => recurse on top half
 */
bool go(int rows, int cols) {
    if (rows == 1 && cols == 1) return true;
    //cerr << rows << " " << cols << "\n";

    int midRow = (rows - 1) / 2;
    int midCol = (cols - 1) / 2;
    
    if (rows > 1 && rowEq(midRow, rows, cols)) {
        //cerr << "ROW EQ\n";
        for (int i = 0; i < cols - 1; i++)
            if (!colMirrored(i, rows, cols)) {
                //cerr << "  COL " << i << " NOT MIRRORED\n";
                return false;
            }
        for (int i = 1; midRow + i < rows - 1; i++)
            if (
                rowCrease[midRow + i][0] == rowCrease[midRow - i][0] ||
                !rowEq(midRow + i, rows, cols) ||
                !rowEq(midRow - i, rows, cols)
            ) {
                //cerr << "  ROWS " << midRow - i << " = " << colCrease[midRow - i][0] << " & " << midRow + i <<" = " << colCrease[midRow + i][0] << " NOT MIRRORED\n";
                return false;
            }

        folds.emplace_back(rowCrease[midRow][0] ? "UM" : "UV");
        return go(rows / 2, cols);
    } else if (cols > 1 && colEq(midCol, rows, cols)) {
        //cerr << "COL EQ\n";

        for (int i = 0; i < rows - 1; i++)
            if (!rowMirrored(i, rows, cols)) {
                //cerr << "  ROW " << i << " NOT MIRRORED\n";
                return false;
            }
        for (int i = 1; midCol + i < cols - 1; i++)
            if (
                colCrease[0][midCol + i] == colCrease[0][midCol - 1] ||
                !colEq(midCol + i, rows, cols) ||
                !colEq(midCol - 1, rows, cols)
            ) {
                //cerr << "  COLS " << midCol - i << " & " << midCol + i << " NOT MIRRORED\n";
                return false;
            }

        folds.emplace_back(colCrease[0][midCol] ? "LM" : "LV");
        return go(rows, cols / 2);
    }

    //cerr << "NOTHING EQ\n";


    return false;
}


int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c - 1; j++)
            cin >> colCrease[i][j];

    for (int i = 0; i < r - 1; i++)
        for (int j = 0; j < c; j++)
            cin >> rowCrease[i][j];

    if (go(r, c)) {
        cout << "YES\n";
        for (const auto& fold : folds)
            cout << fold << "\n";
    } else {
        cout << "NO\n";
    }

}
/**
2 4
1 1 0
0 0 1
1 1 1 1
*/

/**
4 4
1 1 0
1 1 0
0 1 1
0 1 1
1 1 1 0
0 0 1 1
0 1 0 1
*/