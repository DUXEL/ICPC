//============================================================================
// Name        : duxel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

void print(int n) {
	cout <<"+";
	for(int i=0; i<(2*n)-1;i++) cout <<"-";
	cout <<"+\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long T, MOD, init, index;
	char dir;
	string a, b, clock, letters, res;
	while(cin >> N >> T >> dir) {
		cin >>a;
		getline(cin, clock);
		getline(cin, clock);
		cin>>b;
		MOD = 2*N+1;
		res.assign(MOD, '|');
		if(dir == 'R') {
			for(int i = 1; i < MOD;i += 2 ) {
				T %= N;
				index = i/2;
				index = (((index+T)+N)%N)*2+1;
				res[index] = clock[i];
			}
		}else {
			for(int i = 1; i < MOD; i += 2 ) {
				T %= N;
				index = i/2;
				index = (((index+N)-T)%N)*2+1;
				res[index] = clock[i];
			}
		}

		print(N);
		cout << res << "\n";
		print(N);
	}
	return 0;
}

/*
int main() {
	ios::sync_with_stdio(0);
	//cin.tie(0);
	int N, cnt;
	long long T, MOD, init;
	char dir;
	string a, b, clock, letters, res;
	while(cin >> N >> T >> dir) {
		cin >>a;
		getline(cin, clock);
		getline(cin, clock);
		cin>>b;
		MOD = 2*N+1;
		letters = "";
		for(int i = 1; i < MOD; i += 2) {
			letters += clock[i];
		}
		init = (N+T)%N;
		res = "";
		cnt = 0;
		if(dir == 'R') {
			if(init) init = N-init;
			for(; cnt < N; init = (init+1)%N) {
				cnt++;
				res += "|";
				res.push_back(letters[init]);
			}
		}else {
			for(; cnt < N; init = (init+1)%N) {
				cnt++;
				res += "|";
				res.push_back(letters[init]);
			}
		}
		print(N);
		cout << res << "|\n";
		print(N);
	}



	return 0;
}
*/

