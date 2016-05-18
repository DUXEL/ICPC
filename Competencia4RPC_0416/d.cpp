
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

string n;


//Functions

int getDigitVal(char c) {
    if(c < 65) return c-48;
    else return c-55;
}

bool isDivisible(int div) {
    int len = n.size();
    int num = 0;
    for (int i=0; i < len; i++) {
        num = num*16 + getDigitVal(n[i]);
        num %= div;
    }
    return !num;
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n) {
        if(isDivisible(17)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}