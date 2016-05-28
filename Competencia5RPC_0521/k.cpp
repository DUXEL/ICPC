
// Includes
#include <bits/stdc++.h>
using namespace std;

//Macros

#define EPSILON 0.0000000001
#define INF 1000000000
#define MOD 10000000000

typedef long long ll;
typedef vector<int> vi;



//Global variables.
int mat[26][26];
int n, s;

//Functions

bool checkRows() {
    bool checker[n];
    for(int i = 0; i < n; i++) {
        fill(checker, checker+n, false);
        for(int j = 0; j < n; j++) {
            if(checker[mat[i][j]-1]) return false;
            else checker[mat[i][j]-1] = true;
        }
    }
    return true;
}

bool checkCols() {
    bool checker[n];
    for(int i = 0; i < n; i++) {
        fill(checker, checker+n, false);
        for(int j = 0; j < n; j++) {
            if(checker[mat[j][i]-1]) return false;
            else checker[mat[j][i]-1] = true;
        }
    }
    return true;
}

bool checkGrid() {
    bool checker[n];
    int initRow, initCol,count;
    for(int i = 0; i < n; i+=s) {
        count = s;
        initRow = i;
        initCol = 0;
        while(count--) {
            fill(checker, checker+n, false);
            for(int k = initRow; k < n && k < initRow+s; k++) {
                for(int w = initCol; w < n && w < initCol+s; w++) {
                    if(checker[mat[k][w]-1]) return false;
                    else checker[mat[k][w]-1] = true;
                }
            }
            initCol += s;
        }
    }
    return true;
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> n;
        s = (int) sqrt(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        if(checkRows() && checkCols() && checkGrid()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}