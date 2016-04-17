// Imports.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;


// Definitions.

#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define MOD 1000000007
#define EPSILON 0.000000001
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_N 100001

// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.


int arr[100005][11];


//Functions

//Main

int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(false);
    fill(arr[0], arr[0]+10, 0);
    int n, m, l, r, read, res;
    while(cin >> n) {
        for(int i = 1; i <= n; i++) {
            cin >> read;
            for(int d = 0; d < 10; d++) arr[i][d] = arr[i-1][d];
            arr[i][read]++;
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            res = 0;
            cin >> l >> r;
            if(l == 1) {
                for(int d = 0; d < 10; d++) {
                    if(arr[r][d]) res++;
                }
            }else {
                for(int d=0; d < 10; d++) {
                    if(arr[r][d]-arr[l-1][d]) res++;
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}
