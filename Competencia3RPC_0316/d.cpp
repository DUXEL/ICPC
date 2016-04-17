//============================================================================
// Name        : duxel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long double n, nn, avg, a, a1, a2, b, c, n2, num, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n, n) {
		nn = n*n;
		avg = n;
		c = n*(avg*avg);
		b = 2*avg*(nn);
		n2 = 2*n;
		a1 =(n2 * (n2+1) * (2*n2 + 1))/6.0;
		a2 = ((n*(n+1)*(n2+1))/6.0)*4;
		a = a1-a2;
		num = (a - b + c)/(n-1.0);
		res = sqrt(num);
		cout << fixed << setprecision(6) << res << "\n";

	}
	return 0;
}
