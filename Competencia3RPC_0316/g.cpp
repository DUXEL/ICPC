// Imports.

#include <bits/stdc++.h>

using namespace std;


// Definitions.

#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define MOD 1000007
#define EPSILON 0.000000001
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_N 100002

// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.

int n;
vector<int> tri;
bool visited[3000003];

//Functions

int dif(int a, int b) {
    if((a < 0 && b < 0) || (a > 0 && b > 0)) return abs(a-b);
    return abs(a)+abs(b);
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double x1, y1, x2, y2, l, a, res;
    while(cin >> x1 >> y1 >> x2 >> y2) {
        l = dif(x1, x2);
        a = dif(y1, y2);
        res = (l*l+a*a)/6.0;
        cout << fixed << setprecision(5) << res << "\n";
    }

    return 0;
}