
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
vector<long long> arr;

//Functions


//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    ll m, w, curr;
    cin >> cases;
    while(cases--) {
        cin >> m >> w;
        arr.clear();
        for(int i = 0; i < m; i++) {
            cin >> curr;
            arr.push_back(curr);
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        ll sum = 0;
        for(int i = 0; i < m; i++) {
            if(sum+arr[i] > w) break;
            res++;
            sum += arr[i];
        }
        cout << res << "\n";
    }
    return 0;
}