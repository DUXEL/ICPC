
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
ll memo[205][205];

//Functions

ll binomial(ll n, ll k) {
    if(k > n) return 0;
    if(n == k || !k) return 1;
    if(memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = binomial(n-1, k-1) + binomial(n-1, k);
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    ll num;
    memset(memo, -1, sizeof memo);
    cin >> cases;
    while(cases--) {
        cin >> num;
        ll res;
        if(num == 1) res = 1;
        else if(num == 2) res = 2;
        else if(num == 3) res = 4;
        else res = binomial(num, 4) + binomial(num, 2) + 1;
        cout << res << "\n";
    }
    return 0;
}