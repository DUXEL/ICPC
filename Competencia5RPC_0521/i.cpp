// Includes
#include <bits/stdc++.h>

using namespace std;

//Macros

#define EPSILON 0.0000000001
#define INF 1000000000
#define MOD 10000000000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long double, int> pli;


//Global variables.

vector<pli> votes;
long double cityVotes[502];

//Functions

bool comp(pli a, pli b) {
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else {
        return a.second < b.second;
    }
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, candidates, cities;
    long double tempVotes, totalPopulation, cityPopulation, votePerc;
    cin >> cases;
    while(cases--) {
        cin >> candidates >> cities;
        votes.assign((unsigned long) candidates, {0, 0});
        totalPopulation = 0;
        for(int j = 0; j < cities; j++) {
            for(int i = 0; i < candidates; i++) {
                cin >> votePerc;
                cityVotes[i] = votePerc/100.0;
                votes[i].second = i+1;
            }
            cin >> cityPopulation;
            totalPopulation += cityPopulation;
            for(int i = 0; i < candidates; i++) {
                tempVotes = (ll) round(cityVotes[i]*cityPopulation);
                votes[i].first += tempVotes;
            }
        }
        sort(votes.begin(), votes.end(), comp);
        if(((ll)votes[0].first*1000) >= ((ll)501*totalPopulation)) {
            cout << votes[0].second << " " << (ll)votes[0].first;
        }else {
            cout << votes[0].second << " " << (ll)votes[0].first << "\n";
            cout << votes[1].second << " " << (ll)votes[1].first;
        }
        if(cases) cout << "\n\n";
    }
    return 0;
}