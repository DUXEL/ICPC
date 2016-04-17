#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k, arr[20];
ll n;
bitset<60> bs;
string positions;

bool isDivisible(string n, int div) {
    int num = 0;
    for (int i=0; i < n.size(); i++) {
        num = num*2 + n[i]-48;
        num %= div;
    }
    return !num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string bin;

    while(cin >> n) {
        bs = n;
        cin >> k;
        positions = "";
        for (int i=0; i<k; i++) cin >> arr[i];
        bin = bs.to_string();

        for (int i=0; i<k; i++) {
            positions += bin[bin.size()-arr[i]-1];
        }
        sort(positions.begin(), positions.end());
        string modified;
        ll maxx = 0, curr;

        do {
            modified = bin;
            for (int i=0; i<k; i++) {
                modified[59 - arr[i]] = positions[i];
            }
            if (isDivisible(modified, 7)) {
                maxx = stoll(modified, NULL, 2);
                break;
            }
        } while( prev_permutation(positions.rbegin(), positions.rend()) );
        cout << maxx << "\n";
    }
    return 0;
}