
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

ll n;


//Functions

ll multiply(ll a,ll b,ll mod) {
    if(b==1) return a%mod;
    else if(b==0) return 0;
    else if(b%2==0) return (2*multiply(a,b/2,mod))%mod;
    else return (a+multiply(a,b-1,mod))%mod;
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll res;
    while(cin >> n, n) {
        // Formula (n(n+1)/2)^2 % 10000000000
        res = n*(n+1)/2;
        res = multiply(res, res, MOD);
        cout << res << "\n";
    }
    return 0;
}