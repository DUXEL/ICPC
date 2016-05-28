// Includes
#include <bits/stdc++.h>

using namespace std;

//Macros

#define EPSILON 0.0000000001
#define INF 1000000000
#define MOD 10000000000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


//Global variables.

int n, m;
int colMemo[302][302];
int memo[302];
int mat[302][302];


//Functions

int getColValue(int col, int row) {
    if(row >= n) return 0;
    if(colMemo[row][col] != -1) return colMemo[row][col];
    return colMemo[row][col] = max(mat[row][col]+getColValue(col, row+2), getColValue(col, row+1));
}

int dp(int col) {
    if(col >= m) return 0;
    if(memo[col] != -1) return memo[col];
    return memo[col] = max(getColValue(col, 0)+dp(col+2), dp(col+1));
}


//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cin >> mat[i][j];
        }
        memset(memo, -1, sizeof memo);
        memset(colMemo, -1, sizeof colMemo);
        cout << dp(0) << "\n";
    }
    return 0;
}