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
short memo[3000002];

//Functions

int bfs(int num) {
    queue<ii> q;
    fill(visited, visited+3000002, false);
    q.push({num, 0});
    visited[0] = true;
    int i, sum;
    ii curr, next;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        memo[curr.first] = curr.second;
        if(curr.second >= 2) continue;
        i = 0;
        sum = curr.first+tri[i];
        while(sum <= 10000) {
            if(!visited[sum]) {
                visited[sum] = true;
                q.push({sum, curr.second+1});
            }
            i++;
            sum = curr.first+tri[i];
        }
    }
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int curr = 0;
    for(int i = 1; curr <= 3000000; i++) {
        curr += i;
        tri.push_back(curr);
    }
    fill(memo, memo+3000002, 3);
    int sum;
    bool flag;
    for(int i = 0; i < tri.size(); i++) {
        memo[tri[i]] = 1;
        flag = true;
        for(int j = i; j < tri.size() && flag; j++) {
            sum = tri[i] + tri[j];
            if(sum > 3000000) {
                flag = false;
            }else {
                if(memo[sum] > 2) memo[sum] = 2;
            }
        }
    }
    //bfs(0);
    while(cin >> n) {
        cout << memo[n] << "\n";
    }

    return 0;
}