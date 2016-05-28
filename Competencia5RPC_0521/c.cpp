
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
map<char, int> m;

//Functions


//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str, res, partial, temp;
    char curr;
    while(cin >> str) {
        res = "";
        m.clear();
        int id = 1;
        for(int i = 0; i < str.size(); i++) {
            curr = str[i];
            if(!m[curr]) {
                m[curr] = id;
                id++;
            }
            partial = to_string(m[curr]);
            temp = "";
            for(int j = 0; j < partial.size(); j++) {
                if(partial[j] == '2') temp += "5";
                else if(partial[j] == '5') temp += "2";
                else if(partial[j] == '9') temp += "6";
                else if(partial[j] == '6') temp += "9";
                else temp += partial[j];
            }
            res += temp;
        }
        cout << res << "\n";
    }
    return 0;
}