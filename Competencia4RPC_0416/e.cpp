
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


//Functions


//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int q, i, j, index, len;
    while(cin >> s >> q) {
        len = s.size();
        while(q--) {
            cin >> i >> j;
            index = ((i-1)+(j-1))%len;
            cout << s[index] << "\n";
        }
    }
    return 0;
}